#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
#define read(x)  freopen("input.txt","r",stdin);
#define iter(x)  x.begin(),x.end()
#define ll long long
#define ull unsigned ll
#define endl '\n'
#define inf INT_MAX
#define mod 1000000007
#define pa pair<int,int>
#define less_than order_of_key
#define value_at_index find_by_order
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



int32_t main()
{
    int t;
    cin>>t;
    int n,m;
    cin>>n>>m;
    vector<vector<int> >adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;

    }
    string ans;
    cin>>ans;
    if(ans=="NO")
    {
        cout<<1<<endl;
        return 0;
    }
    int center;
    cin>>center;
    vector<int>degree(n+1);


    map<int,int>mp;
    for(int i=0;i<center;i++)
    {
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;


    }
    for(int i=1;i<=n;i++)
        if(degree[i])
            mp[degree[i]]++;
    if(mp.size()==3 and mp[4]==1 and mp[1]==2 )
        cout<<1<<endl;
    else
        cout<<0<<endl;







    return 0;

}
