#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 3e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

ll n , m ;
ll h[N];
vector<ll>g[N] ;
ll dd[N];
ll dfs(ll u ,ll val )
{
    dd[u] =1;
    if(u==n)
    {
        return 1;
    }
    for(ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i] ;
        if(dd[v]==1)continue ;
        if(abs(h[v]-h[u])<=val)
        {
            ll ans = dfs(v,val);
            if(ans)
            {
                return 1;
            }
        }
    }
    return 0;
}
ll tknp()
{
    ll l = 0 ;
    ll r = inf ;
    ll ans =0;
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(dfs(1,mid))
        {
            memset(dd,0,sizeof(dd));
            ans= mid ;
            r=mid-1 ;
        }else
        {
            l=mid+1;
        }
    }
    return ans;
}
void inp()
{
    cin>>n>>m ;
    for(ll i= 1 ;i<=n;i++)
    {
        cin>>h[i] ;
    }
    for(ll i=1 ;i<=m;i++)
    {
        ll u ,v ;
        cin>>u>>v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    cout<<tknp();
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}
