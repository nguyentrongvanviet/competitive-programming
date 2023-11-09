#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
#define pll pair<ll,ll> 
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
bool cmp(pii a , pii b )
{
    return a.X<b.X||(a.X==b.X&&(a.Y<b.Y)); 
}
struct bg 
{
    ll x , val , le ; 
};
bg a[N] ; 
int n ; 
ll pos[N];
ll f[N] ;  
ll sl[N] ; 
ll sg[N] ;
pll v[N];
ll st[4*N];   
ll ma[N] ;
void build(int id , int l , int r )
{
    st[id]= inf ; 
    if(l==r)
    {
        return ; 
    }
    int mid=(l+r)/2 ; 
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r);
}
void up(int id , int l , int r,  ll pos , ll val)
{
    if(l==r&&r==pos)
    {
        st[id] =val; 
        return ; 
    }
    if(r<pos||pos<l)return ; 
    int mid =(l+r)/2 ; 
    up(id*2,l,mid,pos,val) ; 
    up(id*2+1,mid+1,r,pos,val) ; 
    st[id]=min(st[id*2],st[id*2+1]) ; 
}
ll get(int id , int l , int r , int t , int p )
{
    if(t<=l&&r<=p)return st[id] ; 
    if(r<t||p<l)return inf; 
    int mid =(l+r)/2 ; 
    return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void inp()
{
    cin>> n ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].x>>a[i].val>>a[i].le;  
        sg[i]=sg[i-1]+a[i].val; 
        sl[i]=sl[i-1]+a[i].le;
        v[i]={sl[i-1]-a[i].x,i};
    }
    build(1,1,n);  
    ma[0]=-inf;   
    sort(v+1,v+n+1,cmp) ;
    for(int i= 1 ;i<=n;i++)
    {
        pos[v[i].Y]=i ; 
    }
    // s[i]-s[j-1]>=(a[j].pos-a[i].pos)
    ll res= 0 ;
    for(int i=1;i<=n;i++)
    {
        int l = 1 ; 
        int r = n ; 
        int ans = 0 ;
        while(l<=r)
        {
            int mid=(l+r)/2; 
            if(v[mid].X<=sl[i]-a[i].x)
            {
                ans =mid ; 
                l=mid+1; 
            }
            else 
            {   
                r=mid-1; 
            }
        }
        up(1,1,n,pos[i],sg[i-1]); 
        f[i] =get(1,1,n,1,ans);
        res=max(res,sg[i]-f[i]);
        // cout<<sg[i]-f[i]<<endl;
    }
    cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}