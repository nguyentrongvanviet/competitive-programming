#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

ll st ;
ll en ;
ll dd[N] ;
ll d1[N] ,d2[N] , h[N];
ll ma = -inf ;
ll n ,  m , k ;
vector<ll>g[N];
void dfs(ll u , ll p )
{
    if(dd[u]==1)
    {
        if(h[u]>ma)
        {
            ma=max(ma,h[u]);
            st = u ;
        }
    }
    for(auto v : g[u])
    {
        if(v==p)continue;
        h[v] =h[u]+1;
        dfs(v,u);
    }
}
void dfs1(ll u , ll p )
{
    if(dd[u]==1&&d1[u]>ma)
    {
        ma=max(ma,d1[u]);
        en= u ;
    }
    for(auto v : g[u])
    {
        if(v==p)continue ;
        d1[v]=d1[u]+1;
        dfs1(v,u);
    }
}
void dfs2(ll u , ll p )
{
    for(auto v : g[u])
    {
        if(v==p)continue ;
        d2[v]=d2[u]+1;
        dfs2(v,u);
    }
}
void inp()
{
    cin>>n>>m>>k ;
    for(ll i= 1;i<=n-1;i++)
    {
        ll u , v;
        cin>>u>>v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    for(ll i=1;i<=m;i++)
    {
        ll u ;
        cin>>u;
        dd[u] = 1;
    }
    dfs(1,0);
    ma=-inf;
    dfs1(st,0);
    dfs2(en,0);
    ll res= 0 ;
    for(ll i= 1;i<=n;i++)
    {
        if(d1[i]<=k&&d2[i]<=k)
        {
            res++ ;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}
