#include<bits/stdc++.h>
using namespace std ; 
#define ll long long 
const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 998244353
; 

int n; 
int a[N] , ma[N] ; 
int sum[N] ; 
ll pw(ll a, ll n)
{
    if(n==0) return 1;
    ll b = pw(a,n/2); 
    if(n&1)return b*b%sm*a%sm;
    return b*b%sm ;
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n; 
    for(int i=1;i<=n;i++)cin>>a[i] ;    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/i;j++)
        {
            ma[i] = max(ma[i],a[i*j]) ; 
        }
    }
    for(int i=1;i<=n;i++)sum[ma[i]]++; 
    for(int i=1;i<=1e5;i++)sum[i]+=sum[i-1] ; 
    ll res = 0 ; 
    for(int i=1;i<=1e5;i++)
    {
        (res+=((pw(2,sum[i]-sum[i-1])-1)*pw(2,sum[i-1]))%sm*i%sm)%=sm;
    }
    cout<<res;
}