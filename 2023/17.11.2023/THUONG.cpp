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
#define input "THUONG.INP"
#define output "THUONG.OUT"
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
const int N = 3e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ;
struct DL
{
	int val; 
	int pos ;  
	bool operator<(const DL&a)const
	{
		return val<a.val; 
	}
} ;
DL a[N] ;
int A[N] , b[N] ;
int dd[N] ; 
int cam[N] ;
void doc()
{   	
	cin>> n >> m ;
	FOR(i,1,n)
	{
		cin>>a[i].val; 
		a[i].pos = i; 
		A[i] = a[i].val;
	}
	FOR(i,1,m)
	{
		cin>>b[i] ; 
	}
	sort(a+1,a+n+1) ; 
	sort(b+1,b+m+1) ; 
	int it =1 ; 
	FOR(i,1,m)
	{
		while(it<=n&&a[it].val<b[i])
		{
			++it ; 
		}
		while(it<=n&&a[it].val==b[i])
		{
			dd[it] = 1 ;
			cam[a[it].pos] = 1 ; 
			++it;
		}
	}
	ll res = 0 ; 
	ll sum = 0 ;
	FOR(i,1,n)
	{
		if(dd[i])sum=0 ; 
		if(a[i].val!=a[i-1].val)
		{
			sum = a[i].val ; 
		}
		else sum+=a[i].val ; 
		maxi(res,sum) ; 
	}
	FOR(i,1,n)if(cam[i]==0)cout<<A[i]<<" ";
	cout<<el;
	cout<<res; 
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
    if(fopen(input,"r"))
    {
    	freopen(input,"r",stdin) ; 
    	freopen(output,"w",stdout) ; 
    }
    else if(fopen(INPUT,"r"))
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