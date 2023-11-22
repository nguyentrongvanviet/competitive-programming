/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "III"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
#define        Mask(i)  (1ll<<(i))
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ; 
struct ke
{
	int v , id ; 
} ; 
ve<ke>g[N] ;
struct Edge
{
	int u ,v; 
} ; 
Edge E[N] ; 
void doc()
{
    cin>> n >> m ;
    FOR(i,1,m)
    {
    	int u ,v ; cin>> u >>v ;
    	g[u].pb({v,i}) ; 
    	g[v].pb({u,i}) ; 
    	E[i] = {u,v} ;
    }
}

namespace sub1
{
	vi adj[N] ;
	int tot = 0 ;
	int dd[N] ;
	void dfs(int u ,int p)
	{
		tot+=(p!=0) ;
		dd[u] = 1;  
		for(auto v : adj[u])if(dd[v]==0)
		{
			dfs(v,u) ;
		}
	}
	void xuly()
	{
		vi V ;
		FOR(i,1,m)V.pb(E[i].u),V.pb(E[i].v) ;
		uni(V) ;
		int res = 0 , best = 0 ; 

		FORN(msk,0,1<<m)
		{
			FOR(i,1,m)
			{
				int u =E[i].u ;
				int v =E[i].v ; 
				if(BIT(msk,i-1))adj[u].pb(v) ; 
				else adj[v].pb(u) ; 
			}
			tot = 0 ; 
			for(auto u : V)
			{
				dfs(u,0) ; 
				for(auto v : V)dd[v] = 0 ;
			}
			if(maxi(res,tot))best = msk; 
			for(auto u :V)adj[u].clear() ;  
		}
		cout<<res<<" ";
		FOR(i,1,m)
		{
			if(BIT(best,i-1))cout<<"F";
			else cout<<"B";
		}
		cout<<el; 
	}
}
namespace sub2
{
	int ID[N] , LOW[N] , tp[N] ;
	int tt = 0 , tplt = 0; 
	stack<int>st;
	int res[N] ; 
	ll tot = 0 ; 
	void dfs(int u ,int p )
	{
		st.push(u) ;
		ID[u] = LOW[u] = ++tt ;
		for(auto x : g[u])
		{
			int v = x.v ;
			int id = x.id ;
			if(v==p)continue;
			res[id] = (mp(u,v)!=mp(E[id].u,E[id].v));
			if(ID[v])
			{
				mini(LOW[u],ID[v]);
			} 
			else
			{
				dfs(v,u),mini(LOW[u],LOW[v]) ; 
			} 
		}
		if(ID[u]==LOW[u])
		{
			int t ;
			++tplt ; 
			int sz = 0; 
			do
			{
				t=st.top() ; 
				st.pop() ; 
				tp[t] = tplt ;
				++sz;  
			}while(t!=u) ;
			tot+=sz*(sz-1) ; 
		}
	}
	vi adj[N] ; 
	int dd[N] ;
	void go(int u,int p,int sum )
	{
		dd[u] = 1; 
		tot+=sum ;
		for(auto v : adj[u])if(v!=p)
		{
			go(v,u,sum+1) ; 
		}
	}
    void xuly()
    {
    	FOR(i,1,n)if(ID[i]==0)dfs(i,0) ;
    	FOR(i,1,m)
    	{
    		int u = tp[E[i].u] ; 
    		int v= tp[E[i].v] ; 
    		if(u!=v)
    		{
    			adj[u].pb(v) ;
    			adj[v].pb(u) ; 
    		}
    	}
    	FOR(i,1,tplt)if(dd[i]==0)go(i,0,0) ;
    	cout<<tot<<" ";
    	FOR(i,1,m)
    	{
    		if(res[i])cout<<"B";
    		else cout<<"F";
    	}
    	cout<<el;
    	tot = 0 ; 
    	FOR(i,1,n)g[i].clear() , dd[i]=ID[i]= LOW[i] = tp[i] = tt = tplt = 0 ;
		FOR(i,1,m)res[i] = 0 ;
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
    int sub ; 
    cin>>sub ; 
    if(mtt)cin>>  test;

    FOR(i,1,test)
    {
        doc() ; 
        if(sub==1)sub1::xuly() ; 
        if(sub==2)sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}