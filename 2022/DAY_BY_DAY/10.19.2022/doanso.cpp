#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
ll n , m  , k ;
void input()
{	
    cin>> n >> m >> k ; 
}
bool check(ll val)
{
	ll ans =0  ;
	for(ll i=1 ;i<=n;i++)
	{
		if(i>val)
		{
			break;
		}
		ll  l=  1 ; 
		ll r = m ;
		ll x  ; 
		while(l<=r)
		{
			ll mid=(l+r)/2 ; 
			if(mid*i<val)
			{
				ans=mid ;
				l=mid+1;  
			}
			else 
			{
				r=mid-1 ;
			}
		}
		ans+=mid;
	}	
	return ans>=k;
}
void output()
{
    ll l =1 ; 
    ll r= inf ; 
    while(l<=r)
    {
    	ll mid = (l+r)>>1;  
    	if(check(mid))
    	{
    		r=mid-1 ; 
    		ans= mid ; 
    	}
    	else 
    	{
    		l=mid+1; 
    	}
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}