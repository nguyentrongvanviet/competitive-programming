#include<bits/stdc++.h>
using namespace std;

#define TASK "SUMABS"

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

const int N =52,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
int n , s ; 
ll f[N][2*N*N][N];
ll cong(ll a, ll b )
{
	return (a+b)%sm;
}
void doc()
{
 	cin>>n>>s;  	
}
void sub1()
{

}
void xuly()
{
	f[1][0+n*n][0]=1 ;
	f[1][-2+n*n][1]=1;  
 	FOR(i,1,n-1)
 	{
 		FOR(j,0,2*n*n)
 		{
 			FOR(x,0,i)
 			{
 				// i+1 -> i+1 
 				f[i+1][j][x]=cong(f[i][j][x],f[i+1][j][x]);
 				// i+1 -> i+2 , j+1->j+2
 				if(j-2*(i+1)>=0)f[i+1][j-2*(i+1)][x+1]=cong(f[i][j][x],f[i+1][j-2*(i+1)][x+1]) ;
 				// i+1 -> i , j+1 ->j
 				if(x)f[i+1][j+2*(i+1)][x-1]=cong(x*x%sm*f[i][j][x]%sm,f[i+1][j+2*(i+1)][x-1]) ; 
 				// x 
 				// i+1 ->i+2 , j+1-> j
 				if(x)f[i+1][j][x]=cong(x*f[i][j][x],f[i+1][j][x]);
 				// i+1 -> i , j+1->j+2
 				if(x)f[i+1][j][x]=cong(x*f[i][j][x],f[i+1][j][x]);
 			}
 		}
  	}   
  	cout<<f[n][s+n*n][0];
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}