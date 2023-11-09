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
struct bg 
{
    int l , r ; 
    bool operator<(bg x )
    {
        
        return r<x.r; 
    }
};
int n ; 
bg a[N] ;
ll ma[N]  , f[N] ; 
ll st[4*N] ; 
int tknp(int pos)
{
    int l = 1 ;
    int r = pos -1 ; 
    int ans=0 ;  
    while(l<=r)
    {
        int mid = (l+r)/2 ; 
        if(a[mid].r<a[pos].l)
        {
            ans=mid; 
            l=mid+1; 
        }
        else 
        {
            r=mid-1; 
        }
    }
    return ans ; 
}
void up(int id , int l , int r , int pos , int val )
{   
    if(l==r&&r==pos)
    {
        st[id]= val ;
        return ; 
    }
    if(r<pos||pos<l)return ; 
    int mid =(l+r)/2; 
    up(id*2,l,mid,pos,val); 
    up(id*2+1,mid+1,r,pos,val) ; 
    st[id] = max(st[id*2],st[id*2+1]) ;
}
ll get(int id , int l , int r , int t , int p )
{
    if(t<=l&&r<=p)return st[id]; 
    if(r<t||p<l)return -inf; 
    int mid =(l+r)/2; 
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)); 
}
void inp()
{
    cin>> n ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r; 
    }
    ma[0]=-inf; 
    sort(a+1,a+n+1) ;
    for(int i= 1 ;i<=n;i++)
    {
        f[i] = a[i].r-a[i].l ; 
        int pos = tknp(i) ;
        f[i]=max(f[i],ma[pos]+a[i].r-a[i].l);  
        f[i] = max(f[i],get(1,1,n,pos+1,i-1)+a[i].l+a[i].r); 
        up(1,1,n,i,f[i]-2*a[i].r);
        ma[i] =max(f[i],ma[i-1]) ; 
    } 
    ll res= -inf ; 
    for(int i= 1;i<=n;i++)
    {
        // cout<<f[i]<<" ";
        res=max(res,f[i]) ;
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