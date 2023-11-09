#include<bits/stdc++.h>
using namespace std ;
const int N=  1e6+5; 
#define ll long long

int n;  
ll a[N] ; ll res = -1e18;
ll mi[N] , ma[N] ; 
int main()
{
	freopen("CEDEDGES.INP","r",stdin) ; 
	freopen("CEDEDGES.OUT","w",stdout);
	cin>> n;  
	for(int i=1 ;i<=n;i++)cin>>a[i] ; 
	mi[n+1]= 1e18 ; 
	for(int i= n;i>=1;i--)
	{
		mi[i] = min( mi[i+1] , a[i]) ; 
	}
	ma[0] = -1e18;
	for(int i= 1;i<=n;i++)
	{
		ma[i] =max(ma[i-1],a[i])  ; 
	}
	for(int i= 2 ;i<=n-1;i++)
	{
		res=max(res,a[i]+ma[i-1]-mi[i+1]) ;
	}
	cout<<res;
}