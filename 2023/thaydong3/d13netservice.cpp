/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13netservice"
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
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k; 
int spec[N] ;
ll T[N],p[N] ;
struct ke
{
	int v,w; 
}; 
ve<ke>g[N]; 
void doc()
{	
    cin>> n >>m >> k; 
    FOR(i,1,k)cin>>spec[i] ;
    FOR(i,1,k)cin>>T[i] ;  
    FOR(i,1,k)cin>>p[i] ;
	FOR(i,1,m)
	{
		int u ,v ,w ;
		cin>>u>>v>>w;
		g[u].pb({v,w}) ;
	}
}

namespace sub1
{
	ll f[105][N];  
	struct DL
	{
		int u ; 
		ll val; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a,const DL&b)const
		{
			return a.val>b.val ; 
		}
	} ;
	void dij(int u ,ll f[])
	{	
		priority_queue<DL,ve<DL>,cmp>q ;
		FOR(i,1,n)f[i] = inf; 
		q.push({u,f[u]=0}) ; 
		while(!q.empty())
		{
			int u = q.top().u ;
			ll val = q.top().val; 
			q.pop() ;
			if(f[u]<val)continue ;
			for(auto x:g[u])
			{
				int v=x.v ;
				int w=x.w ;
				if(mini(f[v],f[u]+w))q.push({v,f[v]}) ;
			}
		}
	}
	int dd[105] ; 
	vi adj[105] ;
	int pa[105];
	bool dfs(int u)
	{
		if(dd[u])return 0 ; 
		dd[u] =1 ;
		for(auto v:adj[u])if(pa[v]==0||dfs(pa[v]))
		{
			pa[v] = u; 
			return 1 ; 
		}
		return 0 ;
	}
    void xuly()
    {
    	FOR(i,1,k)
    	{
    		dij(spec[i],f[i]) ;
    	}
    	FOR(i,1,k)FOR(j,1,k)if(i!=j)
    	{
    		int u = spec[i] ;
    		int v = spec[j] ;
    		if(T[i]+p[i]+f[i][v]<=T[j])
    		{
    			adj[i].pb(j) ;
    		}
    	}
    	FOR(i,1,k)
    	{
    		FOR(j,1,k)dd[j]= 0 ;
    		dfs(i) ; 
    	}
    	int res = k ; 
    	FOR(i,1,k)if(pa[i])res-- ;
    	cout<<res<<el;
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