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

int n , q; 
vi g[N] ;
void doc()
{
    cin>> n >>q ;
    FOR(i,1,n-1)
    {
    	int u ,v; cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int sz[N] , dd[N] , pa[N] ; 
	int P[N][LO+1] ,MI[N][LO+1];
	int h[N] ; 
	void DFS(int u ,int p)
	{
		MI[u][0] = u ; 
		for(auto v: g[u])if(v!=p)
		{
			P[v][0] = u ;
			h[v] = h[u]+1 ;
			DFS(v,u) ; 
		}
	}
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ; 
		int ans = oo ; 
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			mini(ans,MI[u][i]);
			u=P[u][i] ; 
		}
		if(u==v)
		{
			mini(ans,u);
			return ans; 
		}
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				mini(ans,MI[u][i]) ;  
				mini(ans,MI[v][i]) ;
				u=nu ; 
				v=nv ;
			}
		}
		mini(ans,MI[u][1]) ;
		mini(ans,MI[v][1]) ;
		return ans ;
	}
	struct BG
	{
		int u , val; 
	} ; 
	struct cmp
	{
		bool operator()(const BG&a,const BG&b)const
		{
			return a.val<b.val||(a.val==b.val&&a.u<b.u) ;
		}
	} ;
	int S[N][2] ; 
	int VAL[N] ;
	void dfsz(int u, int p)
	{
		sz[u] =1 ; 
		for(auto v: g[u])if(v!=p&&dd[v]==0)
		{
			dfsz(v,u) ; 
			sz[u]+=sz[v] ;
		}
	}
	int cen(int u ,int p , int n)
	{
		for(auto v: g[u])if(v!=p&&sz[v]>n/2&&dd[v]==0)
		{
			return cen(v,u,n) ; 
		}
		return u ;
	}
	void solve(int u)
	{
		dd[u] = 1 ;
		for(auto v: g[u])if(dd[v]==0)
		{
			dfsz(v,u) ; 
			int c= cen(v,u,sz[v]) ;
			pa[c] = u ; 
			S[u][0] = S[u][1] = 0  ; 
			VAL[c]=oo;
			solve(c);
		}
	}
	int DD[N] ;
	void up(int u)
	{	 
		DD[u] = 1; 
		for(int son = u , v=pa[u] ;v;son=v,v=pa[v])
		{
			int d= lca(v,u) ; 
			if(mini(VAL[son],d))
			{
				if(S[v][0]==son)continue ; 
				if(VAL[S[v][0]]>=VAL[son])
				{
					S[v][1]=S[v][0];
					S[v][0] = son ; 
				}
				else if(VAL[S[v][1]]>VAL[son])
				{
					S[v][1] = son ; 
				}
			}
		}
	}
	int get(int u)
	{	
		int res = VAL[S[u][0]] ; 

		if(DD[u])mini(res,u);
		for(int son = u , v=pa[u] ;v;son=v,v=pa[v])
		{
			int d= lca(u,v) ; 
			if(DD[v])mini(res,d) ; 
			if(S[v][0]!=son)
			{	
				if(S[v][0])mini(res,min(d,VAL[S[v][0]])); 
			}
			else if(S[v][1])mini(res,min(d,VAL[S[v][1]]));
		}
		return res ;
	}
    void xuly()
    {
    	VAL[0] = oo ;
    	DFS(1,0); 
    	FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ,MI[i][j] = min(MI[i][j-1],MI[P[i][j-1]][j-1]);
    	dfsz(1,0);
    	solve(cen(1,0,n)) ;
    	int last = 0; 
    	while(q--)
    	{
    		int TYPE,z ; cin>>TYPE >>z;
    		int u= (z+last)%n+1; 
			cout<<TYPE<<" "<<u<<el;
    		if(TYPE==1)
    		{	
    			up(u) ;
    		}	
    		else
    		{
    			last = get(u) ;
    			cout<<last<<el ;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}