/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "dienbien"
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
#define          SZ(_)  (int)(_.size())
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ; 
vi g[N] ; 
int dd[N] , cam[N] ; 
void doc()
{
    FOR(i,1,k)
    {
    	int u ; cin>>u ; 
        cam[u] =1 ; 
    }
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
    int h[N] ;
    int pa[N], die[N] ;
    void dfs(int u ,int p)
    {
        for(auto v: g[u])if(v!=p)
        {
            h[v]=h[u]+1 ;
            pa[v] = u ;
            dfs(v,u) ; 
        }
    }
    struct cmp
    {
        bool operator()(int a, int b )
        {
            return h[a]<h[b] ; 
        }
    } ; 
    void xuly()
    {  
        dfs(1,0) ;
        priority_queue<int , vi ,cmp>q ;
        FOR(i,1,n)if(cam[i])
        {
            dd[i] = 1;  
            q.push(i) ; 
        }
        int res = 0 ;
        FOR(i,1,n)if(cam[i])for(auto v: g[i])if(cam[v])
        {
            res= -1 ; 
        }
        if(res!=-1)while(!q.empty())
        {
            int u = q.top() ; 
            q.pop() ; 
            int v=pa[u] ;
            if(die[u]||die[v])continue ; 
            if(v==0)break;
            if(dd[v])
            {
                if(cam[v]==0)die[v] = 1,res++; 
                else if(cam[u]==0)
                {
                    res++ ;  
                }
                else 
                {
                    res=-1 ; 
                    break; 
                }
            }
            else
            {
                if(v)q.push(v),dd[v]=1 ;
            }  
        }
    	cout<<res<<el;
        FOR(i,1,n)g[i].clear(),cam[i] = dd[i] = die[i]= 0;  
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
    int theta ;cin>>theta; 
    while(cin>>n>>k)
    {
        doc() ; 
        if(n==-1&&k==-1)break;
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}