#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; 
    vector<int>a(n+1) ;
    for(int i=1;i<=n;i++)cin>>a[i] ;
    int res = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[1])
            res=max(res,i-1) ; 
        if(a[i]!=a[n])
            res=max(res,n-i) ;
    }
    cout<<res;
}