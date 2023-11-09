/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "LABLE"
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m;
vi g[N] ; 
int dd[N] ;

void doc()
{	
    cin>> n >>m ; 
    FOR(i,1,m)
    {
    	int u ,v; cin>>u>>v;
    	g[u].pb(v) ; 
    	if(u==v)dd[u]=1;
    }
}

namespace sub1
{
	int id[N] , low[N] , tp[N] , sz[N] , tt= 0 , tplt = 0 ;
	stack<int>st;  
	void dfs(int u )
	{
		id[u] = low[u] = ++tt  ;
		st.push(u) ;
		for(auto v: g[u])
		{
			if(tp[v])continue ;
			if(id[v])mini(low[u],id[v]) ;
			else dfs(v) ,mini(low[u],low[v]) ;
		}
		if(id[u]==low[u])
		{
			int t ; 
			++tplt ;
			do
			{
				t=st.top() ;
				st.pop() ; 
				tp[t] =tplt ; 
				sz[tplt]++ ;
				if(dd[t])sz[tplt]++;
			}while(t!=u) ;
		}
	}
	int f[N] ;
	set<int>adj[N] ;
	ll solve(int u)
	{
		if(f[u]!=-10)return f[u] ;
		if(u==tp[1])
		{
			if(sz[u]==1)return f[u]=1;
			else return f[u] = -1 ;
		}
		f[u]=0 ;
		for(auto v:adj[u])
		{
			int tmp = solve(v) ;
			if(tmp==-1)return f[u]=-1 ;
			f[u]+=tmp;
		}
		if(f[u]&&sz[u]!=1)return f[u]=-1;
		return min(2,f[u]);
	}
    void xuly()
    {
    	FOR(i,1,n)if(id[i]==0)dfs(i) ; 
    	FOR(u,1,n)for(auto v:g[u])
    	{
    		int tpu= tp[u] ; 
    		int tpv = tp[v] ;
    		if(tpu!=tpv)
    		{
    			adj[tpv].insert(tpu) ;
    		}
    	}
    	FOR(i,1,tplt)f[i] = -10 ;
    	FOR(i,1,n)cout<<solve(tp[i])<<" ";
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