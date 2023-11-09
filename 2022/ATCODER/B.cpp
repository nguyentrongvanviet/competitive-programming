#define TASK "B"
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
const int N =2e3+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , d; 
vi g[N] ; 
int dis[N][N]; 
int res=oo ; 
pii E[N] ;
void read()
{
	cin>> n >>d ; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ;
		E[i]={u,v} ;
	}
}
void dfs(int u , int p , int root)
{
	for(auto v :g[u])
	{
		if(v==p)continue;  
		dis[root][v] = dis[root][u]+1; 
		dfs(v,u,root) ;
	}
}
void solve()
{
	FOR(i,1,n)dfs(i,0,i);
	
	if(d&1)
	{
		for(int i= 1 ;i<=n-1;i++)
		{
			int cnt =0 ; 	
			for(int j= 1 ;j<=n;j++)
			{
				if(min(dis[E[i].fi][j],dis[E[i].se][j])>d/2)cnt++ ; 
			}
			res=min(res,cnt) ; 
		}
	}	
	else
	{
		for(int i= 1 ;i<=n;i++)
		{
			int cnt= 0 ;
			for(int j= 1;j<=n;j++)
			{
				if(dis[i][j]>d/2)cnt++;
			}
			res=min(res,cnt) ; 
		}
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