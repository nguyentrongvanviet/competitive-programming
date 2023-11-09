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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 250000+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ;
vi g[N] ;
int deg[N] ; 
struct ke
{
	int v , c ;
} ; 
struct Edge
{
	int u ,v , w ; 
} E[N] ;
ve<ke>adj[N] ;
void doc()
{
    cin>> n >> m; 
    FOR(i,1,n-1)
    {
    	int u ,v ; 
    	cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    	E[i]={u,v}; 
		deg[u]^=1 ; 
		deg[v]^=1 ; 
   	}
   	while(m--)
   	{
   		int u , v, c; 
   		cin>>u>>v>>c ;
   		adj[u].pb({v,c}) ;
   		adj[v].pb({u,c}) ; 
   	}
}	

namespace sub1
{ 
	int f[N] ;
	int goc[N] ; 
	vi node ;
	int ans = 0 ; 
	int cnt = 0 ; 
	void dfs(int u,int root)
	{
		goc[u] = root;
		node.pb(u) ;  
		if(deg[u])
		{
			cnt^=1 ; 
			ans^=f[u] ; 
		}
		for(auto x:adj[u])	
		{	
			int v = x.v ;
			int c = x.c ; 
			if(goc[v])
			{
				if(f[v]!=(f[u]^c))
				{
					cout<<"No"; 
					exit(0) ; 
				}
			}
			else
			{
				f[v] = f[u]^c;
				dfs(v,root) ;
			}
		}
	}
	int tplt = 0 ; 
	vi res  ; 
    void xuly()	
    {	

    	FOR(i,1,n)if(goc[i]==0)
    	{
    		node.clear() ; 
    		dfs(i,i) ; 
    		++tplt ; 
    		if(cnt&&res.size()==0)
    		{
    			for(auto v : node)res.pb(v) ; 
    		}
    	}	
    	for(auto v: res)f[v]^=ans; 
    	cout<<"Yes"<<el;
    	FOR(i,1,n-1)
    	{
    		cout<<(f[E[i].u]^f[E[i].v])<<" ";
    	}
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}