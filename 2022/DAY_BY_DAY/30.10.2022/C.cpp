#include<bits/stdc++.h>
using namespace std;

#define TASK ""

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =5e3+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

struct bg 
{
	ll x ,w ; 
}
int n ;
ll f[N][K] ; 
void doc()
{	
    cin>>n>> k;  
    for(int i= 1 ;i<=n;i++)cin>>a[i].x>>a[i].w ; 
    sort(a+1,a+n+1) ; 
   	for(int i= 1; i<=n;i++)
   	{
   		for(int j=1 ;j<=n;j++)
   		{
   			cp[i][j] =cp[i][j-1]+abs(a[j].x-a[i].x)*a[i].w;	
   		}
   	}
   	for(int i=0;i<=n;i++)
   	{
   		for(int j= 0 ;j<=k;j++)
   		{
   			f[i][j] = inf ;
   		}
   	}
   	for(int i=0;i<=n;i++)
   	{
   		f[i][0]=0;
   	}
   	for(int i = 0 ;i<=k;i++)
   	{	
   		f[0][i] = 0 ; 
   	}
   	for(int j= 1;j<=k;j++)
  	{
		for(int i= 1;i<=n;i++)
   		{
   			f[i][j] = f[i-1][j] ;
   			for(int ii = 1 ;ii<=i-1;ii++)
   			{
   				f[i][j] = min(f[i][j],f[ii][j-1]+cp[i][ii-1]-cp[i][i])
   			}
   		}	
   	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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