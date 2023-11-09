/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "DTELETOWER"
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
#define        Mask(i)  (1ll<<(i))
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
const int N = 1e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n  ;
ll D ;
int ID[202][202] ;
pii a[N];
void doc()
{
    cin>> n >> D ;
    FOR(i,1,n)
    {
    	int x ,y  ;cin>>x>>y ;
    	ID[x][y] = i ;
    	a[i] = {x,y} ;
    } 
}	

namespace sub1
{
	vi g[N] ;
	int color[N] ;
	void go(int u ,int c)
	{
		color[u] = c;
		for(auto v: g[u])if(color[v]==0)
		{
			go(v,3-c) ;
		}
	}
	int dd[N] ; 
	int pa[N] ; 
	bool dfs(int u)
	{
		if(dd[u])return 0 ;
		dd[u] =1 ;
		for(auto v:g[u])if(pa[v]==0||dfs(pa[v]))
		{
			pa[v] =u ; 
			return 1; 
		}
		return 0; 
	}
    void xuly()
    {
    	sort(a+1,a+n+1) ; 
    	FOR(i,1,n)
    	{
    		FOR(j,i+1,n)
    		{
    			if(sq(a[i].fi-a[j].fi)>sq(D))break;
    			ll dis = sq(a[i].fi-a[j].fi)+sq(a[i].se-a[j].se) ;
    			if(dis==sq(D))g[i].pb(j),g[j].pb(i); 
    		}
    	}
    	FOR(i,1,n)if(color[i]==0)
    	{
    		go(i,1) ; 
    	}
    	vi left ;
    	FOR(i,1,n)if(color[i]==1)left.pb(i) ; 	
    	for(auto i : left)
    	{
    		dfs(i) ; 
    		for(auto i : left)dd[i] = 0 ;
    	}
    	int res = 0 ;
    	FOR(i,1,n)res+=(pa[i]>0) ;
    	cout<<res;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}