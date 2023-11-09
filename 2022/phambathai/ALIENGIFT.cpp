#include<bits/stdc++.h>

#define TASK "ALIENGIFT"   
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
pii a[N] ; 
ll val[N][1<<4] ,st[4*N][1<<4], b[4]  ,f[N][1<<4];
vi tt ; 
vi g[1<<4]; 
void up(int id, int l, int r , int pos, ll val, int msk )
{
    if(l==r)
    {
        st[id][msk]= val; 
        return ; 
    }
    int mid= (l+r)/2;
    if(pos<=mid)up(id*2,l,mid,pos,val,msk);
    else up(id*2+1,mid+1,r,pos,val,msk) ;
    st[id][msk] = max(st[id*2][msk],st[id*2+1][msk]); 
}
ll get(int id , int l , int r ,int t, int p ,int msk)
{
    if(t<=l&&r<=p)return st[id][msk] ;
    if(r<t||p<l)return -inf;
    int mid =(l+r)>>1;
    return max(get(id*2,l,mid,t,p,msk),get(id*2+1,mid+1,r,t,p,msk));
}
void read()
{
    cin>> n; 
    bool ok =  0 ; 
    FOR(i,1,n)
    {
        cin>>a[i].fi>>a[i].se ; 
        FORN(j,0,4)cin>>b[j],ma=max(ma,b[j]), if(b[j])ok=1;  
        FORN(msk,0,1<<4)
        {
            if(msk&(msk<<1))continue;
            FORN(j,0,4)
            {
                if(msk>>j&1)
                {
                    val[i][msk]+=b[j] ; 
                }
            }
        }
    }
    if(!ok)
    {

    }
    FORN(i,0,1<<4)
    {
        if(i&(i<<1))continue ;
        tt.pb(i) ;
    }
    
    for(auto msk:tt)
    {
        FOR(i,1,n)f[i][msk]=st[i][msk] = inf;
        FOR(i,1,4*n)st[i][msk] = -inf;
    }
    FORN(x,0,tt.size())FORN(y,0,tt.size())
    {
        int i = tt[x] ;  
        int j = tt[y];
        if(i&j)continue;
        else g[i].pb(j);
    }
    FOR(i,1,n)
    {
        for(auto msk : tt)
        {
            f[i][msk] = -inf ;
        }
    }
    FORD(i,n,1)
    {
        for(auto msk : tt)
        {
            f[i][msk] =  val[i][msk];
            for(auto x : g[msk])
            {
                if(i+a[i].fi<=n)f[i][msk] =max(f[i][msk],val[i][msk]+get(1,1,n,i+a[i].fi,min(n,i+a[i].se),x));
            }
        }
        for(auto msk :tt)
            up(1,1,n,i,f[i][msk],msk);
    }
    ll res= -inf ; 
    for(auto msk :tt)
    {
        res= max(res,f[1][msk]);
    }
    cout<<res;
}
void process()
{
    
}
void print()
{
    
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
}