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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ,q ;
int Kind[256] ;
struct ke
{
	int v ;
	int TYPE ;
}; 
ve<ke>g[N] ;
struct Query
{
	int TYPE , u , v; 
}Q[N] ; 
void doc()
{
	Kind['A']=1 ;
	Kind['R']=0 ;
	Kind['Q']=2 ; 
	cin>> n>> q ;     
	FOR(i,1,q)
	{
		char T ; int u ,v ; 
		cin>> T >> u >>v ;
		int TYPE  = Kind[(int)T] ; 
		Q[i] = {TYPE,u,v} ; 
		if(TYPE!=2)
		{
			g[u].pb({v,TYPE}) ;  
			g[v].pb({u,TYPE}) ; 
		}
	}
}

namespace sub1
{
	int color[N] ; 
	void dfs(int u,int c  )
	{
		color[u] = c; 
		for(auto x:g[u])
		{
			int v= x.v ; 
			int TYPE = x.TYPE ; 
			if(color[v]==-1)
			{
				dfs(v,c^TYPE) ; 
			}
			else
			{
				assert(color[v]==(c^TYPE));
			}
		}
	}		
	int pa[N] ; 
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
	}
	void hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return  ; 
		pa[chau] = chav; 
	}
    void xuly()
    {   
    	FOR(i,1,n)color[i] = -1 ; 
    	FOR(i,1,n)if(color[i]==-1)
    	{
    		dfs(i,0) ; 
    	}
    	FOR(i,1,n)pa[i] = i; 
    	FOR(i,1,q)
    	{
    		int u =Q[i].u ; 
    		int v =Q[i].v ; 
    		int TYPE = Q[i].TYPE ;
    		if(TYPE!=2)hop(u,v); 
    		else
    		{
    			if(goc(u)!=goc(v))cout<<'?'<<el ; 
    			else if(color[u]==(color[v]^1))
    			{
    				cout<<'A'<<el;
    			}
    			else
    			{
    				cout<<'R'<<el;
    			}
    		}
    	}
    }	
}
namespace sub2
{
	int pa[N] ; 
	int sz[N] ;
	int dis = 0 ;
	struct DL
	{
		int root ;
		int dis;  
	} ; 
	DL pa[N] ; 
	DL goc(int u ,int p)
	{
		while(pa[u].root!=)
	}
	int hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
	}
	void xuly()
	{
		FOR(i,1,q)
		{
			int u = E[i].u ; 
			int v = E[i].v ; 
			int TYPE = E[i].TYPE ;
			if(TYPE!=2){
				hop(u,v) ; 
			}
			else
			{
				DL U = goc(u) ; 
				DL V = goc(v) ;
				if(U.root!=V.root)cout<<'?'<<el ; 
				else
				{
					if(U.dis!=V.dis)cout<<'A'<<el; 
					else cout<<'R'<<el;
				}
			}
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