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
int a[N]  ,f[N];
void input()
{
    cin>> n; 
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i] ; 
    }
}
void output()
{
	int res= 1 ;  
	for(int i= 1;i<=n;i++)
	{
		f[i] =1 ; 
		for(int j= 1;j<=i-1;j++)
		{
			if(a[i]%a[j]==0)
			{
				f[i]=max(f[i],f[j]+1) ; 
				res=max(res,f[i]);  
			}
		}
	}    
	cout<<res; 
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