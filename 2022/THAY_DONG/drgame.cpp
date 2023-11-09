#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =1e3+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

ll n , m ;
vector<ll>adj[N] ;
vector<ll>tmp ;
ll b[N];
ll dd[N];
vector<vector<ll>>tp;
ll fake[N][N];
ll c[N][N];
vector<ll>ans;
void dfs(ll u )
{
    tmp.pb(u);
    dd[u]=1;
    for(auto v :adj[u])
    {
        if(dd[v])continue ;
        dfs(v);
    }
}
void dfs2(ll u )
{
    for(auto v : adj[u])
    {
        if(c[u][v]>=1)
        {
            c[u][v]--;
            c[v][u]--;
            dfs2(v);
//            ans.pb(v);
        }
    }
    ans.pb(u);
}
void inp()
{
    cin>> n >> m ;
    for(ll i=1;i<=m;i++)
    {
        ll u , v  ;
        cin>>u>>v;
        b[v]++ ;
        b[u]++;
        c[u][v]++ ;
        c[v][u]++;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    ll res= 0 ;
    for(ll i =1 ;i<=n;i++)
    {
        if(dd[i]==0)
        {
            tmp.clear();
            dfs(i);
            ll sl = 0 ;
            for(auto u : tmp)
            {
                sl+=(b[u]&1);
            }
            if(sl==0)
            {
                res+=1;
            }
            else
            {
                res+=sl/2;
            }
            tp.pb(tmp);
        }
    }
    cout<<res<<"\n";
    for(auto tmp :tp)
    {
        vector<ll>le;
        for(auto  u : tmp)
        {
            if(b[u]&1)
            {
                le.pb(u);
            }
        }
        if(le.size()>2)
        {
            for(ll i= 2;i<le.size()-1;i+=2)
            {
                adj[le[i]].pb(le[i+1]);
                adj[le[i+1]].pb(le[i]);
                c[le[i]][le[i+1]]++;
                c[le[i+1]][le[i]]++;
                fake[le[i]][le[i+1]]=1;
                fake[le[i+1]][le[i]]=1;
            }
        }
        dfs2(le[0]);
        reverse(ans.begin(),ans.end());
        vector<ll>out;
        for(ll i =0;i<ans.size();i++)
        {
            out.pb(ans[i]);
            if(fake[ans[i]][ans[i+1]]==1)
            {
                fake[ans[i]][ans[i+1]]--;
                fake[ans[i+1]][ans[i]]--;
                cout<<out.size()<<" ";
                for(auto v : out)
                {
                    cout<<v<<" ";
                }cout<<"\n";
                out.clear();
            }
        }
        cout<<out.size()<<" " ;
        for(auto v :out)
        {
            cout<<v<<" ";
        }
        ans.clear();
    }

}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
