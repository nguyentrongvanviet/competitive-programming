#include<bits/stdc++.h>

#define TASK "FLIGHT"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n  ,m ; 
int low[N] , id[N];
vi g[N] ; 
stack<int>st;  
int tp[N], dd[N] ;
int tplt=0  , tt = 0; 
void dfs(int u )
{
	low[u] = id[u] =++tt; 
	st.push(u) ; 
	for(auto v: g[u])
	{
		if(tp[v])continue;
		if(!id[v])
		{
			dfs(v) ; 
			low[u] =min(low[u],low[v]) ; 
		}
		else
		{
			low[u] =min(low[u],id[v]) ;
		}
	}
	if(low[u]==id[u])
	{
		int t;  
		++tplt ; 
		do
		{
			t= st.top();
			tp[t] = tplt;  
			st.pop() ; 
		}while(t!=u);
	}	
}
void add(int x,int nx , int y , int ny)
{
	x = (x<<1^nx) ; 
	y = (y<<1^ny) ; 
	g[x^1].pb(y) ; 
	g[y^1].pb(x) ;
}
void read()
{
	cin>>n>> m; 
	FOR(i,1,n)
	{
		int t , x ,y; 
		cin>>t>>x>>y; 
		if(x==y)
		{
			if(t==1)
			{
				g[x<<1].pb(x<<1^1) ;
				
			}
			else
			{
				g[x<<1^1].pb(x<<1);
			}
		}
		else if(t==0)
		{
			add(x,1,y,0);
			add(x,0,y,1);
		}
		else if(t==1)
		{
			add(x,1,y,1) ; 
			add(x,0,y,0) ;
		}
	}
}
void process()
{
    FOR(i,(1<<1),(m<<1^1))if(!tp[i])dfs(i);
}	
void print()
{
	FOR(i,1,m)
	{
		if(tp[i<<1]==tp[i<<1^1]){cout<<-1;return;}
	}
	vi res; 
	FOR(i,1,m)
	{
		if(tp[i<<1]>tp[i<<1^1]) 
		{
			res.pb(i) ;
		}
	}
	cout<<res.size()<<'\n';
	for(auto x : res)
	{
		cout<<x<<' ';
	}
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
}