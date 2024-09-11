#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int a[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int cam , n ; cin>>cam>> n; 
    for(int i=1;i<=n;i++)cin>>a[i] ;
    sort(a+1,a+n+1) ; 
    int value = 0 ; 
    long long res = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(res<1ll*a[i]*min(cam,n-i+1))
        {
            res=1ll*a[i]*min(cam,n-i+1) ;
            value = a[i] ; 
        }
    }
    cout<<value<<" "<<res;
    return 0; 
}