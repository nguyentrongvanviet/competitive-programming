#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

//const ll N =1e5+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;
const double pi = acos(-1);
double s1 = pi*(0.5*0.5);
double s2=  (1 - s1)*0.25;
ll dd [505][505][6] ;
ll n ;
ll a[501][501];
ll in(ll x , ll y )
{
    return(0<=x&&x<=102&&0<=y&&y<=102);
}
void dfs(ll x , ll y ,ll t )
{
//    cout<<x<<" "<<y<<" "<<t<<endl;
    dd[x][y][t]=1;
    if(t==0)
    {
        for(ll i =1;i<=4;i++)
        {
            if(dd[x][y][i]==0)
            {
                dfs(x,y,i);
            }
        }
    }else if(t==1)
    {
        if(dd[x][y][0]==0&&a[x][y]!=1)dfs(x,y,0);
        if(in(x-1,y))
        {
            if(dd[x-1][y][4]==0)
            {
                dfs(x-1,y,4);
            }
        }
        if(in(x,y-1))
        {
            if(dd[x][y-1][2]==0)
            {
                dfs(x,y-1,2);
            }
        }
    }else if(t==2)
    {
        if(dd[x][y][0]==0&&a[x][y]!=1)dfs(x,y,0);
        if(in(x-1,y))
        {
            if(dd[x-1][y][3]==0)
            {
                dfs(x-1,y,3);
            }
        }
        if(in(x,y+1))
        {
            if(dd[x][y+1][1]==0)
            {
                dfs(x,y+1,1);
            }
        }

    }else if(t==3)
    {
        if(dd[x][y][0]==0&&a[x][y]!=1)dfs(x,y,0);
        if(in(x+1,y))
        {
            if(dd[x+1][y][2]==0)
            {
                dfs(x+1,y,2);
            }
        }
        if(in(x,y+1))
        {
            if(dd[x][y+1][4]==0)
            {
                dfs(x,y+1,4);
            }
        }
    }else if(t==4)
    {
        if(dd[x][y][0]==0&&a[x][y]!=1)dfs(x,y,0);
        if(in(x+1,y))
        {
            if(dd[x+1][y][1]==0)
                dfs(x+1,y,1);
        }
        if(in(x,y-1))
        {
            if(dd[x][y-1][3]==0)
            {
                dfs(x,y-1,3);
            }
        }
    }
    return ;
}
void inp()
{
    cin>> n ;
    for(ll i=1 ;i<=n;i++)
    {
        ll u , v   ;
        cin>>u>>v ;
        a[u][v]=1 ;
    }
    dfs(0,0,0);
    double res= 90*90;
    for(ll i = 0 ; i<=101;i++)
    {
        for(ll j =0;j<=101;j++)
        {
            if(dd[i][j][0]==1)
            {
                res-=s1 ;
            }
            for(ll t = 1 ;t<=4;t++)
            {
                if(dd[i][j][t]==1)res-=s2;
            }
        }
    }
    res-=n*s1;
    cout<<fixed;
    cout<<setprecision(5)<<abs(res);

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
