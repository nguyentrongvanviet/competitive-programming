#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =200+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

ll n ;
ll f[N];
ll a[N] ;
void inp()
{
    cin>> n;
    for(ll i=1 ;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1) ;
    for(ll i= 1;i<=n;i++)
    {
        f[i] =1 ;
    }
    ll res =0 ;
    for(ll i =1;i<=n;i++)
    {
        for(ll j =1;j<=i-1;j++)
        {
            if(a[i]%a[j]==0)f[i] = max(f[i],f[j]+1) ;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        res=max(res,f[i]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
