// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DIV"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ; 
int s[N] ; 
int res = 0;
vector<int>value ; 
int check(int sum)
{
	int ans= 0 ; 
	int l =1  ; 
	int tmp  = 0 ;
	int i=  1 ;  
	while(i<=n)
	{
		tmp+=a[i];
		if(tmp==sum)
		{
			ans++ ;
			tmp =0 ; 
		}
		++i ; 
	}
	if(tmp!=0)return 0 ; 
	return ans ;  
}
void doc()
{
 	cin>> n; 
 	bool ok  = 0 ; 
 	FOR(i,1,n)
 	{
 		cin>>a[i] ;
 		if(a[i]!=0)
 		{
 			ok = 1;  
 			value.pb(a[i]) ; 
 		}
 	}
 	if(ok==0)
 	{
 		cout<<n ;
 		return ; 
 	}
 	n= value.size() ; 
 	FOR(i,1,n)
 	{
 		a[i] =value[i-1]  ;
 		s[i] =s[i-1]+a[i] ;  
 	}
 	FOR(i,1,n)
 	{
 		res=max(res,check(s[i])) ; 
 	}
 	cout<<res;
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