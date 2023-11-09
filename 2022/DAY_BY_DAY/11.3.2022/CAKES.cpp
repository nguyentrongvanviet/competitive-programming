#include<bits/stdc++.h>
using namespace std;

#define TASK "EPATH"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =202 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;  
ll s ; 
ll a[N] ; 
bool check(ll val)
{
	ll res=0 ;  
	for(int i=1 ;i<=n;i++)
	{
		res+=val/a[i];
		if(res>=s)return  1; 
	}
	return 0 ;
}
void doc()
{
	cin>> s>> n; 
	for(int i=1 ;i<=n;i++)cin>>a[i];
	ll l = 0 ; 
	ll r = inf;
	ll ans = 0; 
	while(l<=r)
	{
		ll mid =(l+r)/2; 
		if(check(mid))
		{
			ans= mid ; 
			r=mid-1  ; 
		}
		else 
		{
			l=mid+1; 
		}
	}
	cout<<ans; 
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