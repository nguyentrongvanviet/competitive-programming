// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_D8"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
ll a[N] , b[N] , c[N] ; 
ll f[N][5] ; 
void doc()
{
 	cin>> n ; 
 	FOR(i,1,n)cin>>a[i] ;
 	FOR(i,1,n)cin>>b[i] ; 
 	FOR(i,1,n)cin>>c[i] ; 

 	f[1][1] = a[1] ; 
 	f[1][2] = a[1] ; 
 	f[1][3] =a[1];  
 	f[1][4] = b[1] ;
 	FOR(i,2,n)
 	{
 		f[i][1] = c[i]+max(f[i-1][2],f[i-1][3]) ;
 		// UDU


 		f[i][2] = a[i]+max(f[i-1][1],f[i-1][4]) ; 
 		//DDD 

 		f[i][3] = b[i]+max(f[i-1][2],f[i-1][3]); 
 		// UDD

 		f[i][4] = b[i]+max(f[i-1][1],f[i-1][4]) ;
 		// DDU
 	}
 	cout<<max({f[n-1][1]+a[n],f[n-1][2]+b[n],f[n-1][3]+b[n],f[n-1][4]+a[n]});
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}