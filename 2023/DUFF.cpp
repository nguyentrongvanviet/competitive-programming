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
#define SZ(a) (int)a.size()
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m, q; 
vi g[N] ; 
vi a[N] ;
vi merge(vi& L , vi& R)
{
	vi ans; 
	int l = 0 , r = 0 ;
	while(l<SZ(L)&&r<SZ(R))
	{
		if(L[l]<R[r])
		{
			ans.pb(L[l++]) ;
		}
		else
		{
			ans.pb(R[r++]) ; 
		}
		if(SZ(ans)==10)return ans ;
	}
	while(l<SZ(L)&&SZ(ans)!=10)
	{
		ans.pb(L[l++]) ;
	}
	while(r<SZ(R)&&SZ(ans)!=10)
	{
		ans.pb(R[r++]) ;
	}
	return ans ;
}
vi node[N][LO+1];
void doc()
{
	cin>> n >> m >> q;
	FOR(i,1,n-1)
	{
		int u, v; cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ;
	}
	FOR(i,1,m)
	{
		int u ;cin>>u ; 
		node[u][0].pb(i) ; 
	}
	FOR(i,1,n)
	{
		sort(all(node[i][0])) ; 
		while(SZ(node[i][0])>10)node[i][0].pk() ;
	}
}
namespace sub1
{
	int h[N] ; 
	int P[N][LO+1] ; 
	void dfs(int u ,int p)
	{
		for(auto v: g[u])if(v!=p)
		{
			h[v]=h[u]+1 ;
			P[v][0] = u ;
			dfs(v,u) ; 
		}
	}
	vi lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ; 
		vi tmp ; 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			tmp = merge(tmp,node[u][i]);
			u = P[u][i] ; 
		}

		if(u==v)
		{
			tmp = merge(tmp,node[u][0]) ;
			return tmp;
		}
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				tmp = merge(tmp,node[u][i]) ; 
				tmp = merge(tmp,node[v][i]) ;
				u=nu ; 	
				v=nv ; 
			}
		}
		tmp = merge(tmp,node[u][1]) ; 
		tmp = merge(tmp,node[v][0]) ;
		return tmp ;
	}
    void xuly()
    {
    	dfs(1,0) ;
    	FOR(j,1,LO)FOR(i,1,n)
    	{
    		P[i][j] =P[P[i][j-1]][j-1] ; 
    		node[i][j] = merge(node[i][j-1],node[P[i][j-1]][j-1]);
    	}	
    	while(q--)
    	{
    		int u ,v, k  ;
    		cin>>u>>v>> k;
    		vi x = lca(u,v) ; 
    		cout<<min(k,SZ(x))<<" "; 
    		FORN(i,0,min(k,SZ(x)))cout<<x[i]<<" ";
    		cout<<el;
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