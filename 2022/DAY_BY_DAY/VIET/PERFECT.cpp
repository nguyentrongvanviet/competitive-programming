#define TASK "text"
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
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n  , k ;
ll res= 0 ;
vi g[N];
int bit[N] ; 
int get(int idx)
{
	int ans= 0 ; 
	for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
	return ans ; 
}
void up(int idx,int val )
{
	for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
}
int dd[N]; 
void read()
{
	cin>> n >>k ; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ;
		dd[v] =1 ; 
	}
}
void dfs(int u ,int p)
{
	res+=get(min(n,u+k))-get(max(u-k-1,0)) ; 
	up(u,1) ;
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u) ; 
	}
	up(u,-1) ;
}
void solve()
{
	int h  ; 
	FOR(i,1,n)if(dd[i]==0)
	{
		h= i  ;
		break;  
	}
	dfs(h,0) ; 
	cout<<res;
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