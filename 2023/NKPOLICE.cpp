/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , m; 
vi g[N] ; 
void doc()
{
	cin>> n >>m ; 
	FOR(i,1,m)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}	
namespace sub1
{
	int low[N] , id[N] ; 
	int art[N] ; 
	int tt = 0 ; 
	int OUT = 1 ; 
	int in[N] , out[N] ;
	int stt = 0 ; 
	int h[N] ; 
	int P[N][LO+1]; 
	void dfs(int u ,int p)
	{
		if(p==1)OUT++; 
		id[u] = low[u] = ++tt ; 
		in[u] = ++stt ; 
		for(auto v :g[u])
		{
			if(v==p)continue ;
			if(id[v])mini(low[u],id[v]) ;
			else 
			{
				P[v][0] = u ; 
				h[v] = h[u]+1 ; 
				dfs(v,u);
				mini(low[u],low[v]) ; 
				if(id[u]<=low[v])art[u] = 1; 
			}
		}
		out[u]=++stt ; 
	}
	int go(int u ,int c)
	{
		FORD(i,LO,0)
		{
			if(h[u]-(1<<i)>=h[c]+1)u=P[u][i] ; 
		}
		return u ; 
	}
	bool check_in(int u , int v )
	{	
		return in[v]<=in[u]&&out[u]<=out[v] ; 
	}
	bool check_bridge(int a , int b , int g1 , int g2)
	{
		if(id[g1]>id[g2])
		{
			swap(g1,g2) ; 
		}
		if(!(id[g1]<low[g2]))return 1 ; 
		if(check_in(a,g2)==check_in(b,g2))return 1 ;
		return 0 ; 
	}
	bool check_art(int a ,int b , int c )
    {
    	if(art[c]==0)return 1 ;  
    	if(check_in(a,c)==0&&check_in(b,c)==0)return 1 ; 
    	
    	if(check_in(a,c)&&check_in(b,c))
    	{
    		int X = go(a,c) ; 
    		int Y = go(b,c) ;
    		if(X==Y)return 1 ;
    		if(low[X]<id[c]&&low[Y]<id[c])return 1 ; 
    		return 0 ; 
    	}
    	if(check_in(b,c))swap(a,b) ; 
    	int X = go(a,c) ;   		
    	if(low[X]<id[c])return 1; 
    	return 0 ; 
    }
    void xuly()
    {
        dfs(1,0) ; 
        if(art[1]==1&&OUT<2)art[1]= 0 ; 
        FOR(j,1,LO)FOR(i,1,n)P[i][j] = P[P[i][j-1]][j-1] ; 
    	int q; 
    	cin>>q ;
    	while(q--)
    	{
    		int TYPE ; cin>>TYPE ; 
    		if(TYPE==1)
    		{
    			int a,b,g1,g2 ;cin>>a>>b>>g1>>g2;
 
    			cout<<(check_bridge(a,b,g1,g2)?"yes":"no")<<el;
    		}
    		else
    		{
    			int a, b , c;cin>>a>>b>>c ;
    			cout<<(check_art(a,b,c)?"yes":"no")<<el;
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
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