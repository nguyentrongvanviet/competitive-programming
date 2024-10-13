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

bool mtt = 1 ;
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
const int N = 4e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int numnode , numedge , need ; 
int a[N] ; 
void doc()
{   
    cin>> numnode >> numedge >> need ; 
    FOR(i,1,need)
    {
        cin>>a[i] ; 
    }
}
namespace sub1
{
    ll res[N] ; 
    int Node[N] ;
    int C[N][N] ; 
    void xuly()
    {
        FOR(i,1,numnode)
        {
            FOR(j,1,numnode)
            {
                C[i][j] = oo ; 
            }
            C[i][i] = 0 ; 
        }
        FOR(i,1,numedge)
        {
            int u ,v , w ; cin>> u >>v >>w ; 
            C[u][v] = w ;
            C[v][u] = w ; 
        }
        FOR(k,1,numnode)
        FOR(i,1,numnode)FOR(j,1,numnode)
        {
            C[i][j] = min(C[i][j],max(C[i][k],C[k][j])) ; 
        }
        res[1] = inf ; 
        int ans = -1 ; 
        FOR(i,1,need)
        {
            ll tmp = 0 ; 
            FOR(j,1,need)
            {
                tmp+=C[a[i]][a[j]] ; 
            }
            if(res[1]>tmp)
            {
                res[1] = tmp ;
                ans = a[i] ; 
            }
        }
        FOR(i,1,need)
        {
            Node[a[i]] = ans ; 
        }
        FOR(i,2,need)
        {
            ll less= 0 ; 
            FOR(j,1,need)
            {   
                ll tmp = 0  ;
                FOR(k,1,need)
                {
                    tmp+=max(0,C[a[k]][Node[a[k]]]-C[a[k]][a[j]]) ; 
                }   
                if(maxi(less,tmp))
                {
                    ans= a[j]; 
                }
            }
            FOR(k,1,need)
            {
                if(C[a[k]][Node[a[k]]]-C[a[k]][ans]>0){
                    Node[a[k]] = ans; 
                }   
            }
            res[i]=res[i-1]-less;
        }
        FOR(i,1,numnode)cout<<res[i]<<" ";
        cout<<'\n'; 
        FOR(i,1,numnode)
        {
            res[i] = 0 ; 
            Node[i] = 0 ;
        }
    }
}
namespace sub2
{
    const int N = 5e3+5 ; 
    struct ke
    {
        int v , w; 
    } ;
    ve<ke>g[N];
    int dis[N][N] ; 
    struct DL
    {
        int u ,val ; 
        friend bool operator <(const DL&a , const DL&b)
        {
            return a.val>b.val ; 
        }
    };  
    void dij(int u ,int *f)
    {
        priority_queue<DL>q ;
        FOR(i,1,numnode)
        {
            f[i] = oo; 
        }   
        q.push({u,f[u]=0}); 
        while(!q.empty())
        {
            auto [u,val] = q.top() ; 
            q.pop() ; 
            if(val!=f[u])continue ;
            for(auto [v,w] :g[u])
            {
                if(mini(f[v],max(f[u],w)))q.push({v,f[v]}) ; 
            }
        }
    } 
    void xuly()
    {
        FOR(i,1,numedge)
        {
            int u ,v , w; cin>> u>> v >> w ;
            g[u].pb({v,w}) ;
            g[v].pb({u,w}) ; 
        }
        FOR(i,1,need)
        {
            dij(a[i],dis[a[i]]) ; 
        }
        vll sum(need+1,0) ; 
        vll dd(need+1,0) ; 
        FOR(i,1,need)
        {   
            FOR(j,1,need)sum[i]+=dis[a[i]][a[j]] ;  
        }
        ll val = *min_element(sum.begin()+1,sum.end()) ;
        int u = min_element(sum.begin()+1,sum.end())-sum.begin() ;
        FOR(i,1,need)
        {
            dd[i] = a[u] ; 
            
        }  
        FOR(i,1,need)
        {
            int val = 
        }
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
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}