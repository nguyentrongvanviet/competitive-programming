#include<bits/stdc++.h>
using namespace std;

#define TASK "MAXLENGTH"

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

int n  , m;  
int id[N] , low[N] ;
int tplt = 0 , tt= 0 ;
vector<int>g[N] ;
stack<int>st ;
vector<int>adj[N] ;
int dd[N] ; 
int f[N] ;
void dfs(int u)
{
	st.push(u) ; 
	id[u] = low[u]=++tt;  
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(dd[v])continue ; 
		if(id[v]==0)
		{
			dfs(v) ; 
		}
		else 
		{
			low[u] = min(low[u],id[v]) ;
		}
	}
	if(low[u]==id[u])
	{
		int t ; 
		++tplt ;
		int c= 0 ; 
		do
		{
			c++; 
			t =st.top() ; 
			st.pop() ; 
			dd[t] = tplt;
		}while(t!=u);
		f[tplt] = c-1; 
	}
}
int d[N] ; 

int dfs1(int u )
{
	if(d[u])return f[u] ;
	int ma =-1;  
	for(int i= 0 ;i<adj[u].size();i++)
	{		
		int v= adj[u][i] ; 
		ma=max(ma,dfs1(v)); 
	}	
	d[u]=1; 
	return f[u] =1+ma; 
}
void doc()
{
    cin>> n>> m; 
    for(int i= 1;i<=m;i++)
    {
    	int u , v;  cin>>u>>v;  
    	g[u].pb(v) ; 
    }
    for(int i= 1;i<=n;i++)
    {
    	if(id[i]==0)
    	{
    		dfs(i) ; 
    	}
    }
    for(int u= 1;u<=n;u++)
    {
    	for(int i = 0 ;i<g[u].size();i++)
    	{
    		int v= g[u][i] ; 
    		if(dd[v]!=dd[u])
    		{
    			adj[dd[u]].pb(dd[v]);
    		}
    	}
    }
    int res=0  ;
    for(int i= 1;i<=tplt;i++)
    {
    	res=max(res,dfs1(i)) ;
    }
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
    }
    return 0;
}