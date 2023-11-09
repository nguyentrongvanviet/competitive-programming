#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 2e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 666013 ; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n; 
vi g[N] ;
ll fac[N] , inv_fac[N] ;  
ll res= 1; 
int sz[N] ; 
ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  	
	return b*b%sm ;
}
ll C(int k ,int n )
{
	return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
}
void doc()
{
   	cin>> n; 
   	FOR(i,1,n-1)
   	{
   		int u , v; cin>>u>>v; 
   		g[u].pb(v) ; 
   		g[v].pb(u) ; 
   	}
   	fac[0] = inv_fac[0] = 1; 
   	FOR(i,1,n)fac[i] = fac[i-1]*i%sm ,  inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm ; 
}       
void dfs(int u ,int p)
{
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u) ;
		sz[u]+=sz[v] ; 
		res = res*C(sz[v],sz[u])%sm ;  
	}
	sz[u]++ ; 
}
void xuly()
{
 	dfs(1,0) ; 
 	cout<<res;    
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}