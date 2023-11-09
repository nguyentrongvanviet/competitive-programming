#define TASK "SHIPPING"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}   
const int N =1e5+1;
const ll sm = 1e9+7, cs=330, inf = 1e9; 
int n , q ;
int M ; 
int a[N] ; 
vi g[N] ; 
int pa[N] ; 
int sz[N] , dd[N] ; 
struct X
{
    ll s , ma ; 
};
struct DL
{
    int cha ; 
    int l ,r ;
};
ve<X>st[N];
unordered_map<int,DL>info[N] ; 

multiset<ll>d[N],tot;
ll f[N] ;
void read()
{
    cin>> n >>q>>M ; 
    FOR(i,1,n)cin>>a[i] ;  
    FOR(i,1,n-1)
    {
        int u ,v;
        cin>>u>>v; 
        g[u].pb(v);
        g[v].pb(u) ;
    }
}
void dfsz(int u , int p)
{
    sz[u] = 1; 
    for(auto v :g[u])if(dd[v]==0&&v!=p)
    {
        dfsz(v,u) ;
        sz[u]+=sz[v] ; 
    }
}
int centroid(int u , int p , int n )
{
    for(auto v : g[u])
        if(v!=p&&dd[v]==0&&sz[v]>n/2)
            return centroid(v,u,n) ; 
    return u ; 
}

X join(X a ,X b)
{
    return X{a.s+b.s,max(a.ma,a.s+b.ma)}; 
}
ll tmp[N] ;
void build(int id, int l, int r , ve<X>& st)
{
    if(l==r)
    {
        st[id].s= tmp[l] ;
        st[id].ma=tmp[l] ;  
        return ; 
    }
    int mid = (l+r)/2; 
    build(id*2,l,mid,st) ; 
    build(id*2+1,mid+1,r,st) ; 
    st[id] = join(st[id*2],st[id*2+1]); 
}

void up(int id, int l , int r , int pos ,ll val ,ve<X>&st)
{
    if(l==r&&r==pos)
    {
        st[id].s= val;
        st[id].ma = val;
        return ;   
    }
    if(r<pos||pos<l)return ;
    int mid =(l+r)/2;
    up(id*2,l,mid,pos,val,st);
    up(id*2+1,mid+1,r,pos,val,st);
    st[id] = join(st[id*2],st[id*2+1]); 
}
X get(int id , int l , int r , int t, int p,ve<X>&st )
{
    if(t<=l&&r<=p)return st[id] ;
    if(r<t)return {st[id].s,-inf};
    if(p<l)return {0,-inf};
    int mid =(l+r)/2;
    return join(get(id*2,l,mid,t,p,st),get(id*2+1,mid+1,r,t,p,st));
}

int tt= 0 ; 
void dfs(int u , int p , int cha ,int root )
{
    info[root][u].cha=cha ;
    info[root][u].l=++tt;
    tmp[tt] = a[u] ;
    for(auto v : g[u])if(dd[v]==0&&v!=p)
    {
        dfs(v,u,cha,root);
    }
    info[root][u].r=++tt;
    tmp[tt]=  -a[u];  
}
ll the2(multiset<ll>&s)
{
    ll tmp = 0 ;
    tmp =*s.rbegin();
    ll ans = tmp ;  
    s.erase(s.find(*s.rbegin()));
    ans+=*s.rbegin(); 
    s.insert(tmp);
    return ans;
}
void findma(int u )
{
    f[u] = a[u] ; 
    if(d[u].size())f[u] = max(f[u],a[u]+*d[u].rbegin());
    if(d[u].size()>=2)f[u]=max(f[u],a[u]+the2(d[u]));
    9
}
void solve(int u )
{
    tt= 0 ; 
    dd[u]=1 ; 
    for(auto v : g[u])if(dd[v]==0)
    {
        dfs(v,u,v,u);
    }   
    st[u].resize((int)(4*tt)+1);
    if(tt)build(1,1,tt,st[u]);
    for(auto v:g[u])if(dd[v]==0)
    {
        X val = get(1,1,tt,info[u][v].l,info[u][v].r,st[u]);
        d[u].insert(val.ma);    
    }

    findma(u);
    
    for(auto v :g[u])if(dd[v]==0)
    {
        dfsz(v,u);
        int c=  centroid(v,u,sz[v]); 
        pa[c] = u; 
        solve(c);
    }
}   
void update(int u, ll val)
{
    tot.erase(tot.find(f[u]));
    a[u] = val; 
    findma(u);
    for(int root= pa[u] ; root ; root=pa[root])
    {
        int cha = info[root][u].cha; 
        int l = info[root][u].l ; 
        int r= info[root][u].r ; 
        int x = info[root][cha].l ; 
        int y = info[root][cha].r ;      
        tot.erase(tot.find(f[root]));
        d[root].erase(d[root].find(get(1,1,st[root].size()/4,x,y,st[root]).ma));
        up(1,1,st[root].size()/4,l,a[u],st[root]); 
        up(1,1,st[root].size()/4,r,-a[u],st[root]);
        d[root].insert(get(1,1,st[root].size()/4,x,y,st[root]).ma);
        findma(root);
    }
}   
void solve()
{ 
    dfsz(1,0) ; 
    solve(centroid(1,0,sz[1]));
    if(M==0)
    {
        int j , c;
        FOR(i,1,q)
        {
            cin>>j>>c; 
            update(j,c) ;
            cout<<*tot.rbegin()<<el;
        }
    }
    if(M)
    {
        ll res = *tot.rbegin() ;
        int j ,c;
        FOR(i,1,q)
        {
            cin>>j>>c;  
            j= ((j-1+abs(res))%n)+1;
            c = (abs(c)+abs(res))%M;
            if(i&1)c=-c;
            update(j,c); 
            cout<<*tot.rbegin()<<el;
            res=*tot.rbegin();
        }
    }
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}