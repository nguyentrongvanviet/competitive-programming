#include<bits/stdc++.h>
using namespace std;

#define TASK "village2022"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}
#define vvi vector<vector<int>>
const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n ; 
ll a[N] ; 
ll f[N][2][2] ; 
vector<int>g[N] ; 
ll dp[N][2] ; 
void dfs(int u , int p )
{
	f[u][1][0]=f[u][1][1]=f[u][0][1]=a[u]; 
	for(auto v : g[u])
	{
		if(v==p)continue ; 
		dfs(v,u); 
		f[u][1][1] =f[u][1][1]+max(f[v][1][0],f[v][1][1]); 
		f[u][0][1] =f[u][0][1]+max(f[v][1][0],f[v][1][1]);
		f[u][1][0] =f[u][1][0]+max(f[v][0][1],f[v][0][0]);
	}
	dp[0][1]=-oo;
	for(int i= 1 ;i<=g[u].size();i++)
	{
		int v= g[u][i-1];
		if(v==p)
		{
			dp[i][0]=dp[i-1][0] ; 
			dp[i][1] =dp[i-1][1];
			continue;
		}
		dp[i][0] =dp[i-1][0] + f[v][0][0] ; 
		dp[i][1] =max(dp[i-1][1]+max(f[v][0][0],f[v][0][1]),dp[i-1][0]+f[v][0][1]);
	} 
	f[u][0][0]= max(dp[g[u].size()][0],a[u]+dp[g[u].size()][1]);
}
void doc()
{
    cin>> n ;
	FOR(i,1,n)cin>>a[i] ;
    FOR(i,1,n)
	{
		g[i].clear() ; 
	}
	memset(f,0,sizeof(f)); 
    FOR(i,1,n-1)
    {
    	int u ,v ; 
    	cin>>u>>v;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
    dfs(1,0);
    // cout<<f[1][0][0]<<endl;
    cout<<max(f[1][0][1],f[1][0][0])<<"\n";
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int t; 
    cin>>t ; 
    while(t--)
    {
   		doc(); 
   		xuly();
	}
}