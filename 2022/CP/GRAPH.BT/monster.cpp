#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct pt
{
    ll x, y;
};
ll n , m;
char a[N][N] ;
ll dd[N][N] ;
ll f[N][N];
ll dis[2][N][N];
vector<pt> ms;
vector<pt> pos;
vector<ll>xx={0,1,-1,0} ;
vector<ll>yy={1,0,0,-1} ;
void bfs(vector<pt>p,ll t )
{
    queue<pt>q ;
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            f[i][j] =INF;
            dd[i][j]= 0;
        }
    }
    memset(dd,0,sizeof(dd));
    for(auto v : p )
    {
        q.push({v});
        dd[v.x][v.y]= 1 ;
        f[v.x][v.y]=0;
    }
    while(!q.empty())
    {
        ll x= q.front().x;
        ll y =q.front().y;
        q.pop();
        for(ll i= 0 ;i<4;i++)
        {
            ll nx= x+xx[i] ;
            ll ny =y+yy[i] ;
            if(dd[nx][ny]==0&&(a[nx][ny]=='.'||a[nx][ny]=='M'||a[nx][ny]=='A'))
            {
                dd[nx][ny]=1;
                f[nx][ny]=f[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            dis[t][i][j]=f[i][j];
        }
    }
}
void inp()
{
    cin>> n>> m;
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            cin>>a[i][j] ;
            if(a[i][j]=='A')
            {
                pos.pb({i,j});
            }
            if(a[i][j]=='M')
            {
                ms.pb({i,j});
            }
        }
    }
    bfs(ms,0);
    bfs(pos,1);
    ll u= 0 , v =0 ;
    ll ok = 0 ;
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1 ;j<=m;j++)
        {
            if(i!=1&&i!=n&&j!=1&&j!=m)continue ;
            if(dis[1][i][j]<dis[0][i][j])
            {
                cout<<"YES"<<"\n";
//                cout<<i<<" "<<j<<endl;
                cout<<dis[1][i][j];
                u= i ;
                v =j ;
                ok =1 ;
                break ;
            }
        }
        if(ok==1)break ;
    }
    cout<<"\n";
    if(ok==0){
        cout<<"NO";
        return ;
    }
    vector<char>res;
    ll ans= dis[1][u][v];
    while(a[u][v]!='A')
    {
        for(ll i = 0 ;i<4;i++)
        {
            ll nx = u+xx[i];
            ll ny = v+yy[i];
            if((a[nx][ny]=='.'||a[nx][ny]=='A')&&dis[1][nx][ny]==ans-1)
            {
                ans-- ;
                u=nx ;
                v=ny ;
                if(i==0)res.pb('L');
                if(i==1)res.pb('U');
                if(i==2)res.pb('D');
                if(i==3)res.pb('R');
            }
        }
    }
    reverse(res.begin(),res.end());
    for(auto v : res) cout<<v;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
