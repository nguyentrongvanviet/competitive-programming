/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define int long long 
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
const int N = 4e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , q , k; 
ll a[N][N] ; 
void doc()
{
   	cin>> n >> m >> q >> k  ; 
   	FOR(i,1,n)FOR(j,1,m)
   	{
   		cin>>a[i][j] ; 
   	}	
}

namespace sub1
{
	ll S[N][N] ; 
	void inc(int x ,int y , int len ,int val)
	{
		int X = x-len;
		int Y = y-len; 
		int U = x+len;  
		int V = y+len; 
		assert(U<=N&&V<=N) ; 
		S[X][Y]+=val; 
		S[X][V+1]-=val;
		S[U+1][y]-=val; 
		S[U+1][V+1]+=val; 
	}
	void up(int len , int x, int y , int val)
	{
		if(len<0)return ;
		int u = x-y+2000 ; 
		int v = x+y+2000 ; 
		inc(u,v,len,val) ; 
	}
	ll cost(int x ,int y)
	{
		int u = x-y+2000 ; 
		int v = x+y+2000 ; 
		return S[u][v] ; 
	}
    void xuly()
    {
    	FOR(i,1,q)
    	{
    		int x , y ; cin>>x>>y ;
    	}
    	FOR(i,1,k)
    	{
    		int w , R , L , x, y; 
    		cin>>w>>R>>L>>x>>y ;
    		up(R,x,y,w) ; 
    		up(L-1,x,y,-w) ; 
    	}
    	FOR(i,1,4000)FOR(j,1,4000)S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
    	ll res = 0 ; 
    	FOR(i,1,n)
    	{
    		FOR(j,1,m)
	    	{
	    		ll val = cost(i,j) ;
	    		res+=min(val,a[i][j]) ; 
	    	}
	    }
    	cout<<res;
    }
}
namespace sub2
{
	int dis(int  x ,int y ,int u ,int v)
	{
		return abs(x-u)+abs(y-v) ;
	}
	int s[N][N] ; 
	int c[N][N] ; 
	void xuly()
	{
		FOR(i,1,q)
    	{
    		int x , y ; cin>>x>>y ;
    	}
    	ll res = 0; 
    	while(k--)
    	{
    		int w , R , L , x, y; 
    		cin>>w>>R>>L>>x>>y ;
    		FOR(i,1,n)FOR(j,1,m)
    		{
    			if(L<=dis(i,j,x,y)&&dis(i,j,x,y)<=R)
    			{
    				res+=min(w,a[i][j]) ;
    				c[i][j]+=w; 
    				a[i][j] = max(0ll,a[i][j]-w) ;
    			}
    		}
    	}
    	// FOR(i,1,n)
    	// {
    	// 	FOR(j,1,m)cout<<c[i][j]<<" ";
    	// 	cout<<el;
    	// }
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
        sub2::xuly() ;
        // sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}