#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e2+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ,  m , k ;
ll a[N][N]  ,b[N][N], f[N][N][35]  , g[N] ; 
void inp()
{
    cin>>n>> m>> k ; 
    for(int i= 1;i<=n;i++)
    {
        for(int j =1 ;j<=m;j++)
        {
            cin>>a[i][j] ; 
        }
    }   
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1 ;j<=m;j++)
        {
            cin>>b[i][j] ; 
        }
    }
    for(int i =0;i<=n+1;i++)
    {
        for(int j = 0 ;j<=m+1;j++)
        {
            for(int t= 0 ;t<=k;t++)
            {
                f[i][j][t] =-inf; 
            }
        }
    }
    for(int i=0 ;i<=k;i++)
    {
        g[i] = -inf ; 
    }
    for(int i =1 ;i<=m;i++)
    {
        f[1][i][0] = a[1][i];
        if(b[1][i])
        {
            g[0] = max(g[0],f[1][i][0]);  
        }
    }
    for(int i= 2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int t= 0 ;t<=k;t++)
            {
                f[i][j][t] =max(f[i-1][j][t],f[i-1][j-1][t],f[i-1][j+1][t])+a[i][j]; 
            } 
            if(b[i][j])
            {
                for(int t= 1 ;t<=k;t++)
                {
                    g[t]=  max(g[t],f[i][j][t]); 
                    f[i][j][t] = max(f[i][j][t],g[t]+a[i][j]);
                }
            }
        }
    }
    ll res= -inf ; 
    for(int i=1 ;i<=m;i++)
    {
        for(int t =0  ;t<=k;t++)
        {
            res=max(res,f[n][i][t]);
        }
    }
    cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}