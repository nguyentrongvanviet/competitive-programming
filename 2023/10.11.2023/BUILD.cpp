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
#define        Mask(i)  (1<<(i))
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
const int N = 1e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k; 

struct ke
{
	int v , w;  
} ; 
ve<ke>g[N] ;
int dd[N] ; 
vi node; 
void doc()
{
    cin>> n >> m >> k ; 
    FOR(i,1,k)
    {
    	int u ; cin>> u ;
    	dd[u] =1 ;
    	node.pb(u) ;
    }
    FOR(i,1,m)
    {
    	int u ,v , w ;
    	cin>>u  >>v >> w; 
    	g[u].pb({v,w}) ; 
    	g[v].pb({u,w}) ; 
    }
}

namespace sub1
{
	struct DL
	{
		int u ;
		ll val ; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a,const DL&b)const
		{
			return a.val>b.val; 
		}
	} ; 	
	ll dis[6][N]  ;
	void dij(int id,ll f[])
	{
		priority_queue<DL,ve<DL>,cmp>q  ; 
		FOR(i,1,n)f[i] = inf ; 
		q.push({node[id],f[node[id]]=0}) ;
		while(!q.empty())
		{
			int u =q.top().u ;
			ll val = q.top().val ;
			q.pop(); 
			if(f[u]<val)continue ; 
			for(auto x : g[u])
			{
				int v = x.v; 
				int w = x.w ;
				if(mini(f[v],val+w))
				{
					q.push({v,f[v]}) ; 
				}
			}
		}
	}	
	struct BG
	{
		int u ;
		int msk ; 
		ll val;  
	} ; 
	struct cmpBG
	{
		bool operator()(const BG&a,const BG&b)const
		{
			return a.val>b.val; 
		}
	}; 
	ll res[6][6] ;
	ll f[N][Mask(6)];
	void go(int id ,ll res[]) 
	{
		priority_queue<BG,ve<BG>,cmpBG>q ;
		FORN(i,0,k)
		{
			FORN(msk,0,Mask(k))f[i][msk] = inf; 
		}
		q.push({id,Mask(id),f[id][Mask(id)]=0}) ; 
		while(!q.empty())
		{
			int u = q.top().u ; 
			int msk = q.top().msk ; 
			ll val  = q.top().val;
			q.pop() ;
			if(f[u][msk]>val)continue ;
			FORN(i,0,k)if(BIT(msk,i)==0)
			{
				if(mini(f[i][msk|Mask(i)],f[u][msk]+dis[u][node[i]]))
				{	
					q.push({i,msk|Mask(i),f[i][msk|Mask(i)]}); 
				}		
			}
		}
		FORN(i,0,k)
		{
			res[i] = f[i][Mask(k)-1] ;
		}
	}
    void xuly()
    {
        FORN(i,0,k)
        {
        	dij(i,dis[i]) ; 
        }
        FORN(i,0,k)
        {		      
        	go(i,res[i]); 
        }
        ll min_path = inf ; 
        FOR(i,1,n)if(dd[i]==0)
        {
        	FORN(st,0,k)FORN(en,0,k)
        	{
        		ll tot_len = dis[st][i]+res[st][en]+dis[en][i] ; 
	        	mini(min_path,tot_len) ;	
	       	}
        }
        cout<<min_path;
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