#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_D4"

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

const int N =5e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ;
int g[N][N];
int f[N][N];  
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}
void xuly()
{
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			g[i][j]=f[i][j]=oo; 
		}
	}
	FOR(i,1,n)
	{
		f[i][i]= 0 ; 
		g[i][i] = 0 ;
	}
 	FOR(l,0,n)
 	{
 		FOR(i,1,n-l+1)
 		{
 			int j= i+l-1 ; 
 			if(a[i]==a[i+1])
 			{
 				f[i][j]=min(f[i][j],f[i+1][j]) ; 
 			}
 			else 
 			{
 				f[i][j]=min(f[i][j],f[i+1][j]+1);
 			}
 			if(a[i]==a[j])
 			{
 				f[i][j]=min(f[i][j],g[i+1][j]);
 			}
 			else 
 			{
 				f[i][j]=min(f[i][j],g[i+1][j]+1) ;
 			}
 			if(a[j]==a[j-1])
 			{
 				g[i][j]=min(g[i][j],g[i][j-1]);
 			}
 			else 
 			{
	 			g[i][j]=min(g[i][j],g[i][j-1]+1) ;
 			}
 			if(a[i]==a[j])
 			{
 				g[i][j]=min(g[i][j],f[i][j-1]);
 			}
 			else
 			{
 				g[i][j]=min(g[i][j],f[i][j-1]+1);
 			}
 		}	
 	}
 	// cout<<f[3][6][0]<<endl;
 	cout<<min(g[1][n],f[1][n]);
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}