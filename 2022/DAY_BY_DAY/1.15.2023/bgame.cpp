#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =1e5+5 ,  oo = 2e9, CH = 26 ;
const int LO = 20 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct edge
{
	int u ,v , w;  
	bool operator<(const edge& other)const
	{
		return w>other.w; 
	}
}; 
struct ke
{
	int v ; 
	int w; 
} ;
int n , m; 
edge E[N] ;
ve<ke>g[N] ;
int pa[N] ; 
int P[N][LO],ma[N][LO] ;
int h[N];  
int dd[N] ;
void read()
{
	cin>> n >>m ; 
	FOR(i,1,m)
		cin>>E[i].u>>E[i].v>>E[i].w  ; 
}	
int goc(int u )
{
	return pa[u] == u ? u : pa[u] = goc(pa[u]); 
}
void hop(int idx, int u ,int v,int w )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	g[u].pb({v,w}); 
	g[v].pb({u,w});  
	pa[chau] = chav ;
	dd[idx] =1 ;
}
void dfs(int u ,int p)
{
	for(auto x:g[u])
	{	
		int v =x.v  ;
		int w = x.w ;
		if(v==p)continue;
		h[v] = h[u]+1;
		P[v][0] = u ;
		ma[v][0] = w;
		dfs(v,u) ; 
	}
}
int lca(int u ,int v)
{
	if(h[u]<h[v])swap(u,v) ;
	int ans = 0 ; 
	int dis = h[u]-h[v] ;
	for(int i= 0 ;i<LO;i++)
	{
		if(dis>>i&1)
		{
			ans=max(ans,ma[u][i]) ;
			u= P[u][i] ; 
		}
	}
	if(u==v)return ans ; 
	FORD(i,LO-1,0)
	{
		int nu= P[u][i] ;
		int nv= P[v][i] ; 
		if(nu==nv)continue ;
		ans=max({ans,ma[u][i],ma[v][i]}) ;
		u=nu; 
		v=nv; 
	}
	return max({ans,ma[u][0],ma[v][0]}) ; 
}
void solve()
{
	sort(E+1,E+m+1) ; 
	FOR(i,1,n)pa[i] = i ;
	FOR(i,1,m)
	{
		int u = E[i].u ;
		int v= E[i].v ;
		int w= E[i].w; 
		hop(i,u,v,w) ; 
	}
	FOR(i,1,n)
	{
		if(h[i]==0)
		{
			h[i] = 1; 
			dfs(i,0) ; 
		}
	}
	FORN(j,1,LO)
	FOR(i,1,n)
	{
		P[i][j] = P[P[i][j-1]][j-1];
		ma[i][j] = max(ma[i][j-1],ma[P[i][j-1]][j-1]);
	} 		
	int res= 0; 
	FOR(i,1,m)if(dd[i]==0)
	{
		int u= E[i].u; 
		int v =E[i].v ;
		res=max(res,lca(u,v)+E[i].w) ;
	}
	cout<<res;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}