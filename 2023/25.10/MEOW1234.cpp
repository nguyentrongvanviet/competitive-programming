/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "MEOW1234"
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
#define          SZ(s_)  (int)(_.size())
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
struct pt 
{
	int x ,y; 
	bool operator<(const pt&a)const
	{
		return y<a.y||(y==a.y&&x<a.x) ; 
	}
} ; 
pt a[N] ;
int TYPE ;
void doc()
{
    cin>> n >>TYPE ; 
    FOR(i,1,n)cin>>a[i].x>>a[i].y ; 
}

namespace sub1
{
	ll res = 0 ; 
	ll way = 1 ; 
    ll pw(ll a, ll n )
    {
    	if(n==0)return 1; 
    	ll b = pw(a,n/2) ;
    	if(n&1)return b*b%sm*a%sm; 
    	return b*b%sm; 
    }
    ll fac[N] , inv_fac[N] ;
    ll C(int k ,int n)
    {
    	return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
    }
    int miL[N] , maR[N] ;
    int H[N] ; 
    int R[N] , L[N] ; 
    void xuly()
    {
    	fac[0] = 1; 
    	FOR(i,1,2e5)fac[i] = fac[i-1]*i%sm; 
    	inv_fac[(int)2e5]=pw(fac[(int)2e5],sm-2) ; 
    	FORD(i,(int)2e5-1,0)inv_fac[i] =inv_fac[i+1]*(i+1)%sm;
	    sort(a+1,a+n+1) ; 
	    a[0].y = -oo;  
	    int col = 0 ; 
	    FOR(i,1,n)
	    {
	    	if(a[i].y==a[i-1].y)
	    	{
	    		R[col] = a[i].x ;
	    	}
	    	else
	    	{
	    		++col ; 
	    		H[col] = a[i].y ; 
	    		L[col] = R[col] = a[i].x ; 
	    	}
	    }
	    miL[col+1] = oo ; 
	    maR[col+1] = 0 ; 
	  	FORD(i,col,1)
	  	{
	  		miL[i] = min(miL[i+1],L[i]) ; 
	  		maR[i] = max(maR[i+1],R[i]) ;
	  	}
	  	int l = oo ; 
	  	int r = 0 ;
	    FOR(i,1,col)
	    {	
	    	mini(l,L[i]) ;
	    	maxi(r,R[i]) ; 
	    	res+=r-l+1 ; 
	    	// cout<<l<<" "<<r<<" "<<way<<" "<<res<<el;
	    	if(i==col)break; 
	    	int MIL = miL[i+1] ;
	    	int MAR = maR[i+1] ; 
	    	if(r<MIL)
	    	{	
	    		res+=MIL-r+H[i+1]-H[i]-1 ;
	    		(way*=C(MIL-r,MIL-r+H[i+1]-H[i]))%=sm;
	    		r= 0 ; 
	    		l=MIL ; 
	    	}	
	    	else if(l>MAR)
	    	{
	    		res+=l-MAR+H[i+1]-H[i]-1 ; 
	    		(way*=C(l-MAR,l-MAR+H[i+1]-H[i]))%=sm;
	    		l = oo ; 
	    		r= MAR ; 
	    	}	
	    	else
	    	{

	    		res+=1ll*(min(MAR,r)-max(MIL,l)+1)*(H[i+1]-H[i]-1) ;
	    		maxi(l,MIL) ; 
	    		mini(r,MAR) ;
	    	}
	    }
	    cout<<res<<" "; 
	    if(TYPE)cout<<way<<el;
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