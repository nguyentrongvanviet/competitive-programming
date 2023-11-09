/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "wireless"
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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , q ; 
struct ke
{
	int v,  w; 
} ; 
ve<ke>g[N] ; 
vi Q[(int)1e5+5] ; 
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n-1)
    {
    	int u ,v,w ;cin>>u>>v>>w; 
    	g[u].pb({v,w}) ; 
    	g[v].pb({u,w}) ; 
    }
    FOR(i,1,q)
    {
    	int k; cin>> k; 
    	while(k--)
    	{
    		int u ;cin>>u ; 
    		Q[i].pb(u) ; 	
    	}
    }
}

namespace sub1
{
	const int N = 5e2 ;
	int c[N][N] ;
	void dfs(int u ,int p ,int root)
	{
		for(auto [v,w]: g[u])if(v!=p)
		{
			c[root][v]=c[root][u]+w;
			dfs(v,u,root) ; 
		}
	}
	int a[N] ; 
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		dfs(i,0,i) ; 
    	}
    	FOR(i,1,q)
    	{
    		ll res = inf ;
    		FOR(u,1,n)
    		{
    			ll tmp  = 0;
    			for(auto v : Q[i])
    				tmp+=c[u][v];
    			mini(res,tmp) ; 
    		}
    		cout<<res<<el;
    	}
    	exit(0) ; 
    }	
}
namespace sub4
{
	void xuly()
	{

	}
}
namespace sub2_3
{
	int h[N] ;
	int P[N][LO+2] ; 
	ll W[N][LO+2] ; 
	void dfs(int u ,int p)
	{
		for(auto [v,w]: g[u])if(v!=p)
		{
			P[v][0] = u  ;
			W[v][0] = w ;
			h[v] = h[u]+1 ; 
			dfs(v,u) ; 
		}
	}
	pair<ll,int> lca(int u ,int v)
	{
		ll ans = 0 ; 
		if(h[u]<h[v])
		{
			swap(u,v) ;
		}	 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			ans+=W[u][i] ; 
			u=P[u][i] ; 
		}
		if(u==v)return {ans,u} ;
		FORD(i,LO,0)
		{
			int nu = P[u][i] ;
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				ans+=W[u][i]+W[v][i] ; 
				u=nu ; 
				v=nv ;
			}
		}
		ans+=W[u][0]+W[v][0] ;
		u=P[u][0];  
		return {ans,u}; 
	}
	void xuly()
	{
		dfs(1,0) ; 
		FOR(j,1,LO)FOR(i,1,n)
		{
			P[i][j] = P[P[i][j-1]][j-1] ; 
			W[i][j] = W[i][j-1]+W[P[i][j-1]][j-1] ; 
		}
		FOR(i,1,q)
		{	
			int sz = Q[i].size() ;
			if(sz==2)
			{
				int u =Q[i][0] ; 
				int v =Q[i][1] ;
				cout<<lca(u,v).fi<<el;
			}
			else if(Q[i].size()==3)
			{
				sort(all(Q[i]),[](int i ,int j ){return h[i]>h[j];}); 
				int x = Q[i][0] ; 
				int y = Q[i][1] ; 
				int z = Q[i][2] ; 				
				pair<ll,int>c = lca(x,y) ; 
				pair<ll,int>d = lca(c.se,z) ; 
				cout<<c.fi+d.fi<<el;
			}
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
        if(n<=500&&q<=500)sub1::xuly() ; 
        // if(q==1)sub4::xuly() ; 
    	sub2_3::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}