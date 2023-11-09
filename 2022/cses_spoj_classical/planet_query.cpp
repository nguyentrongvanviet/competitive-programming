	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "planet_query"

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
	const int LO =30  ; 
	int n  , q  ; 
	int pa[N][LO] ; 

	void doc()
	{	
	    cin>> n >>q ; 
	    FOR(i,1,n )
	    {
	    	int u ;   
	    	cin>> u ;
	    	pa[i][0] =  u ;    
	    }
	    FOR(j,1,LO-1)
	    {
	    	FOR(i,1,n)
	    	{
	    		pa[i][j] = pa[pa[i][j-1]][j-1] ; 
	    	}
	    }
	    FOR(i,1,q)
	    {
	    	int u  , k;  
	    	cin>>u>>k;  
	    	FOR(i,0,LO-1)
	    	{
	    		if(k>>i&1)
	    		{
	    			u=pa[u][i] ; 
	    		}
	    	}
	    	cout<<u<<"\n";
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