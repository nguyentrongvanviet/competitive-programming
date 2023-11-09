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

int n ; 
ll m ;  
ll a[N];   
void input()
{
	cin>> n>> m ; 
	for(int i= 1 ;i<=n;i++)
	{
		cin>>a[i]; 
	}    
}
bool check(ll val )
{
	ll ans = 0 ; 
	for(int i=1 ;i<=n;i++)
	{
		if(a[i]>val)
		{
			ans+=a[i]-val ; 
		}
	}
	return (ans>=m);  
}
void np()
{ 
	ll l = 1 ; 
	ll r =  inf ; 
	ll ans=inf ;
	while(l<=r)
	{
		ll mid=(l+r)/2 ; 
		if(check(mid))
		{
			ans= mid ; 
			l=mid+1; 
		}
		else 
		{
			r=mid-1 ; 
		}
	}	
	cout<<ans;  
}
void output()
{

    np() ; 
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
