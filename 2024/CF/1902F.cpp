/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n;  
int a[N]  ; 
vi g[N] ;
int h[N] , P[N][LO+1] ;
vi basis[N][LO+1] ; 
void dfs(int u ,int p)
{
	basis[u][0].pb(a[u]) ; 
	for(auto v:g[u])if(v!=p)
	{
		P[v][0] = u  ; 
		h[v] = h[u]+1 ; 
		dfs(v,u) ; 
	}
}
bool add(vi &a, int val)
{
	if(a.size()==20)
	{
		return 0 ;
	}
	for(auto x :a)
	{
		mini(val,x^val) ; 
	}
	if(val)
	{
		a.pb(val) ;
		return 1;  
	}
	return 0 ; 
}
void add(vi&a , vi &b)
{
	for(auto x : b)
	{
		add(a,x) ; 
	}
}
vi lca(int u ,int v)
{
	if(h[u]<h[v])swap(u,v) ; 
	vi ans ; 
	for(int i=LO;i>=0;i--)if(h[u]-(1<<i)>=h[v])
	{
		add(ans,basis[u][i]) ; 
		u=P[u][i] ; 
	}
	if(u==v)
	{
		add(ans,basis[u][0]) ; 
		return ans;  
	}
	for(int i=LO;i>=0;i--)
	{
		int nu = P[u][i] ; 
		int nv = P[v][i] ; 
		if(nu!=nv)
		{
			add(ans,basis[u][i]) ; 
			add(ans,basis[v][i]) ; 
			u=nu ; 
			v=nv ; 
		}
	}
	add(ans,basis[u][0]) ; 
	add(ans,basis[v][0]) ;
	u=P[u][0] ;
	add(ans,basis[u][0]) ;  
	return ans ; 
}
bool check(int u ,int v ,int val)
{
	vi tmp = lca(u,v) ; 
	return add(tmp,val) ; 
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
    cin>> n; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
    FOR(i,1,n-1)
    {
    	int u ,v ; cin>> u >>v ; 
    	g[u].pb(v) ;
    	g[v].pb(u) ;
    }
    dfs(1,0) ; 
    FOR(j,1,LO)
    {
    	FOR(i,1,n)
    	{
    		P[i][j] = P[P[i][j-1]][j-1] ; 
    		basis[i][j]  = basis[i][j-1] ; 
    		add(basis[i][j],basis[P[i][j-1]][j-1]) ;
    	}
    }
    int q ; cin >> q; 
    while(q--)
    {
    	int u , v , val;  cin>> u >> v >> val ;
    	cout<<(check(u,v,val)==0?"YES":"NO")<<el;
    }
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



