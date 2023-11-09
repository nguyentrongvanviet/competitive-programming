#include<bits/stdc++.h>
using namespace std;

#define TASK "SUMDIV"

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
ll n;  
ll ans =1 ; 
void doc()
{
 	cin>> n ; 
 	ll it = 2 ;
 	ll res= 1;   
 	while(it*it<=n)
 	{
 		ll tmp = 1 ; 
 		while(n%it==0)	
 		{
 			tmp*=it ;
 			n/=it ; 
 		}
 		res*=(tmp*it-1)/(it-1);
 		++it ; 
 	}   	
 	if(n!=1)
 	{
 		res*=(n*n-1)/(n-1);
 	}
 	cout<<res<<"\n";
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
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}