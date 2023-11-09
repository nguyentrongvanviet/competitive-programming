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
	const int N =2e5+5 ,  oo = INT_MAX ;
	const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

	int n ; 
	int a[N] ; 
	int k  ;  
	ll f[N][51]  ; 
	void doc()
	{
	 	cin>> n>> k; 
	 	for(int i=1 ;i<=n;i++)cin>>a[i] ;
	 	for(int i=0;i<k;i++)f[0][i]=-inf;
	 	f[0][0] =  0 ;	
	 	for(int i=1 ;i<=n;i++)
	 	{
	 		for(int j= 0 ;j<k;j++)
	 		{
	 			f[i][j] = f[i-1][j];
	 			if(f[i-1][( (j-a[i]%k)+k)%k]!=-inf)f[i][j] =max(f[i][j] ,f[i-1][( (j-a[i]%k)+k)%k]+1);
	 		}
	 	}
	 	cout<<f[n][0];
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