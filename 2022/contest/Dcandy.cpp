#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e4+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m; 
int a[N] ;  
int dd[N] ; 
int f[N][55] ;  
int st[8*N] ; 
int lazy[8*N] ; 
void dolazy(int id )
{
    st[id]+=lazy[id] ;
    lazy[id*2]+=lazy[id] ; 
    lazy[id*2+1]+=lazy[id] ; 
    lazy[id]= 0 ; 
}
int get(int id , int l , int r,int t ,int p  )
{
    dolazy(id) ; 
    if(t<=l&&r<=p)
    {
        return st[id] ; 
    }
    if(r<t||p<l) return -oo; 
    int mid =(l+r)/2; 
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void up(int id,  int l , int r,int t , int p,int val )
{
    dolazy(id) ;
    if(t<=l&&r<=p)
    {
        st[id]+=val ;
        lazy[id*2]+=val ;
        lazy[id*2+1]+=val;
        return ;  
    }
    if(r<t||p<l)return ; w
    int mid=(l+r)/2 ;
    up(id*2,l,mid,t,p,val) ; 
    up(id*2+1,mid+1,r,t,p,val); 
    st[id]=max(st[id*2],st[id*2+1]) ; 
}
void build(int id , int l , int r ,int t )
{
    lazy[id]= 0 ;
    if(l==r)
    {
        st[id] = f[l][t]; 
        return ; 
    }
    int mid=(l+r)/2; 
    build(id*2,l,mid,t) ;
    build(id*2+1,mid+1,r,t) ; 
    st[id]=max(st[id*2],st[id*2+1]) ;
}
void inp()
{
    cin>> n>> m; 
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }   
    vector<int>exist(n+5,0) ; 
    int tmp  =0  ;
    for(int i= 1 ;i<=n;i++)
    {
        if(exist[a[i]]==0)
        {
            exist[a[i]]=1; 
            tmp++ ; 
        }
        f[i][1] = tmp ; 
    }
    for(int j =2;j<=m;j++)
    {
        for(int i=1;i<=n;i++)dd[i]=0  ;
        build(1,1,n,j-1);
        for(int  i=1;i<=n;i++)
        {
            int u  =dd[a[i]];
            dd[a[i]] = i; 
            if(u==0)up(1,1,n,1,i-1,1) ;
            else up(1,1,n,u,i-1,1); 
            f[i][j] = get(1,1,n,1,i-1);
        }
    }
    cout<<f[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}