#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
struct ke 
{
    int v; 
    int w ; 
};
struct bg 
{
    int u ;
    ll val ; 
};
struct cmp
{
    bool operator()(bg a ,bg b )
    {
        return a.val>b.val;  
    }
};
int n , m;
vector<ke>g[N]; 
int pa[N][30] ;
ll kc[N][30]; 
ll f[50][N]; 
int dd[N], h[N];
vector<int>spec ; 
void dfs(int u , int p )
{
    dd[u]  =1 ; 
    for(int i = 0;i<g[u].size();i++)
    {
        int v = g[u][i].v;
        int w = g[u][i].w;   
        if(v==p)continue; 
        if(dd[v])
        {
            spec.pb(u) ; 
            spec.pb(v) ; 
            continue ; 
        }
        h[v]=h[u]+1; 
        kc[v][0] = w; 
        pa[v][0] = u;  
        dfs(v,u) ; 
    }
}
void dij(int u , int id )
{
    for(int i= 1;i<=n;i++)
    {
        f[id][i] = inf ; 
        dd[i]  =0 ; 
    }
    f[id][u] = 0 ; 
    priority_queue<bg,vector<bg>,cmp>q; 
    q.push({u,0});  
    while(!q.empty())
    {
        int u =q.top().u ; 
        q.pop();  
        if(dd[u])continue;
        dd[u]=1; 
        for(int i =0;i<g[u].size();i++)
        {
            int v = g[u][i].v ;
            int w=g[u][i].w; 
            if(dd[v])continue ; 
            if(f[id][v]>f[id][u]+w)
            {
                f[id][v]=f[id][u]+w;
                q.push({v,f[id][v]}); 
            } 
        }  
    }
}
ll lca(int u ,int v )
{
    ll ans= 0 ; 
    if(h[u]>h[v])
    {
        swap(u,v) ; 
    }
    int dis=h[v]-h[u];
    for(int i = 0;i<=20;i++)
    {
        if(dis>>i&1)
        {
            ans+=kc[v][i];
            v= pa[v][i];
        }
    }  
    if(u==v)return ans;  
    for(int i = 20;i>=0;i--)
    {
        int nu = pa[u][i] ; 
        int nv= pa[v][i] ; 
        if(nu!=nv)
        {
            ans+=kc[u][i]+kc[v][i]; 
            u=nu ; 
            v=nv;
        }
    }
    return ans+kc[u][0]+kc[v][0]; 
}

void inp()
{
    cin>> n >> m ; 
    for(int i =1;i<=m;i++)
    {
        int u , v , w ; 
        cin>>u>>v>>w;  
        g[u].pb({v,w});
        g[v].pb({u,w}) ; 
    }

    dfs(1,0) ;
    for(int j= 1;j<=20;j++)
    {
        for(int  i =1;i<=n;i++)
        {
            pa[i][j] = pa[pa[i][j-1]][j-1] ; 
            kc[i][j] = kc[i][j-1]+kc[pa[i][j-1]][j-1]; 
        }
    }   
    sort(spec.begin(),spec.end()) ; 
    spec.erase(unique(spec.begin(),spec.end()),spec.end());
    for(int i= 0;i<spec.size();i++)
    {
        dij(spec[i],i); 
    }
    int q;  
    cin>> q;
    while(q--)
    {
        int u , v ; 
        cin>>u>>v ; 
        ll ans = lca(u,v) ; 
        for(int i = 0;i<spec.size();i++)
        {
            ans=min(ans,f[i][u]+f[i][v]) ; 
        }
        cout<<ans<<"\n";  
    } 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}