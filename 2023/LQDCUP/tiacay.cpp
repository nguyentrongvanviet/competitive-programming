/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tiacay"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k , x;
int h[N] , g[N] ;
void doc()
{
    cin>> n >> m >> k >>x; 
    FOR(i,1,n)
    {
        cin>>h[i]>>g[i] ; 
    }
}

namespace sub1
{
    void xuly()
    {
        priority_queue<ll>q ;
        FOR(i,1,n)
        {
            q.push(1ll*h[i]+1ll*g[i]*m) ;
        }
        FOR(i,1,m*k)
        {   
            ll val = q.top() ; 
            q.pop() ; 
            if(val>=x)
            {
                val-=x ; 
            }
            q.push(val) ; 
        }
        ll res = q.top() ; 
        cout<<res;
    }
}
namespace sub2
{
    struct DL
    {
        int id ; 
        int h ; 
        ll val; 
    };
    struct cmp
    {
        bool operator()(const DL&a ,const DL&b)const
        {
            return (a.h>=x) < (b.h>=x)|| ( (a.h>=x) == (b.h>=x) && a.val<b.val ); 
        }
    } ;  
    void xuly()
    {
        FOR(i,1,m)
        {
            priority_queue<DL,ve<DL>,cmp>q ;
            FOR(j,1,n)
            {
                h[j]+=g[j] ; 
                q.push({j,h[j],h[j]+g[j]*(m-i)});
            }
            FOR(j,1,k)
            {
                int u =q.top().h ; 
                int id = q.top().id;
                q.pop() ; 
                if(u<x)break; 
                h[id]-=x;
                q.push({id,h[id],h[id]+g[id]*(m-i)});
            }
        }
        cout<<*max_element(h+1,h+n+1) ; 
    }
}
namespace sub3
{
    struct DL
    {
        int id ;
        ll val ; 
    };
    int can[N] , cut[N] ;
    int cnt[N] ; 
    void xuly()
    {
        queue<pii>q; 
        ve<pii>tree; 
        FOR(i,1,n)
        {
            tree.pb({h[i]+m*g[i],i});
            cnt[i] = 0 ;
            can[i] = 1 ; 
        }
        FOR(i,1,m)cut[i] = k ;  
        sort(all(tree)) ; 
        pii u = tree.back() ;
        q.push(u) ; 
        tree.pk() ; 
        while(!tree.empty()&&tree.back().fi>=u.fi-x)
        {
            q.push(tree.back()) ;
            tree.pk() ;
        }
        while(!q.empty())
        {
            int u= q.front().se; 
            int val =q.front().fi; 
            while(can[u]<=m && (can[u]*g[u]+h[u] < (cnt[u]+1)*x||cut[can[u]]==0) )
            {
                ++can[u] ; 
            }
            if(can[u]<=m)
            {
                cut[can[u]]--;
                cnt[u]++;
                val-=x ; 
                q.pop() ; 
                q.push({val,u}) ;
                while(!tree.empty()&&tree.back().fi>=q.front().fi-x)
                {
                    q.push({tree.back()}) ;
                    tree.pk() ;
                }
            }
            else
            {
                return void(cout<<val<<el) ; 
            }
        }
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        // sub2::xuly() ; 
        sub3::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}