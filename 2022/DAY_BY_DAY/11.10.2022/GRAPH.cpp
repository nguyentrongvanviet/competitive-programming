#include<bits/stdc++.h>
using namespace std;

#define TASK "GRAPH"
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
const int N =5e5+5 ,  oo = 1e7 ; 
const ll sm = 1e8+7,cs=330 ,inf = 1e17 ;int n , m ; 
int dd[N] ; 
vector<int>g[N] ; 
vector<int>adj[N] ;
int f[2][N] ; 
int res= oo ; 
void bfs(int s  ,int id )
{
	for(int i= 1;i<=n;i++)dd[i] = 0 , f[id][i] =2*oo;
	queue<int>q ;  
	dd[s] = 1 ; 
	f[id][s] = 1 ; 
	q.push(s);
	while(!q.empty())
	{
		int u = q.front() ;
		q.pop(); 
		for(int i = 0 ;i<adj[u].size();i++)
		{
			int v=adj[u][i] ;
			if(dd[v])continue ;
			f[id][v] =f[id][u]+1;  
			dd[v]=1 ; 
			q.push(v);
		}
	}
}

void dfs(int u,int val  )
{
	dd[u] =1 ;
	res=min(res,val+f[0][u]-2) ;
	// cout<<val+f[0][u]-2<<endl;
	for(int i=0  ;i<g[u].size();i++)
	{
		int v= g[u][i] ;
		if(dd[v])continue ; 
		dfs(v,val) ;  
	}
}
int  b[N] ; 
bool cmp(int a , int b )
{
	return f[1][a]<f[1][b];
}
void doc()
{
 	cin>> n>> m; 
 	FOR(i,1,m)
 	{
 		int u ,v ; 
 		cin>>u>>v ; 
 		g[u].pb(v)  ; 
 		adj[u].pb(v) ; 
 		adj[v].pb(u) ; 
 	}   
 	bfs(1,1) ; 
 	bfs(n,0) ;
 	FOR(i,1,n)
 	{	
 		b[i] = i ; 
 	}
 	sort(b+1,b+n+1,cmp) ; 
 	for(int i= 1;i<=n;i++)dd[i]  = 0 ;
 	FOR(i,1,n)
 	{
 		if(dd[b[i]])continue;
 		dfs(b[i],f[1][b[i]]);
 	}
 	if(res==oo)
 	{
 		cout<< -1  ;
 	}
 	else
 	{
 		cout<<res;
    }
}

main()
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