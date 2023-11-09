#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =1000+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , k ;
ll f[N][N] ; 
void input()
{
 	cin>> n>> k ;  
 	for(int i=1 ;i<=n;i++)
 	{

 	}
 	for(int i=1 ;i<=n;i++)cin>>a[i] ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		for(int j =1 ;j<=7;j++)
 		{
 			f[i][j%m]++;
 		}
 	}
 	for(int i= 1;i<=n;i++)
 	{
 		for(int j =0  ;j<=k;j++)
 		{
 			for(int t= 0;t<=7;t++)
 			{
 				f[i][j] +=f[i-1][jj] ; 
 			}
 		}
 	}
 	for(int i=1 ;i<=n;i++)
 	{
 		
 	}
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}