/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

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
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 5e5+5, oo = 2e9, LO = 18, CH = 26 ; 
// end of macros and constant  

struct Edge
{
	int u ,v , w ; 
	bool operator<(const Edge&a)const
	{
		return w<a.w ; 
	}
} ; 
int n , m , k ; 
int pa[N] ;
Edge E[N] ;
vi g[N] ;  
int P[N][LO+3] , W[N][LO+3] ; 
int h[N] ; 
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
bool hop(int u ,int v)
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return 0 ;  
	pa[chau]=chav ; 
	return 1 ; 
}
void doc()
{
	cin>> n >> k >> m ; 
	FOR(i,1,n)pa[i] = i , W[i][0] = oo ; 
	FOR(i,1,k)
	{
		int u ,v ; cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
		hop(u,v) ; 
	}
	FOR(i,1,m)
	{	
		cin>>E[i].u>>E[i].v >>E[i].w ; 
	}
}
void dfs(int u, int p)
{
	for(auto v: g[u])if(v!=p)
	{
		h[v]=h[u]+1 ; 
		P[v][0] = u ; 
		dfs(v,u) ; 
	}
}
void lca(int u ,int v,int val)
{
	if(h[u]<h[v])swap(u,v) ;  
	FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])mini(W[u][i],val),u=P[u][i] ;
	if(u==v)return ;
	FORD(i,LO,0)
	{
		int nu = P[u][i] ; 
		int nv = P[v][i] ; 
		if(nu!=nv)
		{
			mini(W[u][i],val) ; 
			mini(W[v][i],val) ; 
			u=nu ; 
			v=nv ; 
		}
	}
	mini(W[u][0],val) ; 
	mini(W[v][0],val) ;  
}
ll tmp =  0; 
void xuly()
{
	sort(E+1,E+m+1) ;  
	FOR(i,1,m)
	{
		int u = E[i].u ;
		int v = E[i].v ; 
		if(hop(u,v))tmp+=E[i].w,g[u].pb(v),g[v].pb(u); 
	}
	dfs(1,0) ;
	
	FOR(i,1,n)FOR(j,0,LO)W[i][j]=oo ;
	
	FOR(j,1,LO)
		FOR(i,1,n)
			P[i][j]=P[P[i][j-1]][j-1] ; 
	
	FOR(i,1,m)
		lca(E[i].u,E[i].v,E[i].w) ;
	ll res= 0 ;
	FORD(j,LO,1)
	{
		FOR(i,1,n)
		{
			mini(W[i][j-1],W[i][j]) ; 
			mini(W[P[i][j-1]][j-1],W[i][j]) ; 
		}
	}
	FOR(i,2,n)
	{
		if(W[i][0]==oo)return void(cout<<-1) ;
		res+=W[i][0];
	}	
	cout<<res-tmp; 
}

	
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
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}