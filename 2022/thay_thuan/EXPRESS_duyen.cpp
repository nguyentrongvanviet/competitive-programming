#include<bits/stdc++.h>
using namespace std; 
#define ll long long
const int N=  1e3+5 ; 
int n;  
ll a[N] , s[N] ; 
ll res= 0;  

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
	// freopen("EXPRESS.INP","r",stdin) ; 
	// freopen("EXPRESS.OUT","w",stdout) ; 
	cin>> n ; 
	for(int i= 1;i<=n;i++)cin>>a[i] ; 
	for(int i= 1;i<=n;i++)s[i] = s[i-1]+a[i] ; 
	for(int i= 1;i<=n-2;i++)
	{
		res= max(res,s[i-1]+a[i]*a[i+1]*a[i+2]+s[n]-s[i+2]);
		for(int j= i+2;j<=n-1;j++)
		{
			res=max(res,s[i-1]+a[i]*a[i+1]+a[j]*a[j+1]+s[n]-s[j+1] +s[j-1]-s[i+1]);
		}
	}x
	cout<<res;
}