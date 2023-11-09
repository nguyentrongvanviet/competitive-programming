#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =51,INF = 1e9 , C = 330  , MOD = 1e9+7 ;

struct bg
{
    ll u , gt;
    ll bit ;
    ll du ;
};
struct ke
{
    ll v , w;
};
struct cmp
{
    bool operator()(bg a ,bg b )
    {
        return a.gt>b.gt ;
    }
};
ll n , m ;
vector<ke>g[N] ;
ll f[N][(1<<13)][13];
ll dd[N][(1<<13)][13];
string ok  ;
void dij()
{
    priority_queue<bg,vector<bg>,cmp> q;
    q.push({1,0,1});
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1;j<(1<<13);j++)
        {
            for(ll t= 0 ;t<=12;t++)
            {
                f[i][j][t] =INF ;
                dd[i][j][t]=0;
            }
        }
    }
    f[1][1][0]=0;
    while(!q.empty())
    {
        ll u = q.top().u ;
        ll gt = q.top().gt;
        ll bit = q.top().bit;
        ll du = q.top().du ;
        if(u==n)
        {
            cout<<gt<<"\n";
            return;
        }
        q.pop() ;
        if(dd[u][bit][du]==1)continue ;
        dd[u][bit][du]=1;
        for(ll i = 0;i<g[u].size();i++)
        {
            ll v =g[u][i].v;
            ll w = g[u][i].w ;
            ll ndu = (du+w)%13;
            ll tt  = (1<<(ndu));
            if(dd[v][tt|bit][ndu])continue ;
            if(ok=="True"&&(bit&tt))continue ;
            if(f[v][tt|bit][ndu]>w+gt)
            {
                f[v][tt|bit][ndu] = w+gt;
                q.push({v,w+gt,tt|bit,ndu});
            }
        }
    }
    cout<<-1<<"\n";
}
bool cm(pii a , pii b )
{
    return a.second>b.second ;
}
void solve()
{
    ll dis[N] ;
    for(ll i=1;i<=n;i++)
    {
        dis[i]=INF ;
    }
    priority_queue<pii,vector<pii>,cp>q;
    q.push({1,0});
    while(!q.empty())
    {
        ll u  = q.top().first ;
        ll val =q.top().second ;
        if(d[u])continue ;
        d[u] 1 ;
        if(u==n)
        {
            cout<<val<<"\n" ;
            return ;
        }
        for(ll i= 0 ;i<g[u].size();i++)
        {
            ll v=g[u][i].v ;
            ll w= g[u][i].w;
            if(d[v]==0)
            {
                if(dis[v]>dis[u]+w)
                {
                    dis[v]= dis[u]+w;
                    q.push({v,dis[v]});
                }
            }
        }
    }
}
void inp()
{
    for(ll i= 1 ;i<=n;i++)
    {
        g[i].clear();
    }
    cin>>n>> m ;
    for(ll i=1 ;i<=m;i++)
    {
        ll u ,v,w ;
        cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    cin>>ok ;
    if(ok=="True")dij();
    else solve() ;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    ll t;
    cin>> t;
    while(t--)
    {
        inp();
    }
}
