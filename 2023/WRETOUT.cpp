/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define           umap  unordered_map
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define            tct  template<typename T>
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 5e3+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int  n ; 
ll m; 
int tt =0 ;  
int a[N] ;
int cnt[75] ; 
ll f[75][N]; 
vi value ;
ll fac[N] ,inv_fac[N] ;
ll pw(ll a, ll n)
{
    if(n==0) return 1;   
    ll b = pw(a,n/2); 
    if(n&1)return b*b%sm*a%sm;      
    return b*b%sm ;
}   
void doc()
{
    cin>> n >> m; 
    if(m>5000)
    {
        n-- ;
        m-- ; 
        ll s1 = 1; 
        ll s2 = 1; 
        FOR(i,1,n)(s1*=i)%=sm ;
        for(ll i=m-n+1;i<=m;i++)
        {
            (s2*=(i%sm))%=sm;
        }
        cout<<s2*pw(s1,sm-2)%sm; 
        exit(0) ;
    }
}
ll C(int k ,int n)
{
    return fac[n]*inv_fac[n-k]%sm*inv_fac[k]%sm;
}
void xuly()
{
    FOR(i,1,n)cin>>a[i] ,value.pb(a[i]) ; 
    uni(value) ; 
    umap<int,int>P ; 
    for(auto v:value)
    {
        P[v]=++tt; 
    }
    FOR(i,1,n)
    {
        a[i] = P[a[i]] ;
        cnt[a[i]]++; 
    }
    fac[0]=inv_fac[0]=1;
    FOR(i,1,m)
    {
        fac[i]=(fac[i-1]*i)%sm; 
        inv_fac[i]=(inv_fac[i-1]*pw(i,sm-2))%sm; 
    }
    f[0][0] = 1 ; 
    FOR(i,1,tt)
    {
        int val = value[i-1] ; 
        FOR(j,cnt[i]*val,m)
        {
            for(int k=cnt[i]*val;k<=j;k+=val)
            {
                (f[i][j]+=(f[i-1][j-k]*C(cnt[i]-1,k/val-1)%sm))%=sm;
            }
        }
    }
    cout<<f[tt][m];
}

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}