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

bool mtt = 1 ;
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

int n , m ; 
struct Node
{
	int u ; 
	int h ;
	bool operator<(const Node&a)const
	{
		return h<a.h ; 
	} 
}a[N] ; 
vi g[N] ; 
int h[N] ;
void doc()
{
	cin>> n >> m;  
	FOR(i,1,n)
	{	
		cin>>a[i].h ; 
		h[i] = a[i].h ; 
		a[i].u = i ; 
	}
	FOR(i,1,m)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}	
namespace sub1
{
	struct query
	{ 
		int u , v , c;  
		int id ; 
		bool operator<(const query&a)const
		{
			return h[u]+c<h[a.u]+a.c;
		}
	} ;
	query Q[N] ; 
	int dd[N] ; 
	int pa[N] ;
	int res[N] ; 
	int goc(int u )
	{
		return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
	}
	void hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)return ; 
		pa[chau]=chav ; 
	}
    void xuly()
    {
    	int q ; cin>>q ;
    	FOR(i,1,q)
    	{
    		cin>>Q[i].u>>Q[i].v>>Q[i].c; 
    		Q[i].id = i ;
    	}
    	sort(a+1,a+n+1) ; 
    	sort(Q+1,Q+q+1) ; 
    	FOR(i,1,n)pa[i] =  i; 
    	int it = 1; 
    	FOR(i,1,q)
    	{
    		while(it<=n&&a[it].h<=h[Q[i].u]+Q[i].c)
    		{
    			int u =a[it++].u ;
    			dd[u] =1 ;  
    			for(auto v: g[u])if(dd[v])
    			{
    				hop(u,v) ; 
    			} 
    		}
    		if(goc(Q[i].u)==goc(Q[i].v))res[Q[i].id] = 1;  
    	}
    	FOR(i,1,q)
    	{
    		cout<<(res[i]?"YES":"NO")<<el;
    	}
    	cout<<el;
    	FOR(i,1,n)g[i].clear(),dd[i]=0 ;
    	FOR(i,1,q)res[i] =  0 ; 
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