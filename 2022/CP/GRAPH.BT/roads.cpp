#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =5e2+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct ke
{
    ll v , l,c;
};
struct bg
{
    ll u ,  l , c ;
};
struct bg1
{
    ll u , dis ;
};
struct cmp
{
    bool operator()(bg a , bg b )
    {
        return a.c>b.c;
    }
};
struct cmp1
{
    bool operator()(bg1 a , bg1 b )
    {
        return a.dis>b.dis;
    }
};
ll n ,  m ;
vector<ke>g[N] ;
ll dis[N] ;
ll a[N];
ll len;
ll dd[N];
void inp()
{
    cin>> n ;
    for(ll i=1 ;i<=n;i++)
    {
        cin>>a[i] ;
    }
    cin>>m;
    for(ll i =1 ;i<=m;i++)
    {
        ll u ,v , l , c ;
        cin>>u>>v>>l>>c;
        g[u].pb({v,l,c}) ;
        g[v].pb({u,l,c}) ;
    }
}
ll dij()
{
    for(ll i= 1;i<=n;i++)
    {
        dis[i] = INF ;
    }
    priority_queue<bg1,vector<bg1>,cmp1> q;
    q.push({1,0});
    dis[1]= 0;
    while(!q.empty())
    {
        ll u =q.top().u;
        q.pop();
        if(dd[u])continue;
        dd[u] =1;
        for(ll i= 0 ;i<g[u].size();i++)
        {
            ll v =g[u][i].v;
            ll l=g[u][i].l;
            if(dd[v]==1)continue;
            if(dis[v]>dis[u]+l)
            {
                dis[v]=dis[u]+l;
                q.push({v,dis[v]});
            }
        }
    }
    return dis[n];
}
ll check(ll val )
{
    unordered_map<ll,ll>f[N];
    priority_queue<bg,vector<bg>,cmp> q;
    f[1][val] =0;
    q.push({1,0,val});
    while(!q.empty())
    {
        ll u = q.top().u ;
        ll dis= q.top().l;
        ll cc =q.top().c;
        q.pop();
        if(dis>f[u][cc])continue ;
        if(u==n)
        {
            return (dis==len);
        }
        for(ll i= 0 ;i<g[u].size();i++)
        {
            ll v= g[u][i].v;
            ll w =g[u][i].l ;
            ll c= g[u][i].c ;
            if(cc<c)continue ;
            if(a[v]==1)
            {
                if(f[v][val]==0||f[v][val]>dis+w)
                {

                    q.push({v,f[v][val]=dis+w,val});
                }
            }
            else{
                if(f[v][cc-c]==0||f[v][cc-c]>dis+w)
                {
                    q.push({v,f[v][cc-c]=dis+w,cc-c});
                }
            }
        }
    }
    return 0 ;
}
void tknp()
{
    len= dij();
    ll l=1 ;
    ll r= 1e9 ;
    ll res;
//    for(ll i=1 ;i<=100;i++)cout<<check(i)<< " ";
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(check(mid))
        {
            r=mid-1;
            res=mid ;
        }else
        {
            l=mid+1;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
    tknp();
}
