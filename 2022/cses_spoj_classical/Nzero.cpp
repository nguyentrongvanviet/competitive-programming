#include<bits/stdc++.h>
using namespace std;

#define TASK "Nzero"

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
ll n ; 
bool check(ll m)
{
	ll p = 5 ; 
	ll sochuso_0= 0; 
	while(p<=m)
	{
		sochuso_0=sochuso_0+m/p; 
		p= p*5; 
	}
	return sochuso_0 >=n;
}
void doc()
{
    cin>> n;   
   	ll l = 5;  
   	ll r = n*5 ;
   	ll ans= -1 ;  
   	while(l<=r)
   	{
   		ll mid =(l+r)/2;
   		if(check(mid))
   		{
   			ans= mid;  
   			r=mid-1 ; 
   		}
   		else 
   		{
   			l=mid+1; 
   		}
   	}
   	cout<<ans<<"\n"; 
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
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}