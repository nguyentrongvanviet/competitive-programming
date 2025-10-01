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
int a[N] ; 
vi g[N] ; 
int root ;
ll f[N] , cl[N] ;	
void dfs(int u ,int p)
{
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u) ; 
	}
	vll q;
	ll rest = 0 ;
	for(auto v : g[u])if(v!=p)
	{
		q.pb(f[v]) ; 
		rest+=cl[v] ; 
	}
	sort(all(q),greater<ll>()) ;
	f[u] = (u!=root) ;   
	ll not_used = a[u]-(u!=root) ; 
	if(not_used<=q.size())
	{
		FOR(i,1,not_used)
		{
			f[u]+=q[i-1]+1 ; 
		}
		cl[u] = 0 ; 
	} 
	else
	{
		for(auto x : q)
		{
			f[u]+=x+1; 
			not_used--;
		}
		if(not_used<=rest)
		{
			f[u]+=2*not_used;
			not_used = 0 ; 
			cl[u] = 0 ; 
		}
		else f[u]+=2*rest , cl[u]=not_used-rest;  
	}
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
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v ; cin>> u >>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
    cin>>root ; 
    dfs(root,0) ; 
    cout<<f[root] ; 

    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



