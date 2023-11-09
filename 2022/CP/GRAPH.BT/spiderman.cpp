#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e6+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
ll n , k ;
ll res[N] ;
map<ll,ll>m;
ll a[N] ;
void inp()
{
    cin>>n>>k ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for(auto it : m)
    {
        if(it.first<=k)continue ;
        for(ll j = k;j<=N;j+=it.first)
        {
            res[j]+=it.second;
        }
        if(k==0)res[it.first]--;
    }
    for(ll i= 1 ;i<=n;i++)
    {
        cout<<res[a[i]]<<" " ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
