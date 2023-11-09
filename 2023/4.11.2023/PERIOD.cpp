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
const int N = 5e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
ll DELTA ; 
ll p , q , m; 
ll a[N] ;
void doc()
{
    cin>> n >>DELTA ;
    cin>>p>>q>> m; 
}

namespace sub1
{
	int s[N] ; 
	bool check(ll val)
	{
		FOR(i,1,n)s[i] = 0; 
		ll prel = 1 ; 
		ll prer = n; 
		FOR(i,1,n)
		{
			ll cl = val-a[i];
			if(cl<0)return 0  ;
			ll dis = cl/DELTA ;  
			ll l = i-dis+1; 
			if(l<=0ll)
			{
				l=l+n; 
				maxi(l,1ll*i+1);
			}
			ll r = i ;
			if(l<=r)
			{
				if(prer<l||r<prel)return 0;  
				maxi(prel,l) ; 
				mini(prer,r) ;
				s[l]++ ; 
				s[r+1]-- ;
			}
			else
			{ 
				s[l]++ ; 
				s[1]++ ;
				s[r+1]--;
			}
		}
		FOR(i,1,n)
		{
			s[i]+=s[i-1];
			if(s[i]==n)return 1; 
		}
		return 0; 
	} 
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		a[i] = ((p*i) % m + q);
    	}
    	ll l = 1; 
    	ll r = DELTA*n+2e9; 
    	ll ans = -1 ; 
    	while(l<=r)
    	{
    		ll mid=(l+r)/2;
    		if(check(mid))ans=mid,r=mid-1; 
    		else l=mid+1 ;
    	}
    	cout<<ans;
    }
}
namespace sub2
{
	ll a[N] ,b[2*N] ; 
	void xuly()
	{
		FOR(i,1,n)
		{
    		a[i] = ((p*i) % m + q);
		}
		FOR(i,1,n)
		{
			b[i] = a[i]+DELTA*i;
		}
		FOR(i,n+1,2*n)b[i] = a[i-n]+DELTA*i ;
		deque<ll>q ; 
		ll res = inf;
		FOR(i,1,2*n)
		{
			while(!q.empty()&&q.front()<i-n+1)q.pop_front() ; 
			while(!q.empty()&&b[q.back()]<b[i])q.pop_back() ; 
			q.push_back(i) ; 
			if(i>=n)
			{
				mini(res,b[q.front()]-DELTA*(i-n)) ; 
			}
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly();  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}