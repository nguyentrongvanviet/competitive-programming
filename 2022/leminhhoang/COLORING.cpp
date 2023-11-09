#define TASK "COLORING"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>ne vll vector<ll> 
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
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
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

const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ,  m; 
int V(int i , int j )
{
	return m*(i-1)+j ; 
}
struct DL
{
	int u , v  , c1 , c2; 
	bool operator<(const DL&a)const
	{
		return c1<a.c1||(c1==a.c1&&c2<a.c2) ; 
	}
};
vector<DL>q ; 
int a[N] ,pa[N] , sz[N] ; 
int p[N] , s[N] ;
int res= 0 ; 
int goc(int u , int pa[] )
{
	return pa[u]==u?u:pa[u]=goc(pa[u],pa) ;
}
void hop(int u , int v,int pa[],int sz[])
{
	int cu = goc(u,pa) ; 
	int cv = goc(v,pa) ; 
	if(cu==cv)return ; 
	pa[cu]=cv; 
	sz[cv]+=sz[cu] ;
	res=max(res,sz[cv]);
}
void read()
{
	cin>> n >> m ; 
	FOR(i,1,n*m)pa[i] = i,sz[i]=1;
	FOR(i,1,n)FOR(j,1,m)
	{
		int u = V(i,j) ; 
		int x = V(i-1,j) ; 
		int y = V(i,j-1) ; 
		cin>>a[u] ; 
		if(i>1&&a[u]==a[x])hop(u,x,pa,sz); 
		if(j>1&&a[u]==a[y])hop(u,y,pa,sz);
		if(i>1&&a[u]!=a[x])
		{
			q.pb({u,x,min(a[u],a[x]),max(a[u],a[x])});
		}
		if(j>1&&a[u]!=a[y])
		{
			q.pb({u,y,min(a[u],a[y]),max(a[u],a[y])});
		}
	}
	sort(all(q)) ; 
}

void solve()
{
	FOR(i,1,n*m)
	{
		p[i] = pa[i] ;
		s[i] = sz[i] ;
	}
	for(int i= 0 ;i<q.size();)
	{
		int j=  i ; 
		while(j<q.size()&&q[j].c1==q[i].c1&&q[j].c2==q[i].c2)
		{
			hop(q[j].u,q[j].v,p,s);
			++j; 
		}
		i =j ;
	}
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