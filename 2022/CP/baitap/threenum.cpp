#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int  n  ; 
ll m ; 
vector<ll> a;
ll f[N];
ll x[N] ; 
ll  res= 0 ;
ll sl[N] ; 
void inp()
{
 	cin>> n>> m; 
 	if(n>200)return ; 
    a.resize(n) ; 
 	for(int i= 0 ;i<n;i++)
 	{
 		cin>>a[i] ; 
 	}   
 	for(int i =0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			for(int t =0;t<n;t++)
 			{
 				if((a[i]*a[j]%m)*a[t]%m==0)
 				{
 					res++ ; 
 				}
 			}
 		}	
 	}
 	cout<<res; 
}
void sub2()
{
    cin>> n>> m; 
    a.resize(n+1);
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        x[a[i]%m]++;
    }
    for(int i =0 ;i<=m-1;i++)
    {
        for(int j=0;j<=m-1;j++) 
        {
            sl[i*j%m]+=x[i]*x[j]; 
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=  0 ;j<m;j++)
        {
            if(i*j%m==0)
            {
                res+=x[i]*sl[j]; 
            }
        }
    }
    cout<<res;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        sub2();
    }
    return 0;
}