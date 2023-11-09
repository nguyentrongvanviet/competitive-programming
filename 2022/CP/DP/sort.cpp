#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n ;
ll a[N] , b[N];
ll st[4*N];
void build(ll id=  1 , ll l =1 ,ll r=  n)
{
    if(l==r)
    {
        st[id]= a[l];
        return ;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid) ;
    build(id*2+1, mid+1, r );
    st[id]=min(st[id*2],st[id*2+1]);
}
ll get(ll id , ll l  , ll r ,ll val   )
{
    if(l==r)
    {
        return l;
    }
    ll mid= (l+r)/2;
    if(st[id*2]<=val)
    {
        return get(id*2,l,mid,val);
    }
    return get(id*2+1,mid+1,r,val);
}
void update(ll id, ll l , ll r  , ll pos , ll val )
{
    if(l==r&&r==pos)
    {
        st[id]= val ;
        return ;
    }
    if(r<pos||pos<l) return  ;
    ll mid =(l+r)/2 ;
    update(id*2,l,mid,pos,val) ;
    update(id*2+1,mid+1,r,pos,val) ;
    st[id]=min(st[id*2],st[id*2+1]);
}
void inp()
{
    cin>> n ;
    for(ll i =1 ;i<=n;i++)cin>>a[i];
    build();
    for(ll i =1 ;i<=n;i++)cin>>b[i] ;
    for(ll i= 1;i<=n;i++)
    {
        ll u = get(1,1,n,b[i]);
        if(a[u]!=b[i])
        {
            cout<<"NO";
            return ;
        }
        update(1,1,n,u,INF);
    }
    cout<<"YES";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test;
    while(test--)
    {
        inp();
        cout<<"\n";
    }
}
