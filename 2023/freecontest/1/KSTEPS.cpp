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


int n , m , S , T ;
ll len; 

// matrix multiplication count path length k 
void doc()
{
	cin>> n >> S >> T >> len ; 
}

namespace sub1
{
	struct MT
	{
	    int n , m; 
	    ve<vll> mt ; 
	    MT(int _n ,int _m)
	    {
	        n = _n ;
	        m = _m ; 
	        mt=ve<vll>(n+1,vll(m+1,0)); 
	    }
	};
	MT mul(MT A , MT B )
	{   
	    int n = A.n ;
	    int m = B.m ; 
	    MT ans(n,m) ; 
	    FOR(i,1,n)
	        FOR(j,1,m)
	            FOR(k,1,A.m)
	                ans.mt[i][j]=(ans.mt[i][j]+A.mt[i][k]*B.mt[k][j]%sm)%sm;
	    return ans ;
	}
	MT pw(MT A , ll n)
	{
	    if(n==1)return A ; 
	    MT B = pw(A,n/2) ;
	    if(n&1)return mul(mul(B,B),A) ; 
	    return mul(B,B) ; 
	}
	// struct MT
	// {
	// 	int n ,m ;
	// 	ve<vll>mt ;  
	// 	MT(int _n=0 ,int _m=0)
	// 	{
	// 		n=_n ; 
	// 		m=_m ; 	
	// 		mt=ve<vll>(n+1,vll(m+1,0))  ;
	// 	}
	// } ;
	// MT mul(MT A , MT B)
	// {
	// 	int n = A.n ;
	// 	int m = B.m ;
	// 	MT C(n,m) ; 
	// 	FOR(i,1,n)FOR(j,1,m)
	// 	{
	// 		FOR(k,1,A.m)
	// 		{
	// 			(C.mt[i][j]+=A.mt[i][k]*B.mt[k][j]%sm)%=sm; 
	// 		}
	// 	}

	// 	return C ;
	// }
	// MT pw(MT A , int n)
	// {
	// 	if(n==1)return A ; 
	// 	MT B = pw(A,n/2) ;
	// 	if(n&1)return mul(mul(B,B),A) ;
	// 	return mul(B,B) ; 
	// }
    void xuly()
    {
    	MT A(1,n) ;
    	A.mt[1][S] = 1 ;
    	MT B(n,n) ;  
		FOR(i,1,n)FOR(j,1,n)
		{
			cin>>B.mt[i][j] ; 
		}
		cout<<mul(A,pw(B,len)).mt[1][T]<<el;
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