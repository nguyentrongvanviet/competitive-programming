#include<bits/stdc++.h>
using namespace std;

#define TASK "policechase"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N = 5e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,m; 
int c[N][N];
vector<int>g[N];
int pa[N] ;
int dd[N] ;
int res=0 ; 

void doc()
{
    cin>>n>>m;  
    FOR(i,1,m)
    {
    	int u ,v ; cin>>u>>v;  
    	g[u].pb(v) ;
        g[v].pb(u) ; 
    	c[u][v] =1 ; 
        c[v][u] =1 ; 
    }
}	
bool bfs(int s , int t )
{
    FOR(i,1,n)dd[i] = 0 ;
    queue<int>q; 
    dd[s]=1 ; 
    q.push(s) ; 
    while(!q.empty())
    {
        int u = q.front();  
        q.pop();
        for(auto v : g[u])
        {
            if(dd[v]||c[u][v]==0)continue ; 
            pa[v] =u ; 
            dd[v] =1 ;  
            q.push(v) ;
            if(v==t)return 1 ; 
        }
    }
    return 0 ;
}
int max_flow(int s , int t )
{
    int res= 0 ;
    while(bfs(s,t))
    {
        int mi = oo ; 
        for(int v=t;v!=s;v=pa[v])
        {
            int u = pa[v] ;
            mi = min(mi,c[u][v]);
        }
        res+=mi ; 
        for(int v = t;v!=s;v=pa[v])
        {
            int u= pa[v] ; 
            c[u][v]-=mi;
            c[v][u]+=mi;
        }
    }
    return res;     
}
void dfs(int u )
{
    dd[u]=1 ;
    for(auto v :g[u])
    {
        if(dd[v]==0&&c[u][v])dfs(v);
    }
}
void xuly()
{
    cout<<max_flow(1,n)<<"\n";
    FOR(i,1,n)dd[i] = 0 ; 
    dfs(1);       
    FOR(i,1,n)
    {
        if(dd[i]==0)continue;
        for(auto v : g[i])
        {
            if(dd[v]==0)
            {
                cout<<i<<" "<<v<<"\n";
            }
        }
    }
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}