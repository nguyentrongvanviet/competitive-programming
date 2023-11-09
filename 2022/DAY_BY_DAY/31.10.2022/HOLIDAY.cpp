
#include<bits/stdc++.h>
using namespace std;

#define TASK "HOLIDAY"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e6+5 ,  oo = INT_MAX , LO = 20 ; 
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
struct ke 
{
	int v ; 
	ll w ; 
}; 
int n, q ,   pa[N][LO]  , k , ma=0 , lo , h[N] ;  
ll  c[N][LO];
vector<ke>g[N] ;     
void doc()
{
    cin>> n>>q ; 
    for(int i= 1;i<=n-1;i++)
    {
    	int u , v ; 
    	ll c ; 
    	cin>>u>>v>> c; 
    	++c;
    	g[u].pb({v,c}) ; 
    	g[v].pb({u,c}) ; 
    }
}
void predfs(int u , int p )
{
	for(int i= 0;i<g[u].size();i++)
	{
		int v = g[u][i].v;  
		ll w= g[u][i].w ; 
		if(v==p)continue ; 
		pa[v][0]=u;
		c[v][0]=w; 
		h[v]=h[u]+1;
		ma=max(ma,h[v]);
		predfs(v,u);
	}
}
ll lca(int u , int v )
{
	if(h[u]<h[v])swap(u,v) ; 
	int dis= h[u]-h[v] ; 
	ll ans= 0 ;
	for(int i= 0 ;i<=lo;i++)
	{
		if(dis>>i&1)
		{
			ans+=c[u][i] ;  
			u= pa[u][i] ; 
		}
	}
	if(u==v)return ans ; 
	for(int i = lo;i>=0;i--)
	{
		int nu = pa[u][i] ; 
		int nv = pa[v][i] ; 
		if(nu==nv)continue ;
		ans+=c[u][i] ;
		ans+=c[v][i] ; 
		u=nu ; 
		v=nv ; 
	}
	return ans+c[u][0]+c[v][0];
}
void xuly()
{
	h[1]=1 ; 
	predfs(1,0) ; 
	lo = log2(ma);  
	for(int j= 1 ;j<=lo;j++)
	{
		for(int i=  1 ;i<=n;i++)
		{
			pa[i][j]= pa[pa[i][j-1]][j-1] ; 
			c[i][j] = c[i][j-1]+c[pa[i][j-1]][j-1] ;
		}
	}
	while(q--)
	{
		cin>> k ; 
		vector<int>node; 
		for(int i= 1 ;i<=k;i++)
		{
			int u ;
			cin>> u ; 
			node.pb(u) ; 
		}
		ll dis= 0 ;
		int st =  0 ; 
		for(int i= 1  ;i<node.size();i++)
		{	
			ll ndis = lca(node[0],node[i]); 
			if(dis<ndis)
			{
				dis= ndis;
				st=node[i]  ;  
			}
		}	
		ll res=0 ; 
		for(int i=0 ;i<node.size();i++)
		{	
			res=max(res,lca(st,node[i]));
		}
		cout<<res<<"\n";
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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
        xuly();
    }
    return 0;
}