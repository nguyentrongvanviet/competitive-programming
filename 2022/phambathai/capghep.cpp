#define TASK "text"
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
#define print(a) for(auto  v: a )cout<<v<<" ";

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
const int N =2e3+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ,m  , x ; 
vi g[N] ; 
int cap[N][N] ;	
int pre[N] ; 
void doc()
{
	cin>> n >>m >> x; 
	FOR(i,1,x)
	{
		int u , v; cin>>u>>v ;
		v+=n ; 
		g[u].pb(v);
		g[v].pb(u);
		cap[u][v]=1;
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
int maxflow(int s = 0 , int t=n+m+1)
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
void xuly()
{
	FOR(i,1,n)g[0].pb(i),g[i].pb(0),cap[0][i]=1; 
	FOR(i,1,m)g[i+n].pb(m+n+1),cap[i+n][m+n+1] =1 ;

	int res= maxflow(); 
	cout<<res;
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
    }
}