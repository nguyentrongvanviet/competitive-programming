#define TASK "SMEX2"
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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =5e3+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
int a[N] ; 
ll f[N][N] ; 
void read()
{
	cin>> n ; 
	FOR(i,1,n)cin>>a[i] ; 
	f[0][0] =1;
	FOR(j,1,n)
	{
		f[0][j]+=f[0][j-1];
	}
	FOR(i,1,n)
	{
		vector<int>dd(n+1,0);
		int it =0 ; 
		FORD(j,i,1)
		{
			dd[a[j]] = 1 ;
			while(dd[it]==1)++it; 
			f[i][it] += f[j-1][it];
			f[i][it]%=sm; 
		}
		FOR(j,1,n)f[i][j]+=f[i][j-1],f[i][j]%=sm;
	}
	cout<<f[n][n];
}

void solve()
{

}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}