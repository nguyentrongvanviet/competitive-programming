// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "cuttheribbon"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , a, b, c ;
int f[N] ;
void doc()
{
 	cin>>n>>a>>b>>c; 
 	f[0] =1 ; 
 	FOR(i,1,n)
 	{
 		if(i>=a&&f[i-a])f[i]=max(f[i],f[i-a]+1) ; 
 		if(i>=b&&f[i-b])f[i]=max(f[i],f[i-b]+1) ; 
 		if(i>=c&&f[i-c])f[i]=max(f[i],f[i-c]+1) ; 
 	}   
 	cout<<f[n]-1; 
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