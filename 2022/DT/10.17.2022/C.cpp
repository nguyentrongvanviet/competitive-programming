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
ll f[N][4]  ; 
ll a[N] ; 
ll dd[N];
ll res ; 
void input()
{
	res=-inf ; 
 	cin>> n; 
 	for(int i= 1;i<=n;i++)
 	{
 		char c; 
 		cin>> c; 
 		dd[i]={c=='1'}; 
 	}   
 	for(int i= 1;i<=n;i++)
 	{
 		f[i][1]=f[i][0]=0;
 	}
 	for(int i= 1;i<=n;i++)cin>>a[i];
 	for(int i= 1;i<=n;i++)
 	{
 		if(dd[i])
 		{
 			f[i][1]=a[i]+max(f[i-1][1],f[i-1][0]);
 			f[i][0]= a[i-1]+f[i-1][0];
 		}
 		else 
 		{
 			f[i][0]=max(f[i-1][0],f[i-1][1]); 
 			f[i][1]=0;
 		}
 		res=max({res,f[i][1],f[i][0]});
 	}
 	cout<<res<<"\n";
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
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}