#define TASK "khungbo"
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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 2e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

struct DL
{
	int x ,y ;
	int id ; 
	bool operator<(const DL&a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	} 
}; 
struct cmp
{
	bool operator()(const DL& a, const DL& b )const
	{
		return a.y<b.y||(a.y==b.y&&a.x<b.x) ; 
	}
} ; 
int n , m , L ; 
DL a[N] ; 
int pa[N] ;
int ok[N][5] ; 
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u ,int v)
{
	int nu = goc(u) ; 
	int nv = goc(v) ; 
	if(nu==nv)return ; 
	pa[nu]=nv ; 
	FOR(i,1,4)ok[nv][i]|=ok[nu][i] ; 
}
void doc()
{
    cin>> n >> m >> L ;
    FOR(i,1,m)
    {
    	pa[i] = i; 
    	cin>>a[i].x>>a[i].y ; 
    	if(a[i].x-L<=0)ok[i][1] = 1; 
    	if(a[i].x+L>=n)ok[i][3] = 1;   
    	if(a[i].y+L>=n)ok[i][2] = 1;  
    	if(a[i].y-L<=0)ok[i][4] = 1; 
        a[i].id=i;
    }
}       

void xuly()
{
    sort(a+1,a+m+1) ; 
    multiset<DL,cmp>S; 
    int l =1 ; 
    FOR(i,1,m)
    {
        // cout<<a[i].x<<" "<<a[i].y<<el;		
    	while(a[i].x-a[l].x>L)S.erase(a[l++]);
    	auto u = S.lower_bound(a[i]) ; 
    	if(u!=S.end())
    	{	
            DL A = *u ; 
            if(abs(A.y-a[i].y)<=L)hop(A.id,a[i].id); 
    	}
    	if(u!=S.begin())
    	{
    		--u; 
            DL A = *u ; 
    		if(abs(a[i].y-A.y)<=L)hop(A.id,a[i].id);
    	}
    	S.insert(a[i]) ;
    }
    ve<pii> C = {{1,3},{1,4},{2,3},{2,4}} ;
    ve<DL> res ; 
    FOR(i,1,m)
    {
    	int u =goc(a[i].id) ; 
    	for(auto x: C)
    	{
    		if(ok[u][x.fi]&&ok[u][x.se])
    		{
    			res.pb(a[i]) ; 
    			break;  
    		}
    	}
    }
    // FOR(i,1,m)cout<<goc(i)<<" ";cout<<el;
    cout<<res.size()<<el; 
    sort(all(res)) ;
    for(auto v: res)cout<<v.x<<" "<<v.y<<el;
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