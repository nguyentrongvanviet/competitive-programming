#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+9;
ll n , m ,  k ;
ll f[N][N][15];
ll a[N] , b[N];
void inp()
{
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    for(ll j= 1;j<=m;j++)
    {
        cin>>b[j];
    }
    sort(a+1,a+n+1) ;
    sort(b+1,b+m+1) ;
    for(ll i= 0;i<=n;i++)
    {
        for(ll j= 0 ;j<=m;j++)
        {
            f[i][j][0]=1;
        }
    }
    for(ll t =1;t<=k;t++)
    {
        for(ll i =1 ;i<=n;i++)
        {
            for(ll j =1;j<=m;j++)
            {
                if(a[i]>b[j])
                {
                    f[i][j][t] =(f[i-1][j-1][t-1] +f[i][j-1][t]+f[i-1][j][t]-f[i-1][j-1][t]+MOD)%MOD;
                }else
                {
                    f[i][j][t] = (f[i][j-1][t]+f[i-1][j][t]-f[i-1][j-1][t]+MOD)%MOD;
                }
//                cout<<i<< " " << j<< " " <<t <<" " <<f[i][j][t]<<endl;
            }
        }
    }
    cout<<f[n][m][k];
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
