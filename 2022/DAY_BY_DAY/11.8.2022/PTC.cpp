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
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ;  
int a[N] ; 
int id  ; 
void doc()
{
 	cin>>n ; 
 	id=  1;  
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 
 		if(a[i]<a[id])
 		{
 			id= i ; 
 		}
 	} 
 	FOR(i,1,n)
 	{
 		FOR(j,1,a[i])
 		{
 			int u ;cin>>u ;
 			q[i].pb(u); 
 		}
 	}
}
void xuly()
{
	FOR(i,1,)
	{
		FOR()
		{

		}
	}
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
        xuly();
    }
    return 0;
}