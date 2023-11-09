#include<bits/stdc++.h>
using namespace std;

#define TASK "A"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
const int LO = 20 ; 

struct Q
{
	int u ,v, c; 
}; 
int n , q; 
int h[N]  , f[N] ; 
Q query[N] ; 
int pa[N][LO];
vector<int>g[N]; 
void doc()
{
 	cin>> n >>q ;
 	FOR(i,1,n-1)
 	{
 		int u ,v ; 
 		cin>>u>>v ; 
 		g[u].pb(v) ; 
 		g[v].pb(u) ; 
 	}   
 	FOR(i,1,q)
 	{
 		cin>>query[i].u>>query[i].v>>query[i].c; 
 	}
}
void dfs(int u , int p)
{ 
	for(int i =0 ; i<g[u].size();i++)
	{
		int v= g[u][i] ;
		if(v==p)continue ; 
		f[u] = max(f[u],f[v]+1); 
		h[v] = h[u]+1; 
		pa[v][0]= u ;
		dfs(v,u) ; 
	}
}
pii lca(int u , int v )
{
	int c= 0  ; 
	if(h[u]<h[v])swap(u,v) ; 
	int dis= h[u]-h[v] ; 
	FOR(i,0,19)
	{
		if(dis>>i&1)
		{
			c+=(1<<i) ; 
			u=pa[u][i] ; 
		}
	}
	if(u==v)return {u,c} ; 
	FORD(i,19,0)
	{
		int nu = pa[u][i] ; 
		int nv = pa[v][i] ; 
		if(nu!=nv)
		{
			c+=2*(1<<i);
			u =nu ; 
			v=nv;  
		}
	}
	c+=2; 
	return {pa[u][0],c} ; 
}
void xuly()
{
	dfs(1,0) ; 
	FOR(j,1,LO-1)
	{
		FOR(i,1,n)
		{
			pa[i][j] = pa[pa[i][j-1]][j-1] ; 
		}
	}
	FOR(i,1,q)
	{
		int u= query[i].u ; 
		int v= query[i].v ;
		if(h[u]<h[v])swap(u,v) ;  
		int c= query[i].c ; 
		auto x = lca(u,v) ;
		auto y = lca(u,c) ;
		auto z =lca(v,c) ;
		if(y.se+z.se==x.se)
		{
			cout<<"YES"<<"\n";
			continue ;
		}
		else
		{
			if(y.se+x.se==z.se&&f[c]+y.se==f[u])
			{
				cout<<"YES"<<"\n";
				continue ;
			}
			else if(z.se+x.se==y.se&&f[c]+z.se==f[v])
			{		
				cout<<"YES"<<"\n";
				continue ;
			}
		}
		if(x.fi==v&&z.fi==c)
		{
			if(f[u]+y.se==f[c])
			{
				cout<<"YES"<<"\n";
				continue ;
			}
		}
		cout<<"NO"<<"\n";
		// ko thuoc 

	}
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
        xuly();
    }
}