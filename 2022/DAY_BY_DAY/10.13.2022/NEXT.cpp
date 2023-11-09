#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , m  ; 
vector<int>g[N] ; 
void input()
{
 	cin>> n>>m   ; 
 	for(int i=1 ;i<=m;i++)
 	{
 		int u , v ;  cin>>u>>v ; 
 		g[u].pb(v) ; g[v].pb(u) ; 
 	}   
}
stack<int>st ; 
int tt =0  ;  
int tplt = 0  , low[N] , id[N] ,tp[N] ; 
void dfs(int u , int p )
{	
	low[u]=id[u]=++tt;  
	st.push(u) ; 
	for(int i= 0 ;i<(int)g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ; 
		if(id[v]==0)
		{
			dfs(v,u) ; 
			low[u]=min(low[u],low[v]) ; 
		}
		else 
		{
			low[u]=min(low[u],id[v]); 
		}
	}
	if(low[u]==id[u])
	{
		tplt++ ;
		int t  ;  
		do
		{
			t = st.top() ;
			tp[t] =tplt ; 
			st.pop() ; 
		}while(t!=u);
	}
}
int in[N] ; 
void output()
{
    dfs(1,0) ; 
    for(int i=1 ;i<=n;i++)
    {
    	for(int j=0 ;j<(int)g[i].size();j++)
    	{
    		int v =g[i][j];
    		if(tp[i]!=tp[v])in[tp[v]]++;
    	}
    }
    int cnt = 0 ; 
    for(int i= 1 ;i<=tplt;i++)
    {
    	if(in[i]==1)cnt++ ; 
    }
    cout<<(cnt%2==0?cnt/2:cnt/2+1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("NETX.INP","r",stdin); 
    freopen("NETX.OUT","w",stdout); 
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