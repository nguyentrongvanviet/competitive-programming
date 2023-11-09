#include<bits/stdc++.h>
using namespace std;

#define TASK "p9alphatour"

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
#define int long long   
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ;
int sz[N] ; 
int dd[N] ;
vector<int>g[N] ;
void predfs(int u , int p )
{
	sz[u]=1 ; 
	for(auto v : g[u])
	{
		if(dd[v]||v==p)continue ; 
		predfs(v,u) ; 
		sz[u]+=sz[v] ;
	}
}
int centroid(int u , int p,int n )
{
	for(auto v: g[u])
	{
		if(v==p||dd[v])continue ;
		if(sz[v]>=n/2)
		{
			return centroid(v,u,n);
		} 
	}
	return u ;
}
int res= 0 ; 
int tmp = 0 ;
void dfs(int u , int p, int val )
{		
	tmp=max(tmp,val);
	for(auto v : g[u])
	{
		if(v==p||dd[v])continue ; 
		dfs(v,u,val+a[v]); 
	}
}
void solve(int u  ,int p )
{
	dd[u] =1 ;
	res=max(res,a[u]);  
	int ma= 0 ; 
	for(auto v : g[u])
	{
		if(v==p||dd[v])continue;
		tmp =0;
		dfs(v,u,a[v]);  
		res=max(res,a[u]+tmp+ma);
		// cout<<u<<" "<<tmp<<" "<<ma<<endl;
		ma=max(ma,tmp);
	}
	// cout<<u<<" "<<res<<endl;
	for(auto v : g[u])
	{
		if(v==p||dd[v])continue ; 
		predfs(v,u) ; 
		solve(centroid(v,u,sz[v]),u);
	}
}		
void doc()
{
    cin>> n ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v ; 
    	cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
   	predfs(1,0); 
   	solve(centroid(1,0,n),0);
   	cout<<res;
}
void xuly()
{
    
}
signed main()
{
    IOS();  
    doc(); 
    xuly();
}