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

bool mtt = 1;

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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n  ,k  ,c ;
vi g[N] ;
int P[N][LO+2] ;
int h[N] ;
void doc()
{
	cin>> n >> k >> c ; 
	FOR(i,1,n-1)
	{	
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
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
int lca(int u ,int v)
{
	if(h[u]<h[v])swap(u,v) ; 
	int dis = 0 ;
	FORD(i,LO,0)
	{
		if(h[u]-(1<<i)>=h[v])
		{
			dis+=(1<<i) ;
			u=P[u][i] ; 
		}
	}
	if(u==v)return dis; 
	FORD(i,LO,0)
	{
		int nu =P[u][i] ; 
		int nv =P[v][i] ; 
		if(nu!=nv)
		{
			dis+=2*(1<<i) ;
			u=nu ;
			v=nv ; 
		}
	}
	return dis+2; 
}
void xuly()
{
	h[1] = 0 ; 
	dfs(1,0) ;
	int st = 0; 
	FOR(i,1,n)if(h[i]>h[st])st=i ;
	h[st]= 0 ; 
	FOR(i,1,n)P[i][0] = 0 ;
	dfs(st,0) ;
	int en = 0 ;  
	FOR(i,1,n)if(h[i]>h[en])en=i ; 
	ll res = 0 ;
	FOR(j,1,LO)FOR(i,1,n)
	{
		P[i][j] = P[P[i][j-1]][j-1] ;
	}
	FOR(i,1,n)
	{
		maxi(res,1LL*k*max(lca(i,st),lca(i,en)) -1LL*lca(1,i)*c) ;
	}
	cout<< res<<el;
	FOR(i,1,n)g[i].clear() ;
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