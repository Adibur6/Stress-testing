#include<bits/stdc++.h>
using namespace std;
#define iter(x) x.begin(),x.end()
struct random_generate{

    std::mt19937 gen;  //software generated random number
    random_generate()
    {
         auto currentTime = std::chrono::high_resolution_clock::now();
         auto seed = static_cast<unsigned int>(currentTime.time_since_epoch().count());

        gen.seed(seed);
    }
    long long between(long long m,long long n)
    {
         assert(m<=n);
         std::uniform_int_distribution<long long> dist(m,n);
         return dist(gen);
    }
    double betweenf(double m,double n)
    {
         assert(m<=n);
         std::uniform_real_distribution<double> dist(m,n);
         return dist(gen);
    }
    template<typename T>
    vector<T> shuffle(vector<T>v)
    {
        std::shuffle(std::begin(v), std::end(v), gen);
        return  v;
    }
    std::string generateRandomString(int length, int custom = 0, std::string choice = "") {
    std::string chars;
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string punctuation = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    switch (custom) {
        case 1:
            chars = lowercase;
            break;
        case 2:
            chars = uppercase;
            break;
        case 3:
            chars = lowercase + uppercase + punctuation;
            break;
        case 4:
            chars = choice;
            break;
        default:
            chars = lowercase + uppercase;
    }

    std::string result;

    for (int i = 0; i < length; i++) {
        result += chars[between(0,chars.size()-1)];
    }

    return result;
}

    void graph()
    {
        int n=between(5,10);
        int m=between(n-1,n*(n-1)/2);
        cout<<n<<' '<<m<<endl;
        set<pair<int,int>>s;
        while(m--)
        {
            int p=between(1,n),q=between(1,n);
            while(p==q or s.count({p,q})or s.count({q,p}))
            {
                p=between(1,n),q=between(1,n);

            }
            s.insert({p,q});
            cout<<p<<' '<<q<<endl;
        }

    }
    void tree(int n)
    {
        cout<<n<<endl;
        vector<int>v={1};

        for(int i=2;i<=n;i++)
        {
            int c=between(1,v.size())-1;
            cout<<v[c]<<' '<<i<<endl;
            v.push_back(i);


        }
    }
    void random_array(int length,int left_range,int right_range,bool is_unique=false,bool is_incresing=false)
    {
        cout<<length<<endl;
        set<int>set_for_unique;
        vector<int>res(length);
        for(int i=0;i<length;i++)
        {
            int p=between(left_range,right_range);
            if(is_unique)
            {
                while(is_unique and set_for_unique.count(p))
                    p=between(left_range,right_range);
                res[i]=p;
                set_for_unique.insert(p);
            }
            else
                res[i]=p;

        }
        if(is_incresing)
            sort(iter(res));
        for(int i:res)  cout<<i<<' ';
        cout<<endl;
    }



};
int main()
{



    random_generate a;

    a.random_array(3,4,7,true);









}
