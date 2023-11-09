	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "SEGMENT"

	#define ll long long
	#define pb push_back
	#define pk pop_back
	#define pii pair<int,int>
	#define fi first 
	#define se second
	#define vii vector<int> 
	#define _sz(a) (int)a.size() 
	#define all(a) a.begin(),a.end()

	const int N =30+5 ,  oo = INT_MAX ;
	const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

	int n ;  
	string s[N] ;
	int dd[11] ; 
	int degree[11] ; 
	vector<int>g[11] ;
	void predfs(int u )
	{
		dd[u] = 1; 
		for(int i =0 ;i<g[u].size();i++)
		{
			int v= g[u][i] ; 
			if(dd[v])continue ; 
			predfs(v) ;
		}
	}
	int check(int bit )
	{
		for(int i =0;i<=9;i++)g[i].clear() ,dd[i] =1,degree[i]=0;  
		for(int i= 1 ;i<=n;i++)
		{
			if(bit>>(i-1)&1)
			{
				int a=  s[i][0] -'0' ; 
				int b = s[i][s[i].size()-1]-'0' ; 
				g[a].pb(b) ; 
				g[b].pb(a) ;  
				dd[a] = dd[b] =0 ; 
				degree[a]++ ; 
				degree[b]++ ;
	 		}
		}
		for(int i= 0  ;i<=9;i++)
		{
			if(degree[i]%2==1)return 0  ;
		}
		for(int i=0;i<=9;i++)
		{
			if(dd[i]==0)
			{
				predfs(i) ; 
				break;  
			}
		}
		for(int i= 0;i<=9;i++)if(dd[i]==0)return 0 ; 
		return  1; 
	}
	void doc()
	{
	 	cin>> n; 
	 	for(int i=1;i<=n;i++)
		{
			cin>>s[i] ; 
		}
	 	int res=0 ;
	 	for(int i=0;i<(1<<n);i++)
	 	{
	 		int ans = __builtin_popcount(i) ; 
	 		if(ans<=res)continue;  
	 		if(check(i))res=ans; 
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