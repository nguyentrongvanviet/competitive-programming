#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll a[N] ;
ll n  ;
void inp()
{
    cin>> n ;
    for(ll i =1;i<=n;i++)
        a[i]=i ;
    ll res= 0;
    if(n%2==0)
    {
        for(ll i= 2;i<=n;i+=2)
        {
            swap(a[i],a[i-1]);
        }
    }else
    {
        for(ll i= 3 ;i<=n;i+=2)
        {
            swap(a[i],a[i-1]);
        }
    }
    for(ll i =1;i<=n;i++) cout<<a[i]<< " ";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test;
    while(test--)
    {
        inp() ;
        cout<<"\n";
    }
}
