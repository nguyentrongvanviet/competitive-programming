#include<bits/stdc++.h>
using namespace std;

#define TASK "SCOM"

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

int n  ,  m;  
vector<int>g[N] ; 
int low[N] ,id[N] ;
int tt = 0  , tplt= 0  ; 
stack<int>st;  
int dd[N] ; 
int bac[N];
int res=0 ; 
void dfs(int u)
{
	low[u] = id[u] =++tt;  
	st.push(u) ; 
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i] ; 
		if(dd[v])continue; 
		if(id[v]==0)
		{
			dfs(v) ; 
			low[u]=min(low[u],low[v]) ; 
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
		do
		{
			t= st.top() ; 
			st.pop() ; 
			dd[t] =tplt ; 
		}while(t!=u);
	}
} 
void doc()
{
	cin>> n>> m; 
	for(int i=1 ;i<=m;i++)
	{
		int u ,v ; 
		cin>>u>>v ; 
		g[u].pb(v) ; 
	}
	for(int i= 1;i<=n;i++)
	{
		if(id[i]==0)
		{
			dfs(i); 
		}
	}
	for(int i=1 ;i<=n;i++)
	{
		for(int j= 0 ;j<g[i].size();j++)
		{
			int v=  g[i][j]; 
			if(dd[v]!=dd[i])
			{
				bac[dd[v]]++ ;
			}
		}
	}
	for(int i=1 ;i<=tplt;i++)
	{
		res+=(bac[i]==0); 
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