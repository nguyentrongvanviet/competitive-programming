/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "dfs"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k;
struct DL
{
	int val , u ; 
	bool operator<(const DL&a)const
	{
		return val>a.val ; 
	}
};
DL a[N] ; 
vi g[N] ;
void doc()
{
    cin>> n >> k;
    FOR(i,1,n)cin>>a[i].val,a[i].u= i ;  
    FOR(i,1,n-1)
    {
    	int u, v; cin>>u>>v ;
    	g[u].pb(v) ;
    	g[v].pb(u) ; 
    }   
    sort(a+1,a+n+1) ; 
}

namespace sub1
{
	int sz[N], ok[N] ;
	int sum[N] ; 
	int dd[N] ; 
	int f[N]  ;
	void dfs(int u ,int p)
	{
		sz[u] =1 ; 
		dd[u] = sum[u] = ok[u]  ; 
		for(auto v:g[u])if(v!=p)
		{
			dfs(v,u);
			sz[u]+=sz[v];  
			dd[u]+=dd[v]; 
			if(dd[v]==sz[v])sum[u]+=sz[v] ; 
		}
	}
	void solve(int u ,int p)
	{
		int ma =0 ; 
		f[u] = 1 ;
		for(auto v :g[u])if(v!=p&&ok[v])
		{
			solve(v,u) ;
			if(dd[v]!=sz[v])
			{
				maxi(ma,f[v]) ;
			} 
			else
			{
				f[u]+=sz[v] ;
			}
		}
		f[u]+=ma ; 
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		ok[a[i].u] = 1;   
			FOR(u,1,n)if(ok[u])
			{
				FOR(v,1,n)f[v] = 0 ; 
				dfs(u,0) ; 
				solve(u,0) ; 
				if(f[u]>=k)
				{
					// cout<<i<<" "<<
					cout<<a[i].val<<el; 
					return ;
				}
			}
    	}
    	cout<<"G"<<el;
    }
}
namespace subfull
{
	int sz[N] ,sum[N], dd[N],ok[N] ; 
	int f[N] ;
	int full[N] , thieu[N] ;
	void dfs(int u ,int p)
	{
		sz[u] = 1 ; 
		dd[u] = sz[u] = ok[u] ; 
		int ma =0 ; 
		for(auto v:g[u])if(v!=p)
		{
			dfs(v,u) ; 
			sz[u]+=sz[v] ;
			dd[u]+=dd[v] ;
			if(dd[v]==sz[v])
			{
				sum[u]+=sum[v] ;
				f[u]+=sum[v] ; 
			}	
			else maxi(ma,f[v]) ; 
		}
		f[u]+=ma ; 
		if(ok[u])f[u]++,sum[u]++;
		else f[u] = 0 ,sum[u]=0 ;
	}
	void solve(int u ,int p)
	{ 
		int thieu1 = 0 , thieu2 = 0; 
		for(auto v: g[u])if(v!=p)
		{
			if(thieu1<=f[v])thieu2 = thieu1 ,thieu1=f[v];
			else maxi(thieu2,f[v]) ;
		}
		if(ok[u]==0)thieu[u] = full[u] = 0 ; 
		for(auto v : g[u])if(v!=p)
		{
			full[v]=full[u]+sum[u]-(sz[v]==dd[v]?sum[v]:0); 
			thieu[v] = thieu[u]+1;
			if(f[v]==thieu1)maxi(thieu[v],thieu1) ;
			else maxi(thieu[v],thieu1) ;
			solve(v,u) ;
		}
	}	
	bool check(int id )
	{
		FOR(i,1,n)
		{
			ok[i] = f[i] = sum[i] = thieu[i] = full[i] = dd[i] = sz[i] = 0 ; 
		}
		FOR(i,1,n)ok[a[i].u] = (i<=id) ;
		dfs(1,0) ;
		// prt(ok,n) ; 
		// prt(sum,n) ; 
		// prt(sz,n) ; 
		// prt(dd,n) ; 
		solve(1,0) ;
		FOR(i,1,n)
		{
			if(f[i]+full[i]>=k||sum[i]+thieu[i]>=k||sum[i]+full[i]>=k)return 1;
		}
		return 0; 
	}
	void xuly()
	{
		int l =1 ;
		int r= n ; 
		int ans =0 ;
		while(l<=r)
		{
			int mid=(l+r)/2; 
			if(check(mid))ans=a[mid].val,r=mid-1 ;
			else l=mid+1;
		}
		cout<<ans<<el; 
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
        // subfull::xuly();
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}