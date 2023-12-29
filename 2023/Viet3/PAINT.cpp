/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PAINT"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int W , R , B , K , M ;

void doc()
{   
	cin>>W>>R>>B>>K>>M ; 
}

namespace sub1
{
	const int N = 305 ;
	int f[N*2][N][N][2] ;
	void add(int &a ,int b)
	{
		a+=b;
		if(a>=sm)a-=sm;
	}
	int dp[2][2*N][N];
	ll fac[2*N] , inv_fac[2*N] ;
	ll C(int k ,int n)
	{
		return fac[n] * inv_fac[k]%sm * inv_fac[n-k]%sm ;
	}
	ll pw(ll a,  ll n)
	{
		if(n==0)return 1 ;
		ll b = pw(a,n/2) ;
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm;
	}
    void xuly()
    {
    	FOR(i,0,R)f[0][i][0][0] = 1 ; 
    	FOR(i,0,B)f[0][0][i][1] = 1 ; 
    	FOR(cnt,1,R+B-1)
    	{		
    		FOR(i,1,R)FOR(j,1,B)
    		{
    			add(f[cnt][i][j][0],f[cnt-1][i-1][j][1]) ;
    			add(f[cnt][i][j][0],f[cnt][i-1][j][0]) ;

    			add(f[cnt][i][j][1],f[cnt-1][i][j-1][0]) ; 
    			add(f[cnt][i][j][1],f[cnt][i][j-1][1]) ;
    		}
    	}
    	dp[0][0][0] = 1 ; 
    	dp[1][0][0] = 1 ;
    	FOR(i,1,R+B+1)
    	{
    		FOR(j,0,W)
    		{
    			FOR(k,1,min(j,K-1))
    			{	
    				add(dp[0][i][j], dp[0][i-1][j-k]) ;
    				add(dp[1][i][j], dp[1][i-1][j-k]) ;
    			}
    			add(dp[0][i][j],dp[0][i-1][j]) ; 
    		}
    	}
    	fac[0] = 1;
    	FOR(i,1,600)fac[i] = fac[i-1]*i%sm; 
    	inv_fac[600] = pw(fac[600],sm-2) ; 
    	FORD(i,599,0)
    	{
    		inv_fac[i] = inv_fac[i+1]*(i+1)%sm ;
    	}
    	int res = 0 ;
    	FOR(cnt,M,R+B-1)
    	{	
    		int del = cnt-M ;
    		int tot = 0 ; 
    		FOR(j,0,W)
    		{
				int tmp = 1ll*C(del,cnt)*dp[1][del][j]%sm*dp[0][R+B+1-cnt][W-j]%sm; 
				add(tot,tmp) ;
    		}
    		add(res,1ll*tot*(f[cnt][R][B][1]+f[cnt][R][B][0])%sm);
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
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}