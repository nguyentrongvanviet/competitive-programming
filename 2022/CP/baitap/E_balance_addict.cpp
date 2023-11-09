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
	cin>> n ; 
	for(int i= 1;i<=n;i++)
	{
		cin>>a[i];  
	}
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	inp() ; 
}
