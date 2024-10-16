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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 4e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n; 
struct range
{
	int l ,r ; 
	range(int _l= 0 ,int _r = 0 )
	{
		l = _l ;
		r = _r ;
	} 
} ; 
range a[N] ; 
void doc()
{
    cin>> n; 
    for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r ; 
}

namespace sub1
{
	vi V ; 
	int in[N] , out[N] ; 
	struct DL
	{
		int l,id;  
	} ; 
	ve<DL>Q[N] ;
	struct fenwick
	{
		vi bit ;
		int n  ; 
		fenwick(int _n = 0 )
		{
			n = _n ; 
			bit.resize(n+1,0) ; 
		}
		void up(int id ,int val)
		{
			for(int i=id;i<=n;i+=i&-i)bit[i]+=val; 
		}
		int get(int id)
		{
			int ans = 0 ;
			for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
			return ans ;
		}
		int get(int l ,int r)
		{
			l = max(l,1) ; 
			return get(r) - get(l-1) ; 
		}
	} ; 
	void solve1()
	{
		int m = V.size() ; 
		fenwick bit(m) ; 
		for(int i=1;i<=n;i++)
		{
			Q[a[i].r].push_back({a[i].l,i}) ;
		}	
		for(int i=1;i<=m;i++)
		{
			for(auto [l,id] : Q[i])
			{
				bit.up(l,1) ; 
			}
			for(auto [l,id]:Q[i])
			{
				in[id]=bit.get(l,i) ; 
			}
		}	
	}
	void solve2()
	{
		int m = V.size() ; 
		fenwick bit(m) ;
		for(int i=m;i>=1;i--)
		{
			for(auto [l,id]:Q[i])
			{
				bit.up(l,1) ; 
			}
			for(auto [l,id]:Q[i])
			{
				out[id]=bit.get(1,l) ; 
			}
		}
	}
    void xuly()
    {
    	for(int i=1;i<=n;i++)
    	{
    		V.pb(a[i].l) ; 
    		V.pb(a[i].r) ; 
    	}
    	sort(all(V)) ; 
    	uni(V) ;
    	for(int i=1;i<=n;i++)
    	{
    		a[i].l = UB(all(V),a[i].l)-V.begin() ; 
    		a[i].r = UB(all(V),a[i].r)-V.begin() ; 
    	} 
    	solve1() ; 
    	solve2() ; 
    	for(int i=1;i<=n;i++)cout<<in[i]-1<<" ";
    	cout<<'\n';
   		for(int i=1;i<=n;i++)cout<<out[i]-1<<" ";
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