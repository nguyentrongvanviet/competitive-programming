#include<bits/stdc++.h>
using namespace std ; 

const int N = 2e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int n ;
int a[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; cin>> n; 
    cout<<n<<endl;
    return 0; 
    for(int i=1;i<=n;i++)cin>>a[i] ;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=a[2]-a[1])
        {
            cout<<"NO" ;
            return 0 ;
        }
    }
    cout<<"YES" ;
    return 0;
}