#include<bits/stdc++.h>
using namespace std;

#define TASK "EPATH"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =5e4+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

struct E
{
	int u , v ; 
}; 
int n , m; 
vector<E>edge ; 
vector<E>query;
vector<int>g[N] , adj[N];
vector<int>tp[N]; 
int low[N] , id[N],dd[N] ;
int tt= 0 , tplt =0;
stack<int>st ; 
int d[N] ;
bitset<N>able[N] ;
void dfs(int u )
{
	low[u] =id[u] = ++tt;
	st.push(u) ; 
	for(int i=0  ;i<g[u].size();i++)
	{
		int v =g[u][i] ;
		if(dd[v])continue ;
		if(id[v]==0)
		{
			dfs(v);  
			low[u] =min(low[u],low[v]); 
		} 
		else
		{
			low[u] =min(low[u],id[v]);
		}
	}
	if(id[u]==low[u])
	{
		int t ; 
		++tplt; 
		do
		{
			t =st.top();
			st.pop() ; 
			tp[tplt].pb(t) ; 
			dd[t]=tplt; 
		}while(t!=u);
	}
}
void dfs1(int u)
{
	if(d[u])return ; 
	able[u].set(u,1); 
	for(int i= 0 ;i<adj[u].size();i++)
	{
		int v= adj[u][i] ; 
		dfs1(v) ; 
		able[u]|=able[v];
	}
}
void doc()
{	
    cin>> n>> m; 
    for(int i= 1;i<=m;i++)
    {
    	int u , v ; 
    	cin>>u>>v ; 
    	g[u].pb(v) ; 
    	edge.pb({u,v}) ;
    }
    int q; 
    cin>> q; 
    for(int i=1 ;i<=q;i++)
    {
    	int t  ; cin>>t ; 
    	if(t==1)
    	{
    		int u , c ; 
    		cin>>u>>c ; 
    		++n ;
    		if(c==0)
    		{
    			g[u].pb(n) ;
    			edge.pb({u,n});
    		}
    		else 
    		{
    			g[n].pb(u);
    			edge.pb({n,u});
    		}
    	}
    	else 
    	{
    		int u , v;  
    		cin>>u>>v ; 
    		query.pb({u,v});
    	}
    }
    for(int i =1 ;i<=n;i++)if(id[i]==0)dfs(i);
   	for(int i= 0 ;i<edge.size();i++)
   	{
   		int u = edge[i].u ; 
   		int v= edge[i].v;
   		int x=  dd[u]; 
   		int y= dd[v] ; 
   		if(x!=y)
   		{
   			adj[x].pb(y);
   		}
   	}
   	for(int i= 0 ;i <query.size();i++)
   	{
   		int u  = query[i].u;  
  		int v= query[i].v; 
   		dfs1(dd[u]); 
   		if(able[dd[u]].test(dd[v]))
   		{
   			cout<<"YES"<<"\n";
   		}
   		else 
   		{
   			cout<<"NO"<<"\n";
   		}
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