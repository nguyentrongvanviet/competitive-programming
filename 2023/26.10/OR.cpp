/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "OR"
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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k ,L , R ;
int a[N] ; 
	

void doc()
{
    cin>> n >> k >> L >> R; ; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
}

namespace sub12
{
	const int N =205 ;
	ll f[N][N][(1<<8)] ;
    void xuly()
    { 
    	mini(R,(1<<8)-1) ;
    	f[0][0][0]= 1 ; 
   		FOR(i,1,n)FOR(j,0,k)FORN(msk,0,Mask(8))
   		{	
   			(f[i][j][msk]+=f[i-1][j][msk])%=sm;
   			if(j<k)(f[i][j+1][msk|a[i]]+=f[i-1][j][msk])%=sm;
   		}   	
   		ll res= 0 ;
   		FOR(i,L,R)if(i%3==0)
   		{
   			(res+=f[n][k][i])%=sm;
   		}
   		cout<<res; 
    }
}
namespace sub34
{
	const int N = 1e6 + 5; 
	ll fac[N] , inv_fac[N] ;

	ll C(int k ,int n)
	{
		if(k>n)return 0 ;
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
	}
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	int f[Mask(20)+5] ;
	void xuly()
	{
		fac[0] = 1;
		FOR(i,1,n)fac[i] =fac[i-1]*i%sm; 
		inv_fac[n]=pw(fac[n],sm-2) ; 
		FORD(i,n-1,0)inv_fac[i]=inv_fac[i+1]*(i+1)%sm;
		FOR(i,1,n)f[a[i]]++;
		FORN(i,0,20)
		{
			FORN(msk,0,Mask(20))if(BIT(msk,i))
			{
				f[msk]+=f[msk^Mask(i)];
			}
		}
		FORN(msk,0,Mask(20))
		{
			f[msk]=C(k,f[msk]);
			if(btpc(msk)&1)f[msk]=(-f[msk]+sm)%sm; 
		}
		FORN(i,0,20)
		{
			FORN(msk,0,Mask(20))if(BIT(msk,i))
			{
				(f[msk]+=f[msk^Mask(i)])%=sm;
			}
		}
		ll res = 0 ;
		FOR(msk,L,R)if(msk%3==0)
		{
			if(btpc(msk)&1)(res+=(-f[msk]+sm)%sm)%=sm; 
			else (res+=(f[msk]))%=sm;
		}
		cout<<res;
	}
}
namespace sub5
{
	void xuly()
	{

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
        if(n<=200&&*max_element(a+1,a+n+1)<=200)sub12::xuly() ; 
   		else 
   		sub34::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}