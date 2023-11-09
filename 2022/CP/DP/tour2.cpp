#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =2e5+5 ,  inf = 1e17  ;
vector<ll>g[N];
ll n , m ;
ll tt = 0 ;
ll low[N] , id[N] ;
map<ll,ll>dd[N] ;
map<ll,ll>d[N] ;
ll res= 0 ;
void dfs(ll u ,ll p   )
{
    low[u] = id[u]=++tt;
    for(auto v :g[u])
    {
        if(v==p)continue ;
        if(id[v])
        {
            low[u] = min(low[u],id[v]) ;
        }else
        {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(id[u]<low[v])
            {
                if(dd[u][v]==0)
                {
                    res++;
                }
            }
        }
    }
}
void inp()
{

    cin>>n;
    for(ll i=1 ;i<=n-1;i++)
    {
        ll u , v;
        cin>>u>>v ;
        g[u].pb(v) ;
        g[v].pb(u);
        d[u][v] =1;
        d[v][u] =1 ;
    }
    cin>> m;
    for(ll i= 1;i<=m;i++)
    {
        ll u , v ;
        cin>>u>>v ;
        if(d[u][v]==0)g[v].pb(u) ;
        if(d[u][v]==0)g[u].pb(v) ;
        dd[u][v]=1;
        dd[v][u] =1 ;
        f[u]++ ;
        f[v]++ ;
        f[lca(u,v)]-=2;
    }
    dfs(1,0);
    cout<<res;ac
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
