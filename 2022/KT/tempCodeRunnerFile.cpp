#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
int n  , k ;
int a[N] ; 
ll f[N][205] , ma[N][205]; 
void inp()
{
    cin>> n>> k ; 
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int i =0;i<=n;i++)
    {
        for(int  j= 0;j<=k;j++)
        {
            f[i][j] = -oo;
            ma[i][j]= -inf ; 
        }
    }
    ma[0][1] = -inf ;
    for(int i =1 ;i<=n;i++)
    {
        ma[i][1] =max(ma[i-1][1],-a[i]); 
    }
    for(int i =2;i<=n;i++)
    {
        f[i][1] = max(f[i-1][1],ma[i-1][1]+a[i]);
        cout<<f[i][1]<<" ";
    }
    for(int j =2;j<=k;j++)
    {
        for(int i =1;i<=n;i++)
        {
            f[i][j] = max(f[i-1][j],ma[i-1][j]+a[i]); 
            ma[i][j] = max(ma[i-1][j],f[i-1][j-1]-a[i]);
        }
    }
    // cout<<endl;
    // for(int i =1;i<=n;i++)
    // {
        // cout<<f[i][2]<<" " ;
    // }cout<<endl;
    ll res = -inf ; 
    for(int i= 1;i<=k;i++)
    {
        res=max(res,f[n][i]); 
    }
    cout<<res; 
}
signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout);
    
    inp();
    return 0;
}