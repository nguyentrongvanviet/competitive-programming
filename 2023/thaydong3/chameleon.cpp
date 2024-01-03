/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "chameleon"
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
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
vi g[N] ; 
ll A , B , C; 
struct Edge
{
	int u ,v ; 
}E[N] ;
void doc()
{
	cin>> n >> m >>A>>B>>C;
	FOR(i,1,m)
	{
		int u , v ; cin>> u >>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
		E[i] = {u,v} ;
	}
}

namespace sub1
{
	ll res = 0 ; 
	int dd[N] ; 
	bool dfs(int u ,int need ,int camu ,int camv)
	{
		if(u==need)return 1; 
		dd[u] = 1 ;
		for(auto v:g[u])if(!(u==camu&&v==camv)&&!(u==camv&&v==camu))
		{
			if(dd[v]==0)
			{
				if(dfs(v,need,camu,camv))return 1; 
			}
		}
		return 0; 
	}
	bool cal(int u ,int need ,int cam)
	{
		if(u==need)return 1; 
		dd[u] = 1 ;
		for(auto v:g[u])if(v!=cam)
		{
			if(dd[v]==0)
			{
				if(cal(v,need,cam))return 1; 
			}
		}
		return 0; 

	}
	void solve(int u ,int v)
	{
		int spec_edge = 0 ; 
		FOR(i,1,m)
		{
			spec_edge+=(dfs(u,v,E[i].u,E[i].v)==0) ;
			FOR(x,1,n)dd[x]=0; 
		}
		int spec_node = 2;
		FOR(i,1,n)if(i!=u&&i!=v)
		{
			spec_node+=(cal(u,v,i)==0);
			FOR(x,1,n)dd[x]=0; 
		}
		if(C==1)(res+=(spec_edge*A%sm+spec_node*B%sm)%sm)%=sm;
		else (res+=sq(spec_edge*A%sm+spec_node*B%sm)%sm)%=sm;
	}
    void xuly()
    { 
    	FOR(i,1,n)FOR(j,i+1,n)
    	{
    		solve(i,j) ; 
    	}
    	cout<<res<<el;
    }
}
int id[N] , low[N] , sz[N] , tp[N] ;
stack<int>st;
int tt = 0 , tplt = 0; 	
void dfs(int u ,int p)
{
	id[u] = low[u] = ++tt; 
	st.push(u) ;
	for(auto v:g[u])if(v!=p)
	{
		if(id[v])mini(low[u],id[v]) ;
		else dfs(v,u) , mini(low[u],low[v]) ;
	}		
	if(id[u]==low[u])
	{
		++tplt; 
		int t; 
		do
		{
			t=st.top() ;
			st.pop() ; 
			tp[t] = tplt; 
			sz[tplt]++;
		}while(t!=u) ;	
	}
}
vi adj[N] ;
void TARJAN()
{
	dfs(1,0) ;
	FOR(u,1,n)
	{
		for(auto v:g[u])
		{
			if(tp[u]!=tp[v])adj[tp[u]].pb(tp[v]) ; 
		}
	}
	FOR(i,1,tplt)uni(adj[i]);
}
namespace sub4
{
	int sub_sz[N] ;
	void cal(int u ,int p)
	{
		sub_sz[u]=sz[u] ;
		for(auto v:adj[u])if(v!=p)
		{
			cal(v,u) ;
			sub_sz[u]+=sub_sz[v] ;
		}
	} 
	void xuly()
	{	
		TARJAN() ; 
		cal(1,0) ;
		ll res = 0; 
		FOR(i,1,tplt)(res+=1ll*sub_sz[i]*(n-sub_sz[i])%sm)%=sm;
		cout<<res*A%sm<<el;
	}
}
namespace sub5
{
	int sub_sz[N] ; 
	int dd[N] ;
	void cal_sz(int u ,int p)
	{
		sub_sz[u] = 1 ; 
		for(auto v:adj[u])if(v!=p&&dd[v]==0)
		{
			cal_sz(v,u) ;
			sub_sz[u]+=sub_sz[v] ; 
		}
	}
	int cen(int u ,int p ,int n)
	{
		for(auto v:adj[u])if(v!=p&&dd[v]==0)
		{
			if(sub_sz[v]>n/2)return cen(v,u,n) ;
		}
		return u ;
	}
	ve<pll>V ;
	void cal(int u ,int p,int h)
	{
		V.pb(mp(sz[u],h)) ; 
		for(auto v:adj[u])if(v!=p&&dd[v]==0)
		{
			cal(v,u,h+1) ;
		}
	}
	ll res = 0 ;
	void add(ll &a , ll b)
	{
		a+=b;
		if(a>=sm)a-=sm;
	} 
	void solve(int u )
	{
		dd[u] = 1;
		ll sz_d2 = 0 , sz_ = sz[u]%sm , sz_d = 0 ;    
		for(auto v:adj[u])if(dd[v]==0)
		{
			cal(v,u,1) ; 
			for(auto x : V)
			{
				ll sz = x.fi ;
				ll d  = x.se;
				add(res,sz%sm*sq(d)%sm*sz_%sm); 
				add(res,sz%sm*sz_d2%sm);
				add(res,2*sz%sm*d%sm*sz_d%sm) ;
			}
			for(auto x : V)
			{	
				ll sz = x.fi ;
				ll d  = x.se ;
				add(sz_,sz%sm) ;
				add(sz_d2,sz%sm*sq(d)%sm);
				add(sz_d,sz*d%sm) ;
			}
			V.clear() ;
		}
		for(auto v : adj[u])if(dd[v]==0)
		{
			cal_sz(v,0) ; 
			solve(cen(v,0,sub_sz[v])) ; 
		}
	}
	void xuly()
	{
		TARJAN() ; 
		cal_sz(1,0) ; 
		solve(cen(1,0,sub_sz[1])) ; 
		cout<<res*(sq(A)%sm)%sm<<el;
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

        	if(n<=100)sub1::xuly() ; 
        else 
        	if(B==0&&C==1)sub4::xuly() ;
        else 
        	 if(B==0&&C==2)sub5::xuly() ; 
        else 
        	abort() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}