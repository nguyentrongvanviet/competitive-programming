#define TASK "Knight"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define IOS fast ;  if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
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

const int N =1e2+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,-1,-2,-2,-1,1,2,2,1}; 
int yy[] = {0,-2,-1,1,2,2,1,-1,-2};
int n , m , k ; 
int X[N*N] , dd[N*N] , In[N*N] , ok[2*N*N] ;
ve<pii>res; 
ve<pii>E ; 
struct max_flow
{
	ve<unordered_map<int,int>>cap; 
	ve<vi>g;
	vi dd, pre;
	void init(int n )
	{
		cap.resize(n+1) ; 
		dd.resize(n+1) ; 
		pre.resize(n+1) ; 
		g.resize(n+1) ;
	}
	void add_edge(int u ,int v )
	{
		g[u].pb(v) ; 
		g[v].pb(u) ; 
		cap[u][v] = 1 ; 
		cap[v][u] = 0 ; 
	}
	bool bfs(int s , int t )
	{
		FOR(i,s,t)dd[i] = 0; 
		queue<int>q; 
		q.push(s);  
		while(!q.empty())
		{
			int u= q.front() ;
			q.pop() ; 
			for(auto v : g[u])
			{
				if(dd[v]||cap[u][v]<=0)continue ;
				pre[v]= u ; 
				dd[v]= 1; 
				q.push(v) ; 
				if(v==t)return 1; 
			}
		}
		return 0 ; 
	}
	int maxflow(int s, int t)
	{	
		int ans= 0 ;
		while(bfs(s,t))
		{
			++ans; 
			for(int v= t ;v!=s;v=pre[v])
			{
				int u= pre[v] ; 
				cap[u][v]-- ; 
				cap[v][u]++ ;
			}
		}
		return ans; 
	}
}MF;
struct two_sat
{
	ve<vi>g ; 
	vi tp ,low,id ; 
	stack<int>st;  
	int tt=0 , tplt =0 ; 
	void init(int  n)
	{
		g.resize(2*(n+1)) ;
		tp.resize(2*(n+1)); 
		low.resize(2*(n+1)) ;
		id.resize(2*(n+1)) ; 
	}
	void add_edge(int u , int nu , int v, int nv)
	{
		u = u<<1^nu ;
		v = v<<1^nv ; 
		g[u^1].pb(v) ; 
		g[v^1].pb(u) ;
		ok[u]=ok[u^1]=1 ; 
		ok[v]=ok[v^1]=1 ;
	}
	void dfs(int u )
	{
		low[u] = id[u] =++tt;
		st.push(u) ; 
		for(auto v :g[u])
		{
			if(tp[v])continue ; 
			if(id[v])
			{
				low[u] = min(low[u],id[v]) ; 
			}
			else
			{
				dfs(v) ; 
				low[u] = min(low[u],low[v]) ;
			}
		}
		if(low[u]==id[u])
		{
			int t ; 
			++tplt ; 
			do
			{
				t=st.top() ; 
				st.pop() ;
				tp[t] =tplt ;
			}while(t!=u);
		}
	}
	void solve()
	{
		FOR(i,(1<<1),((n*m)<<1^1))
		{
			if(ok[i]&&id[i]==0)dfs(i);
		}
		FOR(i,1,n*m)
		if(ok[i<<1^1])
		{
			if(tp[i<<1^1]<tp[i<<1])continue; 
			int x=  1+i/m-(i%m==0);
			res.pb({x,i-m*(x-1)});
		}	
	}
}SAT;
int V(int x , int y )
{
	return m*(x-1)+y ; 
}
bool in(int x ,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
void read()
{	
	cin>> n>> m >>k ; 
	MF.init(n*m+5) ; 
	SAT.init(n*m+5) ;
	FOR(i,1,k)
	{
		int x, y; cin>>x>>y;
		X[V(x,y)] = 1; 
	}
	FOR(x,1,n)FOR(y,1,m)if((x-y)%2==0&&X[V(x,y)]!=1)
	{		
		FOR(t,1,8)
		{
			int nx = x+xx[t] ; 
			int ny = y+yy[t] ;
			int u = V(x,y); 
			int v =V(nx,ny) ;
			if(X[V(nx,ny)]||!in(nx,ny))continue ;
			In[V(x,y)]= 1 ; 
			In[V(nx,ny)]=1 ;
			MF.add_edge(V(x,y),V(nx,ny)) ; 
			E.pb({u,v});
		}
	}		
	FOR(i,1,n)FOR(j,1,m)if(X[V(i,j)]==0)
	{
		if(In[V(i,j)]==0)res.pb({i,j});
		else 
		{
			if((i-j)%2==0)MF.add_edge(0,V(i,j)); 
			else MF.add_edge(V(i,j),n*m+1);
		}
	}
}
pii INV(int d)
{
	int x = 1+d/m-(d%m==0);
	return {x,d-(x-1)*m};
}
int spec[N*N];
void solve()
{
			int T = 0 ;
	int match = MF.maxflow(0,n*m+1) ; 
	for(auto e : E)
	{
		int u =e.fi ; 
		int v =e.se ; 
		if(MF.cap[u][v]==0)
		{
			SAT.add_edge(u,1,v,1) ;
			SAT.add_edge(u,0,v,0) ;
			spec[u]=1 ; 
			spec[v]= 1; 
		}	
	}
	for(auto e : E)
	{
		int u =e.fi ; 
		int v =e.se ; 
		pii A = INV(u) ; 
		pii B = INV(v) ;
		if(MF.cap[u][v]==1)
		{
			SAT.add_edge(u,1,v,1);
			if(spec[u]&&spec[v])continue;
			else if(spec[u])SAT.add_edge(u,1,u,1),SAT.add_edge(v,0,v,0);
			else SAT.add_edge(v,1,v,1),SAT.add_edge(u,0,u,0);
		}
	}
	SAT.solve(); 	
}	
void write()
{
	cout<<res.size()<<'\n';
	for(auto v: res)cout<<v.fi<<" "<<v.se<<el; 
}
signed main()
{
    IOS ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
        write() ; 
    }
}