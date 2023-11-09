	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "OLIU"

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

	struct bg 
	{
		int w;  
		int val ;  
	}; 
	bg a[N]  ; 
	int f[N] ; 
	int q ,n , m;  
	void doc()
	{
	 	cin>>q>> n>> m; 
	 	for(int i=1 ;i<=n;i++)
	 	{
	 		int u ;
	 		cin>>u  ;  
	 		a[i]={u,u};
	 	}   
	 	for(int i=1 ;i<=m;i++)
	 	{
	 		int u ; 
	 		cin>>u ; 
	 		a[n+i]={u,u-1}; 
	 	}
	 	f[0] = 0 ; 
	 	for(int i= 1;i<=q;i++)f[i]=-oo; 
	 	int res=0 ; 
	 	for(int i=1 ;i<=n+m;i++)
	 	{
	 		for(int j=q;j>=0;j--)
	 		{
	 			if(j-a[i].w>=0)
	 			{
	 				f[j] = max(f[j],f[j-a[i].w]+a[i].val);
	 			}
	 			res=max(res,f[j]);
	 		}
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