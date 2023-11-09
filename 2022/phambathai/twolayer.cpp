#define TASK "twolayer"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct ke
{
	int v  ; 
	ll w , l ;  
} ; 
struct BG
{
	int u ; 
	ll val; 
}; 
struct cmp
{
	bool operator()(BG a ,BG b)
	{
		return a.val>b.val; 
	}
};
int n , m;
ll a[N] ; 
ve<ke>g[N] ;
bool dd[N] ; 
ll d[N] ,f[N] ;
ll cost[N] ;
void read()
{
	cin>> n >> m; 
	FOR(i,1,n)cin>>a[i]; 
	FOR(i,1,m)
	{
		int u ,v ;ll  w, l ; cin>>u>>v>>w>>l; 
		g[u].pb({v,w,l}) ; 
		g[v].pb({u,w,l}) ; 
	}
}
void dij(int s , ll f[])
{
	priority_queue<BG,ve<BG>,cmp>q ;
	FOR(i,1,n)f[i] = inf,dd[i]=0; 
	f[s] = 0;  
	q.push({s,f[s]}); 
	while(!q.empty())
	{
		int u =q.top().u ;
		q.pop() ;  ; 
		if(dd[u])continue;
		dd[u] =1; 
		for(auto x : g[u])
		{
			int v =x.v; 
			ll w= x.w ;
			if(dd[v])continue ;
			if(f[v]>f[u]+w)
			{
				q.push({v,f[v]=f[u]+w}) ; 
			}
		} 	
	}
}
void solve()
{
	dij(1,f) ; 
	dij(n,d) ;
	priority_queue<BG,ve<BG>,cmp>q; 
	FOR(i,1,n)
	{
		dd[i] =0 ; 
		cost[i]= a[i] ; 
		q.push({i,cost[i]}) ;
	}
	while(!q.empty())
	{
		int u= q.top().u; 
		q.pop() ; 
		if(dd[u])continue ;
		for(auto x : g[u])
		{
			int v= x.v; 
			ll w = x.w+x.l; 
			if(dd[v])continue ;
			if(cost[v]>cost[u]+w)
			{
				q.push({v,cost[v]=cost[u]+w}) ;
			}
		}
	}
	ll res= inf ;
	FOR(i,1,n)
	{
		res=min(res,f[i]+d[i]+cost[i]);
	}
	cout<<res;
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}