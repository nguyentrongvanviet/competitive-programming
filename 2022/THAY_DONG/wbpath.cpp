#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e2+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

ll  n , m ;
char a[N][N] ;
ll f[N][N][N];
void bfs(ll x , ll y , ll u  , ll v )
{
    memset(f,0,sizeof(f));
    memset(dd,0,sizeof(dd));
    q.push({x,y,a[x][y]=='W'? 1 : -1});
}
void inp()
{
    cin>>n>> m;
    for(ll i= 1;i<=n;i++)
    {
        for(ll j= 1;j<=m;j++)
        {
            cin>>a[i][j] ;
        }
    }
    ll q;
    cin>> q;
    while(q--)
    {
        ll u , v, x, y ;
        cin>>x>>y>>u>>v;
        bfs(x,y,u,v);
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
