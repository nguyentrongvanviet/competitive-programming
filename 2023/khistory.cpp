/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "khistory"
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , m;  
vi g[N] ; 
int id[N] , low[N] , tp[N] ; 
stack<int>st;
int tt =0  , tplt = 0;  
void dfs(int u,int p  )
{
	st.push(u) ; 
	low[u] = id[u] = ++tt; 
	for(auto v: g[u])
	{
		if(v==p)continue ; 
		if(tp[v])continue ;
		if(id[v])low[u] = min(low[u],id[v]) ; 
		else dfs(v,u) , low[u]=min(low[u],low[v]) ; 
	}
	if(low[u]==id[u])
	{
		int t; 
		++tplt ;
		do
		{
			t=st.top() ; 
			st.pop() ; 
			tp[t] = tplt ; 
		}while(t!=u);
	}
}

void doc()
{
	cin>> n >>m ; 
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}
set<int>adj[N] ;
ll f[N][2][2];
ll dp[N][2] ; 
void solve(int u,int p,int on,int ok)
{		
	if(f[u][on][ok]!=-1)return ; 
	if(on==1)
	{
		for(auto v: adj[u])if(v!=p)
		{
			solve(v,u,0,1); 
			solve(v,u,1,1);
 		}
 		f[u][1][ok] =1 ; 
 		for(auto v: adj[u])if(v!=p)
 		{
 			f[u][1][ok]+=min(f[v][0][1],f[v][1][1]) ;
 		}
	}
	else
	{
		for(auto v :adj[u])if(v!=p)
		{
			solve(v,u,0,0) ; 
			solve(v,u,1,0) ;
		}
		if(ok==0)
		{	
			int pre = 0 ; 
			dp[pre][0] = 0  ; 
			dp[pre][1] = n+1 ; 
			for(auto v: adj[u])if(v!=p)
			{
				dp[v][0] = dp[pre][0]+f[v][0][0];
				dp[v][1] = min({dp[pre][1]+f[v][1][0],dp[pre][0]+f[v][1][0],dp[pre][1]+f[v][0][0]}); 
				pre=v ;
			}
			f[u][0][0] = dp[pre][1] ;
		}
		else
		{
			f[u][0][1] = 0 ; 
			for(auto v : adj[u])if(v!=p)
			{
				f[u][0][1]+=min(f[v][1][0],f[v][0][0]);
			}
		}
	}
}
void xuly()
{
	FOR(i,1,n)if(tp[i]==0)dfs(i,0) ; 
	FOR(u,1,n)
	{
		for(auto v: g[u])
		{	
			int x = tp[u] ; 
			int y = tp[v] ;
			if(x!=y)
			{
				adj[x].insert(y) ; 
				adj[y].insert(x) ;
			}
		}
	}
	FOR(i,1,tplt)FOR(on,0,1)FOR(ok,0,1)f[i][on][ok] = -1 ; 
	int res= 0 ; 
	FOR(i,1,n)if(f[i][1][0]==-1)
	{
		solve(i,0,1,0) ;  
		solve(i,0,0,0) ;
		res+=min(f[i][1][0],f[i][0][0]);
	} 
	cout<<res;
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
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}