#include<bits/stdc++.h>
using namespace std;

#define TASK "QGRAPH"

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
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 
const int LO =20 ; 
struct ke 
{
	int v;  
	ll w ; 
};
struct DL 
{
	int c; 
	ll val;  
	int dinh  ; 
	DL(){};
	DL(int _c , ll _val,int _dinh)
	{
		c = _c ; 
		dinh =_dinh ;
		val=_val ;
	}
};
int n  ,q ; 
vector<ke>g[N] ;
int h[N] ; 
int pa[N][LO] ;
ll  W[N][LO] ; 
void dfs(int u , int p)
{
	for(auto x : g[u])
	{
		int v=  x.v; 
		ll w= x.w; 
		if(v==p)continue ;
		h[v]=h[u]+1; 
		pa[v][0 ] =u ; 
		W[v][0] = w ; 
		dfs(v,u);
	}
}
DL lca(int u ,int v)
{
	ll ans =0  ;
	int dinh= 0 ; 
	if(h[u]<h[v])swap(u,v) ; 
	int dis= h[u]-h[v] ; 
	FOR(i,0,LO-1)
	{
		if(dis>>i&1)
		{
			dinh+=(1<<i);
			ans+=W[u][i] ; 
			u=pa[u][i] ; 	
		}
	}
	if(u==v)
	{
		return DL{u,ans,dinh}; 
	}
	FORD(i,LO-1,0)
	{
		int nu = pa[u][i] ;
		int nv = pa[v][i] ; 
		if(nu==nv)continue ; 
		ans =W[u][i] +W[v][i] ; 
		u=nu;
		v=nv; 
	}
	return DL{pa[u][0],ans+W[u][0]+W[v][0],dinh+2}; 
}
void doc()
{
 	cin>> n >>q ; 
 	FOR(i,1,n-1)
 	{
 		int u , v, w ;
 		cin>>u>>v>>w; 
 		g[u].pb({v,w}) ; 
 		g[v].pb({u,w}) ; 
 	}
 	dfs(1,0) ; 
 	FOR(j,1,LO-1)
 	{
 		FOR(i,1,n)
 		{
 			pa[i][j] = pa[pa[i][j-1]][j-1];  
 			W[i][j] = W[i][j-1] + W[pa[i][j-1]][j-1] ; 
 		}
 	}
 	auto goup =[&](int u ,int dis)
 	{
 		FOR(i,0,LO-1)
 		{
 			if(dis>>i&1)
 			{
 				u=pa[u][i] ; 
 			}
 		}
 		return u ;
 	};
 	while(q--)
 	{
 		int t;  cin>>t ; 
 		if(t==1)
 		{
 			int u ,v ; 
 			cin>>u>>v; 
 			DL tmp = lca(u,v) ; 
 			cout<<tmp.val<<"\n";
 		}
 		else 
 		{
 			int u ,v , k  ; 
 			cin>>u>>v>>k ; 
 			DL tmp =lca(u,v); 
 			int c= tmp.c;  
 			int sodinh = tmp.dinh ;
 			if(h[u]-h[c]+1>=k)
 			{
 				cout<<goup(u,k)<<"\n";
 			}
 			else 
 			{
 				int x = k-(h[u]-h[c]+1);
 				// cout<<x<<endl;/
 				x= h[v]-h[c]-x;
 				cout<<goup(v,x)<<"\n";
 			}
 		}
 	}
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}