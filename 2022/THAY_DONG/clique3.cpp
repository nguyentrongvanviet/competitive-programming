#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =3e6+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;
ll n ;
ll a[N]  ;
ll m[N];
ll f[4][N];
void inp()
{
    cin>> n ;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    sort(a+1,a+n+1) ;
    ll res= 0 ;
    for(ll i= 1;i<=n;i++)f[1][a[i]]=1;
    for(ll i =1;i<=2;i++)
    {
        for(ll t =1 ; t<=n;t++)
        {
            for(ll x= 2*a[t];x<=a[n];x+=a[t])
            {
                f[i+1][x]+=f[i][a[t]];
            }
        }

    }
    res= 0 ;
    for(ll i=1 ;i<=n;i++)res+=f[3][a[i]] ;
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
