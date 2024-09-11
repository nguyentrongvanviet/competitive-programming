#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    string s ; cin>>s ; 
    int res = 0 ;
    int open = 0 ; 
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='(')open++ ; 
        else open-- ; 
        if(open==-1)res++,open=1;
    }   
    res+=open/2 ; 
    cout<<res ; 
    return 0 ;
}