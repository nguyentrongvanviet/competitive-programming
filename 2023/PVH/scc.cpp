/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "scc"
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
#define        M(i)  (1ll<<(i))
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
const int N = 3e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
struct ke
{
	int v ,w ; 
};
ve<ke>g[N] ;
vi V ;
void doc()
{
	cin>> n >> m ;     
	FOR(i,1,m)
	{
		int u ,v ,w ; cin>> u >> v >> w; 
		g[u].pb({v,w}) ; 
		V.pb(w) ;
	}
}

namespace sub1
{
	bool ok  ;
	stack<int>st;
	int id[N] , low[N] ;
	int tt = 0 ; 
	vi node ; 
	void dfs(int u ,int lo ,int hi)
	{
		node.pb(u) ;
		id[u] = low[u] = ++tt ;
		st.push(u) ;
		for(auto [v,w]:g[u])if(lo<=w&&w<=hi)
		{
			if(id[v])mini(low[u],id[v]) ;
			else dfs(v,lo,hi),mini(low[u],low[v]) ;
		}
		if(id[u]==low[u])
		{
			int t; 
			int sz =0 ;
			do
			{
				t=st.top() ; 
				st.pop() ; 
				++sz ;
			}while(t!=u);
			if(sz==n)ok = 1 ;
			else ok = 0 ;
		}
	}
    void xuly()
    {
      	uni(V) ; 
      	int it = 0;
      	int res = oo ;
      	if(n==1)return void(cout<<0<<el) ;
      	FORN(i,0,SZ(V))
      	{
  			ok = -1 ; 
      		while(it<SZ(V))
      		{
      			for(auto u :node)id[u]=low[u]=0;
      			node.clear() ;
      			dfs(1,V[i],V[it]) ;
      			if(ok)
      			{
      				mini(res,V[it]-V[i]);
      				break;
      			}
      			else ++it ;
      		}
      		if(ok==0)break;
      	}
      	if(res==oo)return void(cout<<-1<<el) ;
      	cout<<res<<el ;
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}