#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =2e3+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;


struct pt
{
    ll x,  y,t;
};
pt t ,s  ;
ll n ,  m ;
char a[N][N] ;
ll xx[4] ={0,0,1,-1} ;
ll yy[4]= {1,-1,0,0};
ll dd[N][N] , f[N][N];
ll in(ll x , ll y )
{
    return(1<=x&&x<=n&&1<=y&&y<=m);
}
void bfs()
{
    queue<pt>q;
    for(ll i= 1 ;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            if(a[i][j]=='+')
            {
                q.push({i,j,0});
                dd[i][j]=1;
            }
        }
    }
    while(!q.empty())
    {
        ll x= q.front().x;
        ll y =q.front().y;
        ll t = q.front().t;
        q.pop();
        for(ll i= 0 ;i<4;i++)
        {
            ll nx = x+xx[i] ;
            ll ny =y+yy[i] ;
            if(in(nx,ny)==0||dd[nx][ny]==1)continue ;
            dd[nx][ny]=1;
            f[nx][ny]=t+1;
            q.push({nx,ny,t+1});
        }
    }
}

ll check(ll val )
{
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            dd[i][j] = 0 ;
        }
    }
    queue<pt>q;
    q.push(s);
    dd[s.x][s.y]=1;
    while(!q.empty())
    {
        ll x =q.front().x;
        ll y =q.front().y;
        q.pop();
        for(ll i = 0 ;i<4;i++)
        {
            ll nx = x+xx[i] ;
            ll ny = y+yy[i] ;
            if(in(nx,ny)==0||dd[nx][ny]||f[nx][ny]<val)continue;
            dd[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    return (dd[t.x][t.y]);
}
void inp()
{
    cin>>n>>m ;
    for(ll i= 1;i<=n;i++)
    {
        for(ll j =1;j<=m;j++)
        {
            cin>>a[i][j] ;
            if(a[i][j]=='P')
            {
                s={i,j};
            }else if(a[i][j]=='C')
            {
                t={i,j};
            }
        }
    }
    bfs();
    ll l=0 ;
    ll r =min(f[s.x][s.y],f[t.x][t.y]);
    ll res=0;
    while(l<=r)
    {
        ll mid =(l+r)/2 ;
        if(check(mid))
        {
            res=mid ;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
