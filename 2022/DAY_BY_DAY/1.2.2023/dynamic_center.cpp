#define TASK "dynamic_center"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}

const int N =3e5+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , h[N] , h1[N],h2[N]  ; 
vi g[N] ; 
void read()
{
	cin>> n ; 
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}	
void dfs(int u , int p ,int h[] )
{
	for(auto v :g[u])
	{
		if(v==p)continue;  
		h[v] = h[u] + 1; 
		dfs(v,u,h) ; 
	}
}
void solve()
{		
	dfs(1,0,h) ;
	int st = 1 ; 
	FOR(i,1,n)if(h[st]<=h[i])st = i;  
	dfs(st,0,h1) ;
	int en = 1 ;
	int ans =  0; 
	FOR(i,1,n)if(h1[en]<=h1[i])
	{
		en = i,ans=max(ans,h1[i]);
	}
	dfs(en,0,h2) ; 
	FOR(i,1,n)
	{
		cout<<max(ans,max(h1[i],h2[i])+1)<<el;
	}
}		

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}