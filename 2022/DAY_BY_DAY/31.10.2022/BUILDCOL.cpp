#include<bits/stdc++.h>
using namespace std;

#define TASK "BUILDCOL"

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

int n  ; 
ll W ; 
ll a[N] ,b[N] ; 
ll l[N] , r[N]; 
bool check(ll val)
{
	for(int i=1;i<=n;i++)
	{
		b[i]= max(a[i],val) ; 
	}
	l[0] =-inf ; 
	r[n+1]=-inf ;
	for(int i= 1;i<=n;i++)
	{
		l[i] =max(l[i-1],b[i]) ;
	}
	for(int i=n;i>=1;i--)
	{
		r[i] =max(r[i+1],b[i]);
	}
	ll ans= 0 ;
	for(int i=2;i<=n-1;i++)
	{	
		ll u = min(l[i-1],r[i+1]); 
		if(b[i]<u)
		{
			ans+=u-b[i];
		}
	}	
	return ans>=W;
}
ll mi = inf ; 
ll ma= -inf ;
void doc()
{
 	cin>>n>> W ; 
 	for(int i=1 ;i<=n;i++)cin>>a[i] , mi =min(a[i],mi) , ma =max(ma,a[i]) ;	
 	ll l = mi; 
 	ll r = ma;
 	ll res=-1; 
 	while(l<=r)
 	{
 		ll mid =(l+r)/2; 
 		if(check(mid))
 		{
 			res=mid;
 			l=mid+1; 
 		}
 		else 
 		{
 			r=mid-1 ; 
 		}
 	} 	   
 	cout<<res; 
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