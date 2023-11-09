#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =5e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , t ;
ll a[N],s[N]  ;
ll res=0 ;
ll ma[N] ;
ll tknp(ll val, ll pos )
{
    ll ans = pos;
    ll l = 0;
    ll r = pos -1;
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(ma[mid]>=val)
        {
            ans=mid;
            r=mid-1;
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
    cin>>n >>t;
    for(ll i =1;i<=n;i++)
    {
        cin>>a[i] ;
        s[i] =s[i-1]+a[i];
    }
    for(ll i =1 ;i<=n;i++)
    {
        ma[i] = max(ma[i-1],s[i]);
    }
    ll st= 0 ;
    for(ll i= 1;i<=n;i++)
    {
        ll pos = tknp(s[i]-t,i);
        if(res<i-pos)
        {
            res=i-pos;
            st=pos+1;
        }else if(res==i-pos)
        {
            st= min(st,pos+1);
        }
    }
    cout<<res<< " "<<st;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
    return 0 ;
}
