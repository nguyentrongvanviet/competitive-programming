/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "FINE"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define           btpc  __builtin_popcountll
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
struct DL
{
	int st ; 
	int t ; 
} ; 
DL a[N] ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n)
	{
		cin>>a[i].st>>a[i].t ; 
	}
}
namespace sub1
{
	struct BG
	{
		int id ;
		int t ; 
	} ;
	ve<BG> start[N] ;   
	struct cmp
	{
		bool operator()(const BG&a, const BG&b)const
		{
			return a.t>b.t ;
		}
	} ; 
	priority_queue<BG,ve<BG>,cmp>q ;
	ll ans[N] ; 
	void xuly()
	{
		FOR(i,1,n)
		{
			start[a[i].st].pb({i,a[i].t}) ; 
		}
		FOR(i,1,1e5)
		{
			for(auto x : start[i])
			{
				q.push(x);
			}
			if(!q.empty())
			{
				int id = q.top().id ;
				int t = q.top().t; 
				q.pop() ;
				if(t==1)
				{
					ans[id] = i+1 ;
				}
				else
				{
					q.push({id,t-1});
				}
			}
		}
		ll res = 0 ;
		FOR(i,1,n)
		{
			res+=ans[i]-a[i].st;  
		}
		cout<<res<<el;
	}
}
namespace sub2
{
	vll V ; 
	struct BG
	{
		int id ;
		ll t;  
	} ; 
	struct cmp
	{
		bool operator()(const BG&a, const BG&b)const
		{
			return a.t>b.t; 
		}
	} ; 
	ll ans[N] ;
	ve<BG>start[N] ;
	void xuly()
	{	
		V.pb(-1) ;
		FOR(i,1,n)
		{
			V.pb(a[i].st) ; 
		}
		uni(V) ; 
		FOR(i,1,n)
		{
			a[i].st=LB(all(V),a[i].st)-V.begin();
			start[a[i].st].pb({i,a[i].t}) ; 
		}
		int len = V.size()-1 ; 
		priority_queue<BG,ve<BG>,cmp>q ; 
		V[len+1] = inf ;
		FOR(i,1,len+1)
		{	
			ll pre=V[i-1] ;  
			while(!q.empty())
			{
				int id = q.top().id ;
				int t = q.top().t ;
				q.pop() ;  
				if(pre+t<=V[i])
				{
					ans[id]=pre+t;
					pre+=t; 
				}
				else
				{
					q.push({id,t-(V[i]-pre)}) ; 
					break;
				}
			}
			for(auto x : start[i])q.push(x) ;
		}
		// prt(ans,n);
		ll res =0 ;  
		FOR(i,1,n)res+=ans[i]-V[a[i].st]; 
		cout<<res; 
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}