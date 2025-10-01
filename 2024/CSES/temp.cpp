#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+5 ;
int n ; 
ll L ; 
ll a[N] , b[N] ; 
signed main()
{
	ll n ; cin>> n ; 
	set<long long>res ;
	ll L = 1 ; 
	ll R = n ; 
	while(L<=R)
	{
		ll l = L ; 
		ll r = R ; 
		ll ans = l ; 
		while(l<=r)
		{
			ll mid = (l+r)>>1 ; 
			if(n/L==n/mid)
			{
				ans=mid ; 
				l=mid+1;
			}
			else r=mid-1 ; 
		}
		res.insert(n/ans) ; 
		L = ans+1 ; 
	}
	cout<<res.size()<<endl;
	for(auto x : res)cout<<x<<" "; 
}