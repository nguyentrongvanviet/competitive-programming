#include<bits/stdc++.h>
using namespace std;

#define TASK "FOODS"

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

int n  ,  m  , low[N ] ,id[N]  ; 
vector<int>g[N] ;
vector<int>adj[N] ; 
int dd[N] ; 
ll f[N] ;  
int a[N] ;
int tt= 0 , tplt = 0  ;
stack<int>st ;  
void dfs(int u )
{
	st.push(u) ;
	low[u] =  id[u]=++tt; 
	for(int i=0  ;i<g[u].size();i++)
	{
		int v =g[u][i] ; 
		if(dd[v])continue  ; 
		if(id[v]==0)
		{
			dfs(v) ; 
			low[u]= min(low[u],low[v]) ; 
		}
		else 
		{
			low[u] = min(low[u],id[v]);  
		}
	}
	if(low[u]==id[u])
	{
		int t ; 
		tplt++ ; 
		do
		{
			t=st.top() ; 
			st.pop();
			dd[t]=tplt;   
			f[tplt]+=a[t]; 
		}while(t!=u); 
	}
}
int d[N] ; 
ll dfs1(int u )
{
	if(d[u])return f[u]; 
	ll ma = 0  ;
	for(int i=0  ;i<adj[u].size();i++)
	{
		int v= adj[u][i] ; 
		ma=max(ma,dfs1(v)); 
	}  
	d[u] = 1 ;
	f[u] =f[u]+ma;
	return f[u]; 
}
void doc()
{
 	cin>>n >>m ; 
 	for(int i= 1;i<=n;i++)cin>>a[i] ; 
 	for(int i= 1;i<=m;i++)
 	{
 		int u ,v  ;cin>>u>>v ; 
 		g[u].pb(v) ; 
 	}   
 	for(int i=1 ;i<=n;i++)
 	{
 		if(id[i]==0)
 		{
 			dfs(i) ; 
 		}
 	}
 	cout<<tplt<<endl;
 	for(int u = 1;u<=n;u++)
 	{
 		for(int i =0 ;i<g[u].size();i++)
 		{
 			int v= g[u][i] ; 
 			if(dd[v]!=dd[u])
 			{
 				adj[dd[u]].pb(dd[v]); 
 			}
 		}
 	}
 	for(int i=1 ;i<=n;i++)
 	{
 		cout<<dfs1(dd[i])<<" "; 
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