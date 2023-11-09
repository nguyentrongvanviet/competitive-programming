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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 4e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k ; 
struct pt
{
	int x, y ;
	bool operator<(const pt&a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	} 
}; 
pt a[N] ; 
void doc()
{	
    cin>> n >> m >> k;
    FOR(i,1,k)cin>>a[i].x>>a[i].y ; 
    a[++k] ={n,m} ;
}

namespace sub1
{
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	ll fac[N] , inv_fac[N] ;
	ll C(int k ,int n)
	{
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
	}
	ll f[N] ;
    void xuly()
    {
    	fac[0]=inv_fac[0] =1 ; 
    	FOR(i,1,N-5)fac[i]=fac[i-1]*i%sm,inv_fac[i]=inv_fac[i-1]*pw(i,sm-2)%sm;
    	sort(a+1,a+k+1);
    	FOR(i,1,k)
    	{
    		f[i] = C(a[i].x-1,a[i].x+a[i].y-2); 
    		FOR(j,1,i-1)if(a[j].x<=a[i].x&&a[j].y<=a[i].y)	
    		{
    			(f[i]-=f[j]*C(a[i].x-a[j].x,a[i].y-a[j].y+a[i].x-a[j].x)%sm-sm)%=sm;
    		}
    	}
    	cout<<f[k] ;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}