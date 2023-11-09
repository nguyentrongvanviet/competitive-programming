#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
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
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
 tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e6+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n,m,D,cnt;
vi g[N];
vector<pii> edgs;
int dd[N],par[N],z[N],ddd[N];
void dfs(int u)
{
	dd[u] = cnt;
	for(auto v : g[u])
	{
		if(dd[v]!=0) continue;
		if(v == 1) continue;
		dfs(v);
	}
}
int Find(int u)
{
	if(u == par[u]) return u;
	return par[u] = Find(par[u]);
}
void doc()
{
	cin>>n>>m>>D;
	for(int i=1;i<=n;i++) par[i] = i;
	for(int i=1;i<=m;i++) 
	{
		int x,y; cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		edgs.pb({x,y});
	}
	for(int i=2;i<=n;i++)
	{
		if(dd[i] == 0) 
		{
			cnt++;
			dfs(i);
		}
	}
	if(g[1].size() < D || cnt > D) cout<<"NO"<<'\n';
	else
	{
		cout<<"YES"<<'\n';
		for(auto v : g[1])
		{
			if(z[dd[v]] == 0) 
			{
				D--;
				par[v] = 1;
				ddd[v] = 1;
				z[dd[v]] = 1;
				cout<<1<<" "<<v<<'\n';
			}
		}
		for(auto v : g[1])
		{
			if(D>0&&ddd[v] == 0)
			{
				D--;
				ddd[v] = 1;
				par[v] = 1;
				cout<<1<<" "<<v<<'\n';
			}
		}
		for(auto o : edgs)
		{
			if(o.fi == 1) continue;
			if(o.se == 1) continue;
			int r1 = Find(o.fi),r2 = Find(o.se);
			if(r1 != r2)
			{
				par[r1] = r2;
				cout<<o.fi<<" "<<o.se<<'\n'; 
			} 
		}	
	}
}

void xuly()
{

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