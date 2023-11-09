#include<bits/stdc++.h>
using namespace std;

#define TASK "sieuthitrungtam"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =3e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m ;
int tt  = 0 ;  
int low[N] , id[N] , dd[N] ;
vector<int>g[N] ;
int ans[N] ;
void dfs(int u , int p )
{
	low[u] = id[u]  =++tt ; 
	FOR(i,0,(int)g[u].size()-1)
	{
		int v= g[u][i]; 
		if(v==p)continue; 
		if(id[v])
		{
			low[u] =min(low[u],id[v]); 
		}
		else
		{
			dfs(v,u);
			low[u]= min(low[u],low[v]); 
			if(low[v]>=id[u])
			{
				ans[u]++;
			}
		}
	} 
}
void predfs(int u )
{
	dd[u ] = 1; 
	for(int v : g[u])
	{
		if(dd[v]==0)predfs(v);
	}
}
void doc()
{
 	cin>> n >> m; 
 	FOR(i,1,m)
 	{
 		int u , v; cin>>u>>v ; 
 		g[u].pb(v) ; 
 		g[v].pb(u) ; 
 	}
 	dfs(1,0);
 	int res= ans[1] ; 
 	int node = 1 ; 
 	FOR(i,2,n)
 	{
 		if(ans[i]+1>res)
 		{
 			res=ans[i]+1 ;
 			node= i ;
 		}
 	}
 	cout<<res<<" "<<node;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}