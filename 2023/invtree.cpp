/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "invtree"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , root ;
vi g[N] ; 

void doc()
{
    cin>> n >>root; 
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int in[N] , out[N]; 
	int tt = 0 ;
	int st[N*(LO+2)+5] , H[N] ;
	int L[N*(LO+2)+5] , R[N*(LO+2)+5] ; 
	int node= 0 ; 
	int sz[N] ; 
	ll f[N] ; 
	inline int up(int old ,int l ,int r, int pos )
	{
		int cur = ++node ;
		if(l==r)
		{
			st[cur] = 1 ;
			return cur; 
		}
		int mid=(l+r)/2; 
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur] = up(L[old],l,mid,pos) ; 
		}
		else
		{
			L[cur]=  L[old] ;
			R[cur] = up(R[old],mid+1,r,pos) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur ;
	}
	inline int get(int id, int l, int r, int t,int p)
	{
		if(id==0)return 0;
		if(t<=l&&r<=p)return st[id]; 
		if(r<t||p<l)return 0 ; 
		int mid=(l+r)/2; 
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
	}
	inline void dfs(int u, int p)
	{
		in[u]=++tt; 
		for(auto v:g[u])if(v!=p)
		{
			dfs(v,u) ; 
		}
		out[u]=tt; 
	}
	inline ll count(int u ,int p ,int R)
	{
		ll ans = 0 ; 
		ans+=get(H[u],1,n,in[R],out[R]);
		for(auto v: g[u])if(v!=p)
		{
			ans+=count(v,u,R) ; 
		} 
		return ans; 
	}
	inline void solve(int u ,int p)
	{
		sz[u] = 1;  
		int Left = 0 ,Right = 0; 
		for(auto v:g[u])if(v!=p)
		{
			solve(v,u) ; 
			sz[u]+=sz[v] ;
			f[u]+=f[v];
			f[u]+=get(H[u],1,n,in[v],out[v]) ;  
			if(!Left)Left=v ; 
			else Right =v ; 
		}
		if(Left&&Right)
		{
			if(sz[Left]>sz[Right])swap(Left,Right) ;
			ll tot = 1ll*sz[Left]*sz[Right] ;
			ll tmp=count(Left,u,Right) ;
			tmp=min(tmp,tot-tmp) ; 
			f[u]+=tmp ; 
		}
	}
    inline void xuly()	
    {	
    	dfs(root,0) ; 
    	FOR(i,1,n)
    	{
    		H[i] = up(H[i-1],1,n,in[i]) ; 
    	}
    	solve(root,0) ;
    	cout<<f[root]<<el; 
    }
}
namespace subtrau
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}