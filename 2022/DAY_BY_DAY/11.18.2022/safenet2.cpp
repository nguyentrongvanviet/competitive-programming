#include<bits/stdc++.h>
using namespace std;

#define TASK "safenet2"

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
int n  , m ;
int low[N] , id[N] ; 
vector<int>g[N] ;
int tt= 0 ; 
int res= 0 ; 
int f[N] ; 
int ma = 0 ; 
int dd[N];
void dfs(int u ,int p   )
{
	id[u] =low[u]=++tt;
	f[u] =1; 
	for(auto v : g[u])
	{
		if(v==p)continue;
		if(id[v])
		{
			low[u] = min(low[u],id[v]) ; 
		}
		else 
		{
			dfs(v,u); 
			low[u] = min(low[u],low[v]) ; 
			if(id[u]>low[v])
			{
				f[u]+=f[v];
			}
		}
		
	}
	// res =max(res,f[u]);
	// cout<<u<<" "<<f[u]<<"\n";
	ma=max(ma,f[u]+1);
} 
void doc()
{
   	cin>>n>> m;  
   	FOR(i,1,m)
   	{
   		int u ,v ; 
   		cin>>u>>v; 
   		g[u].pb(v) ; 
   		g[v].pb(u) ; 
   	}
	int res= 1; 
	if(m==0)
	{
		cout<<1 ; 
		return ;
	}

   	FOR(i,1,n)
   	{
   		if(id[i])continue;
   		ma= 0 ; 
   		dfs(i,0); 
   		res=max(res,ma); 
   	}
   	cout<<res;
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