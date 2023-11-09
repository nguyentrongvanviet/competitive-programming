#include<bits/stdc++.h>
using namespace std;

#define TASK "CEDEDGES"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct ke 
{
    int v ;  
    ll w; 
}; 
struct E
{
    int u , v  ; 
    ll w , c  ; 
};  
struct bg
{
    int u ; 
    ll val ; 
};
struct cmp
{
    bool operator ()(bg a, bg b)
    {
        return a.val>b.val;
    }
};
int n  , m ;

vector<ke>g[N]; 
E edge[N*100] ; 
int pa[N] ; 
ll ca[N][N] ,f[N][N];
ll f1[N] , fn[N];
void doc()
{
    cin>>n>> m; 
    FOR(i,1,m)
    {
        int u ,v  ; ll c, w ; 
        cin>>u>>v>>w>>c ;
        g[u].pb({v,w}); 
        g[v].pb({u,w});
        edge[i]  ={u,v,w,c}; 
    }
}   
void dij(int s , ll f[])
{
    vector<int>dd(n+1,0) ;    
    priority_queue<bg,vector<bg>,cmp>q; 
    FOR(i,1,n)f[i] = inf ,dd[i] = 0 ;
    f[s]= 0 ;  
    q.push({s,0});
    while(!q.empty())
    {
        int u=  q.top().u ;
        q.pop();
        if(dd[u])continue; 
        dd[u] = 1  ; 
        for(auto it : g[u])
        {
            int v = it.v ; 
            ll w = it.w ;
            if(dd[v])continue;  
            if(f[v]>f[u]+w)q.push({v,f[v]=f[u]+w});
        }
    }
}
bool BFS(int s ,int t )
{
    queue<int> q; 
    vector<int>dd(n+1,0);
    dd[s] = 1; 
    q.push(s) ; 
    while(!q.empty())
    {
        int u = q.front();  
        q.pop();
        for(int i= 0 ;i<g[u].size();i++)
        {
            int v = g[u][i].v;  
            if(dd[v])continue ;
            if(ca[u][v]-f[u][v]<=0)continue; 
            dd[v] = 1  ;
            pa[v] = u ; 
            q.push(v);
            if(v==t)return 1;
        }
    }
    return 0 ; 
}
ll max_flow(int s,  int t )
{
    ll ans =0  ;
    while(BFS(s,t)) 
    {
        // cout<<"X";
        ll mi =inf ; 
        for(int v= t;v!=s;v=pa[v])
        {
            int u= pa[v] ; 
            mi=min(mi,ca[u][v]-f[u][v]) ; 
        }    
        ans+=mi;  
        for(int v= t;v!=s;v=pa[v])
        {
            int u= pa[v] ; 
            f[u][v]+=mi;
            f[v][u]-=mi;
        }
    }
    return ans ;
}
void xuly() 
{
    dij(1,f1); 
    // FOR(i,1,n)cout<<f1[i]<<" ";cout<<"\n";
    dij(n,fn);
    FOR(i,1,n)g[i].clear();
    // FOR(i,1,n)FOR(j,1,n)ca[i][j]=-inf;
    FOR(i,1,m)
    {
        int u=edge[i].u ; 
        int v= edge[i].v;  
        ll c=  edge[i].c; 
        ll w= edge[i].w;  
        if(f1[u]+fn[v]+w==f1[n]||f1[v]+fn[u]+w==f1[n])  
        {
            g[u].pb({v,c}); 
            g[v].pb({u,c});
            ca[u][v] =ca[v][u] = c; 
            // cout<<u<<" "<<v<<endl;
        }
    }
    // cout<<BFS(1,n);
    ll res= max_flow(1,n);
    cout<<res;
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;    
    //cin>>t;
    while(t--)
    {
        doc();
        xuly();
    }
    return 0;
}