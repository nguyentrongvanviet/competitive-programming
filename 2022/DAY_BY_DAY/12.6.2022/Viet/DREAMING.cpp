#define TASK "DREAMING"
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
struct ke
{
	int v; 
	ll w; 
}; 
int n , m  ; 
ll L; 
ve<ke> g[N];
void read()
{
	cin>> n >> m>> L ; 
	FOR(i,1,m)
	{
		int  u ,v ; ll w; 
		cin>>u>>v>>w;
		++u ; 
		++v ;
		g[u].pb({v,w});  
		g[v].pb({u,w}); 
	}
}
int dd[N]; 
vi node ; 
ll res =0 ;
void dfsh(int u , int p,ll h[])
{	
	node.pb(u) ;
	for(auto x :g[u])
	{
		int v= x.v; 
		if(v==p)continue; 
		h[v] =h[u]+x.w;
		dfsh(v,u,h);
	}
}
ll h[N],H[N];
ll dia(int u )
{	
	node.clear() ; 
	dfsh(u,0,h); 
	int x= 0 ;
	for(auto v :node)if(h[x]<=h[v])x=v;
	node.clear() ; 
	dfsh(x,0,H);
	int y= 0;
	for(auto v :node)if(H[y]<=H[v])y=v;
	res=max(res,h[y]); 
	node.clear() ; 
	dfsh(y,0,h) ;
	ll ans = inf ;
	for(auto v: node)
	{
		ans=min(ans,max(H[v],h[v]));
	} 
	for(auto v : node)dd[v] = 1;
	return ans; 
}
void solve()
{
	vll q; 
	FOR(i,1,n)
	{
		if(dd[i]==0)
		{
			q.pb(dia(i));
		}
	}
	sort(all(q),greater<ll>()) ;
	ll cen = q[0]  ; 
	res=max(res,cen+L+q[1]);
	if(q.size()>=3)res=max(res,2*L+q[1]+q[2]); 
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