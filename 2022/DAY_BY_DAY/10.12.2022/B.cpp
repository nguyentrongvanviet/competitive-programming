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
ll a[N] , b[N] ; 
void input()
{
    cin>> n ; 
    ll res=0 ;  
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i] ; 
    	res+=a[i] ; 
    }
    ll ma= -inf ; 
    for(int i=1 ;i<=n;i++)
    {
    	cin>>b[i] ;
    	ma=max(ma,b[i]);  
    	res+=b[i] ; 
    }
    cout<<res-ma<<"\n";
}
void output()
{
    cin>> n ; 
    for(int i =1 ;i<=n;i++)
    {
    	cin>>a[i] ; 
    }
   	sort(a+1,a+n+1) ; 
   	for(int i=n;i>=1;i--)
   	{
   		int l = 1;
   		int r = n ; 
   		int ans = 0 ;
   		while(l<=r)
   		{
   			int mid=(l+r)/2; 
   			if(a[mid]<=i)
   			{
   				ans =mid; 
   				l=mid+1; 
   			}
   			else 
   			{
   				r=mid-1;  
   			}
   		}
   		cout<<ans<<endl;
   	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}