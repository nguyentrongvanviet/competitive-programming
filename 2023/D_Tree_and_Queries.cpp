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
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  
 
int n; 
vi g[N] ;
int a[N] ; 
int q ;  
ve<pii> Q[N] ; 
map<int,int>sl[N] ;
void doc()
{
	cin>> n >> q ; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
	FOR(i,1,q)
	{
		int u , sl; cin>>u>>sl; 
		Q[u].pb(mp(sl,i)) ;
	}
}
int node = 0 ; 
int head[N] ; 
int T[(int)2e7][2] ; 
int f[(int)2e7]; 
int res[N] ; 
void add(int root, int val)
{
	int r =root ; 
	FORD(i,LO,0)
	{
		int j = (val>>i&1) ; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
		f[r]++; 
	}
}
void xoa(int root, int val)
{
	int r = root ;
	FORD(i,LO,0)
	{
		int j = (val>>i&1) ; 
		r=T[r][j] ; 
		f[r]--;
	}
}
int get(int root, int val)
{
	int res= 0; 
	int r =root ; 
	FORD(i,LO,0)
	{
		int j = (val>>i&1); 
		if(j==0)
		{
			res+=f[T[r][1]]; 
		} 
		r=T[r][j] ; 
	}
	res+=f[r] ; 
	return res ; 
}
void dfs(int u ,int p)
{
	sl[u][a[u]]++; 
	head[u]=++node; 
	add(head[u],1) ;
	for(auto v: g[u])if(v!=p)
	{
		dfs(v,u) ; 
		if(sl[u].size()<sl[v].size())
		{
			swap(sl[u],sl[v]); 
			swap(head[u],head[v]) ; 
		}
		for(auto x: sl[v])
		{
			int c = x.fi ; 
			int val = x.se ;
			if(sl[u].find(c)!=sl[u].end())xoa(head[u],sl[u][c]) ;
			sl[u][c]+=val; 
			add(head[u],sl[u][c]) ;
		}
		sl[v].clear() ;
	}
	for(auto q : Q[u])
	{
		int val =q.fi ;
		int id = q.se;  
		res[id] = get(head[u],val) ; 
	}
}
void xuly()
{
    dfs(1,0) ; 
    prt(res,q);
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
    // int theta ; cin>>theta;  
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}