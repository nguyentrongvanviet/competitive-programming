#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

struct pt
{
    ll x , y ;
};
 ll a,b,x , y , u, v ;
ll n , m ;
ll s[N][N] ;
ll dd[N][N];
ll f[N][N] ;
ll ok[N][N];
vector<ll>xx{0,0,1,-1} ;
vector<ll>yy{1,-1,0,0} ;
ll check(ll u , ll v )
{
    return (1<=u&&u<=n&1<=v&&v<=m);

}
void bfs()
{
    queue<pt> q ;
    q.push({x,y});
    dd[x][y] =1 ;
    f[x][y] = 0;
    while(!q.empty())
    {
        ll x= q.front().x;
        ll y = q.front().y ;
//        cout<<x<<" " <<y<<endl;
        q.pop();
        for(ll i= 0  ;i<4;i++)
        {
            ll nx = x+xx[i];
            ll ny = y+yy[i];
            if(check(nx,ny)&&check(nx+a-1,ny+b-1)&&dd[nx][ny]==0&&ok[nx][ny]==1)
            {
                dd[nx][ny]=1 ;
                f[nx][ny] =f[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
void inp()
{
    cin>>n>> m;
     cin>>a>>b>>x>>y>>u>>v;
    for(ll i=1;i<=n;i++)
    {
        for(ll j =1;j<=m;j++)
        {
            cin>>s[i][j];
            s[i][j] =s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    for(ll i =1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            if(check(i+a-1,j+b-1)&&s[i+a-1][j+b-1]-s[i-1][j+b-1]-s[i+a-1][j-1]+s[i-1][j-1]==0)ok[i][j] = 1;
            else ok[i][j] = 0 ;
//            cout<<ok[i][j]<< " ";
        }
    }
    bfs();
    if(dd[u][v]==0)
    {
        cout<<-1 ;
    }else
    {
        cout<<f[u][v];
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
