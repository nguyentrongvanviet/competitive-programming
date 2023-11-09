#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N = 4e2+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

ll a[N][N] ;
ll s[N][N] ;
ll x[N] ,  y[N];
ll n , m  ;

ll line(ll t , ll i , ll  j)
{
    return s[t][j]-s[t][i-1]-(s[t-1][j]-s[t-1][i-1]);
}
ll ca(ll t , ll i , ll j )
{
    return s[t][j]-s[t][i-1];
}
ll area(ll t , ll i , ll j )
{
    return (y[j]-y[i])*(x[t]-x[1]);
}
void inp()
{
    cin>>n>>m ;
    for(ll i=1 ;i<=n;i++)cin>>x[i];
    for(ll i =1;i<=m;i++)cin>>y[i];
    for(ll i=1 ;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            cin>>a[i][j] ;
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    ll res= -INF;
    for(ll i=1 ;i<=m;i++)
    {
        for(ll j =i;j<=m;j++)
        {
            res=max(res,line(1,i,j));
            ll ma =  0;
            for(ll t = 2;t<=n;t++)
            {
                ll c = ca(t,i,j);
                ll are=area(t,i,j);
                res=max(res,line(t,i,j));
                res=max(res,c-are+ma);
                ma =max(ma,are-c+line(t,i,j));
            }

        }
    }
    cout<<res;
}
void sub1()
{
    cin>>n>>m ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>x[i] ;
    }
    for(ll i=1;i<=m;i++)
    {
        cin>>y[i] ;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j] ;
            s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
        }
    }
    ll res =0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            for(ll u =1;u<=i;u++)
            {
                for(ll v= 1;v<=j;v++)
                {
                    res=max(s[i][j]-s[i][v-1]-s[u-1][j]-(x[i]-x[u])*(y[j]-y[v]),res);
                }
            }
        }
    }
    cout<<res ;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}
