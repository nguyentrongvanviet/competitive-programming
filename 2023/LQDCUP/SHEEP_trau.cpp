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
bool maximize(T1 &x,T2 y)
{
    if(x<y)
    {
        x=y;
        return 1;
    }
    return 0;
}
template<class T1,class T2>
bool minimize(T1 &x,T2 y)
{
    if(y<x)
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
    freopen("text.INP","r",stdin);
    freopen("text.ANS","w",stdout);

}
const ll N=5e5+10,M=1e9+7;
ll a[N],f[N],n,k;
vector<ll> gr[N];
bool sub1()
{
    memset(f,0x3f,sizeof f);
    for(int i=1; i<=k; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+k+1);
    f[1]=0;
    for(int i=1; i<=k; i++)
    {
        minimize(f[i+1],f[i]+1);
        if(i<k)
        {
            if((a[i+1]-a[i])%2==0) minimize(f[i+2],f[i]+1);
        }
    }
    cout<<f[k+1]<<'\n';
    ll cur=k+1;
    while(cur>1)
    {
        if(f[cur]==f[cur-1]+1)
        {
            cout<<a[cur-1]<<' ';
            cur--;
        }
        else
        {
            cout<<(a[cur-1]+a[cur-2])/2<<' ';
            cur-=2;
        }
    }
    return 0;
}
ll par[N][20],c[N],lv[N],best[N];
void dfs(ll u)
{
    lv[u]=lv[par[u][0]]+1;
    for(auto v:gr[u])
    {
        if(v==par[u][0]) continue;
        par[v][0]=u;
        dfs(v);
    }
}
ll lca(ll u,ll v)
{
    if(lv[u]<lv[v]) swap(u,v);
    for(int i=18; i>=0; i--)
    {
        if(lv[par[u][i]]>=lv[v]) u=par[u][i];
    }
    if(u==v) return u;
    for(int i=18; i>=0; i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
ll F;
ll dis(ll u,ll v)
{
    return lv[u]+lv[v]-2*lv[lca(u,v)];
}
ll getmid(ll u,ll v)
{
    if(lv[u]<lv[v]) swap(u,v);
    ll a=dis(u,v);
    if(a%2==1) return -1;
    ll up=a/2;
    for(int i=18; i>=0; i--)
    {
        if(up>=(1<<i))
        {
            u=par[u][i];
            up-=(1<<i);
        }
    }
    return u;
}
ll dp(ll mask)
{
    if(mask==F) return 0;
    if(f[mask]!=-1) return f[mask];
    f[mask]=1e18;
    ll rmask=F^mask;
    for(int nmask=rmask;nmask;nmask=(nmask-1)&rmask)
    {
        if(c[nmask]!=-1)
        {
            if(minimize(f[mask],1+dp(mask^nmask))) best[mask]=nmask;
        }
    }
    return f[mask];
}
bool sub2()
{
    F=(1<<k)-1;
    memset(f,-1,sizeof f);
    for(int i=1; i<=k; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+k+1);
    dfs(1);
    for(int i=1; i<=18; i++)
    {
        for(int j=1; j<=n; j++)
        {
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    for(int mask=1; mask<=F; mask++)
    {
        vector<ll> vt;
        for(int i=0; i<k; i++)
        {
            if(BIT(i,mask))
            {
                vt.push_back(a[i+1]);
            }
        }
        if(__builtin_popcount(mask)==1)
        {
            c[mask]=vt[0];
            continue;
        }
        ll z=vt[0];
        for(auto v:vt)
        {
            if(dis(v,vt[0])>dis(z,vt[0])) z=v;
        }
        ll nz=vt[0];
        for(auto v:vt)
        {
            if(dis(z,v)>dis(z,nz)) nz=v;
        }
        c[mask]=getmid(z,nz);
        if(c[mask]!=-1)
        {
            ll st=dis(z,c[mask]);
            for(int i=0;i<k;i++)
            {
                if(BIT(i,mask))
                {
                    if(dis(a[i+1],c[mask])!=st)
                    {
                        c[mask]=-1;
                        break;
                    }
                }
                else
                {
                    if(dis(a[i+1],c[mask])<st)
                    {
                        c[mask]=-1;
                    }
                }
            }
        }
//        cout<<c[mask]<<'\n';
    }
    cout<<dp(0)<<'\n';
    ll mask=0;
    // while(mask<F)
    // {
    //     cout<<c[best[mask]]<<' ';
    //     mask^=best[mask];
    // }
    return 0;
}
int main()
{
    online();
    cin>>n>>k;
    bool flag=0;
    for(int i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i=2; i<n; i++)
    {
        if(gr[i].size()!=2) flag=1;
    }
    if(gr[1].size()!=gr[n].size()||gr[1].size()!=1) flag=1;
    // if(!flag) return sub1();
    // return 
    sub2();
}