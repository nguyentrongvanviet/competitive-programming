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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ,m ; 
vi g[N] ; 
void doc()
{
	cin>>n>>m ; 
	FOR(i,1,m)
	{
		int u ,v ; cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ;
	}
}

namespace sub1
{
	int low[N] , id[N] , tp[N] ; 
	int tplt = 0 ,tt=0 ;
	stack<int>st;  
	void dfs(int u,int p  )
	{
		st.push(u) ; 
		low[u] = id[u] = ++tt; 
		for(auto v: g[u])
		{
			if(v==p)continue;
			if(tp[v])continue ; 
			if(id[v])mini(low[u],id[v]);
			else dfs(v,u),mini(low[u],low[v]); 
		}
		if(id[u]==low[u])
		{
			++tplt; 
			int t; 
			do
			{
				t=st.top() ;
				st.pop() ;
				tp[t] = tplt;  
			}while(t!=u); 
		}
	}
	vi adj[N]  ;
	int P[N][LO+3] ;
	int h[N] ;
	void DFS(int u ,int p)
	{
		for(auto v: adj[u])if(v!=p)
		{
			h[v]=h[u]+1 ; 
			P[v][0] = u ; 
			DFS(v,u) ; 
		}
	}
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ;  
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])u=P[u][i] ;
		if(u==v)return u ; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				u=nu ; 
				v=nv ; 
			}
		}
		return P[u][0] ; 
	}
    void xuly()
    {
    	dfs(1,0) ; 
    	FOR(i,1,n)
    	{
    		for(auto j : g[i])if(tp[i]!=tp[j])adj[tp[i]].pb(tp[j]);
    	}
    	DFS(1,0) ;  
		FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
		int k ; cin>> k ; 
		while(k--)
		{
			int s, t ; cin>>s>>t ;
			s=tp[s] ; 
			t=tp[t] ; 
			int c = lca(s,t) ;
			cout<<h[s]+h[t]-2*h[c]<<el;
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