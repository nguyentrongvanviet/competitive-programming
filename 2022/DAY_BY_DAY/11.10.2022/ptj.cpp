#include<bits/stdc++.h>
using namespace std;

#define TASK ""
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int f[N] ,  g[N] ; 
int a[N] ; 
void doc()
{
 	cin>> n;  
 	FOR(i,1,n)
 	{
 		char x;  cin>> x; 
 		 a[i]  = (x=='A') ; 
 	}   
 	if(a[1]==1)
 	{
 		f[1] = 0 ;
 		g[1] = 1 ; 
 	}
 	else 
 	{
 		g[1] = 0; 
 		f[1]= 1 ; 
 	}
 	FOR(i,2,n)
 	{
 		if(a[i]==1)
 		{
 			f[i] = f[i-1];  
 			g[i] = min(g[i-1]+1,f[i-1]+1); 
 		}
 		else 
 		{
 			f[i]= min(g[i-1]+1,f[i-1]+1) ; 
 			g[i] = g[i-1] ; 
 		}
 	}
 	cout<<f[n] ; 
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}