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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ; 
struct pt
{
	ll x ,y ; 
	pt()
	{
		x=0  ; 
		y=0 ; 
	}
	pt(ll _x ,ll _y)
	{
		x=_x ;
		y=_y ; 
	}
} ; 
pt a[N] ; 
vi g[N] ;
db dis(pt A , pt B)
{
	return sqrt(sq(A.x-B.x)+sq(A.y-B.y)) ;
}
void doc()
{
    cin>> n >> m;  
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].y ; 
    }
    FOR(i,1,m)
    {
    	int u , v; cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	ve<pt>node[N] ;
	int tp[N] ; 
	int tplt = 0 ;
	void dfs(int u )
	{
		tp[u] = tplt;  
		node[tplt].pb(a[u]) ;  
		for(auto v: g[u])
		{
			if(tp[v]==0)dfs(v) ; 
		}
	}
	db mi(int A , int B)
	{
		db ans = oo ; 
		for(auto u : node[A])for(auto v :node[B])mini(ans,dis(u,v)) ;
		return ans;  
	}
	struct Edge
	{
		int u ,v ; 
		db c; 
		bool operator<(const Edge&a)const
		{
			return c<a.c ;
		}
	} E[N*N] ;
	int pa[N] ;
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return 0 ;
		pa[chau] = chav ;
		return 1 ; 
	}
    void xuly()
    {
    	FOR(i,1,n)if(tp[i]==0)++tplt,dfs(i) ;
    	m = 0 ;
    	FOR(u,1,tplt)
    	{
    		FOR(v,u+1,tplt)
    		{
    			E[++m]={u,v,mi(u,v)} ; 
    		}
    	} 
    	sort(E+1,E+m+1) ; 
    	FOR(i,1,tplt)pa[i] = i; 
    	db res = 0 ;
    	FOR(i,1,m)
    	{	
    		if(hop(E[i].u,E[i].v))res+=E[i].c;
    	}
    	cout<<setprecision(3)<<fixed;
    	cout<<res ;
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
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