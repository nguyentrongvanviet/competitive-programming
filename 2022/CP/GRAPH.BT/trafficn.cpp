#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct bg
{
    ll u ;
    ll c;
};
struct ke
{
    ll v ;
    ll c;
};
struct edge
{
    ll u , v , c ;
};
struct cmp
{
    bool operator()(bg a  , bg b )
    {
        return a.c>b.c;
    }
};
vector<ke>g[N] ;
edge q[N];
ll  n , m , k , s, t ;
map<ll,ll>dis[N] ;
ll dd[N] , f[N] ;
void dij(ll s )
{
    priority_queue<bg,vector<bg> ,cmp>q ;
    for(ll i= 1 ;i<=n;i++) dd[i]= 0  , f[i] =INF  ;
    f[s] = 0;
    q.push({s,0});
    while(!q.empty())
    {
        ll u =q.top().u ;
        q.pop() ;
        if(dd[u])continue ;
        for(ll i= 0 ;i<g[u].size();i++)
        {
            ll v = g[u][i].v;
            ll c =g[u][i].c;
            if(dd[v])continue ;
            if(f[v]>f[u]+c)
            {
                f[v]= f[u]+c ;
                q.push({v,f[v]});
            }
        }
    }
    for(ll i= 1;i<=n;i++)
    {
        dis[s][i] =  f[i];
    }
}
void inp()
{
    cin>>n>>m>>k>>s>>t ;
    for(ll i= 1 ;i<=m;i++)
    {
        cin>>q[i].u>>q[i].v>>q[i].c;
    }
    for(ll i= 1 ;i<=n;i++) g[i].clear();
    for(ll i=1;i<=m;i++)
    {
       ll u = q[i].u ;
       ll v =q[i].v ;
       ll c= q[i].c ;
       g[u].pb({v,c});
    }
    dij(s);
    for(ll i=  1 ;i<=n;i++)g[i].clear();
    for(ll i= 1 ;i<=m;i++)
    {
        ll u = q[i].u ;
       ll v =q[i].v ;
       ll c= q[i].c ;
       g[v].pb({u,c});
    }
    dij(t);
    ll res=dis[s][t] ;
    for(ll i= 1;i<=k;i++)
    {
        ll u , v ,c;
        cin>>u>>v>>c;
        if(dis[s][u]+c+dis[t][v]<res)
        {
            res= dis[s][u]+c+dis[t][v];
        }else if(dis[s][v]+c+dis[t][u]<res)
        {
            res=dis[s][v]+c+dis[t][u];
        }
    }
    cout<<(res ==INF ?  -1 : res);
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

    ll t;
    cin>>t ;
    while(t--)
    {
        inp();
    }
}
