#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct edge
{
    ll u , v , d ;
};
struct ke
{
    ll v ,d ;
};
struct bg
{
    ll u ,d  ;
};
struct cmp
{
    bool operator()(bg a  ,bg b )
    {
        return a.d>b.d;
    }
};
ll n , m ;
vector<ke>g[N] ;
ll f[N] ,dd[N]  , sl[N];
map<ll,ll>dis[N];
map<ll,ll>way[N];
void  dij(ll s)
{
    for(ll i= 1;i<=n;i++)f[i] =INF,dd[i]=0 ,sl[i] = 0 ;
    priority_queue<bg,vector<bg>,cmp>q;
    q.push({s,0});
    f[s]= 0 ;
    sl[s]= 1;
    while(!q.empty())
    {
        ll u =q.top().u ;
        q.pop();
        if(dd[u])continue;
        dd[u] =1;
        for(ll i= 0 ;i<g[u].size();i++)
        {
            ll v= g[u][i].v ;
            ll d= g[u][i].d;
            if(dd[v]==1)continue ;
            if(f[v]>f[u]+d)
            {
                f[v] =f[u]+d;
                sl[v] = sl[u] ;
                q.push({v,f[v]});
            }
            else if(f[v]==f[u]+d){
                sl[v]+=sl[u];
            }
        }
    }
    for(ll i= 1 ;i<=n;i++)
    {
        dis[s][i] = f[i] ;
        way[s][i] = sl[i];
    }
}
void inp()
{
    cin>>n>>m  ;
    for(ll i= 1;i<=m;i++)
    {
        ll u , v , d;
        cin>>u>>v>>d;
        g[u].pb({v,d}) ;
        g[v].pb({u,d}) ;
    }
    dij(1) ;
    dij(n) ;
    vector<ll>res;
    ll fa =dis[1][n];
    for(ll i= 2;i<=n-1;i++)
    {
        ll le = dis[1][i]+dis[n][i] ;
        if(fa!=le)
        {
            res.pb(i) ;
        }else
        {
            if(way[n][i]*way[1][i]!=way[1][n])res.pb(i);
        }
    }
    cout<<res.size()<<endl ;
    for(ll i= 0  ;i<res.size();i++)cout<<res[i] <<" ";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
