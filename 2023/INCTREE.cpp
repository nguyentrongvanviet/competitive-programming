/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
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

int n , m , q ; 
vi g[N] ; 
int f[N]  ; 
void doc()
{
	cin>> n >>m >>q ; 
	FOR(i,1,n-1)
	{
		int u ,v; cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ;
	}
}
namespace sub1
{
	int h[N] ; 
	int P[N][LO+1] ; 
	int W[N][LO+1] ;
	void dfs(int u ,int p)
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
		if(h[u]<h[v])swap(u,v)  ; 
		FORD(i,LO,0)
		{
			if(h[u]-(1<<i)>=h[v])u=P[u][i] ; 
		}
		if(u==v)return u ;
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)u=nu,v=nv; 
		}
		return P[u][0] ;
	}
	void GIAO(int u ,int v ,int x ,int y)
	{
		int L = lca(x,u);  
		int R = lca(y,u);
		if(h[R]<h[v])R=v ;  
		if(h[L]<h[v])L=v ;
		f[L]-- ; 
		f[R]++ ;
	}
	void DFS(int u, int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			DFS(v,u) ;
			f[u]+=f[v] ;
		}
		W[u][0] = f[u]  ; 
	}
	int dis(int u ,int v)
	{
		int dis = 0 ;
		if(h[u]<h[v])swap(u,v)  ; 
		FORD(i,LO,0)
		{
			if(h[u]-(1<<i)>=h[v])dis+=W[u][i],u=P[u][i] ; 
		}
		if(u==v)return dis;
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)dis+=W[u][i]+W[v][i],u=nu,v=nv; 
		}
		dis+=W[u][0]+W[v][0] ; 
		return dis ;
	}
    void xuly()
    {
        dfs(1,0) ; 
        FOR(j,1,LO)
        {
        	FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
        }
        while(m--)
        {
        	int u ,v , x, y ; 
        	cin>>u>>v>>x>>y ;
        	f[u]++ ; 
        	f[v]++ ; 
        	int c = lca(u,v) ;
        	f[c]-=2 ; 
        	int z = lca(x,y) ; 
        	GIAO(u,c,x,z) ; 
        	GIAO(u,c,y,z) ; 
        	GIAO(v,c,x,z) ; 
        	GIAO(v,c,y,z) ;
        }
        DFS(1,0) ;
        prt(f,n) ; 			
        FOR(j,1,LO)FOR(i,1,n)W[i][j]=W[i][j-1]+W[P[i][j-1]][j-1] ; 
        while(q--)
        {
        	int  u ,v ; cin>>u>>v ;
        	cout<<dis(u,v)<<el;
        }
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
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}