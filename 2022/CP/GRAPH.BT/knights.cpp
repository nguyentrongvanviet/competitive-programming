#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct edge
{
    ll u , v , w ;
    bool operator<(edge a )
    {
        return w<a.w ;
    }
};
struct ke
{
    ll v , w ;
};

ll n , m;
vector<ke>g[N] ;
vector<edge>q;
ll h[N];
ll pa[N] ;
ll ma[N][50] ;
ll p[N][50];
ll goc(ll u )
{
    return (pa[u]==u? u: pa[u]=goc(pa[u]));
}
void dfs(ll u , ll cha )
{
    for(ll i =  0 ;i<g[u].size();i++)
    {
        ll v =g[u][i].v ;
        ll w =g[u][i].w ;
        if(v==cha)continue ;
        h[v] =h[u]+1;
        p[v][0] =u;
        ma[v][0]=w;
        dfs(v,u);
    }
}
ll lca(ll u , ll v )
{
    ll ans = 0 ;
    if(h[u]>h[v])
    {
        swap(u,v);
    }
    ll dis = h[v]-h[u];
    for(ll i= 0  ;i<=30;i++)
    {
        if(dis&(1<<i))
        {
            ans =max(ans,ma[v][i]);
            v=p[v][i];
        }
    }
    if(u==v) return ans ;
    for(ll i=30;i>=0;i--)
    {
        if(p[u][i]!=p[v][i])
        {
            ans= max(ans ,max(ma[u][i],ma[v][i]));
            u=p[u][i];
            v=p[v][i];
        }
    }
    return max(ans,max(ma[u][0],ma[v][0]));
}
void inp()
{
    cin>> n>> m ;
    for(ll i =1 ;i<=m;i++)
    {
        ll u , v , w;
        cin>>u>>v>>w ;
        q.pb ({u,v,w});
    }
    sort(q.begin(),q.end());
    for(ll i =1 ;i<=n;i++)pa[i] = i ;
    for(ll i= 0;i<m;i++)
    {
        ll w =q[i].w ;
        ll u  =q[i].u ;
        ll v = q[i].v;
        ll chau= goc(u) ;
        ll chav= goc(v) ;
        if(chau==chav)continue;
        pa[chav] = chau ;
        g[u].pb({v,w}) ;
        g[v].pb({u,w});
    }
    dfs(1,0);
    for(ll i=1 ;i<=30;i++)
    {
        for(ll j =1;j<=n;j++)
        {
            p[j][i] = p[p[j][i-1]][i-1] ;
            ma[j][i]=max(ma[j][i-1],ma[p[j][i-1]][i-1]);
        }
    }
    ll q;
    cin>> q;
    while(q--)
    {
        ll u , v ;
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    inp() ;
}
