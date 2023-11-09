/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

#include<bits/stdc++.h>
using namespace std; 


#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

struct EDGE
{
	int u ,v  ; 
	ll w ; 
	bool operator<(const EDGE &a )const
	{
		return w<a.w ; 
	}
} ; 
int n , m  , k  ,  q ; 
ll f[N] ; 
EDGE E[(int)3e5+5] ; 
int pa[N] ;
struct ke
{
	int v ; 
	ll w; 
} ; 
ve<ke>g[N] ; 
int h[N] ; 
int P[N][LO+2] ; 
ll MA[N][LO+2] ; 
void doc()
{
	cin>>n >> m >> k >>q ; 
	FOR(i,1,m)
	{
		int u ,v ;
		ll  w; 
		cin>>u>>v >>w; 
		g[u].pb({v,w}) ;
		g[v].pb({u,w}) ; 
		E[i] = {u,v,w} ; 
	}
}
struct DL
{
	int u ;
	ll val ; 
}; 
struct cmp
{
	bool operator()(const DL&a ,const DL&b)
	{
		return a.val>b.val; 
	}
}; 
void dij()
{
	priority_queue<DL,ve<DL>,cmp>q; 
	FOR(i,1,n)f[i] = inf ; 
	FOR(s,1,k)q.push({s,f[s]=0}) ;
	while(!q.empty())
	{
		int u = q.top().u ; 
		ll val =q.top().val ;  
		q.pop() ; 
		if(f[u]<val)continue ; 
		for(auto x:g[u])
		{
			int v = x.v ; 
			int w = x.w ; 
			if(mini(f[v],f[u]+w))q.push({v,f[v]=f[u]+w}) ;  
		}
	}
}
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u ,int v,ll w )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	g[u].pb({v,w}) ; 
	g[v].pb({u,w}) ; 	
	pa[chau]=chav ; 
}
void DFS(int u ,int p)
{
	for(auto x : g[u])
	{
		int v= x.v; 
		ll w= x.w; 
		if(v==p)continue; 
		P[v][0] = u; 
		MA[v][0] = w ; 
		h[v]=h[u]+1; 
		DFS(v,u) ; 
	}
}
void build_lca()
{
	FOR(i,1,m)
	{
		E[i].w = f[E[i].u]+f[E[i].v]+E[i].w;
	}

	sort(E+1,E+m+1) ; 
	FOR(i,1,n)pa[i] = i ;
	FOR(i,1,n)g[i].clear() ; 
	FOR(i,1,m)
	{
		int u = E[i].u ;
		int v = E[i].v ; 
		ll w = E[i].w ;
		hop(u,v,w) ;
	}
	DFS(1,0) ; 
	FOR(j,1,LO)FOR(i,1,n)
	{
		P[i][j] = P[P[i][j-1]][j-1] ;
		MA[i][j] = max(MA[i][j-1],MA[P[i][j-1]][j-1]) ; 
	}
}
ll lca(int u ,int v)
{
	ll res = 0 ; 
	if(h[u]<h[v])swap(u,v) ; 
	FORD(i,LO,0)
	{
		if(h[u]-(1<<i)>=h[v])
		{
			maxi(res,MA[u][i]) ; 
			u = P[u][i] ; 
		}
	}
	if(u==v)return res ; 
	FORD(i,LO,0)
	{
		int nu = P[u][i] ; 
		int nv = P[v][i] ; 
		if(nu!=nv)
		{
			maxi(res,MA[u][i]) ; 
			maxi(res,MA[v][i]) ;
			u=nu ;
			v=nv ; 
		}
	}
	maxi(res,MA[u][0]) ; 
	maxi(res,MA[v][0]) ;
	return res ; 
}
void xuly()
{
	dij() ; 
	build_lca() ;
	while(q--)
	{
		int u ,v ; 
		cin>>u>>v;
		cout<<lca(u,v)<<el; 
	}
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}