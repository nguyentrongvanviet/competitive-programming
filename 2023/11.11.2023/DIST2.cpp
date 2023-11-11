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
const int N = 5e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
struct edge
{
	int u ,v ; 
} ; 
struct polygon
{
	ve<edge>cheo; 
	vi node ; 
	vi dis[2] ;
	int S , T; 
	int get(int id ,int u)
	{
		int pos = LB(all(node),u)-node.begin() ; 
		return dis[id][pos] ;
	}
} ; 
vi g[N] ; 
polygon st[(int)2e6] ;
void doc()
{
    cin>> n; 
    FOR(i,1,n)st[1].node.pb(i) ;
    FOR(i,1,n)
    {
    	int pre=i-1 ; 
    	if(pre==0)pre=n ;
    	int ne= i+1 ;
    	if(ne==n+1)ne=1; 
    	g[i].pb(pre) ;
    	g[i].pb(ne) ;
    } 
    FOR(i,1,n-3)
    { 
    	int u ,v ; cin>> u >>v;  
    	if(u>v)swap(u,v) ;
    	st[1].cheo.pb({u,v}) ; 
    }
}
namespace sub1
{
	int f[N] ;
	void bfs(int st , int id , vi &node , vi&dis )
	{
		queue<int>q; 
		for(auto u :node)f[u] = oo ; 

		q.push(st) ; 
		f[st]= 0; 
		
		while(!q.empty())
		{
			int u= q.front() ;
			q.pop() ; 
			for(auto v :g[u])if(f[v]==oo)
			{
				f[v] =f[u]+1; 
				q.push(v) ;
			}
		}
		for(auto u : node)dis.pb(f[u]) ; 
	}	
	void build(int id)
	{ 
		if(SZ(st[id].node)==3)return ; 

		int tot = oo ;

		int best_u = 0 , best_v = 0;  
		for(auto [u,v]:st[id].cheo)
		{ 
			int l = UB(all(st[id].node),u)-st[id].node.begin() ;
			int r = UB(all(st[id].node),v)-st[id].node.begin() ;
			if(mini(tot,abs(r-l+1-(SZ(st[id].node)-(r-l+1)+2))))
			{	
				best_u = u ; 
				best_v = v; 
			}
		}

		for(auto u : st[id].node)
		{
			if(best_u<=u&&u<=best_v)st[id*2].node.pb(u) ; 
			if(u<=best_u||best_v<=u)st[id*2+1].node.pb(u) ; 
		}

		st[id].S=best_u ; 
		st[id].T=best_v ; 
		g[best_u].pb(best_v) ; 
		g[best_v].pb(best_u) ; 
		for(auto [u,v]: st[id].cheo)
		{
			if(u==best_u&&v==best_v)continue ;
			if(best_u <= u && v <= best_v)
			{
				st[id*2].cheo.pb({u,v}); 
			}
			else 
			{
				st[id*2+1].cheo.pb({u,v}); 
			}
		} 
		for(auto [u,v]:st[id].cheo)
		{
			g[u].pb(v) ;
			g[v].pb(u) ;
		}
		bfs(best_u,0,st[id].node,st[id].dis[0]) ; 
		bfs(best_v,1,st[id].node,st[id].dis[1]) ; 
		
		for(auto [u,v]:st[id].cheo)
		{
			g[u].pk() ; 
			g[v].pk() ; 
		}

		build(id*2) ; 

		build(id*2+1) ;
	}
	bool giao(int l ,int r, int i)
	{
		return l<=i&&i<=r ; 
	}
	int get(int id , int u ,int v)
	{

		int S = st[id].S ;
		int T = st[id].T ; 
		// cout<<"MID "<<S<<" "<<T<<el;
		if(u==v)return 0 ;
		if(SZ(st[id].node)==3)return 1 ; 
		if(u==S&&v==T)return 1 ; 
		if(u==S)
		{
			return st[id].get(0,v) ; 
		}
		else if(v==S)
		{
			return st[id].get(0,u) ; 
		}
		else if(u==T)
		{
			return st[id].get(1,v) ; 
		}
		else if(v==T)
		{
			return st[id].get(1,u) ; 
		}
		if(giao(S,T,u)^giao(S,T,v))
		{
			return min(st[id].get(0,u)+st[id].get(0,v),st[id].get(1,u)+st[id].get(1,v)) ; 
		}
		if(giao(S,T,u)&&giao(S,T,v))
		{
			return get(id*2,u,v) ; 
		}

		return get(id*2+1,u,v) ;

	}
    void xuly()
    {
    	build(1) ; 
    	cin>>q ;
    	while(q--)
    	{
    		int u,v ; cin>> u >>v; 
    		if(u>v)swap(u,v) ; 
    		cout<<get(1,u,v)<<el ; 
    	}
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