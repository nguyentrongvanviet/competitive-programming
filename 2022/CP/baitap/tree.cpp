#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 2e5+5 ,oo = 1e9 ; 
const ll inf = 1e17 , sm =1e9+7 ; 

struct ke 
{
	ll v  ; 
	ll w ; 
};	
ll n ; 
ll sz[N] ; 
ll f[N] ;  
ll d[N] ; 
vector<ke>g[N] ; 
void predfs(int u , int p )
{
	sz[u]= 1;  
	for(int i=0;i<g[u].size();i++)
	{
		ll v= g[u][i].v ; 
		ll w =g[u][i].w; 
		if(v==p)continue ; 
		predfs(v,u) ; 
		sz[u] +=sz[v]; 
		d[u]+=d[v]+w*sz[v]; 
	}	
}
void dfs1(int u , int p )
{
	for(int i =0;i<g[u].size();i++)
	{
		int v= g[u][i].v ; 
		ll w= g[u][i].w ; 
		if(v==p)continue ; 
		f[v]=f[u]-2*sz[v]*w+w*n;
		dfs1(v,u);
	}
}
void inp()
{
	cin>> n ;  
	for(int i= 1;i<=n-1;i++)
	{
		ll u , v , w;  
		cin>>u>>v>>w; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w}) ; 
	}
	predfs(1,0) ;
	f[1]=d[1];   	
	dfs1(1,0); 
	for(int i=1 ;i<=n;i++)
	{
		cout<<f[i]<<"\n";
		sz[i] = 0 ; 
		d[i] = 0 ;  
		g[i].clear(); 
	}
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	int test ;
	cin>>test; 
	while(test--){
		inp() ;
	}
}
