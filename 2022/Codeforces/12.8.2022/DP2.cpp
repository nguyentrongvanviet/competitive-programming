// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DP2"

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

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m; 
int a[N]  ; 
int f[N] ;
bool check(int i)
{
	for(int x = i+1;x<=i+2;x++)
	{
		if(a[x]!=a[x-1]+1)return 0 ;
	}
	return 1 ; 
}
void doc()
{
    cin>>n>>m ; 
    FOR(i,1,n)cin>>a[i] ; 
    sort(a+1,a+n+1) ;
    FOR(i,3,n)
    {
    	f[i] = f[i-1] ;
    	if(a[i]==a[i-1]&&a[i-1]==a[i-2]||(check(i-2)))
    	{
    		f[i] = max(f[i],f[i-3]+1) ; 
    	}
    }
    cout<<f[n]; 
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