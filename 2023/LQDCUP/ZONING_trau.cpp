/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "ZONING"
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
const int N = 3e5+5 , oo = 2e9 , LO = 18 , CH = 26 ; 


int n , m ; 
int spec[N] ; 

struct Edge
{
	int u , v , id ;
}E[N] ;
int dd[N] ; 
void doc()
{
    cin>> n >>m ;
    FOR(i,1,m)
    {
    	int u ,v ; cin>>u>>v ; 
    	E[i] = {u,v,i}; 
    }
    FOR(i,1,n-1)cin>>spec[i],dd[spec[i]]=1 ;
}
namespace sub1
{
	int pa[N] ;
	int goc(int u )
	{
		return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)return 0; 
		pa[chau]=chav ; 
		return 1 ; 
	}
	int tt[N] ; 
	int res[N] ; 
	int tmp[N] ; 
    void xuly()
    {
    	FOR(i,1,m)res[i] =  oo ; 
    	FOR(i,1,m)tt[i] = i ;
    	do
	{
    		FOR(i,1,n)pa[i] =i ;
    		bool ok = 1 ;  
    		FOR(i,1,m)
    		{
    			int id = E[tt[i]].id;
    			if(hop(E[tt[i]].u,E[tt[i]].v))
    			{
    				if(dd[id]==0)
    				{
    					ok =  0 ;
    					break; 
    				} 
    			}
				tmp[id] = i ; 
    		}
    		if(ok)
    		{
    			ok = 0 ; 
	    		FOR(i,1,m)
	    		{
	    			if(res[i]<tmp[i])
	    			{
	    				ok = 0; 
	    				break ; 
	    			} 
	    			if(res[i]>tmp[i])
	    			{
	    				ok = 1; 
	    				break;
	    			}
	    		}	
	    		if(ok)
	    		{
	    			FOR(i,1,m)res[i] = tmp[i] ;  
	    		}
    		}
    	}while(next_permutation(tt+1,tt+m+1)); 	
    	prt(res,m) ; 
    }
}
namespace sub2
{	
	struct ke
	{
		int v ,id ; 
	}; 
	ve<ke>g[N] ; 
	int at[N] , val[N] ,in[N] ,h[N] ; 
	int tt = 0 ; 
	int time_dfs = 0 ; 
	int st[N][LO+2] ;  
	int pa[N] ; 
	pii up[N] ; 
	void dfs(int u ,int p)
	{
		++tt; 
		int cur = ++time_dfs;
		at[time_dfs] = u ;
		val[tt] = time_dfs ;

		in[u] = tt;
		for(auto x:g[u])
		{
			int v= x.v ;
			int id = x.id;
			if(v==p)continue ; 
			up[v] = {u,id}; 
			h[v] = h[u]+1 ;  
			dfs(v,u) ;
			val[++tt] = cur ; 
		}
	}
	void build()
	{
		FOR(i,1,tt)
		{
			st[i][0] = val[i] ;
		}
		FOR(j,1,LO)FOR(i,1,tt-M(j)+1)
		{
			st[i][j] = min(st[i][j-1],st[i+M(j-1)][j-1]) ;
		}
	}
	int lca(int u ,int v)
	{
		if(in[u]>in[v])swap(u,v) ; 
		int l =in[u] ; 
		int r =in[v] ; 
		int k = lg(r-l+1) ; 
		return at[min(st[l][k],st[r-M(k)+1][k])] ;
	}
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
	}
	int res[N] ;
	void xuly()
	{
		FOR(i,1,n-1)
		{
			int id = spec[i] ; 
			g[E[id].u].pb({E[id].v,id}) ;
			g[E[id].v].pb({E[id].u,id}) ;
		}
		dfs(1,0) ;
		build() ; 
		FOR(i,1,n)pa[i] = i; 
		int ans = 0; 
		FOR(i,1,m)if(!res[i])
		{
			int c = lca(E[i].u,E[i].v) ;
			int u = goc(E[i].u) ;
			int v = goc(E[i].v) ;
			vi q;  
			while(h[u]>h[c])
			{		
				q.pb(up[u].se) ;
				pa[u] = up[u].fi;
				u=goc(u) ;
			}
			while(h[v]>h[c])
			{
				q.pb(up[v].se) ;
				pa[v] = up[v].fi ;
				v=goc(v) ;
			}
			sort(all(q)) ;
			for(auto x:q)
			{
				res[x]=++ans; 
			}
			if(!res[i])res[i]=++ans;
		}
		FOR(i,1,m)cout<<res[i]<<" ";
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