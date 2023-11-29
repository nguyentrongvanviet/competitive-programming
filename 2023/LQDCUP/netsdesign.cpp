/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "netsdesign"
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


int n ,m ;
struct pt
{
	int x, y ;
} ;
ll dis(pt a, pt b)
{
	return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
pt a[N] ,b[N] ;
void doc()
{
    cin>> m >> n  ; 
    FOR(i,1,m)
    {
    	cin>>b[i].x>>b[i].y ; 
    }
    FOR(i,1,n)cin>>a[i].x>>a[i].y ; 
}
namespace sub1
{
    struct Edge
    {
    	int u ,v  ; 
    	ll len ; 
    	bool operator<(const Edge&a)const
    	{
    		return len<a.len ;
    	}
    }E[N] ; 
    int pa[N] ;
    int goc(int u )
    {
    	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
    }
    bool hop(int u ,int v)
    {
    	int chau = goc(u) ; 
    	int chav = goc(v) ; 
    	if(chau==chav)return 0; 
    	pa[chau]=chav ; 
    	return 1; 
    }
    vi g[N] ;
    ll res = 0 ; 
    ve<pii>ans;  
    void dfs(int u ,int p)
    {
    	for(auto v:g[u])if(v!=p)
    	{
    		cout<<'u'<<" "<<u<<" "<<v<<el;
    		dfs(v,u) ;
    	}
    }
    void xuly()
    {
        int e = 0 ; 
        FOR(i,1,n)FOR(j,i+1,n)
        {   
            E[++e]={i,j,dis(a[i],a[j])} ; 
        }
        sort(E+1,E+e+1) ; 
        FOR(i,1,n)pa[i] = i ;
        FOR(i,1,e)
        {
            int u =E[i].u ;
            int v =E[i].v ;
            if(hop(u,v))
            {
                g[u].pb(v) ; 
                g[v].pb(u) ; 
                res+=E[i].len; 
            }
        }   
        int start = 0 ;
        ll tot = inf ; 
        FOR(i,1,n)
        {
            ll tmp = 0 ; 
            FOR(j,1,m)
            {   
                tmp+=dis(a[i],b[j]) ; 
            }
            if(mini(tot,tmp))
            {
                start = i ;
            }
        }
        res+=tot ; 
        cout<<res<<el;
        cout<<n+m-1<<el;  
        FOR(i,1,m)
        {
            cout<<'s'<<" "<<i<<" "<<start<<el;
        }
        dfs(start,0) ;
    }
}
namespace sub2
{
    // O(n^2) hct chi bai 
    // luu tap near la dinh gan va kc bao nhieu 
    // moi vong lap tim ra dinh gap cap gan nhat hien tai 
    pair<int,ll>near[N] ;
    int used[N] ;
    ll res = 0 ; 
    vi g[N] ; 
    void PRIM() 
    {
        used[1] = 1 ; 
        FOR(i,2,n)
        {   
            near[i] = {1,dis(a[1],a[i])} ; 
        }
        near[0] = {0,inf} ; 
        FOR(loop,1,n-1)
        {
            int c = 0 ; 
            FOR(i,1,n)if(used[i]==0)
            {
                if(near[c].se>near[i].se)
                {
                    c=i ;  
                }
            }
            used[c] = 1 ;
            res+=near[c].se ; 
            g[c].pb(near[c].fi) ;
            g[near[c].fi].pb(c) ;
            FOR(i,1,n)if(used[i]==0)
            {
                if(near[i].se>dis(a[c],a[i]))
                {
                    near[i] = {c,dis(a[c],a[i])} ; 
                }
            }
        }
    }
    void dfs(int u ,int p)
    {
        for(auto v:g[u])if(v!=p)
        {
            cout<<"u "<<u<<" "<<v<<el;
            dfs(v,u) ; 
        }
    }
    void xuly()
    {
        PRIM() ; 
        int ans = 0 ;
        ll tot = inf ; 
        FOR(i,1,n)
        {
            ll tmp = 0 ; 
            FOR(j,1,m)
            {   
                tmp+=dis(a[i],b[j]) ; 
            }
            if(mini(tot,tmp))
            {
                ans = i ;
            }
        }
        cout<<res+tot<<el;
        cout<<n+m-1<<el;
        FOR(i,1,m)cout<<"s "<<i<<" "<<ans<<el;
        dfs(ans,0) ; 
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
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}