#define TASK "CANDY"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct MT 
{
	int n , m ; 
	ve<ve<ll>>mt ; 
	void init(int _n , int _m)
	{
		n = _n ; 
		m = _m ;
		mt.resize(n+1);
		FOR(i,0,n)mt[i]=vll(m+1,0);
	}
};
MT mul(MT a , MT b)
{
	int n = a.n;  
	int m = b.m; 
	MT ans ; ans.init(n,m) ;  
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			ll tmp = 0 ; 
			FOR(t,0,a.m)
			{	
				tmp+=a.mt[i][t]*b.mt[t][j];
			}	
			ans.mt[i][j] = tmp ; 
		}
	}
	return ans;  
}
MT pw(MT a,int n)
{	
	if(n==1)return a; 
	MT b = pw(a,n/2) ; 
	if(n&1)return mul(a,mul(b,b)) ; 
	return mul(b,b) ; 
}
int n , k; 
ve<pii>E ; 
int head[N] ; 
vi g[N] ; 
void read()
{
	cin>>k>>n;
	int node=0;
	FOR(i,1,n)
	{	
		for(int  u= head[i-1], j=1;j<=i;j++,u=node)
		{
			g[u].pb(++node) ;
		}
		head[i] = node; 
		for(int u=  head[i],j=1;j<=i-1;j++,u=node)
		{
			g[u].pb(++node) ; 
		}
		g[node].pb(head[i]);
	} 
	MT A  ; A.init(1,n);
	MT G  ; G.init(node,node);
	A.mt[0][0]=1;
	FOR(i,0,node)for(auto v: g[i])G.mt[i][v]=1;
	MT ans= mul(A,pw(G,k)) ; 
	cout<<ans.mt[0][head[n]];
}
void solve()
{

}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}