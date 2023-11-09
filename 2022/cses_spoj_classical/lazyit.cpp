#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll a[N] , st[8*N] ;
ll lazy[8*N] ; 
ll n  , q; 
void dolazy(int id )
{
    st[id]+=lazy[id] ; 
    lazy[id*2]+=lazy[id]; 
    lazy[id*2+1]+=lazy[id] ; 
    lazy[id]= 0 ; 
}
void build(int id , int l , int r)
{
    if(l==r)
    {
        st[id] = a[l] ;
        return ; 
    }
    int mid=(l+r)>>1; 
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r) ; 
    st[id]=max(st[id*2],st[id*2+1]); 
}
void up(int id , int l ,int r , int t ,int p ,ll val)
{
    dolazy(id);  
    if(t<=l&&r<=p)
    {
        st[id]+=val; 
        lazy[id*2]+=val; 
        lazy[id*2+1]+=val; 
        return ; 
    }
    if(r<t||p<l)return ; 
    int mid =(l+r)>>1; 
    up(id*2,l,mid,t,p,val) ;
    up(id*2+1,mid+1,r,p,val) ; 
    st[id]=max(st[id*2],st[id*2+1]) ; 
}
ll get(int id , int l ,int r , int t, int p )
{
    dolazy(id) ; 
    if(t<=l&&r<=p)return st[id]; 
    if(r<t||p<l)return -inf ; 
    int mid =(l+r)>>1; 
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));  
}
void inp()
{
    cin>> n;  
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }   
    build(1,1,n) ; 
    cin>>q ; 
    while(q--)
    {
        int t;  
        int l ,r ;
        ll val ;
        cin>> t; 
        if(t==1)
        {
            cin>>l>>r>>val; 
            up(1,1,n,l,r,val) ;
        }
        else 
        {
            cin>>l>>r ;
            cout<<get(1,1,n,l,r)<<"\n";
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}