/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "men-graph"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#pragma GCC target("popcnt")
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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
vi g[N] ;
struct Edge
{
	int u ,v; 
}E[(int)3e5+5] ;
void doc()
{	
    cin>> n >> m; 
    FOR(i,1,m)
    {
    	int u , v; cin>> u >> v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    	E[i] = {u,v} ;
    }
}

namespace sub1
{
	bitset<N>KE[600] ;
	int ID[N] ; 
	void add(int&a ,int b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	} 
 	int pw(int a, int n)
 	{
 		if(n==0)return 1; 
 		int b= pw(a,n/2) ;
 		if(b*b>=sm)
 		{
 			cout<<-2<<el;
 		}
 		if(n&1)return 1ll*b*b*a%sm;  
 		return 1ll*b*b%sm ;
 	}
	int fac[N] , inv_fac[N] ;
	int res = 0 ; 
	int C(int k ,int n)
	{
		if(k>n)return 0 ;
		return 1ll*fac[n]*inv_fac[k]*inv_fac[n-k]%sm; 
	}
 	void way(int L , int R ,int M)
 	{
 		FOR(i,0,3)add(res,1ll*C(3-i,L)*C(i,M)*C(2,R+M-i)%sm);
 	}
 	int dd[N] ;
	int deg[N] ;
	void solve1(int u ,int v)
	{ 
		int L = deg[u]-1 ; 
		int R = deg[v]-1 ;
		int M = 0 ; 
		for(auto x :g[u])dd[x]=1;
		for(auto x : g[v])M+=dd[x] ;  
		L-=M ; 
		R-=M ; 
		for(auto x :g[u])dd[x] = 0 ; 
		way(L,R,M);
		way(R,L,M); 
	}
	void solve2(int u ,int v)
	{
		int L = deg[u]-1 ; 
		int R = deg[v]-1 ;
		int M = (KE[ID[u]]&KE[ID[v]]).count() ; 
		L-=M ; 
		R-=M ; 
		way(L,R,M) ;
		way(R,L,M) ;
	}
	void solve3(int u ,int v)
	{
		if(deg[u]>deg[v])swap(u,v) ;
		int L = deg[u]-1 ; 
		int R = deg[v]-1 ;
		int M = 0; 
		for(auto x:g[u])M+=KE[ID[v]][x] ;
		L-=M; 
		R-=M; 
		way(L,R,M) ;
		way(R,L,M) ; 
	}
	//...
    void xuly()
    {
    	fac[0] = 1 ;
    	FOR(i,1,n)fac[i] = 1ll*fac[i-1]*i%sm ;
    	inv_fac[n] = pw(fac[n],sm-2) ; 
    	FORD(i,n-1,0)inv_fac[i] = 1ll*inv_fac[i+1]*(i+1)%sm ; 
    	FORD(i,n,0)if(inv_fac[i]<0||fac[i]<0)
    	{
    		cout<<i<<" "<<-1<<el
    		 ;
    		return ;
    	}
    	int B = sqrt(2*m) ; 
    	int tt = 0 ; 
    	FOR(i,1,n)
    	{
    		deg[i]=SZ(g[i]) ;
    		if(deg[i]>B)
    		{
    			ID[i] = ++tt ; 
    			for(auto u:g[i])KE[tt][u]=1;
    		}
    	}
    	FOR(i,1,m)
    	{
    		int u = E[i].u , v = E[i].v ;	
    		if(deg[u]<=B && deg[u]<=B)solve1(u,v) ;
    		else if(deg[u]>B && deg[v]>B)solve2(u,v) ; 
    		else solve3(u,v); 
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
    // cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}