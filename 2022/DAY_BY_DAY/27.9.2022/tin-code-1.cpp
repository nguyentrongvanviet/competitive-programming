#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e4+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg 
{
	int u ; 
	ll val ;
};		
struct cmp
{
	bool operator()(bg a, bg b  )
	{
		return a.val>b.val ; 
	}
};
struct ke 
{
	int v ; 
	ll w ; 
};	
int n , m , c; 
int a[N] ; 
vector<ke>g[N] ; 
ll f[N] , d[N] ; 
int dd[N];
void dij()
{
	for(int i =1;i<=n;i++)
	{
		f[i] = inf ; 
		d[i] =inf ;
	}
	priority_queue<bg,vector<bg>,cmp>q;
	f[n]  =0  ; 
	q.push({n,0}) ;
	while(!q.empty())
	{
		int u = q.top().u ;
		q.pop() ; 
		if(dd[u])continue; 
		dd[u] = 1; 
		for(int i = 0;i<g[u].size();i++)
		{
			int v= g[u][i].v;
			ll w =g[u][i].w; 
			if(dd[v])continue ;
			if(f[v]>f[u]+w)
			{
				f[v]=f[u]+w; 
				q.push({v,f[v]}); 
			} 
		}
	} 
}
void inp()
{
	cin>> n>> m >>c ; 	
	for(int i= 1 ;i<=m;i++)
	{
		int u  , v , w ; 
		cin>>u>>v>>w; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w});  
	}
	dij() ; 
	for(int i= 1;i<=n;i++)
	{
		dd[i]= 0 ;  
	}
	priority_queue<bg,vector<bg>,cmp>q ; 
	for(int i =1 ;i<=c;i++)
	{
		int u  ; 
		ll t ;
		cin>>u>>t ;
		d[u] =f[u]-t; 
		q.push({u,d[u]}) ;
	}
	while(!q.empty())
	{
		int u = q.top().u ;
		q.pop() ; 
		if(dd[u])continue ;
		dd[u]= 1; 
		for(int i= 0;i<g[u].size();i++)
		{
			int v= g[u][i].v; 
			ll w= g[u][i].w; 
			if(dd[v])continue ; 
			if(d[v]>d[u]+w)
			{
				d[v] =d[u]+w; 
				q.push({v,d[v]}); 
			}
		}
	}
	for(int i = 1;i<=n-1;i++)
	{
		if(d[i]<=f[i])
		{
			cout<<1<<"\n";
		}
		else 
		{
			cout<<0<<"\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
	freopen("i.txt","r",stdin); 
	freopen("o.txt","w",stdout); 
	inp();
	return 0;
}