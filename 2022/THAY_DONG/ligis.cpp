#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;



ll v(ll x , ll mu)
{
    ll ans =1;
    while(mu)
    {
        if(mu&1)
        {
            ans=(ans*x)%MOD ;
        }
        x=(x*x)%MOD;
        mu>>=1;
    }
    return ans ;
}
ll c(ll k , ll n )
{
    ll tu = 1 ;
    for(ll i= n-k+1;i<=n;i++)
    {
        tu=(tu*i)%MOD;
    }
    ll mau=1 ;
    for(ll i= 1;i<=k;i++)
    {
        mau=(mau*i)%MOD;
    }
    return (tu*v(mau,MOD-2))%MOD;
}
void inp()
{
    ll n ;
    cin>> n;
    ll k = 0 ;
    ll su = 2*(n-1) ;
    for(ll i=1 ;i<=n;i++)
    {
        ll  u ;
        cin>>u;
        if(u==-1)
        {
            k++;
        }else
        {
            su-=u ;
        }
    }
//    cout<<k<<" "<<su<<endl;
    cout<<c(k-1,su-1);
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
