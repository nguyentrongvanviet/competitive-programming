#define TASK "D"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

const int N =5e5+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ,m , k ; 
vi g[N] ; 
int d[N] , f[N] ; 
int dd[N] ; 

void read()
{
	cin>>n>>m>>k; 
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

void bfs(int s, int f[])
{	
	queue<int>q;
	FOR(i,1,n)dd[i] = 0 ;  
	q.push(s) ; 
	dd[s]= 1; 
	f[s]  = 0 ; 
	while(!q.empty())
	{
		int u =q.front() ; 
		q.pop();
		for(auto v :g[u])
		{
			if(dd[v])continue; 
			f[v] =f[u]+1 ;
			dd[v] =1 ;
			q.push(v) ; 
		}
	}
}
int sld[N] , slf[N] ;
int s[N] ; 
void solve()
{
	bfs(1,d) ; 
	bfs(n,f) ;
	if(d[n]<k)
	{
		cout<<0; 
		return ; 
	}
	for(int i= 1;i<=n;i++)
	{
		sld[d[i]]++;
		slf[f[i]]++;
	}
	if(d[n]==k)
	{
		ll res = 0 ;
		FOR(i,0,n)
		{
			s[i] =(i?s[i-1]:0)+slf[i]; 
		}	
		FOR(i,0,n-1)
		{
			if(k-i-2>=0)res+=sld[i]*s[k-i-2];
		}	
		cout<<n*(n-1)/2-m-res;
		return ; 
	}
	ll res= 0 ;
	for(int i= 0 ; i<=n-1;i++)
	{
		int m = k-i-1; 
		if(m>=0)
		{
			res+=1LL*sld[i]*slf[m];
		}
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