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
ll mu[N] ; 
ll a[N] ;
ll  b[N] ;
ll h[N] ;
ll gethash(ll l , ll r )
{
	return	(h[r]-h[l-1]*mu[r-l+1]+sm*sm)%sm; 
}
void input()
{
 	cin>> n; 
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ; 
 	}   
 	for(int i=2; i<=n;i++)
 	{
 		b[i-1]=a[i]-a[i-1] ; 
 	}
 	n= n-1; 
}
bool check(int le )
{
	for(int i= 1;i<=n-le+1;i++)
	{
		for(int j=i+le+1;j+le-1<=n;j++)
		{
			if(gethash(i,i+le-1)==gethash(j,j+le-1))return 1 ; 
		}
	}
	return 0 ; 
}
void np1()
{
	int ans =-1; 
	int l =4 ; 
	int r= n;
	while(l<=r)
	{
		int mid=(l+r)/2; 
		if(check(mid))
		{
			l=mid+1; 
			ans= mid ; 
		}
		else 
		{
			r=mid-1;  
		}
	}
	cout<<ans+1 ;
}
void output()
{
    for(int i= 1;i<=n;i++)
 	{	
 		h[i] = (h[i-1]*cs+b[i])%sm; 
 	}	
  	mu[0] =1;  
 	for(int i =1; i<=n;i++)
 	{
 		mu[i] =(mu[i-1]*cs)%sm ; 
 	}
 	np1();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
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