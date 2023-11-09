// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "path"

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
int p[N] ; 
ll s[N] ; 
ll f[N] ; 
void doc()
{
	cin>>n ; 
	FOR(i,1,n)cin>>p[i] ; 
	f[1] = 2; 
	s[1] = 2;  
	FOR(i,2,n)
	{
		if(p[i]==i)
		{
			f[i] = f[i-1]+2; 
			f[i]%=sm;
		}
		else
		{
			f[i] =f[i-1]+s[i-1]-s[p[i]-1]+2;
			f[i]=(f[i]+sm)%sm;
		} 
		s[i] =(s[i-1]+f[i]-f[i-1]+sm)%sm;
	}   
	cout<<f[n] ;
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