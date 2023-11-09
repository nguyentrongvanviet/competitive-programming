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
const int N = 4e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m;
vi g[N] ;
int dd[N] ; 
int C(int u ,int id)
{
	return (u<<1^id) ;
}
void doc()
{
   	cin>> n >> m; 
   	FOR(i,1,m)
   	{
   		int u ,v , TYPE ; cin>>u>>v>>TYPE ;
   		TYPE--;
   		g[C(u,TYPE^1)].pb(C(v,TYPE)) ; 
   	}
}

namespace sub1
{
	int id[N] , low[N] ,tp[N] , sz[N] ; 
	stack<int>st; 
	int tt = 0 , tplt = 0 ; 
	void dfs(int u )
	{
		id[u] = low[u] = ++tt ;
		st.push(u) ; 
		for(auto v: g[u])
		{
			if(tp[v])continue ;
			if(id[v])mini(low[u],id[v]) ; 
			else dfs(v) , mini(low[u],low[v]) ;
		}
		if(low[u]==id[u])
		{
			int t ; 
			++tplt ; 
			do
			{
				t = st.top() ; 
				st.pop() ; 
				tp[t]=tplt; 
				sz[tplt]++; 
			}while(t!=u);
		}
	}
	vi adj[N] ;
	int f[N] ; 
	int solve(int u )
	{
		if(f[u]!=-1)return f[u] ; 
		if(sz[u]>1)return f[u] = oo ; 
		f[u] = 0 ;
		for(auto v: adj[u])
		{
			maxi(f[u],solve(v)+1) ;
			mini(f[u],oo) ; 
		}
		return f[u] ; 
	}
    void xuly()
    {
    	FOR(i,1<<1,n<<1^1)
    	{
    		if(tp[i]==0)dfs(i) ; 
    	}
    	FOR(u,1<<1,n<<1^1)
    	{	
    		for(auto v: g[u])
    		{
    			int tpu=  tp[u] ;
    			int tpv = tp[v] ;
    			if(tpu!=tpv)adj[tpu].pb(tpv);
    		}
    	}	
    	FOR(i,1,tplt)f[i] = -1 ; 
    	FOR(i,1,n)
    	{
    		int res = max(solve(tp[C(i,0)]),solve(tp[C(i,1)])); 
    		if(res==oo)cout<<-1<<el; 
    		else cout<<res<<el;
    	}
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
