#include<bits/stdc++.h>
using namespace std ;
int n ; 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
    map<char,int>sl ; 
    string s ; cin>>s ;
    for(auto c : s)
    {
        sl[c]++ ; 
    }
    long long res = 0 ;  
    for(auto x : sl)
    {
        res+= 1ll*x.second*x.second ; 
    }
    cout<<res;  
    return 0 ; 
}