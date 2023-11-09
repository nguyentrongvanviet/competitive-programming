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

const int N = 1e6+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

int n;  
vi g[N] ; 
int f[N] ; 
int a[N] ; 
int cnt =0 ;
void doc()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,2,n)
	{
		int p  ; cin>> p ; 
		int u = i ; 
		g[p].pb(u) ;
		g[u].pb(p) ;  
	}    
	if(n==1)cout<<1,exit(0) ; 
}       
void dfs(int u ,int p)
{
	if(u!=1&&g[u].size()==1)
	{
		cnt++ ; 
		f[u] = 1; 
		return ; 
	}
	if(a[u]==1)f[u] = oo; 
	else f[u] = 0 ; 
	for(auto v: g[u])if(v!=p)
	{
		dfs(v,u) ; 
		if(a[u]==1)f[u]=min(f[u],f[v])  ; 
		else f[u]+=f[v] ; 
	}
}
void xuly()
{	
	dfs(1,0) ;
	cout<<cnt-f[1]+1;
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