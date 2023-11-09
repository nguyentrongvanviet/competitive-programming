/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
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

struct ke
{
	int v; 
	int w ;  
} ; 

struct DL
{
	int u ; 
	ll val;  
} ; 
struct cmp
{
	bool operator()(const DL&a,const DL&b)const
	{
		return a.val>b.val; 
	}
};
int n , m ,k ; 
ve<ke>g[N] ; 
int a[N] ;
int dd[N] ;
ll f[N] ;  
int sl[N] ;
int ok[N] ;
void doc()
{
	cin>> n >> m >> k; 
	FOR(i,1,k)cin>>a[i],dd[a[i]]=1  ; 
	FOR(i,1,m)
	{
		int u ,v , c; 
		cin>>u>>v>>c ; 
		g[u].pb({v,c}) ; 
		g[v].pb({u,c}) ; 
	}
}
ll dij(int u )
{
	priority_queue<DL,ve<DL>,cmp>q ; 
	FOR(i,1,n)f[i] = inf;  
	q.push({u,f[u]=0}) ; 
	while(!q.empty())
	{
		int u = q.top().u ; 
		ll val = q.top().val ; 
		q.pop() ; 
		if(f[u]<val)continue ; 
		for(auto x : g[u])
		{
			int v = x.v ;
			int w = x.w ;
			if(mini(f[v],f[u]+w))
			{
				q.push({v,f[v]}) ; 
			} 	
		}
	}
	int node = 0 ; 
	FOR(i,1,k)
	{
		if(f[node]<f[a[i]])
		{
			node = a[i] ; 
		}
	}		
	return node; 
}
void solve(int s )
{
	priority_queue<DL,ve<DL>,cmp>q ;
	FOR(i,1,n)
	{
		f[i] = inf ; 
		sl[i] = 0 ; 	
	}
	sl[s] = 1 ; 
	q.push({s,f[s]=0}) ; 
	while(!q.empty())
	{
		int u = q.top().u ; 
		ll val =q.top().val; 
		q.pop() ; 
		if(f[u]<val)continue ;
		for(auto x : g[u])
		{
			int v = x.v; 
			int w = x.w ; 
			if(f[v]==f[u]+w)
			{
				maxi(sl[v],sl[u]+(dd[v])) ;
			}
			else if(mini(f[v],f[u]+w))
			{
				sl[v] =sl[u]+(dd[v]);
				q.push({v,f[v]}) ; 
			}
		}
	}
	FOR(i,1,n)
	{
		if(sl[i]==k)ok[i] =  1; 
	}
}
void xuly()
{
	int s = dij(a[1]) ; 
	int t = dij(s) ; 
	
	solve(s) ; 

	solve(t) ;
	int ans = 0 ; 
	FOR(i,1,n)ans+=ok[i] ; 
	cout<<ans<<el; 
	FOR(i,1,n)
	{
		if(ok[i])cout<<i<<" ";
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