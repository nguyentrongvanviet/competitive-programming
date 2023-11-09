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
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ,  m ; 
ll a[N] , mi[N] , res=-inf ; 
ll s[N];
void input()
{
    cin>> n>> m;  
    for(int i= 1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i] ; 
}
void output()
{	
	for(int i=0;i<m;i++)
	{
		mi[i] = inf ; 
	}
	mi[0] = 0 ;
    for(int i= 1 ;i<=n;i++)
    {
    	res=max(res,s[i]-mi[i%m]);
    	mi[i%m]=min(mi[i%m],s[i]);
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