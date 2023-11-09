#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 1e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
struct Edge
{
    int u ,v  , c ; 
    bool operator<(const Edge&other)const
    {
        return c<other.c;  
    }
}; 
int n , k; 
vi g[N] ; 
Edge E[N] ;  
int h[N] ; 
void doc()
{
    cin>> n >> k ; 
    if(k==1)cout<<0 , exit(0) ; 
    FOR(i,1,n-1)
    {
        int u ,v , c ; cin>>u>>v>>c ;
        E[i] = {u,v,c} ; 
    }    
}       
int ma  = 0 ; 
void dfs1(int u ,int p)
{
    if(h[u]>h[ma])ma=u ; 
    for(auto v: g[u])if(v!=p)
    {
        h[v] = h[u]+1; 
        dfs1(v,u) ; 
    }
}
bool check(int val )
{
    FOR(i,1,n)g[i].clear() ,h[i]=0; 
    FORN(i,1,n)
    {
        if(E[i].c>val)break ;
        g[E[i].u].pb(E[i].v) ; 
        g[E[i].v].pb(E[i].u) ;  
    }
    FOR(i,1,n)if(h[i]==0)
    {
        ma  = 0;   
        dfs1(i,0)  ;
        int u =ma ; 
        ma =0 ;   
        h[u] = 0; 
        dfs1(u,0) ;
        if(h[ma]+1>=k)return 1 ;  
    }   
    return 0 ; 
}
void xuly()
{
    sort(E+1,E+n) ; 
    int ans = -1 ; 
    int l = 1 ; 
    int r = (1e9) ; 
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(check(mid))ans=mid , r=mid-1 ;
        else l=mid+1; 
    }
    if(ans==-1)return void(cout<<-1) ; 
    cout<<ans+100 ; 
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}