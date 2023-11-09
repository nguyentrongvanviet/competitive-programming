#include<bits/stdc++.h>
using namespace std;

#define TASK "color"

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
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int a[N]  ;
int n , k ;
int dd[N];
void doc()
{
 	cin>> n >>k ; 
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 
 	}   
 	int res=oo  ; 
 	FOR(bit,5,5)
 	{
 		FOR(i,1,n)dd[i] = 0 ;
 		FOR(j,1,n)
 		{
 			if(bit>>(j-1)&1)
 			{
 				for(int x=j;x<=min(n,j+k-1);x++)
 				{
 					if(a[x]==0||a[x]==a[j])dd[x]= 1 ; 
 				}
 			}
 		}
 		int ok = 1;
 		FOR(i,1,n)
 		{
 			// cout<<dd[i]<<" ";cout<<endl;
 			if(dd[i]==0)ok= 0; 
 		}
 		// cout<<bitset<5>(bit)<<endl;
 		if(ok)
 		{
 			cout<<bitset<5>(bit)<<endl;
 			res=min(res,__builtin_popcount(bit));
 		}
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