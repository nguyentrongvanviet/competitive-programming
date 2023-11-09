#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

ll n , m  , k;
ll db[N] , dd[N] ;
ll ans[N] ;
ll d1[N],d2[N];
ll f[N];
vector<ll>g[N];
void dfs(ll u ,ll ba)
{
    d1[u]=-inf ;
    d2[u]=-inf;
    if(db[u]==1)
    {
        d1[u] = 0 ;
    }
    for(auto v : g[u])
    {
        if(v==ba)continue;
        dfs(v,u);
        if(d1[u]<=d1[v]+1&&d1[v]!=-inf)
        {
            d2[u] =d1[u];
            d1[u] = d1[v]+1 ;
        }
        else if(d2[u]<=d1[v]+1&&d1[v]!=-inf)
        {
            d2[u] =d1[v]+1;
        }
        if(d1[u]>k)
        {
            dd[u]=1;
        }
    }
}
void dfs2(ll u , ll ba)
{
    if(dd[u]==0&&u!=1)
    {
        if(d1[ba]==d1[u]+1)
        {
            if(d2[ba]+1>k)
            {
                dd[u]=1 ;
            }
        }else
        {
            if(d1[ba]+1>k)
            {
                dd[u] =1;
            }
        }
    }
    if(d1[ba]==d1[u]+1&&u!=1)
    {
        if(d2[ba]>=d1[u]+1)
        {
            d2[u] =d1[u];
            d1[u] = d2[ba]+1;
        }
        else if(d2[ba]>d2[u]+1)
        {
            d2[u]=d2[ba]+1;
        }
    }
    else
    {
        if(u!=1)
        {

        d2[u] = d1[u]+1;
        d2[u] =d2[ba]+1;
        if(d2[ba]+1>d2[u])
        {
            d2[u] =d2[ba]+1;
        }
        }
    }
    for(auto v : g[u])
    {
        if(v==ba)continue ;
        dfs2(v,u);
    }
}
void inp()
{
    cin>>n>>m>>k;
    for(ll i=1;i<=n-1;i++)
    {
        ll u , v ;
        cin>>u>>v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    for(ll i= 1; i<=m;i++)
    {
        ll u ;
        cin>>u ;
        db[u]=1;
    }
    dfs(1,0) ;
    dfs2(1,0);
    ll res= 0 ;
//    for(ll i=1;i<=n;i++)
//    {
//        cout<<d1[i]<<" "<<d2[i]<<endl;
//    }
    for(ll i=1;i<=n;i++)
    {
        if(dd[i]==0)
        {
            res++;
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
