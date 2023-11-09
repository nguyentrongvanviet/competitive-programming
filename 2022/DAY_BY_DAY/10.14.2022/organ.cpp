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
const int N =2e2+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll s[N] , a[N] ; 
void input()
{
 	cin>> n>>k>>w>>L>>R; 
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ;
 		s[i]=s[i-1]+a[i] 
 	}   
}
ll sc[N];  
ll f[N][N] ; 
void init()
{
	for(int i  =1 ;i<=n;i++)
	{
	}
}
void output()
{
	init() ; 
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1 ;j<=k;j++)
		{
			f[i][j] = -1;  
		}
	}
	for(int t = 1;t<=n;t++)
	{
		if(L<=s[i]&&s[i]<=R)
		{
			f[i][1] =sc(a[i]) ;
		}
		else 
		{
			f[i][1] =-1; 
		}
	}
	for(int j =2;j<=k;j++)
	{
		for(int i= j;i<=n;i++)
		{
			for(int t =i-1;t>=1;t--)
			{
				if(f[t][j]!=-1&&L<=s[i]-s[j]&&s[i]-s[j]<=R)
				{
					f[i][j] = max(f[i][j],f[t][j]+sc[j-i]);
				}
			}
		}
	}
	cout<<f[n][k];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}