// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "text"

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

int n ; 
int a[N] ; 
string s; 
vi kmp(int a[],  int n )
{
	vi z(n) ; 
	for(int i= 1 ;i<n;i++)
	{
		int j=z[i-1]; 
		while(j&&a[j]!=a[i])
		{
			j=z[j-1];
		}  
		if(a[j]==a[i])++j ;
		z[i] = j ;
	}
	return z; 
}	
void doc()
{
    cin>>s ; 
   	n = s.size() ;
    FOR(i,0,n-1)
    {
    	a[i] = s[i]; 
    }
    vi z = KMP(a,n) ; 
    int q; 
    s
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