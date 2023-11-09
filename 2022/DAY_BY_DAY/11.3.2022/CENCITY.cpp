#include<bits/stdc++.h>
using namespace std;

#define TASK "CENCITY"

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

int n  , m  ; 
vector<int>g[N] ; 
int low[N] , id[N] ;  
int tt= 0  , tplt= 0;  
vector<int>tp[N],adj[N];
int dd[N] ;
stack<int>st; 
void dfs(int u)
{
	st.push(u) ;
	low[u] = id[u]=++tt; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(dd[v])continue ;
		if(id[v]==0)
		{
			dfs(v) ; 
			low[u] =min(low[u],low[v]) ; 
		}
		else 
		{
			low[u]=min(low[u],id[v]) ;
		}
	}
	if(id[u]==low[u])
	{
		int t  ; 
		tplt++ ;
		do
		{
			t=st.top() ; 
			st.pop();
			dd[t] =tplt; 
			tp[tplt].pb(t);
		}while(t!=u);
	}
}
int in[N] ; 
int fi = 0  ; 
int x[N] ;
void dfs1(int u  )
{
	x[u] =1; 
	fi++ ; 
	for(int i= 0 ;i<adj[u].size();i++)
	{
		int v = adj[u][i]; 
		if(x[v]==0)dfs1(v) ; 
	}
}
void doc() 
{
 	cin>> n >> m  ; 
 	for(int i=1 ;i<=m;i++)
 	{
 		int u ,v ;  cin>>u>>v ; 
 		g[u].pb(v) ; 
 	}   
 	for(int  i=1 ;i<=n;i++)
 	{
 		if(id[i]==0)dfs(i) ;
 	}
 	for(int  i=1 ;i<=n;i++)
 	{
 		for(int j= 0;j<g[i].size();j++)
 		{
 			int v= g[i][j] ;
 			if(dd[v]!=dd[i])
 			{
 				adj[dd[v]].pb(dd[i]);
 				in[dd[i]]++;
 			}
 		}	
 	}
 	for(int i= 1;i<=tplt;i++)
 	{
 		if(in[i]==0)
 		{
 			fi= 0  ;
 			dfs1(i);
 			if(fi==tplt)
 			{
 				cout<<tp[i].size()<<"\n";
 				sort(tp[i].begin(),tp[i].end());
 				for(int  j = 0 ;j<tp[i].size();j++)
 				{
 					cout<<tp[i][j]<<" ";
 				}
 			}	
 			else 
 			{
 				cout<<0;
 			}
 			return ; 
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