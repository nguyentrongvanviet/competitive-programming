#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;


int n ; 
ll sz[N] ; 
ll f[N] ,g[N] ; 
int a[N] ; 
vector<int>adj[N]; 
void input()
{
	cin>> n ; 
	for(int i=2;i<=n;i++)
	{
		int u ; cin>>u  ; 
		++u ;     
		adj[i].pb(u); 
		adj[u].pb(i);
	} 	   
	for(int i= 1;i<=n;i++)cin>>a[i]; 
}
void predfs(int u , int p )
{
	sz[u] = (a[u]==1);  
	for(int i = 0 ;i<(int)adj[u].size();i++)
	{
		int v = adj[u][i] ; 
		if(v==p)continue ; 
		predfs(v,u);
		sz[u]+=sz[v];  
	}
}
void dfsout(int u , int p  )
{
	g[u]=(a[u]==0);
	f[u]=(a[u]==1);
	for(int i= 0 ;i<(int)adj[u].size();i++)
	{
		int v= adj[u][i] ; 
		if(v==p||sz[v]==0)continue  ;
		dfsout(v,u); 
		if(a[u]==0)
		{
			if(a[v]==1)
			{
				f[u] =(f[u]*f[v]%sm+f[v]*g[u]%sm)%sm;
				g[u] =g[u]*f[v]%sm;
			}
			else 
			{
				f[u]=((f[u]*f[v])%sm+f[v]*g[u]%sm+f[u]*g[v]%sm)%sm;
				g[u] =((g[u]*f[v])%sm+(g[u]*g[v])%sm)%sm;
			}
		}
		else 
		{	
			if(a[v]==1)
			{
				f[u]=(f[u]*f[v])%sm; 
				g[u]=(g[u]*f[v])%sm;  
			}
			else 
			{
				f[u] = (f[u]*g[v]%sm+f[u]*f[v]%sm)%sm; 
				g[u] = (g[u]*f[v]%sm+g[u]*g[v]%sm)%sm; 
			}
		}
	}
}
void output()
{
    predfs(1,0) ; 
    dfsout(1,0) ; 
    cout<<f[1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}