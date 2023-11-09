#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =450+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;


ll n , m ;
ll f[N][N];
ll ans[N];
void inp()
{
    cin>>n>>m ;
    for(ll i=1 ;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            f[i][j] = INF ;
            if(i==j)f[i][j]=0  ;
        }
    }
    for(ll i= 1;i<=m;i++)
    {
        ll u , v , w ;
        cin>>u>>v>>w;
        f[u][v] =min(f[u][v],w);
        f[v][u]=min(f[v][u],w);
    }
    for(ll k= 1 ;k<=n;k++)
    {
        for(ll i= 1;i<=n;i++)
        {
            for(ll j= 1;j<=n;j++)
            {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    ll res = INF ;
    ll pos ;
    for(ll i=1 ;i<=n;i++)
    {
        ll s= 0 ;
        for(ll j=1;j<=n;j++)
        {
            s+=f[i][j];
        }
        ans[i] = s;
        if(res>s) res =s ,pos = i ;
    }
    ll t= 0 ;
    for(ll i=1;i<=n;i++)
    {
        if(ans[i] == res) t++;
    }
    cout<<res<<" " << t ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
