/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ;
struct Edge
{
    int u ,v ; 
}E[N] ;
vi g[N] ; 
void doc()
{
    cin>> n >> k; 
    FOR(i,1,n-1)
    {
        cin>>E[i].u>>E[i].v ;
    }
}
namespace sub3
{
    vector<int>g[N] ; 
    int sz[N] , dd[N] ; 
    void dfsz(int u , int p)
    {
        sz[u] = 1 ;
        for(auto v : g[u])if(v!=p&&dd[v]==0)
        {
            dfsz(v,u); 
            sz[u]+=sz[v] ; 
        }
    }
    ll fac[N] , inv_fac[N] ; 
    ll pw(ll a, ll n)
    {
        if(n==0) return 1;
        ll b = pw(a,n/2); 
        if(n&1)return b*b%sm*a%sm;
        return b*b%sm ;
    }
    int cen(int u , int p ,int n)
    {
        for(auto v :g[u])if(v!=p&&dd[v]==0&&sz[v]>n/2)
        {
            return cen(v,u,n) ; 
        }
        return u ; 
    }
    // fft 
    const ll mod = (119 << 23) + 1, root = 62; // = 998244353
    // For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
    // and 483 << 21 (same root). The last two are > 10^9.
    void ntt(vll &a) 
    {
        int n = a.size(), L = 31 - __builtin_clz(n);
        static vll rt(2, 1);
        for (static int k = 2, s = 2; k < n; k *= 2, s++) {
            rt.resize(n);
            ll z[] = {1, pw(root, mod >> s)};
            FORN(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
        }
        vi rev(n);
        FORN(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        FORN(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) FORN(j,0,k) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
    }
    vll conv(vll a, vll b) {
        if (a.empty() || b.empty()) return {};
        int s = (int)a.size() + (int)b.size() - 1, B = 32 - __builtin_clz(s),
            n = 1 << B;
        int inv = pw(n, mod - 2);
        vll L(a), R(b), out(n);
        L.resize(n), R.resize(n);
        ntt(L), ntt(R);
        FORN(i,0,n)
            out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
        ntt(out);
        return {out.begin(), out.begin() + s};
    }
    int H[N] ; 
    vll tot;
    vll sub ; 
    ll sl[N] ; 
    void dfs(int u ,int p ,int h)
    {
        if(sub.size()==h)sub.pb(1) ; 
        else sub[h]++ ; 
        if(tot.size()==h)tot.pb(1) ; 
        else tot[h]++ ;
        for(auto v : g[u])if(dd[v]==0&&v!=p)
        {
            dfs(v,u,h+1) ; 
        }
    }
    void solve(int u)
    {   
        dd[u] = 1;
        tot={1} ; 
        for(auto v : g[u])if(dd[v]==0)
        {
            sub={0}; 
            dfs(v,u,1) ; 
            sub=conv(sub,sub) ; 
            FORN(i,0,(int)sub.size())
            {
                sl[i]-=sub[i] ; 
            }
        }
        tot=conv(tot,tot) ;  
        FORN(i,0,tot.size())
        {
            sl[i]+=tot[i];
        }
        for(auto v : g[u])if(dd[v]==0)
        {
            dfsz(v,u) ;
            solve(cen(v,u,sz[v])) ;  
        }
    }
    ll C(int k ,int n )
    {
        if(k>n)return 0 ;
        return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
    }
    void xuly() 
    {
        FOR(i,1,n-1)
        {
            g[E[i].u].pb(E[i].v) ; 
            g[E[i].v].pb(E[i].u) ; 
        }
        dfsz(1,0) ; 
        solve(cen(1,0,n)) ; 
        fac[0] = 1; 
        for(int i=1;i<=n;i++)fac[i] = fac[i-1]*i%sm; 
        inv_fac[n] = pw(fac[n],sm-2) ;
        for(int i=n-1;i>=0;i--)inv_fac[i]=inv_fac[i+1]*(i+1)%sm;
        ll res = 0 ;
        FOR(i,0,n-1)
        {
            if(sl[i]==0)break;
            (res+=sl[i]*C(k,n-1-i)%sm)%=sm; 
        }   
        cout<<res ; 
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET aTHE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        // cout<<el;
        // if(sqrt(k)<=n)sub2::xuly() ; 
        sub3::xuly() ;  
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}