/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TRAVEL"
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

struct ke
{
	int v , id ;
} ;
ve<ke>g[N] ;
int n , m , K ; 

void doc()
{
    cin>> n >>m >> K ;
    FOR(i,1,m)
    {
    	int u ,v; cin>>u >> v ;
    	g[u].pb({v,i}) ; 
    	g[v].pb({u,i}) ; 
    }
}

namespace sub1
{
	stack<int>st;
	int id[N] , low[N] , tp[N] ,SZ[N]  ; 
	int tplt = 0 , tt = 0 ; 
	vi adj[N] ;
	int dd[N],sz[N]; 
	void tarjan(int u ,int p)
	{
		id[u] = low[u] = ++tt; 
		st.push(u) ;
		for(auto [v,ID] :g[u])if(ID!=p)
		{
			if(id[v])mini(low[u],id[v]);
			else tarjan(v,ID),mini(low[u],low[v]); 
		}
		if(id[u]==low[u])
		{
			int t;
			++tplt ;  
			do
			{	
				t=st.top() ;
				st.pop() ; 
				SZ[tplt]++ ;
				tp[t] = tplt ;  
			}while(t!=u) ; 
		}
	}
	void dfsz(int u ,int p)
	{
		sz[u] = 1;
		for(auto v:adj[u])if(dd[v]==0&&v!=p)
		{
			dfsz(v,u) ;
			sz[u]+=sz[v] ;
		}
	}
	struct treebit
	{
		int n ;
		int tot = 0 ;
		vi bit;  
		void init(int _n)
		{
			n = _n ; 
			bit.resize(n+1,0) ; 
		}
		void up(int id, int val)
		{
			tot+=val; 
			for(int i=id;i<=n;i+=i&-i)bit[i]+=val;
		}
		int get(int id)
		{
			int ans = 0 ; 
			for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
			return ans; 
		}
	}Bit; 
	int cen(int u ,int p ,int n)
	{
		for(auto v:adj[u])if(v!=p&&dd[v]==0)
		{
			if(sz[v]>n/2)return cen(v,u,n) ; 
		}
		return u ;
	}
	ve<pii>TOT , tmp ;
	void DFS(int u ,int p ,int h)
	{	
		tmp.pb({SZ[u],h});
		for(auto v:adj[u])if(v!=p&&dd[v]==0)
		{
			DFS(v,u,h+1) ; 
		}
	}
	ll res =0 ; 

	void solve(int u )
	{
		dd[u] =1 ;
		for(auto v:adj[u])if(dd[v]==0)
		{
			tmp.clear();
			DFS(v,u,1) ; 
			for(auto [cnt,h] : tmp)
			{
				if(h>=K)res+=1ll*cnt*SZ[u];
				int cl =K-h ;
				maxi(cl,1) ; 
				res+=cnt*(Bit.tot-Bit.get(cl-1));
			}	
			for(auto [cnt,h] : tmp)
			{
				Bit.up(min(K,h),cnt);
				TOT.pb({cnt,h}) ;
			}
		}
		// cout<<u<<" "<<res<<el;
		for(auto [cnt,h]:TOT)Bit.up(min(K,h),-cnt) ;
		TOT.clear();
		for(auto v:adj[u])if(dd[v]==0)
		{
			dfsz(v,u) ; 
			int  c= cen(v,u,sz[v]) ;
			solve(c) ; 
		}
	}
    void xuly()
    {
    	tarjan(1,0) ;
    	FOR(u,1,n)
    	{
    		for(auto [v,id]:g[u])
    		{
    			int tu = tp[u] ; 
    			int tv = tp[v] ; 
    			if(tu!=tv)
    			{
    				adj[tu].pb(tv) ; 
    			}
    		}
    	}
    	if(K>tplt-1)return void(cout<<0<<el);
    	Bit.init(tplt) ; 
    	dfsz(1,0) ;
    	solve(cen(1,0,tplt));
    	// prt(SZ,tplt) ;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}