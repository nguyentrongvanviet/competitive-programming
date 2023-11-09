#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define p(x,y) pair<ll,ll>(x,y)
#define BIT(i,x) ((x>>i)&1)
#define MASK(x) (1<<x)
#define ld long double
#define __builtin_popcount __builtin_popcountll
#define pll pair<ll,ll>
template<class T1,class T2>
bool maximize(T1 &x,const T2 &y)
{
    if(x<y)
    {
        x=y;
        return 1;
    }
    return 0;
}
template<class T1,class T2>
bool minimize(T1 &x,const T2 &y)
{
    if(x>y||x==-1)
    {
        x=y;
        return 1;
    }
    return 0;
}
void online()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef thuc
    freopen("input.INP","r",stdin);
    freopen("output.OUT","w",stdout);
#else
    freopen("cay.INP","r",stdin);
    freopen("cay.ANS","w",stdout);
#endif
}
const ll N=3e5+10;
ll f[N][52][2],co[N][2],ans,topar[N];
int a[N],par[N],d,n,best;
pair<int,int> nxt[N][52][1];
vector<pair<int,int> > gr[N];
vector<int> res;
void dfs(ll u)
{
    for(auto [v,c]:gr[u])
    {
        if(v==par[u]) continue;
        par[v]=u;
        topar[v]=c;
        dfs(v);
        if(maximize(ans,f[v][max(0,d-c)][0]+a[u])) best=v;
        for(int k=d;k>=0;k--)
        {
            co[k][0]=f[u][k][0];
            co[k][1]=f[u][k][1];
        }
        for(ll k=d;k>=0;k--)
        {
            if(maximize(co[min(d-k,k)][0],f[u][d-k][0]+f[v][max(0ll,k-c)][0])) nxt[u][min(d-k,k)][0]=p(v,0);
            if(k*2>=d)
            {
                if(maximize(co[k][0],f[u][k][0]+f[v][max(0ll,k-c)][0])) nxt[u][k][0]=p(v,1);
            }
        }

        for(int k=d;k>=0;k--)
        {
            if(maximize(co[k][0],co[k+1][0])) nxt[u][k][0]=nxt[u][k+1][0];
            f[u][k][0]=co[k][0];
        }
    }
    if(maximize(f[u][0][0],a[u]))
    {
        nxt[u][0][0]=p(u,0);
    }
}
void trace(ll u,ll k)
{
    ll sum=0;
    if(nxt[u][0][0].fi==u&&k==0)
    {
        res.push_back(u);
        return;
    }
    for(auto [v,c]:gr[u])
    {
        if(v==par[u]) continue;
        ll fr=max(d-k,k)-c;
        maximize(fr,0);
        sum+=f[v][fr][0];
    }
    ll nxt=0;
    for(auto [v,c]:gr[u])
    {
        if(v==par[u]) continue;
        ll fr1=k-c;
        ll fr2=max(d-k,k)-c;
        maximize(fr1,0);
        maximize(fr2,0);
        if(sum-f[v][fr2][0]+f[v][fr1][0]==f[u][k][0])
        {
            nxt=v;
            break;
        }
    }
    for(auto [v,c]:gr[u])
    {
        if(v==par[u]) continue;
        ll fr=k-c;
        if(nxt==v)
        {
            fr=k-c;
            maximize(fr,0);
            if(f[v][fr][0]==0) continue;
            while(f[v][fr][0]==f[v][fr+1][0]) fr++;
            trace(v,fr);
        }
        else
        {
            fr=max(d-k,k)-c;
            maximize(fr,0);
            if(f[v][fr][0]==0) continue;
            while(f[v][fr][0]==f[v][fr+1][0]) fr++;
            trace(v,fr);
        }
    }
}
int main()
{
    online();
    cin>>n;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        gr[u].emplace_back(v,c);
        gr[v].emplace_back(u,c);
    }
    dfs(1);
    if(maximize(ans,f[1][0][0])) best=1;
    if(best!=1) res.push_back(par[best]);
    cout<<ans<<'\n';
    // ans-=a[par[best]];
    // if(best==1)
    // {
    //     int k=0;
    //     while(f[best][k][0]==f[best][k+1][0]) k++;
    //     trace(best,k);
    //     if(!res.size()) res.push_back(1);
    // }
    // else
    // {
    //     int k=d-topar[best];
    //     maximize(k,0);
    //     if(f[best][k][0]!=0)
    //     {
    //         while(f[best][k][0]==f[best][k+1][0]) k++;
    //         trace(best,k);
    //     }
    // }
    // cout<<res.size()<<'\n';
    // for(auto v:res) cout<<v<<' ';
}