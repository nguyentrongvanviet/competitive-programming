/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "countpath"
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
const ll inf = 1e18 , cs = 331 , sm =998244353; 
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct Edge
{
	int u ,v , x, y; 
	bool operator<(const Edge&a)const
	{
		return x<a.x||(x==a.x&&y<a.y) ; 
	}
} ; 
int n ,m ; 
Edge E[N] ; 
vi g[N] ; 
void doc()
{
	cin>> n >>m ; 
	FOR(i,1,m)
	{
		int u ,v,  x,y  ; cin>>u>>v>>x>>y ; 
		E[i]= {u,v,x,y} ; 
		g[v].pb(y);
	}
}	

namespace sub1
{
	struct BIT
	{
		vi bit ; 
		int n = 0 ; 
		void resize(int _n)
		{
			n=_n ; 
			bit.resize(n+2,0) ; 
		}
		void up(int id, int val)
		{
			for(int i=id;i<=n;i+=i&-i)(bit[i]+=val)%=sm; 
		}
		int get(int id )
		{
			int ans = 0 ;
			for(int i=id;i;i-=i&-i)(ans+=bit[i])%=sm ; 
			return ans ; 
		}
	} ;  
	BIT bit[N] ; 
	int f[N] ; 
    void xuly()
    {	
    	FOR(i,1,n)
    	{
    		uni(g[i]) ;
    		bit[i].resize(SZ(g[i])) ; 
    	}
    	sort(E+1,E+m+1) ; 
    	int it = 1 ;
    	FOR(i,1,m)
    	{
    		f[i] = 1 ;
    		while(it<i&&E[it].x<E[i].x)
    		{
    			int v = E[it].v ; 
    			int y = E[it].y ; 
    			bit[v].up(UB(all(g[v]),y)-g[v].begin(),f[it]);
    			++it ; 
    		}
    		int u = E[i].u ; 
    		int y = E[i].y ;
    		int p = LB(all(g[u]),y)-g[u].begin(); 
    		(f[i]+=bit[u].get(p))%=sm; 
    	}
    	int res = 0 ;
    	FOR(i,1,m)(res+=f[i])%=sm; 
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
    if(mtt)cin>>  test;
    int sub ; cin>>sub ; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}