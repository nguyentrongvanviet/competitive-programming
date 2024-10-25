/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "segdiv"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n;
int a[N] ;  


void doc()
{
    cin>> n; 
    for(int i=1;i<=n;i++)cin>>a[i] ;     
}

namespace sub1
{
    ll f[N] ; 
    int sl[N] ; 
    void xuly()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)sl[j] = 0 ;
            int ok = 0 ;
            for(int j=i;j>=1;j--)
            {
                ok+=(sl[a[j]]%3==0) ; 
                sl[a[j]]++; 
                ok-=(sl[a[j]]%3)==0 ; 
                if(ok==0)
                {
                    f[i]++;
                    (f[i]+=f[j-1])%=sm ;
                }
                if(sl[a[j]]==4)
                {
                    break ; 
                }
            }
        }
        ll res = 0 ; 
        for(int i=1;i<=n;i++)
        {
            (res+=f[i])%=sm ; 
        }
        cout<<res ; 
    }
}
namespace sub2
{
    map<ll,ve<pair<int,ll>>>sum ;
    ll HASH = 0 ;
    ll mu[N] ; 
    int sl[N] ; 
    vi pos[N] ; 
    int pre[N] ;
    void update(int val)
    {
        HASH=(HASH-sl[val]%3*mu[val]%sm+sm)%sm;
        sl[val]++ ; 
        (HASH+=sl[val]%3*mu[val]%sm)%=sm;
    }
    ll get(ve<pair<int,ll>>&sum , int pre)
    {
        if(sum.empty())return 0 ; 
        int l = 0 , r = sum.size()-1 ;
        int ans = -1 ; 
        while(l<=r)
        {
            int mid = (l+r)/2 ; 
            if(sum[mid].fi<=pre)ans=mid,l=mid+1 ; 
            else r = mid-1 ; 
        }
        return ((sum.back().se-(ans==-1?0:sum[ans].se)+(sum.size()-1-ans)%sm)+sm)%sm ;
    }
    ll f[N] ;
    void xuly()
    {
        mu[0] = 1; 
        for(int i=1;i<=n;i++)mu[i] = mu[i-1]*cs%sm ;
        for(int i=1;i<=n;i++)
        {
            pre[i] = -1 ; 
            if(pos[a[i]].size()>=3)
            {
                pre[i] = pos[a[i]][pos[a[i]].size()-3]-1 ; 
            }
            pos[a[i]].push_back(i); 
        }
        sum[0].push_back({0,0}) ;
        int MA = -1;  
        for(int i=1;i<=n;i++)
        {
            update(a[i]) ; 
            MA = max(MA,pre[i]) ;  
            f[i]=get(sum[HASH],MA) ;
            // cout<<HASH<<" ";
            sum[HASH].push_back({i,((sum[HASH].empty()?0:(sum[HASH].back().se))+f[i])%sm}) ; 
        }
        ll res = 0 ;
        // cout<<el;
        // for(int i=1;i<=n;i++)cout<<f[i]<<" ";
        // cout<<el; 
        for(int i=1;i<=n;i++)(res+=f[i])%=sm; 
        assert(res>0) ; 
        cout<<res ;  
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else 
    {
        freopen("text.INP","r",stdin) ;
        freopen("text.OUT","w",stdout) ; 
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}