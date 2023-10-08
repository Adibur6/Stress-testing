"""

    Here I have coded 2 types of stress testing:

    1. Against a accepted solution.
        1.1. here put you solution int the solution.cpp file
        1.2. put to correct submission in the brute.cpp file
        1.3. create a gen.cpp file that creats random output to generate test cases


    2. Against a validator
        2.1. here put you solution int the solution.cpp file
        2.2. create a gen.cpp file that creats random output for generating test cases
        2.3 create a acceptor.cpp file that 
                first-> takes test cases
                second-> solution output
                check if it is valid
                return 1 if valid
                otherwise 0 




"""
import subprocess


n= int(input("Enter the number of test cases: "))
s= input("1 to check against a existing brute force solution otherwise 0: ")

# Compile the C++ programs
print("Compiling the programs please wait...")
subprocess.run(['g++','-std=c++17', '-o', 'gen', 'gen.cpp'])
subprocess.run(['g++','-std=c++17', '-o', 'solution', 'solution.cpp'])
if s=='1':
    subprocess.run(['g++','-std=c++17', '-o', 'brute', 'brute.cpp'])
else:
    subprocess.run(['g++','-std=c++17', '-o', 'acceptor', 'acceptor.cpp'])
    
# Run gen and capture its output
for i in range(n):
    result_gen = subprocess.run(['./gen'], stdout=subprocess.PIPE)

    # Pass the output of gen to solution and brute and capture their output
    result_solution = subprocess.run(['./solution'], input=result_gen.stdout, stdout=subprocess.PIPE)

    if s=='1':
        result_brute = subprocess.run(['./brute'], input=result_gen.stdout, stdout=subprocess.PIPE)
        # Compare the output of solution and brute
        print(f"Test case {i+1}",end=' ')
        if result_solution.stdout == result_brute.stdout:
            print("OK!")
            
           

        else:
            print("Problem found! Test case here: ")
            print(result_gen.stdout.decode())
            print('Brute :')
            print(result_brute.stdout.decode())
            print('Solution :')
            print(result_solution.stdout.decode())
    else:
        result_acceptor = subprocess.run(['./acceptor'], input=result_gen.stdout+result_solution.stdout, stdout=subprocess.PIPE)
        # Compare the output of solution and brute
        print(f"Test case {i+1}",end=' ')
        p=int (result_acceptor.stdout.decode())
       
        
        if bool(p):
            print("OK!")
        else:
            print("Problem found! Test case here: ")
            print(result_gen.stdout.decode())
            print('Solution :')
            print(result_solution.stdout.decode())
            
        

