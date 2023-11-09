#include<bits/stdc++.h>
using namespace std;

#define TASK "C"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n , m;  
int nt[N*10/2] ;
void sieve()
{
	for(ll i= 2 ;i<=(ll)1e6;i++)
	{
		if(nt[i]==0)
		{
			nt[i]=i ; 
			for(ll j = i*i;j<=ll(1e6);j+=i)
			{
				nt[j] = i ; 
			}
		}
	}
}
ll tinh(int i , int j)
{
	ll  l = 1 ; 
	ll r= n ; 
	while(l<=r)
	{
		int mid = (l+r)/2; 
		if(check(mid))
		{
			ans = mid ; 
			
		}
	}
}
void doc()
{
   	cin>> n >>m ; 
   	FOR(i,1,n)
   	{
   		FOR(j,1,m)
   		{
   			cin>>a[i][j] ; 
   			s[i][j] =s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
   		}
   	}
   	FOR(i,1,n)
   	{
   		FOR(j,1,m)
   		{
   			f[i][j] =max(f[i][j-1],f[i-1][j]) ; 
   			f[i][j] = max(f[i][j],tinh(i,j)) ;   
   		}
   	}
   	FOR(i,1,n)
   	{

   	}
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    sieve(); 
    while(t--)
    {
        doc();
    }
}