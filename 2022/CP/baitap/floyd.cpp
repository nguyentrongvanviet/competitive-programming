#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  

const  int N = 105+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

ll n  , m , q ;  
ll f[N][N] ; 
ll pre[N][N];  
void trace(int u , int v )
{
	vector<int>ans ; 
	do
	{
		ans.pb(u) ; 
		u=pre[u][v];
	}while(u);
	cout<<ans.size()<<" " ; 
	for(int i= 0 ; i<(ll)ans.size();i++)cout<<ans[i]<<" "; 
	cout<<"\n";
}
void inp()
{
	cin>> n >>m>> q ; 
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1;j<=n;j++)
		{
			pre[i][j] = j; 
			f[i][j] = oo ; 
			if(i==j)
			{
				pre[i][i] = 0;
				f[i][i] = 0 ;
			}
		}
		
	}
	for(int i=1 ;i<=m;i++)
	{
		int u , v ; 
		ll w;  x
		cin>>u>>v>>w ; 
		f[u][v]=w; 
		f[v][u]=w ;
	}
	for(int  k= 1;k<=n;k++)
	{
		for(int i =1 ;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]>f[i][k]+f[k][j] )
				{
					f[i][j] =f[i][k]+f[k][j] ; 	
					pre[i][j] = pre[i][k] ; 
				} 
			}
		}
	}
	for(int i =1 ;i<=q;i++)
	{
		int u , v; 
		int t ;
		cin>>t>>u>>v ;  
		if(t==0)
		{
			cout<<f[u][v]<<"\n"; 
		}
		else 
		{
			trace(u,v);  
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	inp() ; 

}