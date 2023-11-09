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
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;
ll a[N] ;  
ll l[N] , r[N];
void input()
{
 	cin>>n ; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		a[i]=abs(a[i]);
 	}
}
bool check(int m)
{
	for(int i= 1;i<=n;i++)
	{
		if((i-1)%m==0)
		{
			l[i] = a[i] ; 
		}
		else 
		{
			l[i] = __gcd(l[i-1],a[i]) ; 
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(i%m==0||i==n)
		{
			r[i] = a[i ]; 
		}
		else 
		{
			r[i] = __gcd(r[i+1],a[i]) ; 
		}
	}
	for(int i= 1;i<=n-m+1;i++)
	{
		if(__gcd(r[i],l[i+m-1])!=1)
		{
			return 1; 
		}
	}
	return  0 ; 
}
int np1()
{
	int  l =1; 
	int r =n ; 
	int ans =0;
	while(l<=r)
	{	
		int mid =(l+r)/2; 
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
	return ans ; 
}
void output()
{		
    int res = np1() ; 
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen("CDSUBSEG","r"))
    {
    	freopen("CDSUBSEG.INP","r",stdin);  
    	freopen("CDSUBSEG.OUT","w",stdout); 
    }
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