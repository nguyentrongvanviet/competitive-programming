#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 2e5+5 ,oo = 1e9 ; 
const int inf = 1e17 , sm =1e9+7 ; 

ll n ; 
ll a[N] ; 

void inp()
{
	cin>> n; 
	for(ll i =1;i<=n;i++)
	{
		cin>>a[i] ; 
	}
	ll su=a[1];  
	for(int i= 2;i<=n;i++)
	{
		if(a[i]==0)continue ; 
		if(su-a[i]>=0)
		{
			cout<<-1<<"\n"; 
			return ; 
		}
		else 
		{
			su+=a[i] ;
		}
	}
	cout<<a[1]<<" " ;
	su =a[1] ;  
	for(int i=2;i<=n;i++)
	{
		
		cout<<su+a[i]<<" "; 
		su+=a[i];
	}
	cout<<"\n"; 
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	int test ;
	cin>>test ;
	while(test--)
	{
		inp() ; 
	}
}
