#include<bits/stdc++.h>
using namespace std;

#define TASK "icpc22_mn_b"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =1000+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const int M= 100005;

struct E
{
	int u , v , c , id ; 
	bool operator <(const E& a)const
	{
		return c>a.c ;
	}
}; 
struct ke 
{
	int v  , c ; 
}; 
struct Q
{
	int t; 
	int u , v  ;
	int val ; 
};
int n , m ,q ; 
E edge[M]; 
bool dd[M] ; 
vector<E>canh  ,consider; 
vector<E>tmp ; 
vector<ke>g[N] ; 
Q query[M] ;
bool o  ;
int value[M] , pa[N] ;  
int h[N] , p[N][11] , c[N][11]; 
bool fi[N] ;
void doc()
{
	cin>>n>> m>>q; 
	for(int i=1 ;i<=m;i++)
	{
		int u , v  , c; 
		cin>>u>>v>>c; 
		edge[i] = {u,v,c,i};  
		value[i] = c; 
		tmp.pb(edge[i]);
	} 
	FOR(i,1,q)
	{
		char c ; 
		int a , b ; 
		cin>>c>>a>>b ;
		bool t = (c=='C')  ; 
		if(t==0)
		{
			int val ; cin>>val ;
			query[i] ={t,a,b,val};
		}
		else 
		{
			query[i] = {t,a,b,0} ; 
		}
		if(t==1)
		{
			dd[a] =1 ;
		}
	}
}
int goc(int u )
{
	return pa[u]==u? u : pa[u] = goc(pa[u]);
}
int tt   ; 
void dfs(int u , int pa)
{
	fi[u] =1 ; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i].v;  
		int w= g[u][i].c; 
		if(v==pa)continue ;
		p[v][0] = u ; 
		c[v][0] =w;
		h[v]=h[u]+1;
		dfs(v,u);
	}
}
int lca(int u , int v )
{
	if(h[u]<h[v])swap(u,v) ; 
	int dis= h[u]-h[v] ;
	int ans = oo ; 
	for(int i=0 ;i<=9;i++)
	{
		if(dis>>i&1)
		{
			ans= min(ans,c[u][i]);  
			u=p[u][i] ; 
		}
	}
	if(u==v)return ans ; 
	for(int i= 9;i>=0;i--)
	{
		int nu = p[u][i] ; 
		int nv = p[v][i] ; 
		if(nu!=nv)
		{
			ans=min({ans,c[u][i],c[v][i]});  
			u=nu ;
			v=nv;  
		}
	}
	return min({ans,c[u][0],c[v][0]});
}	

void build()
{
	for(int i =1 ;i<=n;i++)
	{
		g[i].clear(), pa[i]= i,fi[i]=0 ; 
		for(int j= 0;j<10;j++)
		{
			p[i][j] = 0 ; 
			c[i][j] =0  ;
		}
	} 
	for(int i=0;i<consider.size();i++)
	{
		int u = consider[i].u ; 
		int v = consider[i].v; 
		int id =consider[i].id ; 
		int c= consider[i].c ;
		if(value[id]!=c)continue ; 
		int chau=  goc(u) ; 
		int chav =goc(v) ;  
		if(chau==chav)continue ;
		pa[chau]=chav ;
		g[u].pb({v,c}) ; 
		g[v].pb({u,c});  
	}
}
bool check(int u ,int v ,int val)
{
	if(o==0)
	{
		build();
		o=1;
	}
	dfs(u,0);
	if(fi[v]==0)return 0 ;
	for(int j = 1;j<=9;j++)
	{
		for(int i= 1;i<=n;i++)
		{
			p[i][j] = p[p[i][j-1]][j-1]; 
			c[i][j] = min(c[i][j-1],c[p[i][j-1]][j-1]); 
		}
	}
	int x= lca(u,v);
	return x>=val;
}
void xuly()
{
	// tim mst cua do thi ban dau // find the mst of the init graph 
	for(int i= 1;i<=n;i++)pa[i] = i ; 
	for(auto it: tmp)
	{
		int u = it.u ; 
		int v = it.v ; 
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		int c= it.c;
		if(chau==chav)continue ;
		pa[chau]=chav;
		consider.pb(it);
	}
	// tim mst cua do thi ma cac canh cua do thi bi bo r  
	tmp.clear() ; 
	for(int i= 1;i<=m;i++)
	{
		if(dd[i])continue ;
		tmp.pb(edge[i]) ; 
	}
	sort(all(tmp));
	for(int i= 1;i<=n;i++)pa[i] = i;
	for(auto it: tmp)
	{
		int u = it.u ; 
		int v = it.v ; 
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)continue ;
		pa[chau]=chav;
		consider.pb(it); 
	}
}
void solve()
{
	for(int i= 1;i<=q;i++)
	{
		if(query[i].t==1)
		{
			int id= query[i].u;
			consider.pb({edge[id].u,edge[id].v,edge[id].c,id});
			consider.pb({edge[id].u,edge[id].v,query[i].v,id});
		}
	}
	sort(all(consider))  ; 
	o =0  ;
	FOR(i,1,q)
	{
		int t =query[i].t  ; 
		if(t==1)
		{
			int id = query[i].u ; 
			int u = edge[id].u ; 
			int v =edge[id].v; 
			int c= query[i].v;  
			value[id] = c;  
			o= 0 ;
		}
		else 
		{
			int u = query[i].u ; 
			int v = query[i].v ; 
			bool res=check(u,v,query[i].val); 
			if(res)cout<<"YES"<<"\n"; 
			else cout<<"NO"<<"\n";
		}
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
        solve();
    }
    return 0;
}