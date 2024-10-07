#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
#define all(a) a.begin(),a.end() 
int mex(vector<int>&val)
{
    sort(val.begin(),val.end()) ;
    val.resize(unique(val.begin(),val.end())-val.begin());
    for(int i=0;i<int(val.size());i++)if(val[i]!=i)return i ;
    return int(val.size()) ; 
}
int f[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;       
    int n = 2e3 ; 
    for(int i=1;i<=n;i++)
    {
        vector<int>val ;
        for(int j=1;2*j<i;j++)
        {
            val.push_back(f[j]^f[i-j]) ; 
        }
        f[i] = mex(val) ; 
    }
    int test ;cin>>test;
    while(test--)
    {
        int n; cin>> n;
        if(n>=2000||f[n])cout<<"first"<<'\n';
        else cout<<"second"<<'\n' ;
    }
}