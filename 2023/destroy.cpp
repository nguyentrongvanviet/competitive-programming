/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "durian"
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , k; 
vi g[N] ; 
int pa[N][LO] ;
int sz[N] , dd[N] ; 
map<int,int>D[N] ; 
int P[N] ; 
int Near[N] ; 
int h[N] ;
struct DL
{
	int u  ;
	int h ;
	bool operator<(const DL& a)const
	{
		return h>a.h; 
	}
} ; 
ve<DL>q; 
int go(int u ,int k)
{
	FORN(i,0,LO)if(k>>i&1)u=pa[u][i] ; 
	return u ; 
}
void dfsz(int u ,int p)
{
	sz[u] =  1 ; 
	for(auto v: g[u])if(v!=p&&dd[v]!=1)
	{
		dfsz(v,u) ;
		sz[u]+=sz[v] ; 
	}
}
int cen(int u ,int p ,int n )
{
	for(auto v: g[u])if(v!=p&&dd[v]!=1)
	{
		if(sz[v]>n/2)return cen(v,u,n) ; 
	}
	return u ;
}
void dfs1(int u ,int p ,int root, int d)
{
	D[root][u] = d  ;
	for(auto v: g[u])
	{
		if(dd[v]==0&&v!=p)dfs1(v,u,root,d+1) ; 
	}
}
void build(int u, int p )
{
	D[u][u] = 0 ;
	P[u] = p ; 
	dd[u] = 1; 
	for(auto v: g[u])
	{
		if(dd[v]==0)dfs1(v,u,u,1) ; 
	}
	for(auto v :g[u])if(dd[v]==0)
	{
		dfsz(v,u) ; 
		build(cen(v,u,sz[v]),u) ; 
	}
}
void up(int u)
{
	for(int cha = u ; cha!=0;cha=P[cha])
	{
		mini(Near[cha],D[cha][u]);
	}
}
int check(int u)
{
	int dis = oo ; 
	for(int cha = u ; cha!=0;cha=P[cha]) 
	{
		mini(dis,D[cha][u]+Near[cha]) ;
	}	
	return dis<k ;
}
void doc()
{
	cin>> n >> k;
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

void DFS(int u ,int p)
{
	q.pb({u,h[u]}) ; 
	for(auto v :g[u])if(v!=p)
	{
		pa[v][0]=u ; 
		h[v]=h[u]+1; 
		DFS(v,u) ;
	}
}	
void xuly()
{			
	FOR(i,1,n)Near[i] = oo ; 
	dfsz(1,0); 
	build(cen(1,0,n),0);
	DFS(1,0) ; 
	sort(all(q));
	int res= 0 ;	
	FORN(j,1,LO)FOR(i,1,n)pa[i][j]=pa[pa[i][j-1]][j-1];
	for(auto v: q)
	{
		if(check(v.u))continue ; 
		up(v.u);
		++res;   
	}
	cout<<res; 
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