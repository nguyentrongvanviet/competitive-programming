/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "Slime"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , S ;  
int a[N] ;
void doc()
{
    cin>> n >> S ;
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	int cnt[N] ;

    void xuly()
    {
    	int res = 0; 
    	FORN(i,0,n)a[i] = a[i+1] ; 
    	FORN(msk,1,1<<n)
    	{
    		bool ok  = 0 ;
    		for(int MASK = msk ; MASK ; )
    		{
    			int i = __builtin_ctz(MASK) ;
    			if(a[i]==S)
    			{
    				ok = 1; 
    				break ; 
    			}
    			int x= a[i] ; 
    			cnt[x]++ ; 
    			while(cnt[x]>=2)
    			{
    				cnt[x]-=2; 
    				x*=2 ;
    				cnt[x]++ ;
    				if(x==S)
    				{
    					ok =1 ;
    					break ; 
    				}
    			}
    			MASK^=(1<<i) ; 
    		}
    		for(int i = S;i;i/=2)cnt[i]= 0 ; 
    		res+=ok ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub3
{
	ll fac[N] , inv_fac[N] ; 
	ll pw(ll a, ll n)
	{
		if(n==0)return 1; 
		ll b = pw(a,n/2) ;
		if(n&1)return b*b%sm*a%sm; 
		return b*b%sm;
	}
	ll C(int k ,int n)
	{
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
	}
	void xuly()
	{
		int cnt = lg(S/a[1]) ; 
		if(a[1]*(1<<cnt)!=S)return void(cout<<0<<el) ;
		fac[0] = inv_fac[0] = 1 ;
		cnt=(1<<cnt) ; 
		FOR(i,1,n)
		{
			fac[i] = fac[i-1]*i%sm; 
			inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm; 
		}
		ll res = 0 ; 
		FOR(i,cnt,n)	
		{
			(res+=C(i,n))%=sm;
		}
		cout<<res<<el;
	}
}
namespace sub2
{	
	ll fac[N] , inv_fac[N]  ; 
	ll f[15][1<<14] ;
	int sl[N] ;
	int tmp = 0 ; 
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	ll C(int k ,int n)
	{
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
	}
	ll tinh(int bit, int msk)
	{
		if(bit==13)
		{
			return msk==tmp;
		}
		ll &val = f[bit][msk] ; 
		if(val!=-1)return val  ; 
		val = 0 ; 
		ll t = pw(2,sl[1<<bit]) ;
		FOR(j,0,sl[1<<bit])
		{
			int nmsk = min(tmp,j*(1<<bit)+msk) ; 
			if((j&1)&&BIT(msk,bit)==0&&nmsk!=tmp)nmsk^=(1<<bit);
			(val+=C(j,sl[1<<bit])*tinh(bit+1,nmsk)%sm)%=sm;
			(t-=C(j,sl[1<<bit])-sm)%=sm;
			if(nmsk==tmp)break;
		}
		(val+=t*tinh(bit+1,tmp))%=sm;
		return val ;	 
	}
	void xuly()
	{
		fac[0] = inv_fac[0] = 1 ; 
		FOR(i,1,n)
		{
			fac[i] = fac[i-1]*i%sm; 
			inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm; 
		}
		FOR(i,0,12)if(S%(1<<i)==0)tmp = (1<<i) ; 
		ll res = 1; 
		FOR(i,1,n)
		{	
			if(a[i]%(S/tmp)!=0||btpc(a[i]/(S/tmp))!=1)
			{
				(res*=2)%=sm; 
			}
			else sl[a[i]/(S/tmp)]++ ; 
		}
		FOR(bit,0,12)FORN(msk,0,1<<13)f[bit][msk] = -1 ; 
		(res*=tinh(0,0))%=sm ;
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
   		if(*min_element(a+1,a+n+1)==*max_element(a+1,a+n+1))
   		{
   			sub3::xuly() ; 
   		}
   		else 
   			sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}