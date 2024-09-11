#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int a[N] ;  
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; cin>> n;
    for(int i=1;i<=n;i++)cin>>a[i] ;
    sort(a+1,a+n+1) ;
    long long  res = 0 ;  
    for(int i=1;i<=n;i++)
    {
        int t = i+1 ;
        for(int j=1;j<=i-1;j++)
        {
            while(t!=n+1 && a[i]+a[j]>a[t])++t ; 
            res+=t-i-1;
        }
    }
    cout<<res; 
}