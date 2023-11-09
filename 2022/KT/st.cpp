#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
int n ,q; 
int a[N] ; 
int st[4*N] ; 
void build(int id , int l , int r )
{
    if(l==r)
    {
        st[id] = a[l]  ; 
        return ; 
    }
    int mid =(l+r)/2; 
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r) ; 
    st[id]=st[id*2]+st[id*2+1] ; 
}
void up(int id , int l , int r , int pos , int val)
{
    if(l==r&&r==pos)
    {
        st[id]+=val;  
        return ; 
    }
    if(r<pos||pos<l)return ; 
    int mid =(l+r)/2; 
    up(id*2,l,mid,pos,val); 
    up(id*2+1,mid+1,r,pos,val) ; 
    st[id]=st[id*2]+st[id*2+1] ; 
}
int get (int id,  int l , int r , int t, int p )
{
    if(t<=l&&r<=p)return st[id] ; 
    if(r<t||p<l)return 0 ; 
    int mid =(l+r)/2 ; 
    return get(id*2,l,mid,t,p)+get(id*2+1,mid+1,r,t,p) ; 
}
void inp()
{
    cin>> n>> q; 
    for(int i=1 ;i<=n;i++) cin>>a[i] ; 
    build(1,1,n) ; 
    while(q--)
    {
        int t ; 
        cin>>t ; 
        if(t==0)
        {
            int pos ,val ; 
            cin>>pos>>val ; 
            ++pos;
            up(1,1,n,pos,val) ; 
        }
        else 
        {
            int l ,  r  ; 
            cin>>l>>r  ; 
            l++;

            cout<<get(1,1,n,l,r)<<"\n"; 
        }
    }
}

signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}