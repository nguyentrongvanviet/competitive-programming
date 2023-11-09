/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "Kingdom"
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
#define Mask(j) (1<<(j))
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 6e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k ; 
vi g[N] ; 


void doc()
{
	cin>> n >> m >> k; 
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

namespace sub1
{
	int h[N] ; 
	int a[2*N] ;
	int Start[N] ; 
	int in[N] , out[N] ; 
	int timedfs = 0 ;
	int tt = 0 ;
	int at[N] ;
	int st[2*N][LO+5] ;
	void dfs(int u ,int p)
	{
		in[u]=++timedfs ;
		at[timedfs] = u ;

		a[++tt] = in[u] ;  
		Start[u] = tt ;  

		for(auto v :g[u])if(v!=p)
		{
			h[v]=h[u]+1 ; 
			dfs(v,u) ; 
			a[++tt] = in[u] ; 
		}
	}
	void rmq()
	{
		FOR(i,1,tt)st[i][0] = a[i] ; 
		FOR(j,1,lg(tt))FOR(i,1,tt-Mask(j)+1)
		{
			st[i][j] = min(st[i][j-1],st[i+Mask(j-1)][j-1]) ; 
		}
	}
	int lca(int u ,int v)
	{
		int l = Start[u] ; 
		int r = Start[v] ;
		if(l>r)swap(l,r) ;
		int k = lg(r-l+1) ;
		return at[min(st[l][k],st[r-(1<<k)+1][k])] ; 
	}
	int dis(int u ,int v)
	{
		int c = lca(u,v) ;
		return h[u]+h[v]-2*h[c] ; 
	}
	int EDGE = 0 ;
	set<int>S ; 
	void them(int u )
	{
		if(S.empty())
		{
			S.insert(in[u]) ;
			return ;  
		}
		if(SZ(S)==1)
		{
			int v = at[*S.begin()] ;
			EDGE+=2*dis(u,v) ; 
			S.insert(in[u]); 
			return ; 
		}
		auto it = S.UB(in[u]) ;
		int L = 0 ,R = 0 ; 
		if(it==S.begin()||it==S.end())
		{
			L = at[*S.begin()] ; 
			R = at[*S.rbegin()] ; 
		}
		else
		{
			L = at[*it] ; 
			--it ; 
			R = at[*it] ; 
		}
		EDGE =  EDGE - dis(L,R) + dis(L,u)+ dis(R,u) ; 
		S.insert(in[u]) ; 
	}
	void xoa(int u )
	{
		S.erase(in[u]) ;
		if(S.empty())return ;
		if(SZ(S)==1)
		{
			int v = at[*S.begin()] ;
			EDGE-=2*dis(u,v) ; 
			return ;  
		}
		auto it = S.UB(in[u]) ;
		int L = 0 ,R = 0 ; 
		if(it==S.begin()||it==S.end())
		{
			L = at[*S.rbegin()] ; 
			R = at[*S.begin()] ; 
		}
		else
		{
			L = at[*it] ; 
			--it ; 
			R = at[*it] ; 
		}
		EDGE =  EDGE + dis(L,R) - dis(L,u) - dis(R,u) ; 
	}
    void xuly()
    {   
 	   	dfs(1,0) ; 
    	rmq() ; 
    	int it = 1 ; 
    	int res = 0 ;
    	FOR(i,1,n)
    	{		
    		them(i) ; 
    		// cout<<it<<" "<<i<<" "<<EDGE<<el;
    		while(EDGE/2>k-1)
    		{
    			xoa(it) ; 
    			++it; 
    			// cout<<it<<" "<<i<<" "<<EDGE<<el;
    		}
    		maxi(res,i-it+1) ; 
    	}
    	cout<<res; 
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