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
const int M= 100005 ;
struct E 
{
	int u , v,  c; 
	bool operator<(const E& a)const
	{
		return c>a.c;
	}
};
struct ke 
{
	int v , c  ; 
};
int n  , m , q; 
int d[N] ;
E edge[M];
int h[N] , pa[N] , p[N][12] , c[N][12 ] ;
vector<ke>g[N] ;
int goc(int u)
{
	return pa[u]==u?u:pa[u]=goc(pa[u]); 
}
int tt = 0 ;
void dfs(int u , int cha)
{
	d[u] =tt ; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i].v;  
		int w= g[u][i].c; 
		if(v==cha)continue ; 
		p[v][0]=u ;
		c[v][0]=w;
		h[v]=h[u]+1;
		dfs(v,u) ; 
	}
}
int lca(int u ,int v)
{
	int ans = oo ; 
	if(h[u]<h[v])swap(u,v); 
	int dis= h[u]-h[v] ;
	for(int i= 0;i<=10;i++)
	{
		if(dis>>i&1)
		{
			ans= min(ans,c[u][i]);
			u= p[u][i] ; 
		}
	}
	if(u==v)return ans ;
	for(int i= 10;i>=0;i--)
	{
		int nu = p[u][i] ;
		int nv= p[v][i] ; 
		if(nu!=nv)
		{
			ans= min({ans,c[u][i],c[v][i]});
			u=nu ; 
			v=nv ; 
		}
	}
	return min({ans,c[u][0],c[v][0]});
}	
bool check(int u ,int v , int val)
{
	vector<E>tmp ;
	memset(h,0,sizeof(h)); 
	memset(p,0,sizeof(p)) ; 
	memset(c,0,sizeof(c)) ;
	memset(d,0,sizeof(d)) ; 
	for(int i= 1;i<=n;i++)
	{
		g[i].clear() ; 
		pa[i]=i ;    
	}
	for(int i= 1;i<=m;i++)
	{
		tmp.pb(edge[i]) ; 
	}
	sort(all(tmp));
	for(int i= 0 ;i<tmp.size();i++)
	{
		int u = tmp[i].u ; 
		int v= tmp[i].v ;
		int c= tmp[i].c;  
		int chau = goc(u); 
		int chav = goc(v) ; 
		if(chau==chav)continue ;
		pa[chau] =chav ; 
		g[u].pb({v,c}) ; 
		g[v].pb({u,c}) ;
	}
	tt = 0;
	for(int i =1 ;i<=n ;i++)
	{
		if(d[i]==0)
		{
			++tt; 
			dfs(i,0) ; 
		}
	}
	if(d[u]!=d[v])return 0 ;
	for(int j =1 ;j<=10;j++)
	{
		for(int i=1 ;i<=n;i++)
		{
			p[i][j] = p[p[i][j-1]][j-1] ; 
			c[i][j] = min(c[i][j-1],c[p[i][j-1]][j-1]) ;
		}
	}
	int x =lca(u,v) ;
	return x >=val ;
}
void doc()
{	
    cin>>n>>m>>q; 
    for(int i=1;i<=m;i++)
    {
    	int u , v , c; cin>>u>>v >>c ;
    	edge[i] ={u,v,c}; 
    }
    for(int i =1 ;i<=q;i++)
    {
    	char x ; 
    	cin>>x ; 
    	if(x=='C')
    	{
    		int id ,  c; cin>>id>>c ;
    		edge[id].c= c ;
    	}	
    	else 
    	{
    		int u , v, val  ; cin>>u>>v>>val;  ; 
    		if(check(u,v,val))cout<<"YES"<<"\n"; 
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
        freopen(TASK".ANS","w",stdout); 
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