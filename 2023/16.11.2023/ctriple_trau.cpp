/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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
const int N = 2e5+5 , oo = 1e9 , LO = 17 , CH = 26 ; 


int n; 
int a[N]  ; 
vi g[N] ;

void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v;  cin>> u >> v;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}
int nt[N] ;
int cnt[N]; 
void sang()
{
	FOR(i,2,2e5)if(nt[i]==0)
	{
		nt[i] = i ;
		FOR(j,i,2e5/i)nt[i*j] = i; 
	}
	FOR(i,2,2e5)
	{
		int tmp = i ; 
		while(tmp!=1)
		{
			int u =nt[tmp] ;
			cnt[i]++ ;  
			while(tmp%u==0)
			{
				tmp/=u ; 
			}
		}
	}
}
namespace sub1
{
	const int N = 205;  
	int C[N][N] ; 
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		FOR(j,1,n)C[i][j] = oo ; 
    		C[i][i] = 0 ; 
    	}
    	FOR(u,1,n)for(auto v : g[u]){
    		C[u][v]  =1 ; 
    	}
    	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)mini(C[i][j],C[i][k]+C[k][j]) ;
    	ll res = 0 ;
    	FOR(i,1,n)FOR(j,i+1,n)FOR(k,j+1,n)
    	{
    		int val = gcd(gcd(a[i],a[j]),a[k]); 
    		int dis = (C[i][j]+C[j][k]+C[i][k])/2; 
    		res+=1ll*dis*cnt[val] ; 
    	}
    	cout<<res;
    }
}
namespace sub2
{
	ll sz[N][3] ; 
	ll f[N][3] ; 
	ll res = 0 ;
	void dfs(int u ,int p)
	{
		for(auto v : g[u])if(v!=p)
		{
			dfs(v,u) ;
			(res+=f[u][1]*sz[v][2]%sm+(f[v][2]+sz[v][2])*sz[u][1]%sm)%=sm;
			(res+=f[u][2]*sz[v][1]%sm+(f[v][1]+sz[v][1])*sz[u][2]%sm)%=sm; 
			(f[u][2]+=f[u][1]*sz[v][1]%sm+(f[v][1]+sz[v][1])*sz[u][1]%sm)%=sm ; 
			(f[u][2]+=f[v][2]+sz[v][2])%=sm ; 
			(f[u][1]+=f[v][1]+sz[v][1])%=sm ;
			(sz[u][2]+=sz[u][1]*sz[v][1]%sm)%=sm ;
			(sz[u][2]+=sz[v][2])%=sm ;
			(sz[u][1]+=sz[v][1])%=sm ; 
			// cout<<res<<" "<<f[u][1]<<" "<<f[u][2]<<" "<<sz[u][1]<<" "<<sz[u][2]<<el;
		}
		if(a[u]==2)
		{
			(res+=f[u][2])%=sm;
			(sz[u][2]+=sz[u][1])%=sm ; 
			sz[u][1]++ ; 
		}
	}
	void xuly()
	{
		dfs(1,0) ; 
		cout<<res ; 
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
        sang() ; 
        if(n<=200)sub1::xuly() ; 
    	else 
    	if(*max_element(a+1,a+n+1)==2)
    	{
    		sub2::xuly() ;
    	}	
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}