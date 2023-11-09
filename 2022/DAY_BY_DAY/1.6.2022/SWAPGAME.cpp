#define TASK "SWAPGAME"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false ; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
#define ll long long 
#define db double 
#define vi vector<int> 
#define vll vector<ll> 
#define pii pair<int,int> 
#define pll pair<ll,ll>  
#define ve vector  
#define str string 
#define pb push_back  
#define pk pop_back 
#define el '\n' 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc(a) __builtin_popcount(a)
ll sq(ll a){return a*a;} ; 
ll gcd(ll a, ll b ){return b==0? a : gcd(b,a%b);}
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
const int N = 2e5+5  , oo = 2e9 , CH = 26 ; 
const ll inf = 1e17  , cs =330 , sm = 1e9+7 ; 
const db PI = acos(-1) , eps=  1e-9;
int n  , a[N] , b[N] ; 
vi g[N] , CT  ; ve<vi>A ;  
int dd[N] ;
ll res , ans ; 
map<pii,int>sl ; 
void read() 
{	
	cin>> n ; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n)cin>>b[i] ;
}
void dfs(int u  ,int p )
{
	CT.pb(u) ; 
	dd[u] =1 ;
	for(auto v : g[u])
	{
		if(dd[v]||v==p)continue;
		dfs(v,u) ;  
	}
}

ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  
	else return b*b%sm ;
}
void solve()
{
	FOR(i,1,n)
	{
		if(a[i]==b[i])continue;  
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	FOR(i,1,n)if(dd[i]==0)
	{
		dd[i] = 1; 
		CT.clear() ;
		dfs(i,0); 
		A.pb(CT) ; 
	}
	ans=0  ; 
	for(auto q : A)
	{
		int mi = oo ; 
		map<pii,int>sl ; 
		for(auto u : q)for(auto i  : g[u])sl[{a[i],b[i]}]++;
		int tt = 0 ; 
		for(int i= 0;i<q.size()-1;i++)
		{
			if(tt==0)
			{
				if(sl[{q[i],q[i+1]}]!=0)
				{
					sl[{q[i],q[i+1]}]--;
				}
				else
				{
					ans++ ;
				}
			}
			else
			{
				
			}
			++tt ; 
		}
		sl.clear() ; 
		q.pk(); 
		ans+=mi;  
	}
}
void print()
{			
	res=pw(2,(ll)A.size());
	cout<<res<<el<<ans; 
}
signed  main()
{
	IOS() ; 
	int test=1 ; 
	if(multitest)cin>>test ;
	while(test--)
	{
		read() ; 
		solve() ; 
		print() ; 
	}
}