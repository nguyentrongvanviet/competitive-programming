/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "trie"
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
const int N = 20+1 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ;
int A[N] , B[N] ; 
void doc()
{
    cin>> n  ;  
    FORN(i,0,n)
    {
    	str S ; cin>>S ; 
    	for(auto c : S)
    	{
    		A[i]+=(c=='a') ; 
    		B[i]+=(c=='b') ; 
    	}
    }
}	

namespace sub1
{
	const int N =1e3+5 ;
	int f[N][N] ; 
    void xuly()
    {
    	FOR(i,0,1000)
    	{
    		FOR(j,0,1000)
    		{
    			f[i][j] = 1; 
    			if(i)(f[i][j]+=f[i-1][j])%=sm ; 
    			if(j)(f[i][j]+=f[i][j-1])%=sm ;
    		}
    	}
    	ll res = 0 ;
    	FORN(msk,1,1<<n)
    	{
    		int miA = oo , miB = oo  ; 

    		for(int MSK = msk ; MSK ;)
    		{
    			int i = __builtin_ctz(MSK) ; 
    			mini(miA,A[i]) ;
    			mini(miB,B[i]) ;
    			MSK^=(1<<i); 
    		}
    		if(btpc(msk)&1)(res+=f[miA][miB])%=sm ;
    		else (res-=f[miA][miB]-sm)%=sm;
    	}
    	cout<<res;
    }
}
namespace sub2
{
	ll fac[(int)1e5+5] ,inv_fac[(int)1e5+5] ; 
	ll pw(ll a ,ll n)
	{
		if(n==0)return 1 ;
		ll b = pw(a,n/2) ;
		if(n&1)return b*b%sm*a%sm; 
		return b*b%sm; 
	}
	ll C(int k ,int n)
	{
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm ; 
	}
	void xuly()
	{
		fac[0] =  inv_fac[0] = 1 ; 
		FOR(i,1,1e5)
		{
			fac[i] = fac[i-1]*i%sm; 
			inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm ;
		}
		ll res = 0 ;
		FORN(msk,1,1<<n)
		{
			int miA= oo , miB = oo ; 
			for(int MSK=msk;MSK;)
			{
				int i = __builtin_ctz(MSK) ; 
				mini(miA,A[i]) ; 
				mini(miB,B[i]) ; 
				MSK^=(1<<i) ; 
			}
			if(btpc(msk)&1)(res+=C(miA+1,miB+miA+2)-1)%=sm ; 
			else (res-=C(miA+1,miB+miA+2)-1-sm)%=sm ;
		}	
		cout<<res;
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
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}