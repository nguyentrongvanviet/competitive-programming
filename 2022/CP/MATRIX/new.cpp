#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,l,r) for(ll i= l;i<=r;i++)
const ll N =2e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct range
{
    ll l, r ,i;
    bool operator<(range a )
    {
        return l>a.l;
    }
};
struct ra
{
    ll r ,i;
    bool operator<(ra a )
    {
        return r<a.r;
    }
};
ll bit[N],n ;
range a[N] ;
ra b[N] ;
ll pos[N]  ,res[N] ;
void up(ll idx,ll val )
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
ll get(ll idx)
{
    ll ans= 0 ;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ans ;
}
void inp()
{
    cin>> n ;
    for(ll i=1 ;i<=n;i++)
    {
        a[i].i=i;
        cin>>a[i].l>>a[i].r;
        b[i]={a[i].r,a[i].i};
    }
    sort(b+1,b+n+1);
    FOR(i,1,n)
    {
        pos[b[i].i]=i;
    }
    sort(a+1,a+n+1);
    FOR(i,1,n)
    {
        res[a[i].i] =get(pos[a[i].i]);
        up(pos[a[i].i],1);
    }
    FOR(i,1,n)
    {
        cout<<res[i]<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
