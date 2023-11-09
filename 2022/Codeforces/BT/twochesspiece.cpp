#define TASK "text"
#include<bits/stdc++.h>
using namespace std;

const bool multitest = false;

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second

#define pb push_back
#define pk pop_back
#define all(a) a.begin(),a.end() 
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   

#define print(a) for(auto  v: a )cout<<v<<" ";

ll sq(ll a ){return a*a;}
ll gcd(ll a, ll b )  {return b==0 ? a:gcd(b,a%b);}
ll lcm(ll a , ll b ){ return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
}
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , d ; 
int p[N][maxN] ;
vi g[N] ;
int f[2][N]; 
void doc()
{
	cin>> n >>d;
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u) ;
	}
}
void dfs(int u , int pa)
{
	for(auto v: g[u])
	{	
		if(v==pa)continue ; 
		p[v][0] = u ; 
		dfs(v,u) ; 
	}
}
int goup(int u , int d)
{
	FORN(i,0,maxN)
	{
		if(d>>i&1) u= p[u][i] ; 
	}
	return u ; 
}
void dfsout(int u ,int pa ,int i )
{
	int tmp = 0 ;
	for(auto v :g[u])
	{
		if(v==pa)continue ;
		dfsout(v,u,i);
		tmp|=f[i][v];
	}
	f[i][u]|=tmp ;
}
void xuly()
{
    dfs(1,0) ; 
    FORN(j,1,maxN)
    {
    	FOR(i,1,n)
    	{
    		p[i][j] = p[p[i][j-1]][j-1] ;
    	}
    }
    FOR(i,0,1)
    {
    	int m ; cin>>m ; 
    	FOR(j,1,m)
    	{	
    		int u ; cin>>u ;
    		f[i][u]++;
    		// cout<<goup(u,d)<<endl;
    		f[i^1][goup(u,d)]=1; 
    	}
    }

    FOR(i,0,1)dfsout(1,0,i);
    int res=0 ;
    FOR(i,2,n)
    {
      	FOR(j,0,1)if(f[j][i])res+=2; 
    }
    cout<<res;
}
signed main()
{
    IOS();
    int test= 1;
    if(multitest)cin>>test; 
    while(test--)
    {
        doc() ;  
        xuly() ;  
    }
} 	