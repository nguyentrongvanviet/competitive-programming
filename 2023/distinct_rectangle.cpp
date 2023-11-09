// distinct rectangle 
#define TASK "text"
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
const int N =4e2+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , m ; 
ve<vi>f ,pre,a ; 
unordered_map<int,int>la[N] ; 
void read()
{
	cin>> n >> m ;
	a.resize(n+1,vi(m+1)) ; 
	pre.resize(n+1,vi(m+1,0)) ; 
	f.resize(n+1,vi(m+1,0)) ;
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
}
int res= 0 ; 
void solve()
{	
	FOR(i,1,n)
	{
		FOR(j,1,m)f[j][j] = max(pre[j][j],(la[j].count(a[i][j])?la[j][a[i][j]]+1:1));
		FOR(j,1,m)la[j][a[i][j]]= i ; 
		FOR(jj,2,m)FORD(j,jj-1,1)f[j][jj] = max({pre[j][jj],f[j+1][jj],f[j][jj-1],(la[j].count(a[i][jj])?la[j][a[i][jj]]+1:1),(la[jj].count(a[i][j])?la[jj][a[i][j]]+1:1)});
		FOR(j,1,m)FOR(jj,j,m)
		{
			res=max(res,(i-f[j][jj]+1)*(jj-j+1));
			pre[j][jj] = f[j][jj];
		} 
	}
	cout<<res;
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