#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct bg
{
    ll x , y  ;
    bool operator<(bg u )
    {
        return y<u.y;
    }
};
ll n ;
bg a[N] ;
ll mi[N] , mii[N] , s[N];
void inp()
{
    cin>>n ;
    for(ll i =1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y ;
    }
    sort(a+1,a+n+1);
    for(ll i =1 ;i<=n;i++)
    {
        s[i] = s[i-1]+a[i].y ;
    }
    mi[0]= INF ;
    for(ll i =1 ;i<=n;i++)
    {
        mi[i] =min(mi[i-1],a[i].x-a[i].y);
    }
    mii[n+1]=INF;
    for(ll i= n ;i>=1;i--)
    {
        mii[i]=min(mii[i+1],a[i].x);
    }
    cout<<mii[1]<<"\n";
    for(ll i= 2 ;i<=n;i++)
    {
//        cout<<s[i-1]<<" "<<mii[i]<<endl;
        ll res= min(s[i-1]+mii[i],s[i]+mi[i]);
        cout<<res<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
