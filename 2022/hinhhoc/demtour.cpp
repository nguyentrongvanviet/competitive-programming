#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second 
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int n , m , k ;
int tt =0  ; 
int low[N] , id[N] ; 
vector<int>g[N] ;
vector<int>adj[N] ; 
stack<int>st;
int cnt= 0 ;   
int tp[N];
int sl[N];  
ll res= 0 ; 
int  bit[N] ; 
int dd[N] ,sz[N];
int ma;  

void dfs(int u ,int p  )
{
    low[u]=id[u]=++tt ;
    st.push(u); 
    int t = 0;
    for(int i = 0;i<g[u].size();i++)
    {
        int v  = g[u][i] ; 
        if(v==p&&t==0)
        {
            t++ ; 
            continue ; 
        }
        if(id[v])
        {
            low[u] =min(low[u],id[v]) ; 
        }
        else 
        {
            dfs(v,u) ; 
            low[u]=min(low[u],low[v]) ; 
        }
    }
    if(low[u]==id[u])
    {
        int t ; 
        ++cnt ; 
        do
        {
            t=st.top() ;
            tp[t]=cnt; 
            sl[cnt]++ ;  
            st.pop() ; 
        }while(t!=u) ;       
    }
}
void predfs(int u , int p )
{
    sz[u]= 1; 
    for(auto v :adj[u])
    {
        if(v==p||dd[v])continue  ; 
        predfs(v,u) ; 
        sz[u]+=sz[v]; 
    }
}
int  centroid(int u ,int p ,int n )
{
    for(auto v :adj[u])
    {
        if(v==p||dd[v])continue; 
        if(sz[v]>n/2)
        {
            return centroid(v,u,n) ; 
        }
    }
    return u ;  
}
void up( int x , int val )
{
	for ( int i = x ; i > 0 ; i -= i & -i ) bit[i] += val;
}
int get ( int x )
{
	int ans = 0 ; 
	for ( int i = x ; i <= ma ; i += i & -i ) ans += bit[i];
	return ans;
}
void dfs1(int u , int p , int h )
{
    if(k-h<=ma)
    {
        res+=(ll)sl[u]*get((max(0,k-h))+1) ;      
    }
    for(int v :adj[u])
    {
        if(dd[v]||v==p)continue ; 
        dfs1(v,u,h+1) ;
    }
}
void dfs2(int u , int p ,int h )
{
    up(h+1,sl[u]) ; 
    for(int v :adj[u]) 
    {
        if(dd[v]||v==p)continue ; 
        dfs2(v,u,h+1) ; 
    }
}
void solve(int u)
{
    predfs(u,0) ;
    ma=sz[u]+1; 
    dd[u]=1;  
    up(1,sl[u]);  
    for(int i =0 ;i<adj[u].size();i++ )
    {
        int v= adj[u][i] ; 
        if(dd[v])continue ;
        dfs1(v,u,1); 
        dfs2(v,u,1);
    }
    for(int i=1;i<=ma;i++)
    {
        bit[i] = 0 ;  
    }
    for(int  i= 0 ;i<adj[u].size();i++)
    {
        int v= adj[u][i] ; 
        if(dd[v])continue ;
        solve(centroid(v,u,sz[v]));
    }
}
void inp()
{
    cin>> n >> m>> k; 
    for(int i= 1;i<=m;i++)
    {
        int u , v;  
        cin>>u>> v; 
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }
    dfs(1,0) ; 
    for(int i =1;i<=n;i++)
    {
        for(auto v : g[i])
        {
            if(tp[i]<tp[v])
            {
                adj[tp[v]].pb(tp[i]) ; 
                adj[tp[i]].pb(tp[v]) ; 
            }
        }
    }
    predfs(tp[1],0);
    solve(centroid(tp[1],0,sz[tp[1]]));
    cout<<res; 
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}