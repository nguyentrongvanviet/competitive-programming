	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "SUMPATH"

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

	int n , m ;
	vector<int>g[N]; 
	int s , t ; 
	int d[N] ; 
	ll f[N] ;
	int exist[N] ; 
	void dfs(int u )
	{
		if(d[u])return ;  
		d[u]=1 ; 
		if(u==t)
		{
			f[u] =1 ;
			exist[u] = 1; 
			return ; 
		}
		for(int i= 0 ;i<g[u].size();i++)
		{
			int v =g[u][i]; 
			dfs(v) ; 
			if(exist[v])
			{
				exist[u] =1 ;
				f[u] =(f[u]+f[v])%sm; 
			}
		}		
	}
	void doc()
	{	
	    cin>>n>> m; 
	    cin>>s>>t ; 
	    for(int i=1  ;i<=m;i++)
	    {
	    	int u ,v  ;cin>>u>>v ; 
	    	g[u].pb(v)  ; 
	    }
	    dfs(s) ;
	    cout<<f[s]; 
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