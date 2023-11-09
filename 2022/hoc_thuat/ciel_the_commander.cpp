#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n   ; 
vector<int>g[N] ; 
int pa[N] , sz[N] , dd[N] ; 
int res[N] ; 
void dfs(int u  , int  p)
{
    sz[u]=1; 
    for(auto v : g[u])
    {
        if(dd[u]||v==p)continue ;
        dfs(v,u) ; 
        sz[u]+=sz[v] ;
    }
}
int centroid(int u , int p , int  n )
{
    for(auto  v :g[u])
    {
        if(dd[v]||v==p)continue ;
        if(sz[v]>n/2)return centroid(v,u,n); 
    }
    return u ;
}
void solve(int u , int p )
{
    dd[u]=1 ;
    res[u] = res[p]+1;  
    for(auto v : g[u])
    {
        if(v==p||dd[v])continue ;
        dfs(v,u) ;  
        solve(centroid(v,u,sz[v]),u);
    }
}
bool check()
{
    for(int i = 1; i<=n;i++)
    {
        if(res[i]>26)return false; 
    }
    return true; 
}
void inp()
{
    cin>> n ;  
    for(int i= 1; i<=n-1;i++)
    {
        int u , v ;
        cin>>u>>v;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    dfs(1,0 ); 
    solve(centroid(1,0,n),0);
    if(check())
    {
        for(int i= 1 ;i<=n;i++)
        {
            cout<<char(res[i]+'A'-1)<<" "   ;
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
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