#include<bits/stdc++.h>
using namespace std;

#define TASK "knight2"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
// #pragma GCC target("popcnt")
const int N =3e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , q; 
int a[N] ; 
int ans[N];
int pa[N] ;	
int goc(int u)
{
	return pa[u]==u?u:pa[u]=goc(pa[u]);
}
void doc()
{
 	cin>> n >>q; 
 	FOR(i,1,n)pa[i] = i ;
 	pa[n+1] = n+1;
 	FOR(i,1,q)
 	{
 		int l ,r , x ;
 		cin>>l>>r>>x ; 
 		int alive = l ; 
 		while(alive<=r)
 		{
 			alive= goc(alive) ; 
 			if(alive>r)continue;
 			else if(alive<x)
 			{
 				ans[alive] = x;  
 				pa[alive] =  x;
 			}
 			else if(alive>x)
 			{
 				ans[alive] =x ; 
 				pa[alive] = goc(alive+1);
 			}
 			++alive;
 		}
 	}   
 	FOR(i,1,n)cout<<ans[i]<<" ";
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