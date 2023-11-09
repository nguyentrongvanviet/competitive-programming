#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =5e3+5 , INF =1e9, C= 330  , MOD = 1e9+7 ;


ll n , m ;
ll a[N],b[N],pos[N] ,c[N];
ll f[N][N];
ll st[4*N];
bool cmp(ll i , ll j )
{
    return b[i]<b[j]||(b[i]==b[j]&&i<j);
}
void up(ll idx , ll val )
{
    while(idx<=n)
    {
        bit[idx]=val;
    }
}
ll get(ll idx )
{
    ll ans=0 ;
    while(idx>=0)
    {
        ans =max(ans,);
    }
}
void inp()
{
    cin>>n>> m;
    for(ll i= 1;i<=n;i++)cin>>a[i];
    for(ll i =1 ;i<=m;i++)cin>>b[i],c[i]=i;
    sort(c+1,c+m+1,cmp);
    pos[c[1]]=1;
    for(ll i=2;i<=m;i++)
    {
        if(b[c[i]]==b[c[i-1]])
        {
            pos[c[i]]=pos[c[i-1]];
        }else
        {
            pos[c[i]]=i;
        }
    }
    for(ll i =1 ;i<=n;i++)
    {
        for(ll i=1 ;i<=4*m;i++)
        {
            st[i]= 0;
        }
        for(ll j =1 ;j<=m;j++)
        {
            if(a[i]!=b[j])
            {
                f[i][j] = f[i-1][j];
            }else
            {
                if(pos[j]-1==0)
                {
                    f[i][j]=1;
                }else f[i][j] = get(1,1,m,1,pos[j]-1) + 1 ;
            }
            up(1,1,m,pos[j],f[i-1][j]);
        }
    }
    ll res = 0 ;
    for(ll i= 1;i<=m;i++)
    {
        res=max(res,f[n][i]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
