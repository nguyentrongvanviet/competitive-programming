#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
const ll N =1e5+5 ;
ll n  ,a[N] ,s[N];
ll tknp(ll l , ll r , ll val)
{
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2 ;
        if(a[mid]<val)
        {
            ans= mid ;
            r=mid-1 ;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
void inp()
{
    cin>> n  ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    sort(a+1,a+n+1,greater<ll>());
    for(ll i=1;i<=n;i++)
    {
        s[i] =s[i-1]+a[i] ;
    }
    if(s[n]&1)
    {
        cout<<"NO"<<"\n";
        return ;
    }
    for(ll i=1;i<=n;i++)
    {
        ll t = tknp(i+1,n,i);
        if(t==0)
        {
            if(s[i]>i*(i-1)+i*(n-i))
            {
                cout<<"NO"<<"\n";
                return ;
            }
        }
        else if(s[i]>i*(i-1)+s[n]-s[t-1]+i*(t-i-1))
        {
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ;cin.tie(0) ;cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test ;
    while(test--)
    {
        inp();
    }
}
