#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =5e2+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct ke
{
    ll  v;
    ll t ;
    ll c;
};
struct adj
{
    ll t , c ;
};
struct bg
{
    ll u ;
    ll gt;
};
struct cmp
{
    bool operator()(bg a  , bg b   )
    {
        return a.gt>b.gt;
    }
};
ll n , m ;
vector<ke>g[N];
adj a[N][N];
ll x[N];
ll f[N],dd[N],ans;
void dij(ll s )
{
    priority_queue<bg,vector<bg>,cmp> q ;
    for(ll i= 1;i<=n;i++)f[i] =INF,dd[i]=0;
    f[s]=0 ;
    q.push({s,0});
    while(!q.empty())
    {
        ll u =q.top().u ;
        ll gt=q.top().gt;
        q.pop();
        if(dd[u])continue ;
        dd[u]= 1 ;
        for(ll i=  0;i<g[u].size();i++)
        {
            ll  v= g[u][i].v ;
            ll t= g[u][i].t ;
            ll c= g[u][i].c;
            if(dd[v])continue;
            if(f[v]>gt+t)
            {
                f[v]=gt+t;
                q.push({v,f[v]});
            }
        }
    }
}
void build()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1 ;j<=n;j++)
        {
            if(i==j)continue;
            if(f[i]+a[i][j].t==f[j])
            {
//                cout<<i<<" "<<j<<endl;
                g[i].pb({j,a[i][j].t,a[i][j].c});
            }
        }
    }
}
void dfs(ll u ,ll le ,  ll val,ll ma )
{
    if(u==n)
    {
        ans= 1;
        return ;
    }
    for(ll i = 0 ;i <g[u].size();i++)
    {
        ll v =g[u][i].v  ;
        ll t= g[u][i].t  ;
        ll c=g[u][i].c;
        if(val<c||le+t+f[v]!=f[1])continue;
        dfs(v,le+t,(x[v]==1 ? ma : val-c),ma);
    }
}
ll check(ll val)
{
    ans =0 ;
    dfs(1,0,val,val);
    if(ans)return 1;
    return 0 ;
}
void inp()
{
    cin>>n;
    for(ll i=1 ;i<=n;i++)
    {
        cin>>x[i] ;
    }
    cin>>m;
    for(ll i=1;i<=m;i++)
    {
        ll u , v , t , c ;
        cin>>u>>v>>t>>c;
        g[u].pb({v,t,c});
        g[v].pb({u,t,c});
    }
    dij(n);
    ll l = 0;
    ll r = INF ;
    ll res=INF ;
    for(ll i= 1;i<=n;i++)dd[i] =0 ;
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(check(mid)==1)
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
