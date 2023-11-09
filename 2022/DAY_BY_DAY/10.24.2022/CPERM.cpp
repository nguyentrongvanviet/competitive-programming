#include<bits/stdc++.h>
using namespace std;

#define TASK "CPERM"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
long long mod=1e9+7;
long long n ; 
long long expotitution( long long a, long long b)
{
	if(b==0) return 1;
	long long res=expotitution(a,b/2);
	if(b%2==0)
	{
		return (res*res)%mod;
	}
	else
	{
		return(res*res)%mod *a%mod;
	}
}
void doc()
{
 cin>>n;
 long long ans;
 if(n==0||n==1) cout<<0<<"\n";
 else{
 
 ans=expotitution(2,n-1)-2;
 cout<<ans<<"\n"; 
}
}
void xuly()
{
    
}
int main()
{
//    IOS();
int t;  
cin>>t;
while(t--)
{   
	doc(); 
    xuly();
}
    
}
