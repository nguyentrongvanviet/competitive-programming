#define TASK "ctree3"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"
#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 
#define int long long 
const int N= 1e5+5 ,oo = 1e9 ; 
const ll  inf = 1e17 , sm =1e9+7 ; 

ll n ; 
ll a[N] ; 
vector<int>g[N] ; 
ll f[N][10]  ;		
void dfs(int u ,int p ,  int c )
{
	if(f[u][c])return ;  
	f[u][c]=  c; 
	for(int  i = 0;i<g[u].size();i++)
	{
		int  v= g[u][i]; 
		if(v==p)continue;
		int tmp = oo ;
		for(int j = 1;j<=3;j++)
		{
			if(c!=j)
			{
				dfs(v,u,j);
				tmp = min(tmp,f[v][j]); 
			}
		}
		f[u][c]+=tmp;
	}
}
void inp()
{
	cin>> n ; 
	for(int i=1 ;i<=n-1;i++)
	{
		int u , v; 
		cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u);  
	}
	int res= oo ; 
	for(int i=1 ;i<=3;i++)
	{
		dfs(1,0,i) ; 
		res=min(res,f[1][i]) ; 
	}
	cout<<res; 

}
void IOS()
{
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
signed main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	IOS();
	inp() ; 
}