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
#define TASK "text" 
int n ; 
vector<int>g[N ];
int a[N] ;  
int st1[8*N] ; 
int st2[8*N]; 
int at[N] ;
int pos[N] , h[N]  , l[N],r[N] ;
int lazy1[8*N],lazy2[8*N] ;
void build(int id , int l  ,int r , int st[])
{
    if(l==r)
    {
        st[id]= a[at[l]];
        return ; 
    }
    int mid=(l+r)/2 ; 
    build(id*2,l,mid,st); 
    build(id*2+1,mid+1,r,st); 
}
void dolazy(int id,int st[],int lazy[] )
{
    st[id]+=lazy[id] ; 
    lazy[id*2]+=lazy[id] ; 
    lazy[id*2+1]+=lazy[id]; 
    lazy[id]= 0 ; 
}
void up(int id ,int l  , int r , int t , int p ,int val ,int st[],int lazy[])
{
    dolazy(id,st,lazy) ; 
    if(t<=l&&r<=p)
    {
        st[id]+= val ; 
        lazy[id*2]+=val ; 
        lazy[id*2+1]+=val ; 
        return ; 
    }
    if(r<t||p<l)return ;  
    int mid=(l+r)/2; 
    up(id*2,l,mid,t,p,val,st,lazy) ; 
    up(id*2+1,mid+1,r,t,p,val,st,lazy) ; 
}
int get(int id , int l , int r , int pos  ,int st[],int lazy[])  
{
    dolazy(id,st,lazy) ; 
    if(l==r&&l==pos)
    {
        return st[id] ; 
    }
    int mid=(l+r)/2;
    if(mid>=pos)
    {
        return get(id*2,l,mid,pos,st,lazy) ; 
    }
    return get(id*2+1,mid+1,r,pos,st,lazy) ; 
}
int tt= 0 ; 
void dfs(int u ,int p )
{
    l[u]=++tt;
    at[tt] = u ;  
    pos[u]=l[u]; 
    for(int i= 0  ;i<g[u].size();i++)
    {   
        int v =g[u][i];  
        if(v==p)continue ;
        h[v]=h[u]+1; 
        dfs(v,u); 
    }
    r[u]=tt; 
}
void inp()
{
    int q;  
    cin>> n>> q;  
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int i=1 ;i<=n-1;i++)
    {
        int u , v; 
        cin>>u>>v; 
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }
    h[1]=1; 
    dfs(1,0); 
    // for(int i= 1;i<=n;i++)
    // {
    //     int u = i ; 
    //     cout<<l[u]<<" "<<r[u]<<endl; 
    //     cout<<at[u]<<endl; 
    // }
    build(1,1,n,st1);
    build(1,1,n,st2); 
    // up(1,1,n,l[2],r[2],3,st2,lazy2);
    // cout<<get(1,1,n,pos[2],st2,lazy2);
    while(q--)
    {
        int u ;
        int t; 
        cin>>t>> u;  
        if(t==2)
        {
            if(h[u]%2==1)
            {
                cout<<get(1,1,n,pos[u],st1,lazy1) ; 
            }
            else 
            {
                cout<<get(1,1,n,pos[u],st2,lazy2) ; 
            }
            cout<<"\n";
        }
        else 
        {
            int val ; 
            cin>>val ; 
            if(h[u]%2==1)
            {
                up(1,1,n,l[u],r[u],val,st1,lazy1) ; 
                up(1,1,n,l[u],r[u],-val,st2,lazy2) ;
            }
            else 
            {
                up(1,1,n,l[u],r[u],val,st2,lazy2) ; 
                up(1,1,n,l[u],r[u],-val,st1,lazy1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen(TASK".INP","r",stdin); 
    freopen(TASK".OUT","w",stdout); 
    inp();
    return 0;
}