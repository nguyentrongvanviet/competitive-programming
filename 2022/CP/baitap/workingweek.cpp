#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  

const  int N = 2e5+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

ll n; 
int a[N]; 
void inp()
{	
	cin>> n ;
	for(int i=1 ;i<=n;i++)
	{
		cin>>a[i] ;  
	}
	int u =2*a[1]-1 ; 
	int res= 0 ; 
	for(int i= 2;i<=n;i++)
	{
		res+=a[i]/u-1; 
	}
	cout<<res<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	int t  ; 
	cin>>t; 
	while(t--)inp() ; 

}