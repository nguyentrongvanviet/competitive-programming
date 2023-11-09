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
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int dd[N] ; 
int a[N] ; 
ll w[N] ; 
ll f[N];
ll r[N];
int m ; 
void input()
{
 	cin>> n>> m; 
 	for(int i= 1;i<=n;i++)cin>>a[i],dd[a[i]]=1 ; 
 	for(int i= 1 ;i<=m;i++)
 	{
 		cin>>w[i] ; 
 	}   
 	r[m+1] =inf ;
 	for(int i=m;i>=1;i--)
 	{	
 		r[i]=min(r[i+1],w[i]);
 	}
}
void output()
{
    sort(a+1,a+n+1);
    for(int  i=1 ;i<=m;i++)f[i] =inf ;
    for(int  i=1 ;i<=m;i++)
    {
    	if(dd[i]==0)
    	{
    		f[i] = f[i-1] ; 
    	}
    	else 
    	{
    		for(int j=1 ;j<=m;j++)
    		{
				if(i-j<=0)
				{
					f[i] =min(f[i],r[j]);
					break;
				}    	
				else 
				{
					f[i] =min(f[i],f[i-j]+w[j]);
				}		
    		}
    	}
    }
    cout<<f[m];
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