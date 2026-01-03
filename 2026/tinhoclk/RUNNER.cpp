/*
Name   :   Nguyen Trong Van Viet
DoB    :   29 - 10 - 2006                      
School :   VNUHCM - University Of Science         
Donate :   VCB    - 1026950589                         
*/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;

#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
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

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 4e5+5 , oo = 2e9 , LO = 18 , CH = 26 ; 

int n; 
vector<int>g[N] ;

int h[N] ; 
int P[N][LO+1] ;
void dfs(int u ,int p)
{
	for(auto v : g[u])if(v!=p)
	{
		h[v] = h[u]+1 ; 
		P[v][0] = u ; 
		for(int i=1;i<=LO;i++)
		{
			P[v][i] = P[P[v][i-1]][i-1] ; 
		}
		dfs(v,u) ; 
	}
}
int lca(int u ,int v)
{
	if(h[u]<h[v])swap(u,v) ; 
	for(int i=LO;i>=0;i--)
	{
		if(P[u][i]&&h[P[u][i]]>=h[v])u=P[u][i] ; 
	}
	if(u==v)return u ;
	for(int i=LO;i>=0;i--)
	{
		int nu = P[u][i] ;
		int nv = P[v][i] ; 
		if(nu!=nv)
		{
			u = nu ; 
			v = nv ; 
		}
	}
	return P[u][0] ; 
}
int at[N] ; 
void go(int u ,int p)
{
	for(auto v :g[u])if(v!=p)
	{
		go(v,u) ; 
		at[u]+=at[v] ; 
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
    int n; cin>>n ;
    for(int i=1;i<=n-1;i++)
    {
    	int u , v; cin>> u >>v   ; 
    	g[u].push_back(v) ; 
    	g[v].push_back(u) ;
    }
    dfs(1,0) ;
    for(int i=1;i<=n-1;i++)
    {
    	int c = lca(i,i+1) ; 
    	at[i]++ ; 
    	at[i+1]++ ; 
    	at[c]--;
    	at[P[c][0]]--;
    	// cout<<c<<endl;
    } 
    go(1,0) ; 
    for(int i=1;i<=n;i++)cout<<at[i]<<"\n" ; 
    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


