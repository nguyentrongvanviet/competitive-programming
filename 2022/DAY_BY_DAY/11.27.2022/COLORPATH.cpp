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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 2e5+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

int n ,m ,  k ;
ll f[N][(1<<5)+5] ; 
int a[N] ;
vi g[N] ; 
void doc()
{
	cin >> n >> m >> k ; 
	FOR(i,1,n)cin>>a[i],--a[i] ;  
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u)  ;
	}
	FOR(i,1,n)f[i][1<<a[i]] = 1 ; 
	FORN(msk,1,(1<<k))
	{
		FOR(u,1,n)
		{
			for(auto v: g[u])
			{
				if(msk>>a[v]&1)continue ; 
				f[v][msk|(1<<a[v])]+=f[u][msk] ; 
			}
		}
	} 
	ll res =0 ; 
	FOR(i,1,n)FORN(msk,1,(1<<k))if(btpc(msk)>1)res+=f[i][msk];
	cout<<res; 
}       

void xuly()
{
    
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