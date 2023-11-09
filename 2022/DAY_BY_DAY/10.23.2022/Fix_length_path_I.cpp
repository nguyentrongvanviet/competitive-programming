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
#define TASK "Fix_length_path_I"
int n , k ; 
int dd[N] ;
vector<int>g[N] ; 
int sz[N] ; 
ll res = 0; 
vector<int>high;
void dfs(int u , int p)
{
    sz[u] =1; 
    for(int v : g[u])
    {
        if(dd[v]||v==p)continue ;
        dfs(v,u) ; 
        sz[u]+=sz[v] ;
    }
}
int centroid(int u , int p  ,int  n )
{
    for(int v : g[u])
    {
        if(v==p||dd[v])continue ; 
        if(sz[v]>n/2)return centroid(v,u,n) ; 
    }
    return u ; 
}
void dfs2(int u , int p,int dis )
{
    high.pb(dis);
    for(int v  : g[u])
    {
        if(dd[v]||v==p)continue;
        dfs2(v,u,dis+1); 
    }
}
void solve(int u , int p )
{
    dd[u] =1 ; 
    vector<int>a(sz[u]+1,0);
    a[0]=1;
    for(int v : g[u])
    {
        high.clear() ; 
        if(dd[v]==1)continue ; 
        dfs2(v,u,1) ; 
        for(int it :  high)
        {
            if(0<=k-it&&k-it<=sz[u])
            { 
                res+=a[k-it] ; 
            }
        }
        for(int it: high)
        {
            a[it]++;
        }
    }
    for(int  v : g[u])
    {
        if(dd[v])continue ; 
        dfs(v,u);
        solve(centroid(v,u,sz[v]),u) ; 
    }
 
}
void inp()
{
    cin>>n>> k;  
    for(int i =1 ;i<=n-1;i++)
    {
        int u  , v ; 
        cin>>u>>v; 
        g[u].pb(v) ;
        g[v].pb(u); 
    }
    dfs(1,0) ; 
    solve(centroid(1,0,n),0); 
    cout<<res ; 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    inp();
    return 0;
}