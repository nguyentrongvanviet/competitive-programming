/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "CIRCUIT"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
struct ke
{
	int v, id ; 
} ; 
ve<ke>g[N]; 
void doc()
{
	cin>> n>> m; 
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v; 
		if(u==v)
		{
			cout<<"YES"<<el<<i<<el,exit(0) ;
		}
		g[u].pb({v,i});
	}
}

namespace sub1
{
	int id[N] , low[N] , tp[N] ; 
	int tt = 0 , tplt = 0 ; 
	stack<int>st ; 
	int pre[N] ;
	int pa[N] ; 
	int dd[N] ;
	void go(int u )
	{
		dd[u] = 1; 
		for(auto x: g[u])
		{
			int v = x.v ;
			int id= x.id ;
			if(tp[v]!=tp[u])continue ; 
			if(dd[v]==0)
			{
				pre[v] = id ;
				pa[v] = u ;
				go(v) ;
			}
			else
			{
				vi res; 
				res.pb(id);
				while(u!=v)
				{
					res.pb(pre[u]);
					u=pa[u] ; 
				}
				reverse(all(res)) ; 
				cout<<"YES"<<el;
				prv(res); 
				exit(0) ; 
			}
		}
	}
	void dfs(int u )
	{
		st.push(u) ; 
		id[u] = low[u] = ++tt ; 
		for(auto x:g[u])
		{	
			int v=x.v ;
			if(tp[v])continue ;
			if(id[v])mini(low[u],id[v]) ;
			else dfs(v) ,mini(low[u],low[v]) ;
		}
		if(id[u]==low[u])
		{
			int t; 
			int sz =0 ; 
			++tplt;
			do
			{
				t= st.top() ; 
				st.pop() ; 
				++sz; 
				tp[t]=tplt; 
			}while(t!=u) ;
			if(sz>1)
			{
				go(u) ; 
				cout<<u<<" "<<sz<<el;
				exit(0) ;
			} 
		}
	}
	void xuly()
	{
		FOR(i,1,n)if(id[i]==0)dfs(i) ; 
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