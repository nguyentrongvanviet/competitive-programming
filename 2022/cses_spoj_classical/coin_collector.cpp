#include<bits/stdc++.h>
using namespace std;

#define TASK "coin_collector"

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
const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n , m ; 
ll a[N] , f[N] , p[N] ; 
vector<int>g[N] ; 
vector<int>adj[N] ;
int low[N] , id[N] ; 
int tp[N]  , dd[N] ;
int tt= 0 , tplt = 0 ;
stack<int>st ;

void doc()
{
	cin>> n>> m; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)
	{
		int u , v; 
		cin>>u>>v ; 
		g[u].pb(v) ;
	}
}
void dfs(int u )
{	
	low[u] = id[u] =++tt; 
	st.push(u);
	for(auto v : g[u])
	{
		if(tp[v])continue ; 
		if(id[v])
		{
			low[u] = min (low[u],id[v]) ; 
		}
		else 
		{
			dfs(v) ; 
			low[u] = min(low[u],low[v]) ; 
		}
	}
	if(low[u]==id[u])
	{
		int t;
		++tplt ; 
		do
		{
			t=st.top() ; 
			st.pop() ; 
			tp[t]=tplt; 
			p[tplt]+=a[t] ;
		}while(t!=u); 
	}
}
void dfs2(int u )
{
	if(dd[u])return ; 
	dd[u] =1 ;
	f[u] = p[u];
	for(auto v : adj[u])
	{
		if(!dd[v])dfs2(v) ; 
		f[u]=max(f[u],p[u]+f[v]) ; 
	}
}
void xuly()
{
	FOR(i,1,n)if(!tp[i])dfs(i) ;
	FOR(u,1,n)
	{
		for(auto v: g[u])
		{
			if(tp[u]!=tp[v])adj[tp[u]].pb(tp[v]); 
		}
	}
	ll res=0  ;
	FOR(i,1,n)
	{
		dfs2(i) ;
		res=max(res,f[i]) ; 
	}
	cout<<res;
}
int main()
{	
    IOS(); 
    doc() ;
  	xuly();
}