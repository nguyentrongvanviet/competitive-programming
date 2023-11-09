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

#define prt(a,n) FOR(x,1,n)cout<<a[x]<<" "; cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ,  k;   
bool ok[N][51] ; 
vi g[N] ; 
struct node
{
	int u , idu  ; 
} ; 
int tt = 0 , tplt = 0 ;
int id[N][51] , low[N][51] , tp[N][51] , f[N*51] ;
int dd[N] ;
vi adj[N*51] ;
node st[N*51] ; 
int sz = 0  ; 
void doc()
{
    cin>> n >>m  >> k ;
    FOR(i,1,m)
    {
    	int u ,v ; cin>>u>>v; 
    	g[u].pb(v) ;
    }
    FOR(i,1,n)
    {
    	FOR(j,1,k)
    	{
    		char x; cin>>x;  
    		ok[i][j] = x-'0' ; 
    	}
    }
}

namespace sub1
{
	inline void dfs(int x )
	{ 
		int u  = x/k+(x%k!=0); 
		int idu = (x%k==0?k:x%k) ; 
		low[u][idu] = id[u][idu] = ++tt ;
		st[++sz]={u,idu} ; 
		for(auto v: g[u])
		{
			int idv = (idu==k?1:idu+1) ;
			if(tp[v][idv])continue ; 
			if(id[v][idv])
			{
				low[u][idu]=min(low[u][idu],id[v][idv]) ; 
			}
			else dfs((v-1)*k+idv),low[u][idu]=min(low[u][idu],low[v][idv]) ; 
		}
		if(low[u][idu]==id[u][idu])
		{	
			node t ; 
			++tplt ;
			int sl = 0 ;  
			do
			{		
				t=st[sz] ; 
				--sz ;  
				int u = t.u ; 
				int idu = t.idu ; 
				tp[u][idu] = tplt;  
				if(dd[u]!=tplt&&ok[u][idu])
				{
					dd[u] = tplt; 
					sl++ ;
				}
			}	
			while(t.u!=u||t.idu!=idu); 
			f[tplt] = sl ; 
		}	
	}
	int go[N*52] ; 
	int solve(int u )
	{
		if(go[u])return f[u] ;
		go[u] = 1 ;
		int ma =0 ; 
		for(auto v : adj[u])
		{
			ma=max(ma,solve(v)) ;  
		}
		f[u]+=ma ; 
		return f[u] ;  
	}
    void xuly()
    {   	
    	dfs(1) ;  
    	
    	FOR(u,1,n)
    	{
    		FOR(idu,1,k)
    		{
    			for(auto v:g[u])
    			{ 
    				int idv = (idu+1==k+1?1:idu+1); 
    				int X =tp[u][idu] ; 
    				int Y = tp[v][idv] ;
    				if(X!=Y)
    				{
    					adj[X].pb(Y) ; 
    				}
    			}
    		}
    	}
    	FOR(u,1,tplt)
    	{
    		int ma =0 ; 
    		for(auto v: adj[u])
    		{
    			ma=max(ma,f[v]) ;
    		}
    		f[u]+=ma;
    	}
    	cout<<f[tplt] ;
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
         // if(n==99/998 )sub2::xuly(),exit(0) ;
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}