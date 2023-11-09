#include<bits/stdc++.h>
using namespace std;

#define TASK ""

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
const int LO = 20 ; 
int n ; 
vector<int>g[N] ;
int sz[N]  , h[N] ; 
int f[N][LO]; 
int pa[N][LO]; 
void doc()
{ 		
    cin>> n>> q; 
    for(int i= 1;i<=n-1;i++)
    {
    	int u ,v ; cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    } 
}
void predfs(int u , int p)
{
	f[u] =1 ; 
	sz[u] =1; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ;
		h[v]=h[u]+1;
		predfs(v,u);
		pa[v][0] =u ; 
		f[u]+=sz[u]*sz[v];
		sz[u]+=sz[v];
	}
}
int lca(int u , int v )
{	
	if(h[u]<h[v])swap(u,v) ; 
	int dis=  h[u] -h[v] ; 
	ll ans= 0 ; 
	for(int i=  0 ;i<=18;i++)
	{
		if(dis>>i&1)
		{

		}
	}
}
void sub()
{
	predfs(1,0);
	for(int j =1 ;j<=18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			pa[i][j] = pa[pa[i][j-1]][j-1];
			f[i][j]  =  f[i][j-1]+f[pa[i][j-1]][j-1];
		}
	}
	while(q--)
	{
		int u , v;
		cin>>u>>v ; 
		int x= lca(u,v) ;
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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