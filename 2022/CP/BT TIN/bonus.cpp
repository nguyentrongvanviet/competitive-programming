#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N= 3e5+5, INF = 1e17  , C =330 , sm = 1e9+7  ;

ll n , m ;
string  c[N] ;
ll p[N];
ll T[1000001][26];
ll mx[N];
ll node= 1;
ll f[1000001] , dp[N];
vector<ll>g[N];
ll res;
void up(string s , ll val)
{
    ll r =1 ;
    for(ll i=  0;i<(ll)s.size();i++)
    {
        ll j = s[i] - 'A';
        if(T[r][j]==0)
        {
            ++node;
            T[r][j] = node ;
        }
        r= T[r][j] ;
        f[r] =max(f[r],val);
    }
}
ll get(string s)
{
    ll r= 1;
    for(ll i =0 ;i<(ll)s.size();i++)
    {
        ll  j = s[i]- 'A' ;
        if(T[r][j] ==0) return 0 ;
        r=T[r][j] ;
    }
    ll ans =0  ;
    for(ll i = 0 ;i<26;i++)
    {
        ll u = T[r][i] ;
        ans= max(ans,f[u]);
    }
    return ans;
}
void inp()
{
    cin>> n >> m ;
    for(ll i= 1;i<=n;i++)
    {
        cin>>c[i] >>p[i] ;
    }
    for(ll i= 1 ;i<=m;i++)
    {
        ll u ,v  ;
        cin>>u>>v ;
        g[u].pb(v) ;
        g[v].pb(u);
    }
    dp[1] =p[1];
    up(c[1],dp[1]);
    mx[p[1]]=p[1];
    res=p[1] ;
    for(ll i=2 ;i<=n;i++)
    {
        dp[i] =p[i] ;
        for(ll j =0  ;j<(ll)g[p[i]].size();j++)
        {
            dp[i] =max(dp[i],p[i]+mx[g[p[i]][j]]);
        }
        dp[i]= max(dp[i],get(c[i])+p[i]);
        up(c[i],dp[i]);
        mx[p[i]]=max(mx[p[i]],dp[i]);
        res=max(res,dp[i]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
