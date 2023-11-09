#define TASK "GCHESS"
#include<bits/stdc++.h>
using namespace std;

const bool multitest = false;

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second

#define pb push_back
#define pk pop_back
#define all(a) a.begin(),a.end() 
#define el '\n' 
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define printv(a) for(auto v: a )cout<<v.fi<<" "<<v.se<<'\n';
#define print(a) for(auto  v: a )cout<<v<<" ";cout<<'\n';
#define here cout<<" RUN OK "<<'\n';
ll sq(ll a ){return a*a;}
ll gcd(ll a, ll b )  {return b==0 ? a:gcd(b,a%b);}
ll lcm(ll a , ll b ){ return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
}
const int N =1e3+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,-1,-2,-2,-1,1,2,2,1}; 
int yy[] = {0,-2,-1,1,2,2,1,-1,-2};

int n , m , k;  
int S ,T ; 
int pre[N*N] ; 
map<int,int>cap[N*N];
int ok[N*N];
vi L , R ;  
int dd[N*N];
vi g[N*N]; 
int out[N*N];
int c(int x,int y) {return m*(x-1)+y;}
void doc()
{
    cin>>n>>m>>k;  
    FOR(i,1,k)
    {
    	int x, y ; cin>>x>>y ; 
    	dd[c(x,y)] = 1; 
    }
}
bool bfs(int s, int t )
{
	FOR(i,s,t)pre[i] =-1  ;
	queue<int>q; 
	q.push(s);  
	pre[s] = 1  ; 
	while(!q.empty())
	{
		int u= q.front() ;
		q.pop() ; 
		for(auto v : g[u])
		{
			if(pre[v]!=-1||cap[u][v]<=0)continue ; 
			pre[v] = u ; 
			q.push(v) ;
			if(v==t)return 1;  
		}
	}
	return 0 ; 
}
int maxflow(int s , int t)
{
	int ans =0 ; 
	while(bfs(s,t))
	{
		++ans; 
		for(int v= t;v!=s;v=pre[v])
		{
			int u=  pre[v] ; 
			cap[u][v]--; 
			cap[v][u]++;
		}
	}
	return ans; 
}
bool in(int x , int y )
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
struct SAT
{
	int low[N*N] , id[N*N]  , tp[N*N] ,  tplt = 0 , tt= 0 ;
	stack<int>st; 
	vi g[N*N];
	void add_edge(int u , int nu , int v , int nv )
	{
		u = u<<1^nu ;
		v = v<<1^nv ; 
		g[u^1].pb(v) ; 	
		g[v^1].pb(u) ; 
	}
	void dfs(int u )
	{
		low[u] = id[u] = ++tt; 
		st.push(u); 
		for(auto v : g[u])
		{
			if(tp[v])continue ; 
			if(id[v])
			{
				low[u] =min(low[u],id[v]) ;
			}
			else
			{
				dfs(v) ; 
				low[u] = min(low[u],low[v]) ;
			}
		}
		if(low[u]==id[u])
		{
			int t;
			++tplt ;   
			do
			{	
				t=st.top() ; 
				st.pop() ;
				tp[t] = tplt;  
			}	
			while(u!=t);
		}
	} 
	void solve()
	{
		FOR(i,1,n*m)if(id[i]==0&&out[i]==0&&dd[i]==0)dfs(i);
	}
}two_sat;
vi res ;
void xuly()
{
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(dd[c(i,j)])continue ; 
			int u=c(i,j);
			// cout<<i<<" "<<j<<" "<<c(i,j)<<endl;
			if(abs(i-j)%2==0)L.pb(u); 
			else R.pb(u);
		}
	}
	// cout<<L.size()<<" "<<R.size()<<endl;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			int u = c(i,j); 	
			if(u%2==1||dd[c(i,j)])continue ;
			FOR(t,1,8)
			{	
				int nx=i+xx[t] ;
				int ny=j+yy[t] ; 
				if(in(nx,ny)&&dd[c(nx,ny)]==0)
				{
					int v = c(nx,ny);
					g[u].pb(v) ;
					g[v].pb(u) ; 
					cap[u][v] =1 ;
					cap[v][u] =0 ;
				}
			}
		}
	}
	S= 0 ; 
	T=n*m+1; 
	for(auto v: L )
	{
		g[0].pb(v) ;
		g[v].pb(0) ; 
		cap[0][v]=1; 
		cap[v][0]=0;
	}	
	for(auto v: R )
	{
		g[v].pb(T);
		g[T].pb(v);
		cap[v][T] =1 ; 
		cap[T][v] =0 ;
	}
    for(auto u :L ) 
    {
    	for(auto v : g[u])
    	{
    		if(cap[u][v]==0)
    		{
    			ok[u]=ok[v]=1;
    		}
    	}
    }
    maxflow(S,T) ;
}
void xaydung(vi L )
{
	for(auto u : L)
    {
    	if(g[u].size()==1)
    	{
    		res.pb(u);
    		out[u] =1; 
    		continue;
    	}
    	for(auto  v : g[u])
    	{
    		if(cap[u][v]==0)
    		{
    			two_sat.add_edge(u,1,v,1) ; 
    			two_sat.add_edge(u,0,v,0) ; 
    		}
    		else
    		{
    			if(dd[u]&&dd[v])
    			{
    				two_sat.add_edge(u,1,v,1);
    			}
    			else
    			{
    				two_sat.add_edge(u,1,v,1) ;
    				if(ok[u])two_sat.add_edge(u,1,u,1);
    				else two_sat.add_edge(v,1,v,1);
    			}
    		}
    	}
    }
    for(auto u:  R )
    {
    	if(g[u].size()==1)
    	{
    		res.pb(u); 
    		out[u]=1;
    		continue ;
    	}
    }
}
void build()
{
    xaydung(L);	
    two_sat.solve();	
    FOR(i,1,m*n)
    {
    	if(out[i]||dd[i])continue;
    	if(two_sat.tp[i<<1^1]==two_sat.tp[i<<1])cout<<i<<" WA "<<endl;
    	if(two_sat.tp[i<<1^1]<two_sat.tp[i<<1])continue;
    	else res.pb(i); 
    }
    cout<<res.size()<<endl;
    for(auto v : res)
    {
    	int x = 1+v/m-(v%m==0); 
    	int y = v-m*(x-1);
    	cout<<x<<" "<<y<<endl;
    } 	
}
signed main()
{
    IOS();
    int test= 1;
    if(multitest)cin>>test; 
    while(test--)
    {
        doc() ;  
        xuly() ; 
        build() ; 
    }
}
