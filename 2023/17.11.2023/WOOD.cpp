/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#define input "WOOD.INP"
#define output "WOOD.OUT"
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
void doc()
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
void xuly()
{

    np() ; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(input,"r"))
    {
    	freopen(input,"r",stdin) ; 
    	freopen(output,"w",stdout) ; 
    }
    else if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
        xuly(); 
    }
    return 0;
}
