#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
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
const int N = 2e2+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n;
int a[N] ; 
int f[N][2*N];
void doc()
{
	cin>>n ; 
	FOR(i,1,n)cin>>a[i] ; 
	sort(a+1,a+n+1) ; 
	FOR(i,1,n)FOR(j,0,2*n)f[i][j] = oo ; 
	FOR(i,1,n)
	{
		FOR(j,1,2*n)
		{
			FOR(jj,0,j-1)
			{
				f[i][j] = min(f[i][j],f[i-1][jj]+abs(a[i]-j));
			}
		}
	}
	FOR(i,1,n)
	{
		// FOR(j,1,n)cout<<f[i][j]<<" ";cout<<el;
	}
	int res= oo ; 
	FOR(i,1,2*n)
	{
		res=min(res,f[n][i]);
	}
	cout<<res<<el;
}

void xuly()
{

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