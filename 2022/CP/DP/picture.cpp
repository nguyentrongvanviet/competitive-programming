#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , m;
ll a[N][N] ;
ll f[N][N];
ll ma[N][N];
void inp()
{
    cin>> n >> m ;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(f,-1e9,sizeof(f));
    memset(ma,-1e9,sizeof(ma));
    for(ll i=1;i<=m;i++)
    {
        f[1][i] =max(f[1][i-1],a[1][i]);
        ma[1][i] =max(ma[1][i-1],f[1][i]);
    }
    for(ll i=2 ;i<=n;i++)
    {
        for(ll j=i;j<=m;j++)
        {
            f[i][j] = ma[i-1][j-1]+a[i][j];
            ma[i][j] =max(ma[i][j-1],f[i][j]);
        }
    }
    ll res=-INF ;
    for(ll i= n;i<=m;i++)
    {
        res=max(res,f[n][i]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
