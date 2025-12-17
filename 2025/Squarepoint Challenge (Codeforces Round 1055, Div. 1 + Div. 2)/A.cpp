#include<bits/stdc++.h>
using namespace std ;



signed main()
{
	int test ; cin>>test ;
	while(test--)
	{
		int n ; cin>> n; 
		vector<int>a(n) ; 
		for(int i=0;i<n;i++)cin>>a[i] ;
		int res = 0 ;  
		sort(a.begin(),a.end(),greater<int>()) ; 
		for(int i=0;i<n;)
		{
			res++ ; 
			while(i+1<n&&a[i+1]==a[i])++i;
			++i ; 
			res+=min(n-i,1) ; 
		}
		cout<<res<<'\n' ; 
	}
}