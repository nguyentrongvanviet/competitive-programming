#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back
const ll N =2000 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll x , a , y , b , n ;
pair<ll,ll>f[N][N];
pair<ll,ll> sta(pair<ll,ll>a , ll t , ll val)
{
    a.second+=t ;
    if(a.second>=val)
    {
        a.first++;
        a.second = 0 ;
    }
    return a;
}
ll check(ll val)
{
    for(ll i=  0 ; i<=x;i++)
    {
        for(ll j=0;j<=y;j++)
        {
            f[i][j] = make_pair(0,0);
        }
    }
    for(ll i =0 ;i<=x;i++)
    {
        for(ll j = 0 ;j<=y;j++)
        {
            pair<ll,ll>k = f[i][j];
            if(f[i][j].first==n)
            {
                return 1 ;
            }
            if(i<x)
            {
                f[i+1][j]=max(f[i+1][j],sta(f[i][j],a,val));
            }
            if(j<y)
            {
                f[i][j+1] =max(f[i][j+1],sta(k,b,val));
            }
        }
    }
    return 0 ;
}
void inp()
{
    cin>>x>>a>>y>>b>>n ;
    ll l = 0 ;
    ll r = (a * x + b * y) / n;
    ll res=0;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            res=mid ;
            l=mid+1;
        }else
        {
            r=mid-1;
        }
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll t= 2 ;
    while(t--)inp();
}
