#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e3+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct bg
{
    ll su;
    ll mo;
};
ll l , r , m , k ;
bg pre[N][N];
ll ans[N][N];
ll bfs()
{
    memset(ans,-1,sizeof ans) ;
    queue<bg>q;
    for(ll i= 1;i<10;i++)
    {
        q.push({i,i%m});
        pre[i][i%m]={0,0};
        ans[i][i%m]=i;
    }
    while(!q.empty())
    {
        ll su = q.front().su;
        ll mo = q.front().mo ;
        q.pop();
//        cout<<su<<" ";
        if(l<=su&&su<=r&&mo==k) return su;
        if(su>r)continue ;
        for(ll i= 0  ;i<10;i++)
        {
            ll s=  su+i ;
            ll nmo = (mo*10+i)%m;
            if(ans[s][nmo]==-1)
            {
                pre[s][nmo] = {su,mo};
                ans[s][nmo]=i ;
                q.push({s,nmo});
            }
        }
    }
    return 0;
}
void inp()
{
    cin>>l>>r>>m>>k;
    if(l==0&&k==0)
    {
        cout<<0 ;
        return ;
    }
    ll x= bfs();
    if(x==0)
    {
        cout<<-1 ;
        return;
    }
    vector<ll>res;
    while(ans[x][k]!=-1)
    {
        res.pb(ans[x][k]);
        ll u =pre[x][k].su ;
        ll mo =pre[x][k].mo ;
        x= u ;
        k= mo ;
    }
    for(ll i = res.size()-1;i>=0;i--) cout<<res[i];
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    ll test ;
    cin>>test;
    while(test--)
    {
         inp() ;
         cout<<"\n";
    }
}
