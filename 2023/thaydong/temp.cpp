/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "KINGDOM"
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
const int N = 3e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , K ;
vi g[N] ;  
int ST[N] ; 
int tt = 0 ; 
int h[N] ; 
int P[N][LO+2] ; 
void doc()
{
	int m ; 
	cin>> n >>m>> K ; 
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
void dfs(int u ,int p)
{
	ST[u]=++tt; 
	for(auto v : g[u])if(v!=p)
	{
		h[v] = h[u]+1; 
		P[v][0] = u ; 
		dfs(v,u) ; 
	}
}
struct DL
{
	int u ; 
	int val; 
} ; 
struct cmp
{
	bool operator()(const DL&a , const DL&b)const
	{
		return a.val<b.val;  
	}
};
int lca(int u ,int v)
{
	if(h[u]<h[v])swap(u,v) ; 
	FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
	{	
		u=P[u][i] ; 
	}
	if(u==v)return u ; 
	FORD(i,LO,0)
	{
		int nu = P[u][i]; 
		int nv = P[v][i]; 
		if(nu!=nv)
		{
			u=nu; 
			v=nv ; 
		}
	}
	return P[u][0] ; 
} 
int dis(int u ,int v)
{
	return h[u] + h[v] - 2*h[lca(u,v)] ;
}
int EDGE ; 
set<DL,cmp>S ;  
void ADD(DL NEW )
{
	auto cur = S.LB(NEW) ; 
	if(cur==S.begin())
	{
		int U = (*cur).u ; 
		int V = (*prev(S.end())).u;
		EDGE-=dis(U,V) ; 
		EDGE+=dis(NEW.u,U);
		EDGE+=dis(NEW.u,V);
	}	
	else if(cur==S.end())
	{	
		int  U = (*S.begin()).u ;
		int V = (*prev(cur)).u ;
		EDGE-=dis(U,V) ;
		EDGE+=dis(U,NEW.u) ; 
		EDGE+=dis(V,NEW.u) ;    
	}	
	else
	{
		int U = (*prev(cur)).u ; 
		int V = (*cur).u; 
		EDGE-=dis(U,V) ; 
		EDGE+=dis(U,NEW.u) ; 
		EDGE+=dis(V,NEW.u) ; 
	}
	S.insert(NEW) ; 
}
void DEL(DL NEW )
{
	S.erase(NEW) ; 
	auto cur = S.LB(NEW) ; 
	if(cur==S.begin())
	{
		int U = (*cur).u ; 
		int V = (*prev(S.end())).u;
		EDGE+=dis(U,V) ; 
		EDGE-=dis(NEW.u,U);
		EDGE-=dis(NEW.u,V);
	}	
	else if(cur==S.end())
	{	
		int  U = (*S.begin()).u ;
		int V = (*prev(cur)).u ;
		EDGE+=dis(U,V) ;
		EDGE-=dis(U,NEW.u) ; 
		EDGE-=dis(V,NEW.u) ;    
	}	
	else
	{
		int U = (*prev(cur)).u ; 
		int V = (*cur).u; 
		// if(NEW.u==2)cout<<"FAFSAFAFS "<<U<<" "<<V<<el;
		EDGE+=dis(U,V) ; 
		EDGE-=dis(U,NEW.u) ; 
		EDGE-=dis(V,NEW.u) ; 
	} 
}
void xuly()
{
    dfs(1,0) ; 
    FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
	int res = 1 ; 
	S.insert({1,ST[1]}) ; 
    for(int i=2 , L=1 ;i<=n;i++)
    {
    	ADD({i,ST[i]}) ; 
    	// cout<<i<<" "<<EDGE<<el;
    	while(EDGE/2>K-1)
    	{
    		DEL({L,ST[L]}); 
    		// cout<<EDGE<<" ";
    		++L ; 
    	}
    	// cout<<el;
    	maxi(res,i-L+1) ; 
    }
    cout<<res ; 
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