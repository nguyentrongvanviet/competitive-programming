/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "fsp"
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
const int N = 8e4+5, oo = 2e9, LO = 16, CH = 26 ; 
// end of macros and constant

int n ;
struct ke
{
	int v ; 
	int w ; 
} ; 
ve<ke>g[N] ; 
void doc()
{
	cin>>n ; 
	FOR(i,1,n-1)
	{
		int u ,v , w; cin>>u>>v>>w; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w}) ;
	}
}
namespace sub1
{
	ll f[N] ; 
	int h[N] ;
	int P[N][LO+1] ; 
	ll W[N][LO+1]  ;
	void DFS(int u ,int p)
	{
		for(auto x: g[u])
		{
			int v = x.v ; 
			int w = x.w ; 
			if(v==p)continue ; 
			h[v]=h[u]+1 ;
			P[v][0] = u ;
			W[v][0] = w ; 
			DFS(v,u) ; 
		}
	}
	ll lca(int u ,int v)
	{
		ll dis = 0 ; 
		if(h[u]<h[v])swap(u,v) ; 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			dis+=W[u][i] ; 
			u = P[u][i] ; 
		}
		if(u==v)return dis;
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				dis+=W[u][i]+W[v][i] ; 
				u=nu ; 
				v=nv ; 
			}
		}
		return dis+W[u][0]+W[v][0] ; 
	}
	void xuly()
	{
		DFS(1,0) ; 
		FOR(j,1,LO)FOR(i,1,n)
		{
			P[i][j] =P[P[i][j-1]][j-1] ; 
			W[i][j] = W[i][j-1] +W[P[i][j-1]][j-1] ; 
		}
		f[1] = 0 ; 
		FOR(i,2,n)
		{
			f[i] = inf;  
			FOR(j,1,i-1)
			{
				mini(f[i],f[j]+lca(i,j)) ; 
			}
		}	
		prt(f,n) ; 
	}
}
namespace sub2
{
	int h[N] ;
	int P[N][LO+1] ; 
	ll W[N][LO+1]  ;
	int sz[N] , pa[N] ;
	void DFS(int u ,int p)
	{
		for(auto x: g[u])
		{
			int v = x.v ; 
			int w = x.w ; 
			if(v==p)continue ; 
			h[v]=h[u]+1 ;
			P[v][0] = u ;
			W[v][0] = w ; 
			DFS(v,u) ; 
		}
	}
	ll lca(int u ,int v)
	{
		ll dis = 0 ; 
		if(h[u]<h[v])swap(u,v) ; 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			dis+=W[u][i] ; 
			u = P[u][i] ; 
		}
		if(u==v)return dis;
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				dis+=W[u][i]+W[v][i] ; 
				u=nu ; 
				v=nv ; 
			}
		}
		return dis+W[u][0]+W[v][0] ; 
	}
	void dfsz(int u ,int p )
	{
		sz[u] =1 ; 
		for(auto x : g[u])
		{
			int v = x.v ;  
			if(v==p||pa[v])continue ;
			dfsz(v,u) ; 
			sz[u]+=sz[v] ;
		}	
	}
	int cen(int u ,int p ,int n )
	{
		for(auto x: g[u])
		{
			int v =x.v ; 
			if(v==p||pa[v])continue ; 
			if(sz[v]>n/2)return cen(v,u,n) ; 
		}
		return u ; 
	}
	int pos[N] ; 
	struct DL
	{
		int u ; 
		ll val ; 
	}; 
	struct cmp
	{
		bool operator()(const DL&a,const DL&b)const
		{
			return a.val>b.val||(a.val==b.val&&a.u<b.u); 
		}
	} ; 
	set<DL,cmp>S[N] ; 
	ll Val[N] ;
	void build(int u )
	{
		for(auto x: g[u])
		{
			int v = x.v ; if(pa[v])continue ;  
			
			dfsz(v,u) ; 
			int c= cen(v,u,sz[v]) ;
			pa[c] = u ; 		
			// cout<<u<<" "<<c<<el;
			S[u].insert({c,Val[c]=inf});
			
			build(c) ; 
		}
	}	
	ll f[N] ;
	void up(int u)
	{
		for(int son = u , v = pa[u]; v!=-1;son=v,v=pa[v])
		{
			ll dis_u_v = f[u]+lca(u,v) ; 
			if(Val[son]>dis_u_v)
			{
				S[v].erase({son,Val[son]});
				S[v].insert({son,Val[son]=dis_u_v});
			}
		}
	}
	ll get(int u)
	{
		ll res= (S[u].empty()?inf:(*S[u].rbegin()).val);
		for(int son = u , v = pa[u];v!=-1;son=v,v=pa[v])
		{
			ll dis = lca(u,v) ;

			mini(res,f[v]+dis);
			if(S[v].size())
			{
				int c = (*S[v].rbegin()).u; 
				ll val = (*S[v].rbegin()).val ; 
				if(c!=son)
				{
					mini(res,val+dis) ; 
				}	
				else if(S[v].size()>=2)
				{
					auto x = S[v].rbegin() ; 
					x++;
					ll val = (*x).val ; 
					mini(res,val+dis) ;
				}
			}
		}
		return res ; 
	}
	void xuly()
	{		
		DFS(1,0) ;
		FOR(j,1,LO)FOR(i,1,n)
		{
			P[i][j] = P[P[i][j-1]][j-1] ;
			W[i][j] = W[i][j-1] + W[P[i][j-1]][j-1] ; 
		} 
		dfsz(1,0) ;
		int c= cen(1,0,n) ; 
		pa[c] = -1 ; 
		build(c) ; 
		FOR(i,1,n)f[i] = inf ;
		f[1] = 0 ;
		up(1) ;
		
		FOR(i,2,n)
		{
			// FOR(j,1,n)
			// {
			// 	cout<<"Node: "<<j<<el;
			// 	for(auto x : S[j])
			// 	{
			// 		cout<<x.u<<" "<<x.val<<el;
			// 	}
			// }
			// cout<<"___"<<el;
			f[i]=get(i); 
			up(i) ; 
		}
		prt(f,n) ; 
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
       	// if(n<=1000)
       		// sub1::xuly() ;
       	// else 
       		sub2::xuly() ;  
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}