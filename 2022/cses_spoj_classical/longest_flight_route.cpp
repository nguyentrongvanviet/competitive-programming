#include<bits/stdc++.h>
using namespace std;

#define TASK "longest_flight_route"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n, m ; 
vector<int>g[N] ; 
int f[N] ;
int dd[N];  
int able[N] ; 
void dfs(int u)
{
	if(dd[u])return ; 
	dd[u] =1 ; 
	if(u==n)
	{
		able[u] = 1;  
		f[u] = 1; 
		return ; 
	}
	for(auto v : g[u])
	{
		dfs(v) ; 
		if(able[v])
		{
			able[u] =1;
			f[u] =max(f[u],f[v]+1) ;  
		} 
	}
}
void dfsout(int u)
{
	cout<<u<<" ";
	for(auto v : g[u])
	{
		if(f[u]==f[v]+1)
		{
			dfsout(v);
			return ;
		}
	}
}
void doc()
{
 	cin>>n >> m ;
 	FOR(i,1,m)
 	{
 		int u ,v ; 
 		cin>>u>>v; 
 		g[u].pb(v) ; 
 	}   
 	dfs(1) ; 
 	if(f[1]==0)
 	{
 		cout<<"IMPOSSIBLE";
 		return ; 
 	}
 	cout<<f[1]<<"\n";
 	dfsout(1); 
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}