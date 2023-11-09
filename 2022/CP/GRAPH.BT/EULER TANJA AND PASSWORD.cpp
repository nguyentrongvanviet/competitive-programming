#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n ;
ll node= 0;
map<string,ll>dd;
map<ll,string>a;
vector<ll>g[N];
ll in[N] , out[N] ;
void inp()
{
    cin>> n ;
    for(ll i=1 ;i<=n;i++)
    {
        string s;
        cin>>s;
        string u =  s.substr(0,2);
        string v= s.substr(1);
        cout<<u<<" " <<v;
        cout<<endl;
        if(dd[u]==0)
        {
            dd[u]=++node;
            a[node] = u;
        }
        if(dd[v]==0)
        {
            dd[v]=++node;
            a[node]=v ;
        }
        g[dd[u]].pb(dd[v]);
        in[dd[v]]++;
        out[dd[u]]++;
    }
    ll s= 0 ;
    ll t= 0 ;
    for(ll i= 1 ;i<=n;i++)
    {
        if(in[i]==out[i])continue ;
        if(in[i]+1==out[i])
        {
            if(s==0)s=i ;
            else
            {
                cout<<"NO" ;
                return ;
            }
        }else if(in[i]==out[i]+1)
        {
            if(t==0)
            {
                t=i;
            }else
            {
                cout<<"NO";
                return ;
            }
        }
    }
    cout<<"YES"<<"\n";
    ll q= 0 ;
    if(s==0&&t==0)
    {
        s=1 ;
        q=1 ;
    }
    if(t!=0)
    {
        g[t].pb(s);
    }
    stack<ll>st ;
    vector<ll>res;
    st.push(s);
    while(!st.empty())
    {
        ll u = st.top() ;
        ll d=0;
        while(!g[u].empty())
        {
            ll v=  g[u].back() ;
            g[u].pk();
            d=  1;
            st.push(v);
            break ;
        }
        if(d==0)
        {
            res.pb(u);
            st.pop() ;
        }
    }
    cout<<s<<" " <<t <<endl;
    cout<<node<<endl;
    if(q==1)
    {
        for(ll i =0;i<res.size();i++)
        {
            cout<<a[res[i]]<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
