#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e6, INF =1e17 , C= 330  , MOD = 1e9+7 ;
ll k , l , m ;
ll f[N];
void inp()
{
    cin>>k>>l>> m;
    vector<ll>v{k,l,1};
    ll n = 1000000;
    f[0]= 0 ;
    for(ll i=1;i<=n;i++)
    {
        for(auto it : v )
        {
            if(i>=it)
            if(f[i-it]==0)
            {
                f[i] = 1;
                break ;
            }
        }
    }
    for(ll i =  1 ;i<=m;i++)
    {
        ll u ;
        cin>>u ;
        cout<<(f[u]==1? 'A':'B');
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
