#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , m  , k ;
vector<ll>g[N] ;
ll h[N];
ll dd[N] ;
ll dis[N] ;
void dfs(ll u , ll p )
{
    if(dd[u]==1)
    {
        h[u]= 0 ;
    }
    for(ll i = 0 ;i<g[u].size();i++)
    {
        ll v=g[u][i] ;
        if(v==p)continue ;
        dfs(v) ;
    }
}
void inp()
{
    cin>>n>>m>>k ;
    for(ll i =1;i<=n-1;i++)
    {
        ll u , v ;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(ll i =1;i<=m;i++)
    {
        ll u  ;
        cin>>u ;
        dd[u]=1 ;
    }
    dfs(1,0);
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
