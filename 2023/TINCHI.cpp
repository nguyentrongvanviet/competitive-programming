// Author: Nguyen Quoc Phu Dep Trai    
#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define pt pop_front
#define pf push_front
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define            tct  template<typename T>
#define BIT ((x>>i)&1)
#define MASK(x) (1<<(x))

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
const ll INF=(ll)1e18 + 7LL;
ll product(ll a,ll b){
    if(a==0||b==0) return 0;
    return INF/a<b?INF:a*b;
}
const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 
struct DL{
    ll a,b;
    int idx1,idx2;
    friend bool operator < (const DL &A,const DL &B){
        return A.b<B.b;
    }
}a[N];

// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA

ll n,k,m=0,s[N],pos[N];
pll bit[N];
vector<pll>val;
void read()
{
    cin>>n>>k;
    f(i,1,n){
        cin>>a[i].a>>a[i].b;
        s[i]=s[i-1]+a[i].a;
        a[i].idx1=i;
        a[i].idx2=i+n;
        val.pb(mp(a[i].a,i));
        val.pb(mp(a[i].b-a[i].a,i+n));
    }
    sort(a+1,a+n+1);
    sort(val.begin(),val.end(),[&](pll x,pll y){return x.fi<y.fi||(x.fi==y.fi&&x.se<y.se);});
    for(auto v:val){
        pos[v.se]=++m;
    }
}
void update(ll idx,ll val,ll cnt){
    for(;idx<=m;idx+=idx&-idx){
        bit[idx].fi+=val;
        bit[idx].se+=cnt;
    }
}
ll getval(ll idx){
    ll res=0;
    for(;idx;idx-=idx&-idx) res+=bit[idx].fi;
    return res;
}
ll get(ll limit){
    ll sum=0;
    ll cnt=0;
    ll pos=0;

    for(int i=LG;i>=0;i--){
        if(pos+(1<<i)<=m&&cnt+bit[pos+(1<<i)].se<=limit){
            sum+=bit[pos+(1<<i)].fi;
            cnt+=bit[pos+(1<<i)].se;
            pos+=(1<<i);
        }
    }
    return sum;
}
void solve()
{

    f(i,1,n) update(pos[a[i].idx1],a[i].a,1);
    ll res=(k<=n?get(k):inf);
    for(int i=1;i<=n;i++){
        update(pos[a[i].idx1],-a[i].a,-1);
        res=min(res,a[i].b+s[i-1]+get(k-i-1));
        update(pos[a[i].idx2],a[i].b-a[i].a,1);
    }
    cout<<res<<el;
}

signed main()    
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(TASK".INP", "r"))
    {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }
    fast;
    int test =1; 
  //  cin>>test;
   while(test--)
    {
        read(); 
        solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}