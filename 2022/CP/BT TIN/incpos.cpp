#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e5+5 , INF = 1e17  , C= 330 , MOD = 1e9+7 ;
ll n , m, p , T ,B ;
ll a[N]  ;
ll b[N] ;
ll tknp1(ll val )
{
    ll l =  0 ;
    ll r=  p+1 ;
    ll ans ;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(b[mid]>=val)
        {
            ans=  mid  ;
            r = mid-1;
        }else
        {
            l=mid+1;
        }
    }
    return ans;
}
ll tknp2(ll val )
{
    ll l = 0 ;
    ll r = p+1;
    ll ans  ;
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(b[mid]<=val)
        {
            ans= mid ;
            l=mid+1;
        }
        else
        {
            r=mid-1 ;
        }
    }
    return ans ;
}
void inp()
{
    cin>>n>>m>>p>>T>>B  ;
    for(ll i= 1;i<=m;i++)
    {
        cin>>a[i]  ;
    }
    for(ll i= 1 ;i<=p;i++)
    {
        cin>>b[i];
    }
    if(n==1)
    {
        cout<<0 ;
        return ;
    }
    b[0] = 1 ;
    b[p+1] = n ;
    a[0] = 1;
    a[m+1] = n;
    ll res=0  ;
    for(ll i = 1; i<=m+1;i++)
    {
        ll x = tknp1(a[i-1]);
        ll y  = tknp2(a[i]);
        ll z= tknp2(a[i-1]);
        ll t=  tknp1(a[i]);
        ll mi1 , mi2 ;
        if(abs(a[i-1]-b[x])<abs(a[i-1]-b[z]))
        {
            mi1 = x;
        }else
        {
            mi1= z ;
        }
        if(abs(a[i]-b[y])<abs(a[i]-b[t]))
        {
            mi2= y ;
        }else
        {
            mi2= t;
        }
        ll ans = (a[i]-a[i-1])*T ;
        ans = min(ans,abs(b[mi1]-a[i-1])*T+B+abs(b[mi2]-a[i])*T);
        res+=ans ;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0);

    inp() ;
}
