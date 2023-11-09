#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll l ,  n ;
ll a[N] ;
ll tinh(ll i , ll l , ll r , ll u )
{
    if(i==n+1) return 1 ;
    if(u>n)return  0 ;

}
void inp()
{
    cin>>l>>n ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    ll l =2 ;
    ll r =n ;
    ll res=n;
    while(l<=r)
    {
        ll mid = (l+r)/2 ;
        if(check(mid))
        {
            res= mid ;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<res ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
