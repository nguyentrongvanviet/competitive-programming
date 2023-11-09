#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
const ll N =1e5+5 ;
const ll LO=22;
#define TASK "LCA"
int n ,q;
int lo =15;
struct ke
{
    int  v ;
    ll ts;
};
vector<ke>g[N];
int h[N];
int pa[N][LO] ;
ll dis[N][LO];
void dfs(int u , int p)
{
    for(ll i =0;i<g[u].size();i++)
    {
        int  v = g[u][i].v ;
        ll ts= g[u][i].ts;
        if(v==p) continue ;
        h[v]=h[u]+1;
        dis[v][0]=ts;
        pa[v][0] =u;
        dfs(v,u) ;
    }
}
ll get(int u , int v)
{
    if(h[u]>h[v]) swap(u,v) ;
    int kc = h[v]-h[u];
    ll res= 0 ;
    for(ll i = 0; i<=lo;i++)
    {
        if(kc>>i&1)
        {
            res+=dis[v][i];
            v=pa[v][i] ;
        }
    }
    if(u==v) return res ;
    for(ll i=lo;i>=0;i--)
    {
        if(pa[u][i]!=pa[v][i])
        {
            res+=(dis[u][i]+dis[v][i]);
            u=pa[u][i];
            v=pa[v][i] ;
        }
    }
    res+=(dis[u][0]+dis[v][0]);
    return res;
}
void solve()
{
    for(int i= 1;i<=n;i++)
    {
        g[i].clear() ;
    }
    for(int i =1;i<=n-1;i++)
    {
        int  u  ; 
        ll  ts;
        cin>>u>>ts;
        ++u;
        g[i+1].pb({u,ts})  ;
        g[u].pb({i+1,ts}) ;
    }
    dfs(1,0) ;
    for(int i =1;i<=lo;i++)
    {
        for(int j =1;j<=n;j++)
        {
            pa[j][i]=pa[pa[j][i-1]][i-1] ;
            dis[j][i]=dis[j][i-1]+dis[pa[j][i-1]][i-1] ;
        }
    }
    cin>>q;
    while(q--)
    {
        int u , v ;
        cin>> u>> v;
        ++u; 
        ++v; 
        cout<<get(u,v)<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin)  ; 
        freopen(TASK".OUT","w",stdout);
    }
    while(cin>>n)
    {
        if(n==0) return 0  ;
        lo = log2(n) ;
        solve() ;
    }
    return 0  ;
}