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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ; 
vi g[N] ;
int a[N] ; 

void doc()
{	
	cin>> n;    
	FOR(i,1,n)cin>>a[i] ;  
	FOR(i,1,n-1)
	{
		int u ,v; cin>> u >>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

namespace sub1
{
	ll res = 0 ;
	void dfs(int u ,int p ,int cur)
	{
		cur = gcd(cur,a[u]) ; 
		res+=cur; 
		for(auto v :g[u])if(v!=p)
		{		
			dfs(v,u,cur) ;
		}
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		dfs(i,0,a[i]) ;
    		res-=a[i] ; 
    	}
    	cout<<res/2; 
    }
}
namespace sub2
{
	int P[N][LO+1] ;  
	int VAL[N][LO+1] ;
	int h[N] ; 
	ll res = 0 ;
	void dfs(int u ,int p )
	{
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1 ;
			P[v][0] = u ; 
			VAL[v][0] = a[v] ; 
			dfs(v,u) ;
		}
	}
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ;
		int ans = 0 ; 
		FORD(i,LO,0)if(h[u]-M(i)>=h[v])
		{
			ans=gcd(ans,VAL[u][i]) ;
			u=P[u][i] ; 
		}
		if(u==v)
		{
			ans=gcd(ans,a[u]) ; 
			return ans; 
		}
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				ans=gcd(ans,VAL[u][i]) ; 
				ans=gcd(ans,VAL[v][i]) ; 
				u=nu ;
				v=nv ;
			}
		}
		ans=gcd(ans,VAL[u][1]) ; 
		ans=gcd(ans,VAL[v][0]) ;
		return ans ;
	}
	void xuly()
	{
		dfs(1,0) ;
		FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] , VAL[i][j] = gcd(VAL[i][j-1],VAL[P[i][j-1]][j-1]) ;
		FOR(i,1,n)FOR(j,i+1,n)
		{
			res+=lca(i,j) ; 
		}
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
    int sub; cin>>sub  ; 
    FOR(i,1,test)
    {
        doc() ; 
        if(sub==1)sub1::xuly() ;
        if(sub==2)
        	sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}