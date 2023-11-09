/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "superm"
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
#define          SZ(_)  (int)(_.size())
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
const int N = 1048576+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ;
vi g[N] ;
int ok[N] ;
int root  ;  
void doc()
{
	int theta; cin>>theta ;
   	cin>>n>>m ;
   	FOR(i,1,n-1)
   	{
   		int u ,v ;cin>>u>>v ;
   		g[u].pb(v) ; 
   		g[v].pb(u) ;
   	}
   	FOR(i,1,m)
   	{
   		int u ;cin>> u ;
   		ok[u] =1 ;
   		root = u; 
   	}
}

namespace sub1
{
	vi adj[N] ; 
	int res =0 ;
	void dfs(int u ,int p)
	{
		for(auto v :g[u])if(v!=p)
		{
			dfs(v,u) ; 
			if(ok[v])adj[u].pb(v),adj[v].pb(u) ,res+=2;
			ok[u]+=ok[v] ; 
		}
	}
	struct DL
	{
		int val; 
		int id ;
		bool operator>(const DL&a)const
		{
			return (val>a.val)||(val==a.val&&id<a.id) ; 
		}
		bool operator<(const DL&a)const
		{
			return (val<a.val)||(val==a.val&&id>a.id) ; 
		}
		bool operator<=(const DL&a)const
		{
			return (*this<a)||(val==a.val); 
		}
	} ; 
	DL f[N] ;
	DL ma ; 
	void solve(int u, int p )
	{
		f[u] = {0,u} ;
		for(auto v: adj[u])if(v!=p)
		{ 
			solve(v,u) ; 
			maxi(f[u],DL{f[v].val+1,f[v].id}) ;
		}
	}
	DL dis[N] ;
	void cal(int u,int p)
	{
		DL d1=DL{-oo,0} ,d2=DL{-oo,0} ; 
		maxi(dis[u],{0,u}) ;
		for(auto v : adj[u])if(v!=p)
		{
			if(d1<=f[v])
			{
				d2=d1 ;
				d1=f[v] ;
			}
			else 
			{
				maxi(d2,f[v]) ; 
			}
		}
		for(auto v: adj[u])if(v!=p)
		{
			dis[v] = DL{dis[u].val+1,dis[u].id};
			if(d1.id==f[v].id)
			{
				maxi(dis[v],DL{d2.val+2,d2.id}) ; 
			}
			else 
			{
				maxi(dis[v],DL{d1.val+2,d1.id}); 
			}
			cal(v,u) ;

		}
	}	
    void xuly()
    {
        dfs(root,0) ;  
        solve(root,0) ;
        FOR(i,1,n)if(ok[i])dis[i]={-oo,0};
        cal(root,0) ;  
        DL ma =DL{0,0}; 
        FOR(i,1,n)if(ok[i])
        {
        	maxi(f[i],dis[i]) ; 
        	maxi(ma,f[i]) ;
        }
        cout<<res-ma.val<<el ; 
        FOR(i,1,n)if(ok[i])
        {
        	if(f[i].val==ma.val)cout<<i<<" ";
        }
        cout<<el;
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
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}