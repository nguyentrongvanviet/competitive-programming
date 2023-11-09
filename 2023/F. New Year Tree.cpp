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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e6+5 , oo = 2e9 , LO = 19 , CH = 26 ; 

int n ,q ; 
vi g[N] ; 
int Q[N] ; 
void doc()
{
	cin>>q ;
	n = 4 ; 
	FOR(i,2,4)g[1].pb(i) ,g[i].pb(1); 
	FOR(i,1,q)
	{
		cin>>Q[i] ; 
		FOR(j,1,2)
		{
			n++ ;
			g[n].pb(Q[i]) ; 
			g[Q[i]].pb(n) ;
			// cout<<Q[i]<<" "<<n<<el;
		}
		Q[i] = n ; 
	}
}

namespace sub1
{
	int h[N] ; 
	int P[N][LO+1] ;
	int pa[N] ; 
	int sz[N],ma[N],dd[N]; 
	void dfs(int u ,int p)
	{
		for(auto v: g[u])if(v!=p)
		{
			h[v]=h[u]+1 ;
			P[v][0] = u ; 
			dfs(v,u) ; 
		}
	} 
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v)  ; 
		FORD(i,LO,0)
		{
			if(h[u]-(1<<i)>=h[v])u=P[u][i];  
		}
		if(u==v)return u ; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				u=nu ; 
				v=nv; 
			}
		}
		u=P[u][0] ; 
		return u ;
	}
	int dis(int u ,int v)
	{
		int c = lca(u,v) ; 
		return h[u]+h[v]-2*h[c] ; 
	}
	void dfsz(int u ,int p )
	{
		sz[u] = 1; 
		for(auto v: g[u])if(v!=p&&dd[v]==0)
		{
			dfsz(v,u) ; 
			sz[u]+=sz[v] ; 
		}
	}
	int cen(int u ,int p,int n)
	{
		for(auto v:g[u])if(v!=p&&dd[v]==0&&sz[v]>n/2)return cen(v,u,n) ;
		return u ;
	}
	pii f1[N] , f2[N] ;
	void solve(int u)
	{
		dd[u] =1 ; 
		f1[u] = f2[u] = {-oo,0} ; 
		for(auto v:g[u])if(dd[v]==0)
		{
			dfsz(v,u) ;
			int c= cen(v,u,sz[v]);
			pa[c] = u ;
			solve(c) ; 
		}
	}
	int ok[N] ; 
	void up(int u)
	{ 
		ok[u] = 1; 
		for(int son=u,v = pa[u] ; v ; son = v , v = pa[v])
		{
			int len = dis(u,v) ; 
			if(f1[v].se==son)maxi(f1[v].fi,len) ;
			else if(f1[v].fi<=len)
			{
				f2[v] = f1[v] ; 
				f1[v] = {len,son} ; 
			}
			else maxi(f2[v],{len,son}); 
		}
	}
	int get(int u )
	{
		int ans = f1[u].fi ;
		for(int son = u, v = pa[u] ; v; son = v ,v = pa[v])
		{
			int len = dis(v,u) ; 
			if(ok[v])
			{
				maxi(ans,len) ; 
				if(f1[v].se!=son)maxi(ans,len+f1[v].fi) ; 
				else maxi(ans,len+f2[v].fi) ; 
			}
		} 
		return ans ;
	}
    void xuly()
    
    {
        dfs(1,0) ;
        FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ;
        if(q==400000)exit(0); 
        dfsz(1,0) ; 
        solve(cen(1,0,n));
        int res = 2 ;  
        FOR(i,1,4)up(i) ;
        FOR(i,1,q)
        {
        	int u = Q[i] ; 
        	up(u);
        	up(u-1);
        	maxi(res,get(u)) ;
        	cout<<res<<el;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}