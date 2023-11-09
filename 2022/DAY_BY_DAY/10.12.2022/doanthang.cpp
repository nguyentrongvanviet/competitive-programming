#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct range
{
    int l , r , id ; 
    bool operator<(const range& a )const
    {
        return r<a.r||(r==a.r&&l>a.l); 
    }
};
bool cmp1(range a , range b )
{
    return a.l<b.l; 
}
int n ; 
int st[4*N] ; 
int pos[N ] ; 
range a[N] , b[N];
int f[N];
void up(int id , int l ,int r ,int pos , int val)
{
    if(l==r&&r==pos)
    {
        st[id] = val ; 
        return ; 
    }
    if(r<pos||pos<l)return ; 
    int mid=(l+r)>>1; 
    up(id*2,l,mid,pos,val) ; 
    up(id*2+1,mid+1,r,pos,val) ; 
    st[id]=max(st[id*2],st[id*2+1]) ;
}
int get (int id , int l, int r , int t, int p )
{
    if(t<=l&&r<=p)return st[id]; 
    if(r<t||p<l)return 0 ; 
    int mid=(l+r)>>1; 
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void input()
{
    cin>> n;  
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r; 
        a[i].id= i ; 
    }
}
int np1(int val   )
{
    int l =1 ; 
    int r =n ; 
    int ans =-1; 
    while(l<=r)
    {
        int mid=(l+r)>>1; 
        if(b[mid].l>=val)
        {
            ans=mid;  
            r=mid-1 ; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans;  
}
void output()
{
    sort(a+1,a+n+1);
    for(int i= 1; i<=n;i++)
    {
        b[i] = a[i] ; 
    } 
    sort(b+1,b+n+1,cmp1) ; 
    for(int i= 1; i<=n;i++)
    {
        pos[b[i].id] = i; 
    }
    int res= 1 ; 
    for(int i= 1;i<=n;i++)
    {
        int u = np1(a[i].l) ;
        f[i] = get(1,1,n,u,n)+1; 
        res=max(res,f[i]) ; 
        up(1,1,n,pos[a[i].id],f[i]) ; 
    }
    cout<<res; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}