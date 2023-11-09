#include<bits/stdc++.h>
using namespace std;

#define TASK ""

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
int n ; 
ll a[N]  ; 
int tknp(int val,int id )
{
	ll l = 0 ; 
	ll r=(ll)oo ;  
	ll ans = 0  ; 
	while(l<=r)
	{
		ll mid =(l+r)/2;
		ll g=  mid*n+id ; 
		ll sum  ; 
		if(g%2==0)
		{
			g/=2 ; 
			sum=(g+1)*g/2; 
		}
		else 
		{
			g/=2 ; 
			sum=(g+1)*g/2+g;  
		}
	}
}
void doc()
{
    cin>> n ; 
    FOR(i,0,n-1)cin>>a[i] ; 
    int ans = 0  ; 
    ll mi = inf ; 
    FOR(i,0,n-1)
    {
    	ll x=  tknp(a[i],i) ; 
    	if(x<mi)
    	{
    		 mi = x;  
    		 ans =i ; 
    	}
    } 
    cout<<ans ;
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