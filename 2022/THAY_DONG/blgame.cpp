#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , C = 330  , MOD = 1e9+7 ;

struct bg
{
    ll x , y , a , b , c ;
};
bg q[9000005];
ll xx[4]={0,0,1,-1};
ll yy[4]={1,-1,0,0};
ll a , b , c , m , n , k ;
ll res= 0 ;
ll f[4] ;
ll t[N][N];
ll dd[N][N][3][3];
ll s[N][N];
ll sum ;
ll in(ll x ,ll y)
{
    return (1<=x&&x<=n&&1<=y&&y<=m);
}
ll su(ll x , ll y , ll a , ll b )
{
    return s[x][y]-s[x-a][y]-s[x][y-b]+s[x-a][y-b];
}
void bfs()
{
    q[1]={a,b,0,1};
    ll d=1;
    ll cu= 1;
    dd[a][b][0][1]=1;
    while(d<=cu)
    {
        ll x= q[d].x;
        ll y =q[d].y;
        ll a = q[d].a;
        ll b= q[d].b;
        ll c= sum-a-b;
        d++;
        int u=x-f[a]+1;
        int v=y-f[b]+1;
        t[u][v]++;
        t[x+1][v]--;
        t[u][y+1]--;
        t[x+1][y+1]++;
        for(ll i= 0  ;i<4;i++)
        {
            ll nx =x+xx[i] ;
            ll ny =y+yy[i] ;
            if(in(nx,ny)==1&&in(nx-f[a]+1,ny-f[b]+1)==1&&dd[nx][ny][a][b]==0){
                if(su(nx,ny,f[a],f[b])==0)
                {
                    dd[nx][ny][a][b]=1;
                    q[++cu]={nx,ny,a,b};
                }
            }
        }
        ll nx , ny ,na ,nb , nc ;
        nx = x-f[a];
        ny = y;
        na = c;
        nb = b ;
        nc = a ;
        if(in(nx,ny)&&in(nx-f[na]+1,ny-f[nb]+1)&&dd[nx][ny][na][nb]==0)
        {
            if(su(nx,ny,f[na],f[nb])==0)
            {
                dd[nx][ny][na][nb]=1;
                q[++cu]={nx,ny,na,nb};
            }
        }
        nx = x ;
        ny = y-f[b];
        na = a;
        nb = c ;
        nc = b ;
        if(in(nx,ny)&&in(nx-f[na]+1,ny-f[nb]+1)&&dd[nx][ny][na][nb]==0)
        {
            if(su(nx,ny,f[na],f[nb])==0)
            {
                dd[nx][ny][na][nb]=1;
                q[++cu]={nx,ny,na,nb};
            }
        }
        nx = x ;
        ny = y+f[c];
        na = a;
        nb = c ;
        nc = b ;
        if(in(nx,ny)&&in(nx-f[na]+1,ny-f[nb]+1)&&dd[nx][ny][na][nb]==0)
        {
            if(su(nx,ny,f[na],f[nb])==0)
            {
                dd[nx][ny][na][nb]=1;
                q[++cu]={nx,ny,na,nb};
            }
        }
        nx = x+f[c] ;
        ny =  y;
        na = c;
        nb = b ;
        nc = a ;
        if(in(nx,ny)&&in(nx-f[na]+1,ny-f[nb]+1)&&dd[nx][ny][na][nb]==0)
        {
            if(su(nx,ny,f[na],f[nb])==0)
            {
                dd[nx][ny][na][nb]=1;
                q[++cu]={nx,ny,na,nb};
            }
        }
    }
}
void inp()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&n,&m,&k);
    f[0] =a;
    f[1] =b;
    f[2] =c;
    sum=3;
    for(ll i=1 ;i<=k;i++)
    {
        ll u , v ;
        scanf("%d%d",&u,&v);
        s[u][v]= 1;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j =1;j<=m;j++)
        {
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    bfs();
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
    {

        t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
        if(t[i][j]>0)res++;
    }
    printf("%d",res)
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
