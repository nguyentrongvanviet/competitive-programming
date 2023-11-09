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

bool mtt = 1 ;
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ; 
ll k ; 
ll M; 

struct MT
{
	int n,m; 
	ve<vll>mt ;
	MT(int _n ,int _m)
	{
		n=_n ;
		m=_m;  
		mt=ve<vll>(n+1,vll(m+1,0)) ; 
	}
};
MT mul(MT A , MT B)
{
	int n =A.n ;
	int m = B.m; 
	MT C(n,m) ;  
	FOR(i,1,n)FOR(j,1,m)
	{
		FOR(k,1,A.m)
		{
			(C.mt[i][j]+=A.mt[i][k]*B.mt[k][j])%=k;
		}
	}
	return C; 
} 
MT pw(MT A ,ll n)
{
	if(n==1)return A; 
	MT B = pw(A,n/2) ; 
	if(n&1)return mul(mul(B,B),A) ; 
	return mul(B,B) ; 
}
ll fib[(int)1e6+5] ;
ll s[N] ;
void doc()
{
    cin>> n >> k >> M;
    MT A(1,2) ; 
    A.mt[1][1] = A.mt[1][2] =1 ; 
    MT B(2,2) ; 	
	B.mt[1][2] = 1 ; 
	B.mt[2][1] = 1 ; 
	B.mt[2][2] = 1 ;	
	if(M==1)
	{
		fib[1] = 1 ; 
		fib[2] = 1 ; 
	}	
	else
	{
		MT TMP =mul(A,pw(B,M-1)) ;
		fib[1] = TMP.mt[1][1] ; 
		fib[2] = TMP.mt[1][2] ;  
	}
	FOR(i,3,n)
	{
		fib[i] = (fib[i-1]+fib[i-2])%k;
	}	
	map<int,int>last; 
	last[0]= 0 ; 
	FOR(i,1,n)
	{
		s[i] =(s[i-1]+fib[i])%k ;
		if(last.count(s[i]))
		{
			int pre = last[s[i]] ;
			cout<<i-pre<<el; 
			FOR(pos,pre+1,i)
			{
				cout<<pos+M-1<<" ";
			}
			cout<<el;
			return ;
		} 
		last[s[i]] = i ;
	}
}

namespace sub1
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}