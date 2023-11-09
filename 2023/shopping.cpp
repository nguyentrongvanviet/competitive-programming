/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "shopping"
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


int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e3+5 , oo = 50+(int)1e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
int n ; 
int B ; 
vi g[N] ;
int cost[N] , sale[N] ; 
void doc()
{
	cin>> n >> B ; 
	FOR(i,1,n)
	{
		cin>>cost[i]>>sale[i] ; 
		sale[i] = cost[i] - sale[i] ; 
		if(i>1)
		{	
			int u ; cin>>u ; 
			g[u].pb(i) ;
		}
	}
}

namespace sub1
{
	int f[N][N][2] ;
	int cur[N][N][2] ; 
	int sz[N] ; 
	void up(int &a ,int x )
	{
		a = min(a,min(oo,x)) ;
	}
	void dfs(int u)
	{ 
		for(auto v:g[u])dfs(v) ;
		f[u][0][0] = 0 ;
		f[u][0][1] = 0 ;  
		for(auto v:g[u])
		{
			FOR(i,0,sz[u]+sz[v])cur[u][i][0]=cur[u][i][1]= oo;
			FOR(i,0,sz[u])
			{
				FOR(j,1,sz[v])
				{
					up(cur[u][i+j][0],f[u][i][0]+f[v][j][0]);
					up(cur[u][i+j][1],min(f[u][i][0],f[u][i][1])+min(f[v][j][0],f[v][j][1]));
				}
			}
			sz[u]+=sz[v];
			FOR(i,0,sz[u])
			{
				mini(f[u][i][0] , cur[u][i][0] ); 
				mini(f[u][i][1] , cur[u][i][1] ); 
			}		
		}
		sz[u]++ ; 
		FORD(i,sz[u],1)
		{	
			up(f[u][i][0],f[u][i-1][0]+cost[u]) ;  
			f[u][i][1]=min(oo,min(f[u][i-1][0],f[u][i-1][1])+sale[u]) ; 
		}
	}

    void xuly()
    {	
    	FOR(i,1,n)FOR(j,0,n)FOR(ok,0,1)f[i][j][ok] = oo ; 
    	dfs(1) ; 
    	int res = 0 ; 
    	FORD(i,n,1)if(min(f[1][i][0],f[1][i][1])<=B)
    	{
    		res=i ; 
    		break;
    	}
    	cout<<res<<el;
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
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}