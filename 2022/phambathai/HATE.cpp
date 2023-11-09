#include<bits/stdc++.h>

#define TASK "HATE"
const bool multitest = true;  
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
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
vi g[N] ; 
void read()
{
    cin>> n;
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    	int v; cin>>v ; 
    	g[i].pb(v) ; 
    	g[v].pb(u) ; 
    } 
}
int fi =0 ; 
vi CT ; s

void dfs(int u ,int p )
{
	dd[u] =1 ; 
	for(auto v :g[u])
	{
		if(v==u||ok)continue ;
		if(dd[v])
		{
			ok = v; 
			return ;	
		}	
		pre[v] =  u ; 
		dfs(v,u); 
	}
}	
ll DFS(int u , int p , int j)
{
	for(auto v: g[u])
	{
		if(v==p)continue ;
		if(j==1)
		{

		}		
		else
		{

		}
	}
	return f[u][j] ; 
}
void process()
{
	ll res =0  ; 
	FOR(i,1,n)
	{
		if(!dd[i])
		{
			ok = 0 ;
			dfs(i,0) ; 
			if(ok)
			{

			} 	
			else
			{
				res+=DFS(i,0);
			}
		}
	}
	cout<<res;
}
void print()
{
    
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