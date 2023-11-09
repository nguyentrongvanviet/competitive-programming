#include<bits/stdc++.h>
using namespace std;

#define TASK "giant_pizza"
// 2-sat
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  , m ; 
vector<int>g[N]  ,adj[N] ;
int tt =0 , tplt = 0 , low[N] , id[N] ; 
stack<int> st ; 
int dd[N] , tp[N]  ; 
int pos[N] ;
void dfs(int u)
{
	low[u] = id[u] = ++tt ; 
	st.push(u) ; 
	for(auto v : g[u])
	{
		if(tp[v])continue ; 
		if(id[v])
		{
			low[u] =min(low[u],id[v]) ; 
		}
		else 
		{
			dfs(v) ; 
			low[u] =min(low[u],low[v]) ; 
		}
	}
	if(id[u]==low[u])
	{
		int t; 
		++tplt ; 
		do
		{
			t=st.top() ; 
			st.pop() ; 
			tp[t] =tplt ; 
		}while(t!=u);
	}
} 
vector<int>topo; 
void dfs2(int u)
{
	dd[u] = 1  ;
	for(auto v: adj[u])
	{	
		if(dd[v]==0)
		{
			dfs2(v) ;
		}
	}
	dd[u]=2 ; 
	topo.pb(u) ; 
}
void doc()
{
 	cin>> n >> m ;
 	FOR(i,1,n)
 	{
 		char x , y   ; 
 		int u ,v ; 
 		cin>>x>>u>>y>>v; 
 		// cout<<x<<" "<<u<<" "<<y<<" "<<v<<"\n";
 		if(x=='-')u=2*m+1-u; 
 		if(y=='-')v=2*m+1-v;
 		g[2*m+1-u].pb(v);  
 		g[2*m+1-v].pb(u); 
 		// cout<<2*m+1-u<<" "<<v<<"\n";
 		// cout<<2*m+1-v<<" "<<u<<"\n";
 	}   

 	FOR(i,1,2*m)if(!id[i])dfs(i) ; 
 	FOR(u,1,2*m)
 	{
 		for(auto v:g[u])
 		{
 			if(tp[v]!=tp[u])
 			{
 				adj[tp[u]].pb(tp[v]);  
 			}
 		}
 	} 
 	FOR(i,1,2*m)if(dd[i]==0)dfs2(i);
 	reverse(topo.begin(),topo.end());
 	// for(auto v : topo)cout<<v<<" ";cout<<"\n";
 	for(int i=  0 ;i<topo.size();i++)
 	{
 		pos[topo[i]]= i+1 ; 
 	}
 	FOR(i,1,m)
 	{	
 		if(pos[tp[i]]==pos[tp[2*m+1-i]])
 		{
 			cout<<"NO";
 			return ; 
 		}
 	}
 	FOR(i,1,m)
 	{
 		if(pos[tp[i]]>pos[tp[2*m+1-i]])
 		{
 			cout<<"+"<<" "; 
 		}
 		else 
 		{	
 			cout<<"-"<<" ";
 		}
 	}
 	
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}