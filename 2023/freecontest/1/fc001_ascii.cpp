/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "fc001_ascii"
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
const int N = 1e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ; 
struct pt
{
	ll x ,y; 
	pt(ll _x , ll _y)
	{
		x=_x ;
		y=_y ; 
	}
	pt operator - (pt a)
	{
		return pt(x-a.x,y-a.y) ;
	}
	ll operator * (pt a )
	{
		return x*a.y-y*a.x ;
	}
} ;
ll ccw(pt a , pt b , pt c)
{
	return (b-a)*(c-b) ; 
}
char a[N][N] ;
void doc()
{
	cin>> n >> m ;
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>>a[i][j] ; 
	} 
}

namespace sub1
{
	ve<pt>P ; 
	ve<pii>g[N][N] ;
	int dd[N][N]; 
	void dfs(int x, int y)
	{
		dd[x][y]=1 ; 
		P.pb(pt(x,y)) ;
		for(auto ke:g[x][y])
		{
			int nx=ke.fi ; 
			int ny=ke.se ;
			if(dd[nx][ny]==0)
			{
				dfs(nx,ny) ;
			}
		}
	} 
	void build_polygon()
	{
		int cnt = 0; 
		int x=-oo , y= -oo ; 
		FOR(i,1,n)FOR(j,1,m)
		{
			if(a[i][j]=='/')
			{
				cnt++ ; 
				x=i-1; 
				y=j ;
				g[i-1][j].pb(mp(i,j-1)) ;
				g[i][j-1].pb(mp(i-1,j)) ; 
			}
			else if(a[i][j]!='.')
			{
				cnt++ ; 
				g[i-1][j-1].pb(mp(i,j)) ; 
				g[i][j].pb(mp(i-1,j-1)) ; 
			}
		}
		assert(x!=-oo&&y!=-oo&&cnt>=4) ; 
		dfs(x,y) ; 
		P.pb(pt(x,y)) ;	
	}
	int area(ve<pt>&P)
	{
		// for(auto [x,y]:P)cout<<x<<" "<<y<<el;
		int res = 0 ;
		FORN(i,0,SZ(P)-1)
		{
			res+=P[i]*P[i+1]; 
		}
		return res/2 ; 
	}
    void xuly()
    {
    	build_polygon() ;
    	cout<<area(P)<<el; 
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