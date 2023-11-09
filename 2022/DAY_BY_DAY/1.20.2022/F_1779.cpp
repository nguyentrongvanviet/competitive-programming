#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
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
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ; 
int a[N] ; 
vi g[N] ; 
int sz[N] ;  
int sum[N];
int ok[N][32];
pii pre[N][32];
int dd[N]  ;
void read()
{			
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,2,n)
	{
		int u ; cin>>u ; 
		g[u].pb(i) ; 
		g[i].pb(u) ; 
	}
}
void dfs(int u ,int p)
{
	sz[u] = 1; 
	sum[u] = a[u] ; 
	vi tmp(32,0) , cur(32,0) ; 
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u) ; 
		sum[u]^=sum[v] ; 	
		sz[u]+=sz[v] ;
		FOR(i,0,31)if(ok[v][i])
		{
			if(tmp[i]==0)
			{
				pre[u][i] = {v,i} ; 
				cur[i] = 1 ; 
			}
			FOR(j,0,31)if(tmp[j]&&tmp[i^j]==0)
			{
				pre[u][i^j]={v,i};
				cur[i^j]=1 ;
			} 
		}
		FOR(i,0,31)tmp[i]=cur[i];
	}
	FOR(i,0,31)ok[u][i]=tmp[i] ;
	if(sz[u]%2==0)ok[u][sum[u]]=1,pre[u][sum[u]]=mp(0,0);
} 
vi res ;
void dfsout(int u , int tot )
{	
	dd[u] = 1; 	
	if(pre[u][tot]==mp(0,0))
	{
		res.pb(u) ; 
		return ; 
	}
	for(int i = tot , tmp = 0 ; tmp!=tot;tmp^=pre[u][i].se , i = (i^pre[u][i].se))
	{
		dfsout(pre[u][i].fi,pre[u][i].se);
	}
}
void solve()
{
	dfs(1,0);
	if(n%2==0||sum[1]==0)return void(cout<<2<<el<<1<<" "<<1);	
	if(ok[1][sum[1]]==0)return void(cout<<"-1");
	dfsout(1,sum[1]);
	cout<<res.size()+1<<el;
	for(auto v : res)cout<<v<<" ";
	cout<<1;
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