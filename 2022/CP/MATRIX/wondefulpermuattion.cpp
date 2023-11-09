#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
ll n , k ;
ll a[N] ;
void inp()
{
    cin>>n>> k ;
    for(ll i= 1;i<=n;i++)
        cin>>a[i];
    ll res= 0 ;
    for(ll i =1 ;i<=k;i++)
    {
        if(a[i]>k)res++;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll t ;
    cin>>t ;

    while(t--)
    {
        inp();
        cout<<"\n";
    }
}
