#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int  m ,n  ,c ; 
ll a[N][N]  ,dd[N][N];
ll f[N][N][7] ;   
void inp()
{
    cin>>n>>m>> c;  
    for(int i=1 ;i<=n;i++)
    {
        for(int j=1 ;j<=m;j++)
        {
            cin>>dd[i][j] ; 
        }
    }
    for(int i=1 ;i<=n;i++)
    {
        for(int j =1 ;j<=m;j++)
        {
            cin>>a[i][j] ; 
        }
    }
    for(int i= 0;i<=n+1;i++)
    {
        for(int j= 0 ;j<=m+1;j++)
        {
            for(int t= 0;t<=2;t++)
            {
                f[i][j][t] =-inf ; 
            }
        }
    }   
    for(int  i=1 ;i<=m+1;i++)
    {
        f[0][i][0]=0;
    }
    vector<ll>ma(11,-inf) ;
    ll res=-inf ; 
    for(int t =0 ;t<=min(2,c);t++)
    {
        for(int i=1;i<=n;i++)
        {   
            for(int j= 1;j<=m;j++)
            {
                f[i][j][t] =max({f[i-1][j-1][t],f[i-1][j][t],f[i-1][j+1][t]})+a[i][j];
                if(dd[i][j]&&t>0)
                {
                    f[i][j][t]=max(f[i][j][t],ma[t-1]+a[i][j]);
                }
                if(dd[i][j])ma[t]=max(ma[t],f[i][j][t]); 
                if(i==n)res=max(res,f[i][j][t]); 
            }
        }
    }
    if(c<=2)
    {
        cout<<res ; 
        return ; 
    }
    res = -inf ; 
    for(int i= 1;i<=m;i++)
    {
        res=max(res,f[n][i][2]+(c-2)*max((ll)0,(ma[2]-ma[1])));
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