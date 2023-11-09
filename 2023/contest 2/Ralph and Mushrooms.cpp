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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 	
ll C[N] ; 
ll cost(int val)
{
	ll l = 0 ;
	ll r= 1e9 ; 
	ll k = 0 ; 
	while(l<=r)
	{
		ll mid= (l+r)/2;
		if(mid*(mid+1)/2<=1LL*val)
		{
			k=mid; 
			l=mid+1; 
		} 
		else r=mid-1 ;
	}
	return (k+1)*val - C[k];
} 	
struct ke
{
	int v ,w ;
}; 
ve<ke>g[N] ;
void doc()
{
	FOR(i,1,1e6)
	{
		C[i] = C[i-1]+1LL*i*(i+1)/2;
	}
	cin>> n >>m ; 
	FOR(i,1,m)
	{
		int u ,v , w;
		cin>>u>>v>>w;
		g[u].pb({v,w}) ;
	}
}
namespace sub1
{
	int low[N] , id[N] , tp[N]  ; 
	stack<int>st ;
	int tt = 0 , tplt= 0 ; 
	ve<ke>adj[N] ; 
	ll val[N] ;
	ll f[N] ;
    void dfs(int u )
    {
    	id[u] = low[u] = ++tt; 
    	st.push(u) ;
    	for(auto x: g[u])
    	{	
    		int v= x.v ; 
    		if(tp[v])continue; 
    		if(id[v])mini(low[u],id[v]) ;
    		else dfs(v) , mini(low[u],low[v]) ;
    	}
    	if(low[u]==id[u])
    	{
    		int t ; 
    		++tplt  ;
    		do
    		{	
    			t= st.top() ; 
    			st.pop() ; 
    			tp[t] = tplt ;  
    		}while(t!=u); 
    	}
    }
    ll solve(int u)
    {
    	if(f[u]!=-1)return f[u] ; 
    	ll ans=0;
    	for(auto x : adj[u])
    	{	
    		int v=x.v; 
    		int w=x.w ;
    		solve(v) ; 
    		maxi(ans,f[v]+w)  ; 
    	}
    	return f[u] = val[u]+ans;
    }
    void xuly()
    {		
        FOR(i,1,n)if(id[i]==0)dfs(i)  ; 
    	FOR(u,1,n)		
    	{
    		for(auto tmp: g[u])
    		{
    			int v=tmp.v ;
    			int w=tmp.w;

    			int x= tp[u] ;
    			int y =tp[v] ;
    			if(x==y)
    			{
    				val[x]+=cost(w) ;
    			}
    			else
    			{
    				adj[x].pb({y,w}) ;
    			}
    		}
    	}
    	int s ;cin>>s; 
    	FOR(i,1,tplt)f[i]=-1 ;
    	ll res = solve(tp[s]) ;
    	cout<<res; 
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