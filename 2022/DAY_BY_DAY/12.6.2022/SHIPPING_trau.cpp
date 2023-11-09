#define TASK "SHIPPING"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
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
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".ANS","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , q, M; 
ll a[N] ;
vi g[N] ; 
ll res=0 ;
void dfs(int u ,int p ,ll val)
{
	val+=a[u] ; 
	res=max(res,val); 
	for(auto v :g[u])if(v!=p)
	{
		dfs(v,u,val);
	}
}
void read()
{
	cin>> n >>q >>M;
	FOR(i,1,n)cin>>a[i] ;
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v); 
		g[v].pb(u); 
	} 
	res=-inf ; 
	for(int i=1 ;i<=n;i++)dfs(i,0,0);
	ll ans= res;  
	FOR(i,1,q)
	{
		int u , c; 
		cin>>u>>c;
		if(M)
		{
			u=(u-1+abs(ans))%n+1;
			c= pow(-1,i%2)*((abs(c)+abs(ans))%M);
		}
		a[u]=c; 
		res= -inf ;  
		for(int i= 1;i<=n;i++)dfs(i,0,0); 
		cout<<res<<el;
		ans=  res;
	}
}

void solve()
{

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