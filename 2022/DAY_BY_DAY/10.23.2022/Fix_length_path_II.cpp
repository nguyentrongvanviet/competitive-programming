#include<bits/stdc++.h>
using namespace std;
#define TASK "Fix_length_path_II"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
int L , R ;  
vector<int>g[N];
void doc()
{
 	cin>> n>>L>>R; 
 	for(int i= 1;i<=n-1;i++)
 	{
 		int u ,v ;  
 		cin>>u>>v ;
 		g[u].pb(v) ;
 		g[v].pb(u) ;
 	}
}
int sz[N] ;
int dd[N] ;
void predfs(int u ,int p)
{
	sz[u] =1 ; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i] ;
		if(dd[v]||v==p)continue ;
		predfs(v,u);
		sz[u]+=sz[v] ;
	}
}
int centroid(int u ,int p ,int n)
{
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i];
		if(dd[v]||v==p)continue;
		if(sz[v]>n/2)return centroid(v,u,n) ;
	}	
	return u ;
}
vector<int>d;
void dfs(int u , int p , int l)
{
	d.pb(l);
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i]  ;
		if(v==p||dd[v])continue ;
		dfs(v,u,l+1);
	}
}
ll bit[N];  
void up(int idx , int n , ll val )
{
	for(int i=idx;i<=n;i+=i&-i)
	{
		bit[i]+=val; 
	}
}
ll get(int idx ,int n )
{
	ll ans= 0 ;
	for(int i=  idx;i;i-=i&-i)
	{
		ans+=bit[i] ; 
	}
	return ans ;
}
ll res=0 ;
void solve(int u, int p)
{
	dd[u] =1 ; 
	up(1,sz[u]+1,1);
	for(int i = 0;i<g[u].size();i++)
	{
		d.clear();
		int v= g[u][i] ; 
		if(dd[v]||v==p)continue ; 
		dfs(v,u,1);
		for(int j= 0 ;j<d.size();j++)
		{
			int l =d[j] ; 
			if(R<l)continue;
			res+=get(min(sz[u],R-l+1),sz[u]+1);
			if(l<L)
			{
				res-=get(min(sz[u],L-l),sz[u]+1);
			}
		}	
		for(int j= 0 ;j<d.size();j++)
		{
			up(d[j]+1,sz[u]+1,1);
		}
	}
	for(int i=1 ;i<=sz[u]+1;i++)
	{
		bit[i] = 0 ; 
	}
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(dd[v]||v==p)continue ;
		predfs(v,u) ;
		solve(centroid(v,u,sz[v]),u);
	}	
}
void sub1()
{
	predfs(1,0);
	solve(centroid(1,0,n),0);
	cout<<res;
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
        sub1();
    }
    return 0;
}