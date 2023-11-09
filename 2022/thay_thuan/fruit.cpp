#define TASK "fruit"
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
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =250000+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
const int LO = 20 ; 
const int M = 4*N+__lg(N)*N;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , q ; 
int a[N] ; 
vi g[N] ; 
int h[N] ; 
int pa[N][LO+4];
int node = 0 ;
int head[N] , L[M] , R[M] ;
int st[M] ;
void read()
{
	cin>> n >> q; 
	FOR(i,1,n)cin>>a[i] ;
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
int update(int old ,int l, int r, int pos , int val)
{
	int cur = ++node; 
	if(l==r&&r==pos)
	{
		st[cur] = st[old] + val; 
		return cur ; 
	}
	int mid =(l+r)/2; 
	if(pos<=mid)
	{
		R[cur] = R[old] ;  
		L[cur] = update(L[old],l,mid,pos,val) ; 
	}
	else
	{
		L[cur] = L[old];
		R[cur] = update(R[old],mid+1,r,pos,val) ; 
	}
	st[cur] =st[L[cur]]+st[R[cur]] ; 
	return cur ; 
}
int get(int id, int l, int r, int t, int p )
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return 0 ; 
	int mid =(l+r)/2; 
	return get(L[id],l,mid,t,p) + get(R[id],mid+1,r,t,p) ; 
}
void dfs(int u ,int p)
{
	head[u] = update(head[p],1,n,a[u],1);
	for(auto v : g[u])if(v!=p)
	{
		pa[v][0] = u ; 
		h[v]=h[u]+1;
		dfs(v,u);
	}
}
pii lca(int u ,int v)
{
	int d= 0 ; 
	if(h[u]<h[v])swap(u,v) ;
	int dis = h[u]-h[v] ;
	FORN(i,0,LO)if(dis>>i&1)u= pa[u][i],d+=(1<<i) ;
	if(u==v)return {u,d} ; 
	FORD(i,LO-1,0)
	{
		int nu = pa[u][i] ; 
		int nv = pa[v][i] ; 
		if(nu==nv)continue; 
		d+=2*(1<<i);
		u=nu; 
		v=nv; 
	}
	return mp(pa[u][0],d+2);
}
int find(int id1, int id2, int id3 ,int id4,int l ,int r,int sz)
{	
	if(l==r)
	{
		if(st[id1]+st[id2]-st[id3]-st[id4]>sz)return l ; 
		return -1 ; 
	}
	int mid =(l+r)/2;
	if(st[L[id1]]+st[L[id2]]-st[L[id3]]-st[L[id4]]>sz)
		return find(L[id1],L[id2],L[id3],L[id4],l,mid,sz) ;
	if(st[R[id1]]+st[R[id2]]-st[R[id3]]-st[R[id4]]>sz)
		return find(R[id1],R[id2],R[id3],R[id4],mid+1,r,sz);
	return -1 ;
}
void solve()
{
	dfs(1,0);  
	FORN(j,1,LO)FOR(i,1,n)pa[i][j] = pa[pa[i][j-1]][j-1] ;
	FOR(i,1,q)
	{
		int u, v ;cin>>u>>v ; 
		pii tmp = lca(u,v) ; 
		tmp.se++;
		int res = find(head[u],head[v],head[tmp.fi],head[pa[tmp.fi][0]],1,n,tmp.se/2);
		cout<<res<<el;    	
	}
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