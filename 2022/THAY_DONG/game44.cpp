#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,l,r) for(ll i =l;i<=r;i++)
const ll N =5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;


vector<vector<ll>>a(5,vector<ll>(5)) ;
map<vector<vector<ll>>,ll>dd;
map<vector<vector<ll>>,ll>dd2;
vector<vector<ll>>ans;
vector<ll>xx{0,0,1,-1} ;
vector<ll>yy{1,-1,0,0} ;
vector<vector<ll>>st ;
vector<vector<ll>>en ;
ll res;
ll n = 4;
ll in(ll x , ll y)
{
    return (1<=x&&x<=4&&1<=y&&y<=4);
}
void bfs1()
{
    queue<vector<vector<ll>>>q;
    q.push(a);
    dd[a]=0 ;
    while(!q.empty())
    {
        vector<vector<ll>> u =q.front();
        q.pop();
        ll t= dd[u];
        if(t==13)continue;
        ll ok =0 ;
        for(ll i= 1;i<=4&&ok==0;i++)
        {
            for(ll j= 1;j<=4&&ok==0;j++)
            {
                if(u[i][j]==0)
                {
                    ok = 1;
                    for(ll id = 0 ;id<4;id++)
                    {
                        ll nx = i+xx[id] ;
                        ll ny = j+yy[id];
                        if(in(nx,ny)==0)continue;
                        swap(u[i][j],u[nx][ny]);
                        if(dd.count(u)==0)
                        {
                            q.push(u);
                            dd[u]=t+1;
                        }
                        swap(u[i][j],u[nx][ny]);
                    }
                }
            }
        }
    }
}
void bfs2()
{
    queue<vector<vector<ll>>>q;
    q.push(a);
    dd2[a]=0;
    while(!q.empty())
    {
        vector<vector<ll>> u =q.front();
        q.pop();
        ll t= dd2[u];
        if(dd[u]!=0)
        {
            if(res>dd[u]+dd2[u])
            {
                res=  dd[u]+dd2[u] ;
                ans =  u ;
            }
        }
        if(t==13)continue;
        ll ok =0 ;
        for(ll i= 1;i<=4&&ok==0;i++)
        {
            for(ll j= 1;j<=4&&ok==0;j++)
            {
                if(u[i][j]==0)
                {
                    ok = 1;
                    for(ll id = 0 ;id<4;id++)
                    {
                        ll nx = i+xx[id] ;
                        ll ny = j+yy[id];
                        if(in(nx,ny)==0)continue;
                        swap(u[i][j],u[nx][ny]);
                        if(dd2.count(u)==0)
                        {
                            q.push(u);
                            dd2[u]=t+1;
                        }
                        swap(u[i][j],u[nx][ny]);
                    }
                }
            }
        }
    }
}
void trace()
{
    vector<ll>out ;
    vector<vector<ll>>u = ans  ;
    while(dd[u]>0)
    {
        ll t=  dd[u] ;
        ll ok = 0 ;
        for(ll i= 1;i<=4&&!ok;i++)
        {
            for(ll j= 1;j<=4&&!ok;j++)
            {
                if(u[i][j]==0)
                {
                    ok =1;
                    for(ll id =0 ;id<4;id++)
                    {
                        ll nx = i+xx[id] ;
                        ll ny = j+yy[id] ;
                        if(in(nx,ny))
                        {
                            swap(u[i][j] ,u[nx][ny]);
                            if(dd[u]==t-1)
                            {
                                out.pb(u[i][j]);
                                break ;
                            }
                            swap(u[i][j],u[nx][ny]);
                        }
                    }
                }
            }
        }
    }
    reverse(out.begin(),out.end());
    u= ans ;
    while(dd2[u]>0)
    {
        ll t =dd2[u] ;
        ll ok = 0;
        for(ll i= 1;i<=4&&!ok;i++)
        {
            for(ll j= 1;j<=4&&!ok;j++)
            {
                if(u[i][j]==0)
                {
                    ok =1;
                    for(ll id =0 ;id<4;id++)
                    {
                        ll nx = i+xx[id] ;
                        ll ny = j+yy[id] ;
                        if(in(nx,ny))
                        {
                            swap(u[i][j] ,u[nx][ny]);
                            if(dd2[u]==t-1)
                            {
                                out.pb(u[i][j]);
                                break ;
                            }
                            swap(u[i][j],u[nx][ny]);
                        }
                    }
                }
            }
        }
    }
    cout<<out.size()<<"\n";
    for(auto v : out ) cout<<v<<" " ;
}
void inp()
{
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            cin>>a[i][j];
        }
    }
    bfs1();
    ll tt =0  ;
    for(ll i =1;i<=4;i++)
    {
        for(ll j= 1;j<=4;j++)
        {
            a[i][j]=++tt;
        }
    }
    a[4][4]= 0 ;
    res=INF;
    bfs2();
    trace();
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
    return 0 ;
}
