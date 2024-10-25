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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 4e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n; int n , m , q ; 
int C[N][N] ; 
void doc()
{
	cin>> n >> m >> q;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)C[i][j] =oo ; 
		C[i][i] = 0 ; 
	}
	for(int i=1;i<=m;i++)
	{
		int u ,v ,w ; cin >> u >>v >> w; 
		C[u][v] = min(C[u][v],w) ;
		C[v][u] = min(C[u][v],w) ;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		C[i][j] = min(C[i][j],C[i][k]+C[k][j]) ;
	}
}

namespace sub1
{
	struct Edge
	{
		int u ,v ,w ;  
	} ;
	vector<Edge>q ; 
	struct DSU
	{
		vector<int>pa ;
		int n; 
		DSU(int _n)
		{
			n = _n ; 
			pa.resize(n+1) ; 
			for(int i=1;i<=n;i++)pa[i] = i ; 
		}
		int goc(int u)
		{
			return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
		}
		bool hop(int u ,int v)
		{
			int chau = goc(u) ;
			int chav = goc(v) ;
			if(chau==chav)return 0;  
			pa[chau] = chav; 
			return 1; 
		}
	}
	vector<pii>Q[N] ;
    void xuly()
    {
    	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
    	{
			q.push({i,j,C[i][j]}) ;
    	}
    	sort(all(q),[](Edge a , Edge b){return a.w<b.w;}) ;
    	DSU dsu(n) ; 
    	for(auto [u,v,w] : q)
    	{
    		if(dsu.hop(u,v))
    		{
    			Q[w].push_back({u,v}) ; 
    		}
    	}
    	while(q--)
    	{
    		int sl; cin>>sl;
    		while(sl--)
    		{
    			int u ; 
    			cin>> u ;
    			for(auto v:Q[i])
    			{
    			}
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}