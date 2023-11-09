#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define pk pop_back

const ll N = 1e3+5 , INF = 1e17 , sm = 1e9+7 ;

struct cmp
{
    bool operator()(pii a , pii b )
    {
        return a.first<b.first;
    }
};
ll n ;
ll dd[N][N] ;
vector<ll>g[N] ;
vector<ll>ans[N];
ll b[N];
priority_queue<pii,vector<pii>,cmp> q;
void dfs(ll u  )
{
    for(ll i=  0;i<g[u].size();i++)
    {
        ll v=g[u][i];
        if(dd[u][v]==0&&dd[v][u]==0)
        {
            b[u]--;
            b[v]--;
            dd[u][v]=1;
            ans[u].pb(v);
            dfs(v);
            return ;
        }
    }
}
void inp()
{
    for(ll i= 1;i<=n;i++)
    {
        g[i].clear();
        ans[i].clear();
    }
    memset(dd,0,sizeof(dd));
    cin>> n ;
    for(ll i=1;i<=n;i++)
    {
        ll u ;
        cin>>u ;
        q.push({u,i});
        b[i]=u;
    }
    while(!q.empty())
    {
        ll  x= q.top().first ;
        ll  u=q.top().second;
        q.pop();
        if(x>q.size())
        {
            cout<<"-1\n";
            return ;
        }
        vector<pii>tmp ;
        while(x--)
        {
            ll xx=q.top().first ;
            ll v=q.top().second;
            g[u].pb(v);
            g[v].pb(u);
            q.pop() ;
            xx-- ;
            tmp.pb({xx,v});
        }
        for(auto v :tmp)
        {
            q.push(v);
        }
    }
    for(ll i =1 ;i<=n;i++)
    {
        if(b[i]&1)
        {
            dfs(i);
        }
    }
    for(ll i=1 ;i<=n;i++)
    {
        if((b[i]&1)==0)
        {
            dfs(i);
        }
    }
    for(ll i=1 ;i<=n;i++)
    {
        for(ll j= 0 ;j<ans[i].size();j++)
        {
            cout<<i<<" "<<ans[i][j]<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;cout.tie(0) ;
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    ll test ;
    cin>>test ;
    while(test--)
    {
        inp();
    }
}
