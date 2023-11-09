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
const int N =5e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , q;  
int a[N] ; 
int f[N][N]  , ma[N][N] ;
int l[N] ,r[N];
void input()
{
 	cin>>n>> q; 
 	for(int i=1 ;i<=n;i++)cin>>a[i] ; 
 	for(int i=  1;i<=q;i++)
 	{
 		cin>>l[i] ; 
 	}
 	for(int i= 1;i<=q;i++)
 	{
 		cin>>r[i] ; 
 	}
}
void output()
{
    for(int i =1 ;i<=n;i++){f[i][i]=1,ma[i][i]=i;}
 	for(int  i=2;i<=n;i++)
 	{
 		for(int l= 1;l+i-1<=n;l++)
 		{
 			int r = l+i-1; 
 			if(a[ma[l][r-1]]>a[ma[l+1][r]])
 			{
 				ma[l][r]=  ma[l][r-1] ; 
 			}
 			else 
 			{
 				ma[l][r] =ma[l+1][r]; 
 			}
 			f[l][r] =r-l+1 +f[l][ma[l][r]-1]+f[ma[l][r]+1][r];
 		}
 	}
 	
 	for(int i= 1;i<=q;i++)
 	{
 		cout<<f[l[i]][r[i]]<<" ";
 	}
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