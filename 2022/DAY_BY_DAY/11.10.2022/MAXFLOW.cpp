/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "maxflow"
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
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ; 
int s, t;  
ll c[N][N]; 
vi g[N] ;
void doc()
{
    cin>> n >> m;
    s=1 , t = n;  
    // cin>>s>>t ;  
    FOR(i,1,m)
    {
    	int u ,v , w; 
    	cin>>u>>v>>w; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ;  
    	c[u][v]+=w ;
    }
}

namespace sub1
{
	int pa[N] ; 
	bool bfs(int s ,int t){
		queue<int>q; 
		FOR(i,1,n)pa[i] = 0 ;
		q.push(s) ; 
		while(!q.empty())
		{
			int u = q.front() ;
			q.pop() ;
			for(auto v:g[u])if(pa[v]==0&&c[u][v]>0)
			{	
				pa[v] = u ;  
				q.push(v) ; 
				if(v==t )return 1 ; 
			}
		}
		return 0 ; 
	}
	void flow(int s, int t )
	{
    	ll res = 0 ; 
        while(bfs(s,t))
        {
        	ll mi = inf ;
        	for(int u = t ; u!=s ; u=pa[u])
        	{
        		int v= pa[u] ; 
        		mini(mi,c[v][u]) ;
        	}
        	res+=mi ; 
        	for(int u = t ; u!=s ; u=pa[u])
        	{
        		int v = pa[u] ; 
        		c[v][u]-=mi ; 
        		c[u][v]+=mi ;
        	}
        }
        cout<<res<<el; 
	}
    void xuly()
    {
    	flow(s,t); 
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