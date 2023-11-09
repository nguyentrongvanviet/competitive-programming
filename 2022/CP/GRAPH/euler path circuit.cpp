#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct ke
{
    ll v ;
    ll id ;
};
ll n , m ;
ll in[N], out[N];
vector<ke>g[N] ;
ll dd[N] ;
ll check()
{
    for(ll i =2;i<=n-1;i++)
    {
        if(in[i]!=out[i]) return 0 ;
    }
    if(out[1]-in[1]!=1) return 0 ;
    if(in[n]-out[n]!=1) return 0 ;
    return 1;
}
map<pii,vi>sl; 
void inp()
{
    cin>> n>>  m;
    for(ll i= 1 ;i<=m;i++)
    {
        ll u , v ;
        cin>>u>>v ;
        g[u].pb({v,i});
        sl[mp(u,v)].pb(i) ; 
        out[u]++ ;
        in[v]++;
    }
    if(!check())
    {
        cout<<"IMPOSSIBLE";
        return ;
    }
    g[n].pb({1,m+1}) ;
    vector<ll>ans;
    stack<ll> st;
    st.push(1) ;
    while(!st.empty())
    {
        ll u = st.top();
        ll f= 0 ;
        while(!g[u].empty())
        {
            ll v =g[u].back().v ;
            ll id = g[u].back().id ;
            g[u].pk();
            if(dd[id]==1)continue ;
            st.push(v);
            dd[id]=1;
            f=1 ;
            break;
        }
        if(f==0)ans.pb(u),st.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()!=m+2)
    {
        cout<<"IMPOSSIBLE";
        return ;
    }
//    for(ll i=  0 ;i<ans.size();i++) cout<<ans[i]<<" ";
//    cout<<endl;
    for(ll i =0  ;i<ans.size();i++)
    {
        ll u = ans[i];
        ll v =ans[i+1] ;
        if(u==n&&v==1)
        {
            for(ll j = i+1;j<ans.size()-1;j++)
            {
                cout<<ans[j]<<" ";
            }
            for(ll j= 0 ; j<=i;j++)
            {
                cout<<ans[j]<< " ";
            }
            break ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
