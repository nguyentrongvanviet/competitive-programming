	/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "elecar"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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

int n , q ;
struct pt
{
	int x, y ;
	int id ; 
	bool operator<(const pt&a)const
	{
		return y<a.y ; 
	}
} ;
pt a[N] ; 
int dis(pt u ,pt v)
{
	return abs(u.x-v.x)+abs(u.y-v.y) ;
}
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].y ; 
    	a[i].id = i ; 
    }
}

namespace sub12
{
	struct Edge
	{
		int u ,v  ,w ;
		bool operator<(const Edge&a)const
		{
			return w<a.w ; 
		}
	} ; 
	ve<Edge>E ; 
	int pa[N] ;
	int goc(int u)
	{
		return pa[u] ==u ? u : pa[u] = goc(pa[u]) ;
	}
	bool hop(int u,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return 0 ;
		pa[chau] =chav; 
		return 1; 
	}
	struct ke
	{
		int v, w ;
	}; 
	ve<ke>g[N] ; 
	int h[N] ; 
	int P[N][LO+1] ; 
	int W[N][LO+1] ; 
	void dfs(int u ,int p)
	{
		for(auto x:g[u])
		{
			int v=x.v ;
			int w =x.w; 
			if(v==p)continue ;
			P[v][0] = u ; 
			W[v][0] =w ;
			h[v]=h[u]+1;  
			dfs(v,u) ; 
		}
	}
	int lca(int u,int v)
	{
		int res = 0 ; 
		if(h[u]<h[v])swap(u,v) ;
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			maxi(res,W[u][i]) ; 
			u=P[u][i];  
		}
		if(u==v)return res;  
		FORD(i,LO,0)
		{
			int nu  = P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				maxi(res,W[u][i]) ; 
				maxi(res,W[v][i]) ; 
				u=nu ; 
				v=nv ;
			}
		}
		maxi(res,W[u][0]) ; 
		maxi(res,W[v][0]) ;
		return res; 
	}
    void xuly()
    {
    	FOR(i,1,n)FOR(j,i+1,n)
    	{	
    		E.pb({i,j,dis(a[i],a[j])});
    	}		
    	sort(all(E));
    	FOR(i,1,n)pa[i] = i ; 
    	for(auto x:E)
    	{
    		int u =x.u ;
    		int v= x.v; 
    		int w =x.w; 
    		if(hop(u,v))
    		{
    			g[u].pb({v,w}) ; 
    			g[v].pb({u,w}) ;
    		}
    	}
    	dfs(1,0) ; 
    	FOR(j,1,LO)FOR(i,1,n)
    	{
    		P[i][j] = P[P[i][j-1]][j-1] ;
    		W[i][j] = max(W[i][j-1],W[P[i][j-1]][j-1]) ; 
    	}
    	FOR(_,1,q)
    	{
    		int u ,v ;cin>>u>>v;
    		cout<<lca(u,v)<<el;
    	}
    }	
}
bool OK3()
{
	FOR(i,1,n)
	{
		if(a[i].x)return 0; 
	}
	return 1; 
}
namespace sub3
{
	int P[N] ; 
	int st[N][LO+1];
	int get(int l, int r)
	{
		if(l>r)return 0 ;
		int k = lg(r-l+1) ; 
		return max(st[l][k],st[r-(1<<k)+1][k]); 
	}
	void xuly()
	{
		sort(a+1,a+n+1) ; 
		FOR(i,1,n)
		{
			P[a[i].id]= i; 
		}
		FOR(i,1,n)
		{
			st[i][0] = dis(a[i+1],a[i]) ; 
		}
		FOR(j,1,lg(n))FOR(i,1,n)
		{
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
		}
    	FOR(_,1,q)
		{
			int u, v; cin>>u>>v; 
			u= P[u] ; 
			v= P[v] ; 
			if(u>v)swap(u,v) ; 
			cout<<get(u,v-1)<<el;
		}
	}
}
bool OK4()
{
	FOR(i,1,n)
	{
		if(a[i].x<0||a[i].x>1)return 0; 
	}
	return 1;  
}
namespace sub4
{
	struct Edge
	{
		int u ,v  ,w ;
		bool operator<(const Edge&a)const
		{
			return w<a.w ; 
		}
	} ; 
	ve<Edge>E ; 
	int pa[N] ;
	int goc(int u)
	{
		return pa[u] ==u ? u : pa[u] = goc(pa[u]) ;
	}
	bool hop(int u,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return 0 ;
		pa[chau] =chav; 
		return 1; 
	}
	struct ke
	{
		int v, w ;
	}; 
	ve<ke>g[N] ; 	
	int h[N] ; 
	int P[N][LO+1] ; 
	int W[N][LO+1] ; 
	void dfs(int u ,int p)
	{
		for(auto x:g[u])
		{
			int v=x.v ;
			int w =x.w; 
			if(v==p)continue ;
			P[v][0] = u ; 
			W[v][0] =w ;
			h[v]=h[u]+1;  
			dfs(v,u) ; 
		}
	}
	int lca(int u,int v)
	{
		int res = 0 ; 
		if(h[u]<h[v])swap(u,v) ;
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			maxi(res,W[u][i]) ; 
			u=P[u][i];  
		}
		if(u==v)return res;  
		FORD(i,LO,0)
		{
			int nu  = P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				maxi(res,W[u][i]) ; 
				maxi(res,W[v][i]) ; 
				u=nu ; 
				v=nv ;
			}
		}
		maxi(res,W[u][0]) ; 
		maxi(res,W[v][0]) ;
		return res; 
	}
    void xuly()
    {
    	sort(a+1,a+n+1) ; 
    	int la0 = 0 ; 
    	int la1 = 0 ; 
    	FOR(i,1,n)
    	{
    		if(la0)E.pb({a[i].id,a[la0].id,dis(a[i],a[la0])});
    		if(la1)E.pb({a[i].id,a[la1].id,dis(a[i],a[la1])});
    		if(a[i].x==0)la0= i ; 
    		else la1=i; 
    	}
    	sort(all(E));
    	FOR(i,1,n)pa[i] = i ; 
    	for(auto x:E)
    	{
    		int u =x.u ;
    		int v= x.v; 
    		int w =x.w; 
    		if(hop(u,v))
    		{
    			g[u].pb({v,w}) ; 
    			g[v].pb({u,w}) ;
    		}
    	}
    	dfs(1,0) ; 
    	FOR(j,1,LO)FOR(i,1,n)
    	{
    		P[i][j] = P[P[i][j-1]][j-1] ;
    		W[i][j] = max(W[i][j-1],W[P[i][j-1]][j-1]) ; 
    	}
    	FOR(_,1,q)
    	{
    		int u ,v ;cin>>u>>v;
    		cout<<lca(u,v)<<el;
    	}
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
        if(n<=1000&&q<=1000)sub12::xuly();
        else if(OK3())
        {
        	sub3::xuly()  ; 
        } 
        else 
        if(OK4())
        {
        	sub4::xuly() ;  
        }
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}