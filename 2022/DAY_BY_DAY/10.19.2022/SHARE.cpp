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

struct bg 
{
	ll val ; 
	ll id;  
	bool operator<(const bg&a )const
	{
		return val<a.val; 
	}
};
ll n , m ; 
bg a[N] ; 
ll sum =0 ; 
void input()
{
 	cin>>n>> m; 
 	for(ll i=1 ;i<=n;i++)cin>>a[i].val,sum+=a[i].val,a[i].id=i;
}
void output()
{
	if(sum==m)
	{
		for(int i=1 ;i<=n;i++)
		{
			cout<<a[i].val<<" "; 
		}
		return ;
	}
 	if(sum<m)
 	{
 		cout<<-1 ;
 		return ;  
 	}
 	sum =sum-m;  
 	sort(a+1,a+n+1) ; 
 	vector<ll>res(n+1);
 	for(ll i=n-1;i>=0;i--)
 	{
 		if(sum-(a[i+1].val-a[i].val)*(n-i)<=0)
 		{	
 			ll newh = sum/(n-i);
 			ll cl = sum-newh*(n-i);
 			for(int j =1 ;j<=i;j++)
 			{
 				res[a[j].id]=a[j].val;  
 			}
 			for(int  j=i+1;j<=n;j++)
 			{
 				res[a[j].id]=a[i+1].val-newh;
 			}
 			for(int j =i+1;j<=i+cl;j++)
 			{
 				res[a[j].id]--;
 			}	
 			for(int  j=1 ;j<=n;j++)cout<<res[j]<<" ";
 			return ;
 		}
 		else 
 		{
 			sum-=(a[i+1].val-a[i].val)*(n-i);
 		}
 	}	
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("SHARE.INP","r",stdin); 
    freopen("SHARE.OUT","w",stdout); 
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