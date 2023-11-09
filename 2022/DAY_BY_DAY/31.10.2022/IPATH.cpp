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
const int LO = 22 ;
int n ; 
int pa[N][LO];
ll c[N][LO] ; 
void doc()
{
 	cin>> n>>q; 
 	for(int i= 1;i<=n-1;i++)
 	{
 		int u , v;  cin>>u>>v ; 
 		g[u].pb(v) ; 
 		g[v].pb(u) ; 
 	}   
}
void predfs(int u , int p)
{
	sz[u] =1 ; 
	f[u][0] =1 ; 
	for(int i= 0;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ; 
		h[v]=h[u]+1; 
		pa[v][0]=u; 
		predfs(v,u);
		f[u][0]+=sz[v]*f[u][0];
	}
}
void xuly()
{
	predfs(1,0) ; 
	lo =log2(n);
	for(int j =1;j<=lo;j++)
	{
		for(int i= 1;i<=n;i++)
		{
			pa[i][j] = pa[pa[i][j-1]][j-1] ; 
			c[i][j] =c[i][j-1]+c[pa[i][j-1]][j-1] ;
		}
	}
	while(m--)
	{
		int u ,v ; 
		cin>>u>>v  ; 
		cout<<lca(u,v)<<"\n"; 
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