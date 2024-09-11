#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ;
int nt[int(1e7+3)] ;
vector<int>snt  ;  
vector<int> sieve()
{
    vector<int>snt ; 
    for(int i=2;i<=1e7;i++)
    {
        if(nt[i]==0)
        {
            snt.push_back(i) ; 
            nt[i] = i ; 
            for(int j=i;j<=1e7/i;j++)
            {
                nt[i*j] = i ; 
            }
        }
    }
    return snt ; 
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    vector<int>prime = sieve() ; 
    int l ,r ;cin>> l >>r ;
    int res = 0 ; 
    for(auto x : prime)
    {
        if(l<=x&&x<=r)res++ ; 
    }
    cout<<res ;
    return 0 ; 
}