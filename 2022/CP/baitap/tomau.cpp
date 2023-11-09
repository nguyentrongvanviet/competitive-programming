#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 2e5+5 ,oo = 1e9 ; 
const ll  inf = 1e17 , sm =1e9+7 ; 

ll n ; 
ll a[N] ; 
vector<int>g[N] ; 
int f[N][5]  ;
void dfs(int u ,int p ,  int c )
{
	if(f[u][c])return ;  
	f[u][c]=  c; 
	for(int  i = 0;i<g[u].size();i++)
	{
		int  v= g[u][i]; 
		if(v==p)continue;
		int tmp = oo ;
		for(int j = 1;j<=4;j++)
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
	for(int i=1 ;i<=4;i++)
	{
		dfs(1,0,i) ; 
		res=min(res,f[1][i]) ; 
	}
	cout<<res; 

}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	inp() ; 
}
