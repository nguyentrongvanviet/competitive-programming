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
const int N =1e5+4, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 


// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA

ll n,k,G1,G2,G3,c=0,f[N][53],slo1=0;
string s;
void read()
{
    cin>>n>>k>>G1>>G2>>G3;
    cin>>s;
    s="0"+s;
    f(i,1,n) if(s[i]=='#'){
        c++;
    } else slo1++;
}

void solve()
{
    f(i,0,n) f(j,0,c) f[i][j]=-inf;
    f[0][0]=0;
    f(i,1,n){
        f(j,0,c){
            f[i][j]=f[i-1][j];
            if(s[i]=='.'&&s[i-1]=='.')maxi(f[i][j],f[i-2][j]+1);
            if(j>0&&s[i]=='.'&&s[i-1]=='#'&&s[i-2]=='.')maxi(f[i][j],f[i-3][j-1]);
        }
    }
    ll res=0;
    f(j,0,c){
        ll sl1=slo1-2*f[n][j]-2*j; ll sl2=f[n][j]; ll sl3=j;
        if(f[n][j]<0) continue;
        res=max(res,sl2*G2+sl3*G3);
        if(sl1<=k){
            // res=max(res,sl1*G1+sl2*G2+sl3*G3);
            f(x,sl1,k){
                ll thua1=x-sl1; ll new2=(2*sl2-thua1);
                if(new2>=0){
                    new2=(new2>=2?new2/2:0);
                    maxi(res,x*G1+new2*G2+j*G3);
                }
            }
        }
    }
    cout<<res;
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
