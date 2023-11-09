#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e3+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

ll s1[N][N] ;
ll s2[N][N] ;
ll a[N][N] ;

ll n , k  ;
void inp()
{
    cin>> n>> k ;
    for(ll i = 1;i<=n;i++)
    {
        for(ll j= 1;j<=n;j++)
        {
            cin>>a[i][j] ;
        }
    }
    for(ll i=1 ;i<=n;i++)
    {
        for(ll j= 1;j<=n;j++)
        {
            s1[i][j] =s1[i-1][j-1]+a[i][j] ;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=n;j>=1;j--)
        {
            s2[i][j] =s2[i-1][j+1] +a[i][j];
        }
    }
    ll res=  -inf ;
    for(ll i=k;i<=n&&i<=n;i++)
    {
        for(ll j=k;j<=n;j++)
        {
            res=max(res,s1[i][j]-s1[i-k][j-k]+s2[i][j-k+1]-s2[i-k][j+1]-(k%2==1? a[i-k/2][j-k/2]:0));
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}

