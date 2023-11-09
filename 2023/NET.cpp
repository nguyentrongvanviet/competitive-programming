/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define            tct  template<class T>
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

int n , m , K , L ; 
vi g[N] ;	
int dda[N] ,ddb[N] ;
int fa[N]  , fb[N] ;  
void doc()
{
	cin>> n >> m >> K >> L ; 
	FOR(i,1,K)
	{
		int u ; cin>> u ;
		dda[u] = 1; 
	}
	FOR(i,1,L)
	{
		int u ; cin>>u ; 
		ddb[u] =1 ; 
	}
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

namespace sub1
{
	int id[N] , low[N]  , tp[N] ; 
	stack<int>st ; 
	int tt= 0 ,tplt= 0 ; 
	vi adj[N] ; 
	void dfs(int u ,int p)
	{
		low[u]=id[u]=++tt; 
		st.push(u) ; 
		for(auto v: g[u])
		{
			if(tp[v]||v==p)continue;
			if(id[v])mini(low[u],id[v]); 
			else dfs(v,u),mini(low[u],low[v]) ; 
		}
		if(id[u]==low[u])
		{
			++tplt ; 
			int t; 
			do
			{
				t=st.top() ; 
				tp[t]=tplt ; 
				st.pop() ; 
				fa[tplt]+=dda[t]; 
				fb[tplt]+=ddb[t] ; 
			}while(u!=t);
		}
	}
	int res= 0 ; 
	void DFS(int u ,int p)
	{	
		for(auto v:adj[u])if(v!=p)
		{
			DFS(v,u)  ; 
			fa[u]+=fa[v] ; 
			fb[u]+=fb[v] ; 
			if(fa[v]==0||fa[v]==K||fb[v]==0||fb[v]==L)res++ ; 
		}
	}
    void xuly()
    {
    	dfs(1,0) ; 
    	FOR(u,1,n)for(auto v :g[u])
    	{
    		int nu =tp[u] ; 
    		int nv = tp[v] ; 
    		if(nu!=nv)adj[nu].pb(nv); 
    	}
    	DFS(1,0) ;
    	cout<<res<<el;  
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
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}