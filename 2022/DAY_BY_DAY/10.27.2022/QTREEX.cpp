#include<bits/stdc++.h>
using namespace std;

#define TASK "QTREEX"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
const int LO =18;
int n ; 
vector<int>g[N];
map<int,int>canh[N];
int sz[N] , pa[N][20]; 
int tt= 0 ; 
int deep[N] ; 
int node[N]  , id[N] ,h[N] ,head[N] , st1[8*N] , st2[8*N];
int lazy[8*N];
int a[N] ;
pii edge[N];

void doc()
{
    cin>> n; 
    for(int i= 1;i<=n-1;i++)
    {
        int u ,v,c ; 
        cin>>u>>v>>c ;  
        canh[u][v]=c ;
        canh[v][u]=c ;
        g[u].pb(v)  ; 
        g[v].pb(u) ; 
        edge[i] = {u,v};
    }
}

void predfs(int u , int p )
{
    sz[u] = 1 ;     
    if(g[u][0]==p)swap(g[u][0],g[u][g[u].size()-1]);
    for(int i= 0 ;i<g[u].size();i++)
    {
        int v= g[u][i] ; 
        if(v==p)continue ; 
        pa[v][0]= u ; 
        predfs(v,u); 
        sz[u]+=sz[v]; 
        if(sz[g[u][0]]<sz[g[u][i]])
        {
            swap(g[u][0],g[u][i]);
        }
    }
}
void HLD(int u ,int p)
{   
    ++tt; 
    id[u] =tt;  
    node[tt]= u ; 
    if(sz[u]==1)return ;    
    head[g[u][0]]=head[u];
    deep[g[u][0]] =deep[u];
    HLD(g[u][0],u);
    for(int i=1;i<g[u].size();i++)
    {
        int v= g[u][i]; 
        if(v==p)continue;
        head[v]=v ; 
        deep[v]=deep[u]+1;
        HLD(v,u);
    }
}
void build(int id, int l, int r)
{
    if(l==r)
    {
        st1[id]= a[l] ;
        st2[id]= a[l] ;
        return ; 
    }
    int mid=(l+r)/2 ;
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r) ; 
    st1[id] = min(st1[id*2],st1[id*2+1]);  
    st2[id] = max(st2[id*2],st2[id*2+1]);
}
void init()
{   
    predfs(1,0) ; 
    head[1]=1;
    deep[1]=1;
    HLD(1,0);
    for(int i=1 ;i<=n-1;i++)
    {
        a[i] =canh[node[i]][node[i+1]];
    }
    build(1,1,n-1);
}
void dolazy(int id )
{  
    if(lazy[id]==0)return ;
    st1[id]=-st1[id] ; 
    st2[id]=-st2[id] ; 
    swap(st1[id],st2[id]);
    lazy[id*2]+=1; 
    lazy[id*2+1]+=1;
    lazy[id*2]%=2; 
    lazy[id*2+1]%=2;
    lazy[id]=0;
}
void up(int id ,int l , int r , int t , int p )
{
    dolazy(id);
    if(t<=l&&r<=p)
    {
        st1[id]=-st1[id] ; 
        st2[id]=-st2[id] ;  
        swap(st1[id],st2[id]);
        lazy[id*2+1]+=1; 
        lazy[id*2]+=1;
        lazy[id*2+1]%=2; 
        lazy[id*2]%=2;
        return ; 
    }
    if(r<t||p<l)return ; 
    int mid=(l+r)/2;
    up(id*2,l,mid,t,p) ; 
    up(id*2+1,mid+1,r,t,p);
    st1[id]=min(st1[id*2],st1[id*2+1]) ; 
    st2[id]=max(st2[id*2],st2[id*2+1]) ;
}
void update(int id, int l , int r, int pos , int val)
{
    dolazy(id);
    if(l==r&&l==pos)
    {
        st2[id]= val ; 
        st1[id]= val ; 
        return ; 
    }
    if(r<pos||pos<l)return ; 
    int mid=(l+r)/2; 
    update(id*2,l,mid,pos,val) ; 
    update(id*2+1,mid+1,r,pos,val) ; 
    st1[id]=min(st1[id*2],st1[id*2+1]) ; 
    st2[id]=max(st2[id*2],st2[id*2+1]) ;
}
int get(int id , int l ,int r ,int t, int p )
{
    dolazy(id);
    if(t<=l&&r<=p)return st2[id] ; 
    if(r<t||p<l)return -oo ; 
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void _negate(int u ,int v )
{
    if(deep[u]<deep[v])swap(u,v) ; 
    while(deep[u]>deep[v])
    {
        up(1,1,n-1,id[head[u]],id[u]-1);
        u=head[u];
        int pu = pa[u][0] ; 
        canh[pu][u] = -canh[pu][u] ; 
        canh[u][pu] = -canh[u][pu] ;
        u = pu ; 
    }
    while(head[u]!=head[v])
    {
        up(1,1,n-1,id[head[u]],id[u]-1) ; 
        u =head[u] ; 
        int pu=  pa[u][0] ; 
        canh[u][pu] =-canh[u][pu] ; 
        canh[pu][u] =-canh[pu][u] ;
        u=pu ;   
        up(1,1,n-1,id[head[v]],id[v]-1) ;
        v =head[v] ; 
        int pv= pa[v][0] ; 
        canh[v][pv] =-canh[v][pv] ; 
        canh[pv][v] =-canh[pv][v] ; 
        v=pv;
    }
    if(id[u]<id[v])
    {
        up(1,1,n-1,id[u],id[v]-1);
    }
    else 
    {
        up(1,1,n-1,id[v],id[u]-1);
    }
}
int _query(int u , int v  )
{
    int ans =-oo;
    if(deep[u]<deep[v])swap(u,v) ; 
    while(deep[u]>deep[v])
    {
        ans=max(ans,get(1,1,n-1,id[head[u]],id[u]-1));
        u=head[u];
        int pu = pa[u][0] ; 
        ans=max(ans,canh[pu][u]);
        u = pu; 
    } 
    while(head[u]!=head[v])
    {
        ans=max(ans,get(1,1,n-1,id[head[u]],id[u]-1)) ; 
        u =head[u] ; 
        int pu=  pa[u][0] ; 
        ans=max(ans,canh[pu][u]);
        u= pu ;
        ans=max(ans,get(1,1,n-1,id[head[v]],id[v]-1)) ;
        v =head[v]; 
        int pv= pa[v][0] ;
        ans=max(ans,canh[pv][v]); 
        v=pv ;
    }
    if(id[u]<id[v])
    {
        ans=max(ans,get(1,1,n-1,id[u],id[v]-1));
    }
    else 
    {
        ans=max(ans,get(1,1,n-1,id[v],id[u]-1));
    }
    return ans; 
}
void _change(int x, int c )
{
    int u =edge[x].fi ; 
    int v= edge[x].se ;
    canh[u][v] = canh[v][u] = c;  
    if(id[u]<id[v])swap(u,v);  
    if(id[v]+1==id[u])
    {
        update(1,1,n-1,id[v],c);
    }
}
void xuly()
{
    string tmp ; 
    while(cin>>tmp)
    {
        if(tmp=="DONE")return  ;
        if(tmp=="NEGATE")
        {
            int u , v ; 
            cin>>u>>v ; 
            if(u==v)continue;
            _negate(u,v); 
        }
        else if(tmp=="CHANGE")
        {
            int t , c; 
            cin>>t>>c ; 
            _change(t,c);
        }
        else if(tmp=="QUERY")
        {
            int u ,v  ; 
            cin>>u>>v ;
            if(u==v)
            {
                  cout<<0<<"\n";
            }
            else 
            {
                cout<<_query(u,v)<<"\n";
            }
        }
    }
}
void clear()
{
    for(int i=1 ;i<=n;i++)
    {
        for(int j= 0 ; j<=LO;j++)
        {
            pa[i][j] = 0 ; 
        }
        tt=0 ; 
        g[i].clear();
        canh[i].clear();
        deep[i] = 0 ;
        head[i] = node[i] = a[i]  = h[i] = sz[i]=id[i]= 0;
    } 
    for(int iu= 1;iu<=8*n;iu++)
    {
        st1[iu]= st2[iu] = 0 ; 
        lazy[iu]= 0 ;
    }  
} 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
        init();
        xuly(); 
        clear();
    }
    return 0;
}