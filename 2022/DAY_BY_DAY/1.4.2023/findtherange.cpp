#include<bits/stdc++.h>
using namespace std; 
const int N= 1e6 +5; 


int a[N] ; 
int n ; 


int main()
{
	// freopen("text.INP","r",stdin) ; 
	// freopen("text.OUT","w",stdout) ;
	cin>> n; 
	for(int i= 1;i<=n;i++)cin>>a[i] ; 
	int la =0 ; 
	for(int i= 1;i<=n;i++)if(a[i]>0)la= i; 
	cout<<la;  
}