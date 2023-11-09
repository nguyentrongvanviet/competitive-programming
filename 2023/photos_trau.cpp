/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "photos"
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
#define fi first 
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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 1e4+5 , oo = 2e9 , LO = 29 , CH = 26 ; 

int n , k; 
int a[N] ; 
void doc()
{
    cin>>n >> k ; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
}

namespace sub1
{
	int T[N*(LO+3)][2] ;
	int cnt[N*LO][LO+2] ; 
	int f[N*LO] ; 
	int node= 1; 
	void up(int val)
	{
		int r= 1 ;
		FORD(i,LO,0)
		{
			int j = BIT(val,i) ; 
			if(!T[r][j])T[r][j]=++node; 
			r=T[r][j] ; 
			FOR(x,0,LO)cnt[r][x]+=BIT(val,x) ;
			f[r]++ ; 
		}
	}
	pll operator +(pll a , pll b)
	{
		return mp(a.fi+b.fi,(a.se+b.se)%sm) ; 
	}
	pll get(int X ,int val)
	{
		int r = 1 ; 
		pll ans={0,0};
		FORD(i,LO,0)
		{
			int j =BIT(X,i) ; 
	 		int c = BIT(val,i) ;
			if(c==0)
			{	
				int sl = f[T[r][j^1]];
				FOR(x,0,LO)
				{
					if(BIT(X,x))(ans.se+=1ll*(1<<x)*(sl-cnt[T[r][j^1]][x])%sm)%=sm ;
					else (ans.se+=1ll*(1<<x)*cnt[T[r][j^1]][x]%sm)%=sm;
				}
				ans.fi+=f[T[r][j^1]] ;
				r=T[r][j] ; 
			}
			else
			{	
				r=T[r][j^1] ; 
			}
		}
		int sl = f[r];  
		FOR(x,0,LO)
		{
			if(BIT(X,x))(ans.se+=1ll*(1<<x)*(sl-cnt[r][x])%sm)%=sm ;
			else (ans.se+=1ll*(1<<x)*cnt[r][x]%sm)%=sm;
		}
		ans.fi+=f[r] ;
		return ans ; 
	}
	bool check(int val)
	{
		ll tmp = 0 ; 
		FOR(i,1,n)
		{
			tmp+=get(a[i],val).fi ;
			if(tmp>=k)return 1;  
		}
		return 0; 
	}
	pll count(int val)
	{
		pll res = {0,0} ; 
		FOR(i,1,n)
		{
			res=res+get(a[i],val) ;
		}
		if(val==0)res.fi-=n;  
		res.fi/=2,res.se/=2; 
		return res;  
	}
    void xuly()
    {	
    	FOR(i,1,n)up(a[i]) ; 
    	int l= 0; 
    	int r = (1<<(LO+1))-1 ; 
    	int ans = -1 ;
    	while(l<=r)
    	{
    		int mid =(l+r)/2 ; 
    		if(check(mid))ans=mid , l=mid+1 ;
    		else r = mid-1 ;
    	}
    	pll res = count(ans) ; 
    	cout<<res.se-(res.fi-k)*ans<<el;
    }
}
namespace subtrau
{
	void xuly()
	{
		vi val; 
		FOR(i,1,n)
		{
			FOR(j,i+1,n)
			{
				val.pb(a[i]^a[j]) ;
			}
		}
		sort(all(val),greater<int>()) ; 
		// prv(val);
		ll res =0 ; 
		FORN(i,0,k)(res+=val[i])%=sm ; 
		cout<<res ;
		// cout<<val[k-1]<<el;
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
        subtrau::xuly() ;
        // sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}