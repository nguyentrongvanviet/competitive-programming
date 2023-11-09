#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
struct edge
{
    ll u , v , w;
    bool operator<(edge a )
    {
        return w>a.w;
    }
};
struct ke
{
    ll v , w ;
};
ll n , m ;
edge q[N];
vector<edge>s;
vector<ke>g[N];
ll pa[N] , h[N] ;
ll p[N][35] ,mi[N][35];

ll goc(ll u )
{
    return (pa[u]==u ?  u : pa[u] =goc(pa[u]));
}
void dfs(ll u , ll pa )
{
    for(ll i= 0 ;i<g[u].size();i++)
    {
        ll v = g[u][i].v;
        ll w= g[u][i].w;
        if(v==pa)continue;
        h[v]=h[u]+1;
        p[v][0] = u ;
        mi[v][0] = w ;
        dfs(v,u) ;
    }
}

ll lca(ll u , ll v )
{
    if(h[u]<h[v])swap(u,v);
    ll dis = h[u] - h[v] ;
    ll ans=  INF ;
    for(ll i= 0 ;i<=30;i++)
    {
        if((1<<i)&dis)
        {
            ans = min(ans,mi[u][i]) ;
            u=p[u][i] ;
        }
    }
    if(u==v)return ans;
    for(ll i =30;i>=0;i--)
    {
        ll uu = p[u][i] ;
        ll vv= p[v][i] ;
        if(uu!=vv)
        {
            ans= min(ans,min(mi[u][i],mi[v][i]));
            u= uu ;
            v=vv;
        }
    }
    return min(ans,min(mi[u][0],mi[v][0]));
}
void inp()
{
    cin>>n>> m ;
    for(ll i =1 ;i<=n;i++) pa[i] = i ;
    for(ll i =1 ;i<=n;i++)
    {
        for(ll j =0 ;j<=30;j++)
        {
            mi[i][j] =INF ;
        }
    }
    for(ll i =1 ;i<=m;i++)
    {
        ll u , v ,w;
        cin>>u>>v>> w;
        q[i] ={u,v,w} ;
    }
    sort(q+1,q+m+1);
    for(ll i =1 ;i<=m;i++)
    {
        ll u = q[i].u ;
        ll v =q[i].v ;
        ll w= q[i].w;
        ll chau =goc(u) ;
        ll chav=goc(v) ;
        if(chau==chav)
        {
            s.push_back(q[i]);
            continue ;
        }
        pa[chau] =chav ;
        g[u].pb({v,w}) ; g[v].
        pb({u,w});
    }
    dfs(1,0);
    for(ll j =1 ;j<=30;j++)
    {
        for(ll i = 1;i<=n;i++)
        {
            p[i][j] = p[p[i][j-1]][j-1] ;
            mi[i][j] = min(mi[i][j-1],mi[p[i][j-1]][j-1]);
        }
    }
    ll res= 0 ;
    for(ll i =0 ;i<s.size();i++)
    {
        ll u = s[i].u ;
        ll v = s[i].v ;
        ll w= s[i].w ;
        res+=lca(u,v)-w;
//        cout<<lca(u,v)<<endl;
//        cout<<u<<" " <<v<<endl ;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
