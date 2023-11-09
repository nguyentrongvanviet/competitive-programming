#define TASK "skilevel"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
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
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =5e2+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,-1}; 
int yy[] = {0,-1,0};


int n , m ; 
int T ;
int a[N*N] ; 
int h[N][N] ;
int pa[N*N]  ,sz[N*N] , sl[N*N] ;
int D[N*N] ; 
int V(int x , int y )
{
	return m*(x-1)+y;  
}
bool in(int x, int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m; 
}
struct DL
{
	int u , v;
	int c ; 
	bool operator<(const DL&a)const
	{
		return c<a.c;  
	}  
}; 
ve<DL>q; 
void read()
{
	cin>>n >>m >> T ; 
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>> a[V(i,j)] ;
	}
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>>D[V(i,j)];
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			int u = V(i,j) ; 
			FOR(t,1,2)
			{
				int ni = i+xx[t] ; 
				int nj = j+yy[t] ; 
				if(!in(ni,nj))continue ; 
				int v= V(ni,nj) ; 
				q.pb({u,v,abs(a[u]-a[v])}); 
			}
		}
	}
}
int goc(int u)
{
	return pa[u] ==u  ? u : pa[u]=goc(pa[u]) ;
} 
ll res= 0 ; 
void hop(int u ,int v,int c )
{
	u = goc(u) ; 
	v = goc(v) ;
	if(u==v)return ;
	int a = sl[u] ; 
	int b = sl[v] ; 
	if(a)
	{
		if(sz[u]<T&&sz[u]+sz[v]>=T)res+=a*c; 
	}
	if(b)
	{
		if(sz[v]<T&&sz[u]+sz[v]>=T)res+=b*c;
	}
	sl[v]+=sl[u] ; 
	sz[v]+=sz[u] ; 
	pa[u] = v; 
}
void solve()
{
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			int u= V(i,j) ; 
			if(D[u]==1)sl[u]= 1;  
			pa[u]= u; 
			sz[u] =1;  
		}
	}
	sort(all(q));
	for(auto x: q)
	{
		int u= x.u ; 
		int v=x.v ; 
		int c= x.c; 
		hop(u,v,c) ; 
	}
	cout<<res;
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}