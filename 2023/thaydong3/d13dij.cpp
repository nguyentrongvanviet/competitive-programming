/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13dij"
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
const ll inf = 1e17 , cs = 331 , sm = 1e9+7; 
const int N = 4e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k ; 
struct ke
{
	int v,w ;
};
ll C[N][N] ;
ve<ke>g[N] , adj[N] ;
void doc()
{
	cin>> n >> m >> k; 
	FOR(i,1,n)
	{
		FOR(j,1,n)C[i][j] = inf ;	
		C[i][i] = 0 ;
	}
	FOR(i,1,m)
	{
		int u ,v ;ll  w; 
		cin>> u >>v >> w; 
		g[u].pb({v,w}) ;
		adj[v].pb({u,w}) ;
		mini(C[u][v],w) ;
	}  
}

namespace sub1
{
	struct DL
	{
		int u; ll val; 
	};
	struct cmp
	{
		bool operator()(const DL&a , const DL&b)const
		{
			return a.val>b.val; 
		}
	}; 
	priority_queue<DL,ve<DL>,cmp>q ;
	void dij(int u , ll f[],int ok  )
	{
		FOR(i,1,n+3)f[i] = inf ; 	
		q.push({u,f[u]=0}) ;
		while(!q.empty())
		{
			int u = q.top().u ;
			ll val =q.top().val ;
			q.pop() ;
			if(f[u]<val)continue ;
			if(ok==0)
			{
				for(auto x:g[u])
				{
					int v=x.v;
					int w=x.w; 
					if(mini(f[v],f[u]+w))
					{
						q.push({v,f[v]}) ;	
					}
				}
			}
			else
			{
				for(auto x:adj[u])
				{
					int v=x.v;
					int w=x.w; 
					if(mini(f[v],f[u]+w))
					{
						q.push({v,f[v]}) ;	
					}
				}
			}
		}
	}
	const int M = 2e5+5 ;	
	struct Edge
	{
		int u ,v ,w ;
	}; 
	Edge ADD[M] ;
	ll fg[4][N] , fadj[4][N] ;
    void xuly()
    {
    	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)mini(C[i][j],C[i][k]+C[k][j]) ;
    	while(k--)
    	{
    		int new_edge ;
    		cin>>new_edge ; 
    		FOR(i,1,new_edge)
    		{
    			int u ,v , w; 
    			cin>> u >>v >> w ;
    			ADD[i] = {u,v,w} ; 
    			g[u].pb({v,w}) ; 
    			adj[v].pb({u,w}) ;
    		}	
    		FOR(i,1,3)dij(n+i,fg[i],0),dij(n+i,fadj[i],1) ;
    		ll res = 0 ;	
    		FOR(i,1,n)FOR(j,1,n)
    		{
    			ll tmp = C[i][j] ;
    			FOR(mid,1,3)
    			{
    				mini(tmp,fadj[mid][i]+fg[mid][j]);
    			}
    			res+=tmp ;
    		}	
    		FOR(mid,1,3)FOR(i,1,n)
    		{
    			res+=fg[mid][i] ; 
    			res+=fadj[mid][i] ; 
    		}
    		FOR(u,1,3)FOR(v,1,3)res+=fg[u][v+n];
    		cout<<res<<el;
    		FOR(i,1,new_edge)
    		{
    			int u =ADD[i].u ;
    			int v =ADD[i].v ;
    			g[u].pk() ; 
    			adj[v].pk() ;
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