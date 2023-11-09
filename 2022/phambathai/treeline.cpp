#include<bits/stdc++.h>

#define TASK "treeline"
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
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct Edge
{
	int u ,v , w; 
	bool operator<(const Edge&a)const
	{
		return w>a.w; 
	}
}; 
int n , q ; 
Edge E[N] ;  
vi Q[N] ;
int st[4*N] ; 
int a[N] ;
int pa[N] , pre[N] , Ne[N] , pos[N],tail[N] ;
vi node[N] ;
int res[N] ;
void read()
{
    cin>> n; 
    FORN(i,1,n)
    {
    	int u ,v , w ; 
    	cin>>u>>v>>w; 
    	E[i]={u,v,w};
    }
    cin>>q; 
    FOR(i,1,q)
    {
    	int k ; cin>> k ; 
    	while(k--)
    	{
    		int u ; cin>> u ; 
    		Q[i].pb(u) ; 
    	}	
    }
}

void build(int id , int l , int r )
{
	if(l==r)
	{
		st[id] =a[l] ; 
		return ; 
	}
	int mid =(l+r)/2; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id]= min(st[id*2],st[id*2+1]) ; 
}
int get(int id , int l , int r ,int t,  int p)
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return oo ; 
	int mid =(l+r)/2; 
	return min(get(id*2,l,mid,t,p) , get(id*2+1,mid+1,r,t,p)) ;
}
int goc(int u )
{
	return pa[u] == u ? u : pa[u] = goc(pa[u]) ;
}
void Go(int u , int v, int w )
{
	u= goc(u) ; v =goc(v) ; 
	pa[u] = v; 
	Ne[u] = w;
	pre[tail[v]]= u ;
	tail[v] =tail[u] ;
}
bool cmp(int u  ,int v)
{
	return pos[u] <pos[v] ;
}
int query(vi node)
{
	sort(all(node),cmp);
	int res=-oo ;
	for(int i = 0;i<node.size()-1;i++)
	{
		int u = node[i] ; 
		int v= node[i+1];
		u = pos[u]  ;
		v= pos[v]-1;
		res=max(res,get(1,1,n-1,u,v)) ;  
	}
	return res; 
}
void process()
{
    sort(E+1,E+n) ;
    FOR(i,1,n)pa[i]=i, node[i].pb(i), pa[i]= i ,Ne[i]=0,tail[i] = i ;
    FORN(i,1,n)Go(E[i].u,E[i].v,E[i].w) ;
    int cnt= 0 ;
    int v=goc(1);
    for(int i = n-1;i>=1;v=pre[v],i--)
    {
    	pos[v] =i+1;
    	int  u=pre[v] ; 
    	a[i] = Ne[u] ; 
    }
    pos[v] = 1; 
    build(1,1,n-1) ;
    FOR(i,1,q)
	{
		res[i] =query(Q[i]);
	}
}
void print()
{
	FOR(i,1,q)
	{
		cout<<res[i]<<'\n';
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