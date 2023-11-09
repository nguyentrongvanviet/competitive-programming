#include<bits/stdc++.h>
using namespace std;

#define TASK "text"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first    
#define se second  
const int N =5e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m , s , t;  
int dd[N][N];
ll c[N][N] ; 
vector<int>g[N] ; 
int vis[N]  , pa[N] ; 
bool bfs(int s,int t  )
{
    memset(vis,0,sizeof(vis)) ; 
    queue<int>q; 
    q.push(s) ; 
    vis[s] =1 ; 
    while(!q.empty()) 
    {
        int u =q.front()  ; 
        q.pop() ; 
        FOR(i,0,(int)g[u].size()-1)
        {
            int v = g[u][i] ; 
            if(!vis[v]&&c[u][v]>0)
            {
                pa[v] = u ; 
                vis[v] =  1; 
                q.push(v) ; 
                if(v==t)
                {
                    return 1  ; 
                }  
            }
        }
    }
    return 0 ; 
}
ll Max_flow(int s , int t  )
{
    ll ans= 0 ; 
    while(bfs(s,t))
    {
        ll mi = inf ;
        for(int v =t ;v!=s;v=pa[v])
        {
            int u = pa[v] ; 
            mi = min(mi,c[u][v]);  
        }
        ans+=mi; 
        for(int v=t;v!=s;v=pa[v])
        {
            int u=  pa[v] ;
            c[u][v]-=mi; 
            c[v][u]+=mi ;       
        }
    }
    return ans; 
}
void doc()
{
 	cin>> n>> m ; 
 	FOR(i,1,m)
 	{
 		int u ,v  ;ll w ; 
 		cin>>u>>v>>w;  
        g[u].pb(v); 
        g[v].pb(u);
        c[u][v]=w;     
 	}   
    s = 1 ;
    t = n ; 
    ll res = Max_flow(s,t) ;
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
    }
    return 0;
}