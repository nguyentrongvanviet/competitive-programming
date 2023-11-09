#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
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
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 200+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , m , p ; 	
ll a[N] , b[N] , c[N] ;
ll f[N][N][N];
void doc()
{
	cin>>n>>m>>p ;
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)cin>>b[i] ; 
	FOR(i,1,p)cin>>c[i]; 
}
void xuly()
{
	sort(a+1,a+n+1) ; 
	sort(b+1,b+m+1) ; 
	sort(c+1,c+p+1) ;
	FOR(i,0,n)FOR(j,0,m)FOR(k,0,p)
	{
		ll tmp =0 ; 
		if(i&&j)tmp =max(tmp,f[i-1][j-1][k]+a[i]*b[j]); 
		if(j&&k)tmp =max(tmp,f[i][j-1][k-1]+b[j]*c[k]); 
		if(i&&k)tmp =max(tmp,f[i-1][j][k-1]+a[i]*c[k]) ;
		f[i][j][k] = tmp ; 
	}
	cout<<f[n][m][p];
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
}