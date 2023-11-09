#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
struct pt
{
    ll x , y ;
};
ll dis(pt a  ,pt b  )
{
    return pow(a.x-b.x,2)+pow(a.y-b.y,2);
}
ll n , m ;
pt a[N] , b[N];
ll f[N][N][2];
void inp()
{
    cin>> n>> m ;
    for(ll i =1 ;i<=n;i++)cin>>a[i].x>>a[i].y ;
    for(ll i=1;i<=m;i++)cin>>b[i].x>>b[i].y;
    for(ll i= 0;i<=n;i++)
    {
        for(ll j = 0 ; j<=m;j++)
        {
            for(ll t= 0 ; t<=1;t++){
                f[i][j][t]= INF ;
            }
        }
    }
    f[1][0][0]=0;
    for(ll i =1;i<=n;i++)
    {
        for(ll j =0;j<=m;j++)
        {

            if(j>0)
            {
                f[i][j][1] =min(f[i][j][1],min(f[i][j-1][1]+dis(b[j-1],b[j]),f[i][j-1][0]+dis(a[i],b[j])));
            }
            f[i][j][0] = min(f[i][j][0],min(f[i-1][j][0]+dis(a[i],a[i-1]),f[i-1][j][1]+dis(a[i],b[j])));

        }
    }

    cout<<f[n][m][0]<<endl;
}
int main()
{
//    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
