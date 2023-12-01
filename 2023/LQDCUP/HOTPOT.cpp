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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k; 
struct ke
{
	int v ,w ; 
} ; 
ve<ke>g[N] ;
void doc()
{
	cin>> n >> k; 
	FOR(i,1,n-1)
	{
		int u ,v , w; 
		cin>> u >> v >>w ; 
		g[u].pb({v,w}) ;
		g[v].pb({u,w}) ; 
	}
}

namespace sub1
{
	int P[N][LO+2]; 
	int MA[N][LO+2] ; 
	int h[N] ; 
	void dfs(int u ,int p)
	{
		for(auto [v,w]: g[u])if(v!=p)
		{
			P[v][0] = u ;
			MA[v][0] = w ; 
			h[v] = h[u]+1 ;
			dfs(v,u) ; 
		}
	}
	bool check(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ; 
		int dis = 0; 
		int ma = 0 ; 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			maxi(ma,MA[u][i]) ; 
			dis+=(1<<i) ; 
			u=P[u][i] ; 
		}
		if(u==v)return ma>=dis ;
		FORD(i,LO,0)
		{
			int nu =P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				maxi(ma,MA[u][i]) ;
				maxi(ma,MA[v][i]) ; 
				dis+=(1<<(i+1)) ; 
				u=nu ; 
				v=nv ;
			}
		}
		maxi(ma,MA[u][0]) ; 
		maxi(ma,MA[v][0]) ; 
		dis+=2 ;
		return ma>=dis; 
	}
    void xuly()
    {
        dfs(1,0) ;
        FOR(j,1,LO)FOR(i,1,n)
        {
        	P[i][j]=P[P[i][j-1]][j-1] ; 
        	MA[i][j]=max(MA[i][j-1],MA[P[i][j-1]][j-1]) ;
        }
        int res = 0;
        FOR(i,1,n)FOR(j,1,n)if(i!=j)
        {
        	res+=check(i,j) ; 
        }
        cout<<res<<el;
    }
}
namespace sub2
{
	struct DL
	{
		int len , ma; 
		bool operator<(const DL&a)const
		{
			return ma>a.ma ;
		}
	} ; 
	DL a[N] ;
	ll res = 0 ; 
	void build(int u,int p  ,int ma , int h )
	{
		a[u]={h,ma};
		for(auto [v,w]:g[u])if(v!=p&&dd[v]==0)
		{
			build(v,u,max(ma,w),h+1) ;
		}
	}
	int bit[N] ;
	void up(int idx, int val)
	{
	    for(int i=idx;i;i-=i&-i)bit[i]+=val;
	}
	int get(int idx )
	{
	    int ans =0 ; 
	    for(int i=idx;i<=n+1;i+=i&-i)ans+=bit[i] ;
	    return ans ;
	} 
	ve<DL>V ;
	void add(int u ,int p )
	{
		V.pb(a[u]) ; 
		for(auto [v,w]:g[u])if(dd[v]==0&&v!=p)
		{
			add(v,u) ; 
		}
	}
	void cal(int u ,int sign)
	{
		V.clear() ; 
		add(u,0) ; 
		sort(all(V)) ; 
		for(auto [len,ma]:V)
		{
			res+=sign*get(len+1);
			if(ma-len-k>=0)up(min(n+1,ma-len-k+1),1) ; 
		}
		for(auto [len,ma]:V)
		{
			if(ma-len-k>=0)up(min(n+1,ma-len-k+1),-1) ; 
		}
	}
	int sz[N] , dd[N] ;

	void dfsz(int u ,int p)
	{
		sz[u] =1 ; 
		for(auto [v,w]:g[u])if(v!=p&&dd[v]==0)
		{
			dfsz(v,u) ;
			sz[u]+=sz[v] ; 
		}
	}
	int cen(int u ,int p ,int n)
	{
		for(auto [v,w]:g[u])if(v!=p&&dd[v]==0)
		{
			if(sz[v]>n/2)return cen(v,u,n) ; 
		}
		return u ;
	}
	void solve(int u) 
	{
		dd[u] = 1 ;
		build(u,0,0,0) ;
		cal(u,1) ; 
		for(auto [v,w]:g[u])if(dd[v]==0)cal(v,-1) ;  
		for(auto [v,w]:g[u])if(dd[v]==0)
		{
			dfsz(v,u); 
			solve(cen(v,u,sz[v])) ; 
		}
	}
	void xuly()
	{
		dfsz(1,0) ; 
		solve(cen(1,0,n)) ; 
		cout<<res*2; 
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
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}