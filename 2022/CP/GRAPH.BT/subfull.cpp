#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n  ;
ll a[N] , b[N] ;
ll sa[N] , sb[N] ;
ll f[N][N] ;
void inp()
{
    cin>> n ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i] ;
    }
    for(ll i =1 ;i<=n;i++)
    {
        sa[i] =sa[i-1]+a[i] ;
        sb[i] =sb[i-1]+b[i] ;
    }
    ll res= -INF ;
    for(ll i =1 ;i<=n;i++)
    {
        for(ll j =1;j<=n;j++)
        {
            f[i][j] =a[i]*b[j]-(sa[i-1]*sa[i-1]+sb[j-1]*sb[j-1]);
            res=max(res,f[i][j]-(sa[n]-sa[i])*(sa[n]-sa[i])-(sb[n]-sb[j])*(sb[n]-sb[j]));
            for(ll u= 1 ;u<=i-1;u++)
            {
                for(ll v= 1;v<=j-1;v++ )
                {
                    f[i][j] =max(f[i][j],a[i]*b[j]+f[u][v]-(sa[u]-sa[i-1])*(sa[u]-sa[i-1])-(sb[j-1]-sb[v])*(sb[j-1]-sb[v]));
                    res=max(f[i][j]-(sa[n]-sa[i])*(sa[n]-sa[i])-(sb[n]-sb[j])*(sb[n]-sb[j]),res);
                }
            }
//            cout<<f[i][j]<<" " ;
        }
    }
    cout<<res ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
