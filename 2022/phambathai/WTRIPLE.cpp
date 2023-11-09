#define TASK "WTRIPLE"
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
int n , m  ,  p ;  
ll a[N]  ,b[N] , c[N] , sa[N] , sc[N] ;
void read()
{
	cin>>n>>m>>p ;
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)cin>>b[i] ;
	FOR(i,1,p)cin>>c[i] ; 
	sort(a+1,a+n+1) ; 
	sort(b+1,b+m+1) ; 
	sort(c+1,c+p+1) ; 
}
void solve()
{
	FOR(i,1,n)sa[i] = (sa[i-1]+a[i])%sm; 
	FOR(i,1,p)sc[i] = (sc[i-1]+c[i])%sm; 
	int u =0 , v= 0 ; 
	ll res= 0 ; 
	FOR(i,1,m)
	{
		while(a[u+1]<=b[i]&&u+1<=n)++u;
		while(c[v+1]<=b[i]&&v+1<=p)++v;
		ll A = sa[u] * sc[v] % sm;
		ll B = b[i] * b[i] % sm * u % sm * v % sm;
		ll C = ( v * sa[u] % sm + u * sc[v] % sm) % sm * b[i]  % sm;
		if(u&&v)res+=(A + B + C);
		res%=sm;
	}	
	cout<<res%sm;
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