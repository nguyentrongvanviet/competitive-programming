#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
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
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n;  
vi g[N] ; 
int id[N] , low[N] ; 
stack<int>st; 
bool ok  ; 
int tt = 0 , tplt =0 ; 
int tp[N] ; 
int dd[N] , h[N] ;
void doc()
{
	cin>> n ; 
	FOR(i,1,n)
	{
		int k ; cin>> k ; 
		FOR(j,1,k)
		{
			int x; cin>>x; 
			g[i].pb(x);
		}
	}
}	


void dfs(int u )
{
	st.push(u) ; 
	id[u] = low[u] =++tt;
	for(auto v: g[u])
	{	
		if(tp[v])continue ;
		if(id[v])low[u] = min(low[u],id[v]) ; 
		else 
		{
			dfs(v) ; 
			low[u] =min(low[u],low[v]) ;
		}
	}
	if(low[u]==id[u])
	{
		int t ; 
		++tplt; 
		int sz = 0 ;
		do
		{
			t =st.top() ; 
			st.pop() ; 
			tp[t]=tplt;
			++sz;  
		}
		while(t!=u);
		if(sz>1)ok=0 ;
	}
}
void go(int u)
{
	if(dd[u])return ; 
	dd[u] = 1 ; 
	h[u] =1 ;
	for(auto v :g[u])
	{
		go(v) ; 
		if(v>u)h[u]=max(h[u],h[v]+1);
		else h[u] =max(h[u],h[v]);
	}
}
void xuly()
{
	ok =1 ; 
	FOR(i,1,n)if(id[i]==0)
	{
		dfs(i) ;
		if(ok==0)return void(cout<<-1<<el);
	}
	FOR(i,1,n)
	{
		if(dd[i]==0)go(i);
	}
	int res=0 ; 
	FOR(i,1,n)res=max(res,h[i]) ;
	cout<<res<<el;
}
void clear()
{
	tplt = 0 ; 
	tt = 0 ;
	FOR(i,1,n)
	{
		g[i].clear() ; 
		dd[i] = id[i] = low[i] = tp[i] = h[i] = 0 ; 
	}
}
signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
        clear();
    }
}