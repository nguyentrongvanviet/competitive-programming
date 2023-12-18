/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13gcdct3"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
// #define int __int128 
// #define ll __int128 
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
// ll lg(ll a){return __lg(a);}
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
 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


ll a , b, sm ;  
struct MT
{
	int n , m; 
	ve<vll>mt ; 
	MT(int _n=0,int _m=0)
	{
		n=_n; 
		m=_m; 
		mt=ve<vll>(n+2,vll(m+2,0)) ; 
	}
};
// nhan indian
ll nhan(ll a , ll b)
{
	ll res = 0;  
	while(a)
	{
		if(a&1)(res+=b)%=sm; 
		a/=2 ;
		b=2*b%sm; 
	}
	return res ;
}
MT mul(MT A , MT B)
{
	MT ans(A.n,B.m) ; 
	FOR(i,1,A.n)FOR(j,1,B.m)FOR(k,1,A.m)
	{
		(ans.mt[i][j]+=nhan(A.mt[i][k],B.mt[k][j])%sm)%=sm;
	}
	return ans; 
}
MT pw(MT A , ll n)
{
	if(n==1)return A ; 
	MT B = pw(A,n/2) ;
	if(n&1)return mul(mul(B,B),A) ; 
	return mul(B,B) ;
}
// __int128 read() {
//     __int128 x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }
// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }
// bool cmp(__int128 x, __int128 y) { return x > y; }
void doc()
{
	// a=read() ;
	// b=read() ;
	// sm =read() ; 
	cin>>a>>b>>sm; 
	MT A(1,2) ; 
	A.mt[1][1]= 0 ; 
	A.mt[1][2]= 1 ;  	
	while(b!=0)
	{
		a%=b;
		swap(a,b) ;
	}
	if(a<=1)
	{
		// print(a) ; 
		cout<<a<<el;
	}
	else
	{
		MT B(2,2) ;
		B.mt[1][1]=0;
		B.mt[1][2]=1; 
		B.mt[2][1]=1;
		B.mt[2][2]=1 ;
		MT ans = mul(A,pw(B,a)) ;
		cout<<ans.mt[1][1]<<el;
		// print(ans.mt[1][1]) ; 

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