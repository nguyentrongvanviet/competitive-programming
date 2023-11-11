/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
struct DL
{
	ll x, v ;
	bool operator<(const DL&a)const
	{
		return v<a.v||(v==a.v&&x<a.x) ;  
	}
} ; 
vll V ; 
DL a[N] ; 
void doc()
{
    cin>> n ; 
    FOR(i,1,n)cin>>a[i].x ; 
    FOR(i,1,n)cin>>a[i].v;
    FOR(i,1,n)
    {
    	V.pb(a[i].x) ; 
    }
    uni(V) ; 
    sort(a+1,a+n+1) ;  
}

namespace sub1
{
	struct treebit
	{
		vll bit; 
		treebit(int _n)
		{
			n=_n ; 
			bit=vll(n+5,0) ; 
		}
		void up(int id ,ll val)
		{
			for(int i =id;i<=n;i+=i&-i)bit[i]+=val; 
		}
		ll get(int id)
		{
			ll ans =0 ;
			for(int i =id;i;i-=i&-i)ans+=bit[i] ; 
			return ans; 
		}
		ll get(ll l , ll r)
		{
			return get(r)-get(l-1) ;
		}
	};
    void xuly()
    {
    	treebit Sum(SZ(V)) ; 
    	treebit Cnt(SZ(V)) ;
    	ll res = 0;  
    	FOR(i,1,n)
    	{
    		ll x = a[i].x ; 
    		int pos = UB(all(V),x)-V.begin() ; 
    		ll sum = Sum.get(pos) ; 
    		ll cnt = Cnt.get(pos) ; 
    		res+=cnt*x-sum;  
    		Sum.up(pos,a[i].x); 
    		Cnt.up(pos,1) ; 
    	}
    	cout<<res<<el;  
    }
}
namespace sub2
{
	void xuly()
	{
		ll res = 0; 
		FOR(i,1,n)FOR(j,i+1,n)
		{
			if((a[i].x<a[j].x&&a[i].v<=a[j].v)||(a[i].x>a[j].x&&a[i].v>=a[j].v))
			{
				res+=abs(a[i].x-a[j].x) ; 
			}
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}