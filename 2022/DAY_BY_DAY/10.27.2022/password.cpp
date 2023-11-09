// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "password"

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

string s;  
int n ; 
int a[N] ;
map<int,int>sl; 
vector<int>Z_func(int s[] , int n )
{
	int l =0  ; 
	int r = 0 ;
	vi z(n);
	for(int i =1  ,l = 0 , r = 0   ; i<=n-1;i++)
	{
		if(i<=r)
		{		
			z[i] = min(r-i+1,z[i-l]);
		}
		while(s[i+z[i]]==s[z[i]])++z[i] ; 
		if(r<i+z[i]-1)
		{
			l= i ; 
			r=i+z[i]-1; 
		}
	}
	return z; 
}
void doc()
{
 	cin>>s;    
 	n = s.size(); 
 	FOR(i,0,n-1)
 	{
 		a[i] =s[i]; 
 	}
 	vector<int>z = Z_func(a,n) ;
 	// for(int i =0;i<n;i++)cout<<z[i]<<" "; 
 	FOR(i,1,n-1)
 	{
 		sl[z[i]]++; 
 	} 	
 	int res=0  ;
 	int tt =0  ;
 	FORD(i,n,1)
 	{
 		tt+=sl[i]; 		
 		if(tt>=2&&z[n-i]==i)
 		{
 			res=i ; 
 			break; 
 		}
 	}
 	if(res==0)
 	{
 		cout<<"Just a legend"; 
 	}
 	else 
 	{
 		cout<<s.substr(n-res);
 	}
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