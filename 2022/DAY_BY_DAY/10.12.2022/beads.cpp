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
int f[N] , d[N]  ,c[N]  ,b[N];
int res=0  ;
int a[N] ;
int np1(int val )
{
	int l = 1; 
	int r = n ; 
	int ans =0  ; 
	while(l<=r)
	{
		int mid=(l+r)>>1; 
		if(b[mid]>=val)
		{
			ans= mid ; 
			r=mid-1;  
		}
		else 
		{
			l=mid+1; 
		}
	}
	return ans;  
}
int np2(int val)
{
	int l = 1; 
	int r = n ; 
	int ans =0  ;
	while(l<=r)
	{
		int mid =(l+r)>>1; 
		if(c[mid]<=val)
		{
			ans= mid;
			r=mid-1;  
		}
		else 
		{
			l=mid+1; 
		}
	}
	return ans ; 
}
void input()
{
    cin>> n;  
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i] ; 
    	b[i] =oo ; 
    	c[i] = -oo ; 
    }
    for(int i =n;i>=1;i--)
    {
    	f[i] = np1(a[i]) ; 
    	d[i] = np2(a[i]) ; 
    	b[f[i]]=a[i] ; 
   		c[d[i]]=a[i] ; 
    }
    int res= 0 ; 
    for(int i =1 ;i<=n;i++)
    {
    	res=max(res,f[i]+d[i]-1); 
    }
    cout<<res; 
}
void output()
{
    
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