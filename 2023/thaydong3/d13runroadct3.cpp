/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13runroadct3"
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


int n; 
int a[N] ;
int T ; 
vi g[N] ; 
void doc()
{
    cin>> n >>T ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>> u >>v ;
    	if(a[u]>T||a[v]>T)continue ;
    	g[u].pb(v) ;
    	g[v].pb(u) ;
    }
}

namespace sub1
{
	const int N = 2e2+5 ;
	int ma[N][N] , dis[N][N] ; 
	void dfs(int u ,int p ,int root)
	{
		for(auto v:g[u])if(v!=p)
		{
			dis[root][v] = dis[root][u]+1 ;
			ma[root][v] = max(ma[root][u],a[v]) ; 
			dfs(v,u,root) ;
		}
	}
    void xuly()
    {
        FOR(i,1,n)
        {
        	ma[i][i] = a[i] ; 
        	dis[i][i] = 0 ;
        	dfs(i,0,i) ; 
        }
        ll res = 0;
        FOR(i,1,n)FOR(j,i+1,n)FOR(k,j+1,n)
        {
        	if(max({ma[i][j],ma[j][k],ma[k][i]})==T)
        	{
        		(res+=dis[i][j]+dis[j][k]+dis[k][i])%=sm ; 
        	}
        }
        cout<<res<<el;
    }
}
namespace sub3
{
	ll f[N][3][2] , sl[N][3][2] ;
	ll res = 0 ; 
	void add(ll &a , ll b)
	{
		(a+=b)%=sm ; 
	}
	int dd[N] ; 
	void dfs(int u ,int p)
	{
		dd[u] = 1 ;
		ve<vll>Pre(3,vll(2,0)) ;
		ve<vll>SlPre(3,vll(2,0)) ;  
		ve<vll>Cur(3,vll(2,0)) ; 
		ve<vll>SlCur(3,vll(2,0)) ; 
		if(a[u]==T)SlCur[1][1]=SlPre[1][1] = 1; 
		else SlCur[1][0]=SlPre[1][0] = 1; 
		for(auto v:g[u])if(v!=p)
		{
			dfs(v,u) ;
			if(a[u]==T)
			{
				add(f[v][1][1],f[v][1][0]) ; 
				add(sl[v][1][1],sl[v][1][0]) ; 
				f[v][1][0] = 0 ; 
				sl[v][1][0] = 0 ; 
				add(f[v][2][1],f[v][2][0]) ; 
				add(sl[v][2][1],sl[v][2][0]) ;
				f[v][2][0] = 0 ;
				sl[v][2][0] = 0 ;
			}
			// 1 0 
			add(Cur[1][0],f[v][1][0]+sl[v][1][0]) ;
			add(SlCur[1][0],sl[v][1][0]) ; 

			// 1 1 
			add(Cur[1][1],f[v][1][1]+sl[v][1][1]) ; 
			add(SlCur[1][1],sl[v][1][1]) ;
			
			// 2 0 
			add(Cur[2][0],f[v][2][0]+sl[v][2][0]) ;
			add(SlCur[2][0],sl[v][2][0]) ;
			add(Cur[2][0],(f[v][1][0]+sl[v][1][0])*SlPre[1][0]%sm+Pre[1][0]*sl[v][1][0]%sm) ; 
			add(SlCur[2][0],sl[v][1][0]*SlPre[1][0]%sm) ;

			// 2 1 
			add(Cur[2][1],f[v][2][1]+sl[v][2][1]) ; 
			add(SlCur[2][1],sl[v][2][1]) ; 
			
			add(Cur[2][1],(f[v][1][1]+sl[v][1][1])*SlPre[1][1]%sm+Pre[1][1]*sl[v][1][1]%sm) ;
			add(SlCur[2][1],sl[v][1][1]*SlPre[1][1]%sm) ;
			
			add(Cur[2][1],(f[v][1][0]+sl[v][1][0])*SlPre[1][1]%sm+Pre[1][1]*sl[v][1][0]%sm) ;  
			add(SlCur[2][1],sl[v][1][0]*SlPre[1][1]%sm); 
			
			add(Cur[2][1],(f[v][1][1]+sl[v][1][1])*SlPre[1][0]%sm+Pre[1][0]*sl[v][1][1]%sm) ; 
			add(SlCur[2][1],sl[v][1][1]*SlPre[1][0]%sm) ;

			FOR(sz1,1,2)FOR(ok1,0,1)FOR(sz2,3-sz1,3-sz1)FOR(ok2,0,1)if(ok1|ok2)
			{
				add(res,(f[v][sz1][ok1]+sl[v][sz1][ok1])*SlPre[sz2][ok2]%sm+sl[v][sz1][ok1]*Pre[sz2][ok2]%sm);
			}

			FOR(sl,1,2)FOR(ok,0,1)Pre[sl][ok]=Cur[sl][ok],SlPre[sl][ok]=SlCur[sl][ok] ;
		}	
		FOR(sz,1,2)FOR(ok,0,1)f[u][sz][ok]=Cur[sz][ok],sl[u][sz][ok]=SlCur[sz][ok];
		// cout<<"NODE "<<u<<el;
		// FOR(sz,1,2)FOR(ok,0,1)
		// {
		// 	cout<<"SZ : "<<sz<<" OK : "<<ok<<" f : "<<f[u][sz][ok]<<" sl : "<<sl[u][sz][ok]<<el;
		// }
		// cout<<res<<el;
	} 
	void xuly()
	{
		FOR(i,1,n)if(dd[i]==0&&a[i]==T)
		{
			dfs(i,0) ; 
		}
		// dfs(1,0) ;
		cout<<res*2%sm<<el;
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
        // if(n<=2e2)sub1::xuly() ;
        // else 
        	sub3::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}