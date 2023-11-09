#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N= 2e6+5 , INF = 1e17  , C =330 , sm = 1e9+7  ;
map<ll,ll>dd;
ll n , k ;
ll a[N] ;
ll res;
void inp()
{
    cin>> n >>k ;
    for(ll i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    res= n ;
    for(ll i=1;i<=n;i++)
    {
        dd[a[i]]++ ;
        if(dd[a[i]]>=k)
        {
            dd[a[i]+1]++;
            dd[a[i]]=0;
            res-=k;
            res++;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
