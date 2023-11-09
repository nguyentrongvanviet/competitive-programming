#include<bits/stdc++.h>
using namespace std;

#define TASK "colorboard"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n , m  ,q ;  
int a[N][N] ;
int s[N][N] ; 
int sum_in(int x , int y  , int u , int v )
{
	return (s[u][v]-s[u][y-1]-s[x-1][v]+s[x-1][y-1])>0;
}
void doc()
{
 	cin>> n>> m  >> q ; 
 	FOR(i,1,n)
 	{
 		FOR(j,1,m)
 		{
 			char x ;
 			cin>>x ; 
 			a[i][j] = (x=='*');
 		}
 	}   
 	FOR(i,1,n)FOR(j,1,m)
 	{
 		s[i][j] =s[i-1][j]+s[i][j-1]-s[i-1][j-1]+((a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])%2==1);
 	}
 	FOR(i,1,q)
 	{
 		int x, y, u , v; 
 		cin>>x>>y>>u>>v ; 
 		if(x==u||y==v)
 		{
 			cout<<"YES"<<"\n";
 		}
 		else 
 		{
 			if(sum_in(x,y,u-1,v-1))
 			{
 				cout<<"NO"<<"\n";
 			}
 			else 
 			{
 				cout<<"YES"<<"\n";
 			}
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
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}