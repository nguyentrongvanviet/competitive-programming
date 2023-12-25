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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k;
struct Edge
{
	int u ,v , w; 
	bool operator<(const Edge&a)const
	{
		return w<a.w ;
	}
}E[N] ;

void doc()
{    
	cin>> n >> m >> k;
	FOR(i,1,m)
	{
		int u ,v,w ;
		cin>>u>>v>>w; 
		E[i] = {u,v,w}; 
	}
}

namespace sub1
{
	struct ke
	{
		int v , w ;
	} ;
	ve<ke>g[N] ;
	struct DL
	{
		int u ;
		ll val; 
	} ;
	struct cmp
	{
		bool operator()(const DL a , const DL b )const
		{		
			return a.val>b.val ;
		}
	}; 
	priority_queue<DL,ve<DL>,cmp>q; 
	priority_queue<ll>value ;
	ll f[N] ;
	void dij(int st )
	{	
		q.push({st,f[st]=0}) ;	
		vi node ;
		node.pb(st) ;
		while(!q.empty())
		{
			int u= q.top().u ;
			ll val = q.top().val ;
			q.pop() ;
			if(f[u]<val)continue ;
			if(st<u)
			{
				if(SZ(value)<k)value.push(f[u]) ; 	
				else if(value.top()>f[u])
				{
					value.pop() ;
					value.push(f[u]) ; 
				}
			} 
			for(auto x:g[u])
			{
				int v=x.v; 
				int w =x.w ;
				if(f[v]==inf)node.pb(v) ;
				if(mini(f[v],f[u]+w))
				{
					q.push({v,f[v]}) ;
				}
			}
		}
		for(auto u : node)f[u] = inf; 
	}
    void xuly()
    {
    	sort(E+1,E+m+1) ;
    	FOR(i,1,min(m,k))
    	{
    		int u =E[i].u ;
    		int v =E[i].v ;
    		int w = E[i].w ;
    		g[u].pb({v,w}) ; 
    		g[v].pb({u,w}) ;
    	}
    	FOR(i,1,n)f[i] = inf; 
    	FOR(i,1,n)dij(i) ; 
    	cout<<value.top()<<el;
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