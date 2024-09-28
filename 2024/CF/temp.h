const int N = 4e5+5 ;
const int LO = 20 ; 
int n , m ;
struct Edge
{
    int u ,v ,w ; 
    bool operator<(const Edge&a)const
    {
        return w<a.w ; 
    }
}E[N] ;

void build();
void init(int N, int M, vector<int>u, vector<int>v, vector<int>w)
{
    n=N ;
    m=M ;
    for(int i=0;i<m;i++)
    {
        ++u[i] ; 
        ++v[i] ; 
        E[i+1]={u[i],v[i],w[i]} ;
    }
    build() ; 
}
int pa[N] , deg[N] , ok[N] ;
vector<int>g[N] ;
int h[N] ; 
int P[N][LO+2] ;
int res[N] ; 
int goc(int u )
{
    return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
}
void hop(int u ,int v ,int w)
{
    int chau = goc(u) ; 
    int chav = goc(v) ; 
    ++n;
    res[n] = w ;  
    pa[n]=n; 
    ok[n]=max(ok[chau],ok[chav]) ; 
    pa[chau] = pa[chav] = n ; 
    g[n].push_back(chau) ; 
    if(chau==chav)
    {
        ok[n] = 1 ; 
    }
    else
    {
        g[n].push_back(chav) ; 
    }
    deg[u]++ ;
    deg[v]++ ;
    if(deg[u]==3||deg[v]==3)
    {
        ok[n] = 1  ;
    }
}
void dfs(int u)
{
    for(auto v:g[u])
    {
        h[v] = h[u]+1 ; 
        dfs(v) ; 
        P[v][0] = u ; 
        for(int i=1;i<=LO;i++)P[v][i] = P[P[v][i-1]][i-1] ; 
    }
}
void build()
{
    sort(E+1,E+m+1) ;
    for(int i=1;i<=n;i++)pa[i] = i  ;   
    for(int i=1;i<=m;i++)
    {
        hop(E[i].u,E[i].v,E[i].w) ; 
    }
    dfs(n) ;
}
int getMinimumFuelCapacity(int u ,int v)
{ 
    if(ok[n]==0)return -1 ; 
    int ans = -1 ;  
    if(h[u]<h[v])swap(u,v) ; 
    for(int i=LO;i>=0;i--)
    {
        if(h[u]-(1<<i)>=h[v])
        {
            u=P[u][i] ; 
        }
    }
    for(int i=LO;i>=0;i--)
    {
        int nu  = P[u][i] ; 
        int nv  = P[v][i] ; 
        if(nu!=nv)
        {
            u=nu ;
            v=nv;  
        }
    }
    if(u!=v)
    {
        u=P[u][0] ; 
    }
    if(ok[u])
    {
        return res[u] ; 
    }
    for(int i=LO;i>=0;i--)
    {
        if(P[u][i]&&ok[P[u][i]]==0)
        {
            u=P[u][i] ; 
        }
    }
    return res[P[u][0]] ; 
}
