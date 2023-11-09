#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define int long long 
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int a[N] ;
map<int,int>sl ; 
void inp()
{
 	cin>> n ; 
 	for(int i= 0 ;i<=2000;i++)
 	{
 		sl[i]  = 0 ;
 	}
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		sl[a[i]]++ ; 
 	}   
}
void solve()
{
	ll res= 0 ; 
	for(int i= 1 ;i<=1000;i++)
	{
		for(int j=i+1;j<=1000;j++)
		{
			res+=sl[i]*sl[j]*sl[i+j]; 
		}
	}
	for(int i =1 ;i<=1000;i++)
	{
		res+=sl[i]*(sl[i]-1)/2*sl[0];
	}
	for(int i=1;i<=1000;i++)
	{
		res+=sl[i]*(sl[i]-1)/2*(sl[i+i]) ; 
	}
	res+=sl[0]*(sl[0]-1)*(sl[0]-2)/6; 
	cout<<res ; 
}
 main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        inp();
        solve() ; 
    }
    return 0;
}