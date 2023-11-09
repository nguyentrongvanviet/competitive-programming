#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  

const  int N = 2e5+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

struct bg
{
	ll val ; 
	ll id ; 
};
struct cmp
{
	bool operator()(bg a , bg b )
	{
		return a.val>b.val; 
	}
};		
ll n;  
ll a[N] ; 
void inp()
{
	ll s=0 ;  
	cin>> n; 
	for(int i=1 ;i<=n;i++)
	{
		cin>>a[i] ;
		s+=a[i] ; 
	}
	cout<<s ; 
}
int main()
{
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	inp() ; 

}