#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , k ; 
ll  a[N] , f[N][N]  ,mi[N][N] ; 
void inp()
{
 	cin>> n>> k;  
 	for(int  i=1 ;i<=n;i++)cin>>a[i] ;
 	for(int i=0;i<=n;i++)
 	{
 		for(int j= 1;j<=k;j++)
 		{
 			mi[i][j]=oo ; 
 		}
 	}
 	for(int j=1;j<=k;j++)
 	{
 		for(int i = 2*j;i<=n;i++)
 		{
 			f[i][j] =mi[i-2][j-1]+abs(a[i]-a[i-1]) ; 
 			mi[i][j] =min(mi[i-1][j],f[i][j]); 
 		}
 	}
 	cout<<mi[n][k]; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
     freopen("i.txt","r",stdin); 
     freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        inp();
    }
    return 0;
}
