#include<bits/stdc++.h>

// #define TASK "CAMERA"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define int long long 
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
struct Edges 
{
	int u , v , w;  
};
int n , m , k ;
ve<Edges>q , E; 
vi g[N] ; 
int tp[N] ,low[N],id[N] , tplt =0 ,tt= 0 ; 
bool dd[N] , spec[N] ;
stack<int>st;  
int ans=-1 ; 
void read()
{
    cin>> n >> m >> k; 
    FOR(i,1,m)
    {
    	int u , v, w ; 
    	cin>>u>>v>>w ; 
    	if(w==-1)q.pb({u,v,w}),spec[u]=1,spec[v]=1;
    	else if(w>0)E.pb({u,v,w});
    }
    m = E.size();
}
void add(int u , int nu , int v , int nv )
{
	u= u<<1^nu ; 
	v= v<<1^nv ;  
	dd[u] = dd[u^1] =dd[v] = dd[v^1] =1 ; 
	g[u^1].pb(v) ;
	g[v^1].pb(u) ;
}
void dfs(int u )
{
	low[u]  = id[u] = ++tt;  
	st.push(u) ; 
	for(auto v :g[u])
	{
		if(tp[v])continue ; 
		if(!id[v])
		{
			dfs(v); 
			low[u]=min(low[u],low[v]);
		}
		else
		{
			low[u] =min(low[u],id[v]); 
		}
	}
	if(low[u]==id[u])
	{
		int t;  
		tplt++ ;
		do
		{
			t =st.top() ; 
			st.pop() ; 
			tp[t] =tplt;  
		}while(t!=u);
	}
}
bool check(int val)
{
	FOR(i,(1<<1),(n<<1^1))g[i].clear(),tp[i]=low[i]=id[i]=dd[i]=tt=tplt=0;
	FORN(i,0,E.size())
	{
		int w  =E[i].w ; 
		if(w<=val)continue; 
		int u = E[i].u;  
		int v = E[i].v; 
		if(u==v)
		{
			if(spec[u])add(u,1,v,1);
		}
		if(spec[u]&&spec[v])add(u,1,v,1);
		else if(spec[u])add(u,1,u,1),add(u,1,v,1),add(u,0,v,0);
		else if(spec[v])add(v,1,v,1),add(u,1,v,1),add(u,0,v,0); 
		else return 0 ; 
	}
	FORN(i,0,q.size())
	{
		int u =q[i].u ; 
		int v= q[i].v ; 
		if(u==v)
		{
			add(u,1,u,1);
		}
		else
		{
			add(u,0,v,0) ;
			add(u,1,v,1) ;
		}
	}
	FOR(i,(1<<1),(n<<1^1))if(dd[i]&&!id[i])dfs(i);
	FOR(i,(1<<1),(n<<1^1))if(dd[i]&&tp[i]==tp[i^1]){return 0;} 
	return 1;
}
void process()
{
    int l=0;
    int r= oo;
    ans = -1 ;
    while(l<=r)
    {
    	int mid =(l+r)/2 ;
    	if(check(mid))
    	{
    		ans= mid ; 
    		r=mid-1 ; 
    	}
    	else
    	{
    		l=mid+1;
    	}
    } 
}
void print()
{
	int res= ans;  
    cout<<res<<'\n';
    int x = check(res);
    FOR(i,1,n)
    {
    	if(spec[i])
    	{
    		if(tp[i<<1^1]<tp[i<<1])
    		{
    			cout<<i<<" ";
    		}
    	}
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
        print(); 
    }
    return 0 ; 
}