#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
ll f[N][N];
ll n , m ;
ll a[N];
void inp()
{
    cin>> n>> m;
    for(ll i= 1;i<=n;i++)cin>>a[i];
    for(ll i =0;i<=n;i++)
    {
        f[i][0]=1 ;
    }
    for(ll i =1; i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            f[i][j] = (f[i-1][j]+(f[i-1][j-1]*a[i])%MOD)%MOD;
        }
    }
    cout<<f[n][m];
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    inp() ;
}
