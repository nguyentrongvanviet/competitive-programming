#define TASK "SUBSTR"
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
const int N =5e2+5 ,  oo = 2e9, CH = 'a' ;
const ll sm = 666013, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
str a, b ;
int n , m ; 
int la[N][CH+4] , lb[N][CH+4]; 
int  d[N][N];
ll f[N][N];
void read()
{
	cin>>a>>b; 
	n = a.size(); 
	m = b.size();
	a='#'+a; 
	b='$'+b;
	FOR(i,1,26)la[n+1][i]=n+1,lb[m+1][i]=m+1;
	FORD(i,n,0)
	{
		FOR(j,1,26)la[i][j] =  la[i+1][j];
		if(i)la[i][a[i]-CH+1] = i ;
	}
	
	FORD(i,m,0)
	{
		FOR(j,1,26)lb[i][j]=lb[i+1][j] ; 
		if(i)lb[i][b[i]-CH+1] = i ;
	}
	f[0][0] =1 ; 
	int ma= 0 ;
	FOR(i,0,n)FOR(j,0,m)
	{
		FOR(c,1,26)
		{
			int u = la[i+1][c]; 
			int v= lb[j+1][c] ; 
			if(u==0||v==0)continue;
			if(d[u][v]<d[i][j]+1)
			{
				d[u][v] = d[i][j]+1; 
				f[u][v] = f[i][j] ; 
			}
			else if(d[u][v]==d[i][j]+1)
			{
				f[u][v] +=f[i][j] ; 
			}
		}
		ma=max(ma,d[i][j]);
	}
	ll res= 0 ;
	FOR(i,1,n)FOR(j,1,m)if(d[i][j]==ma)res+=f[i][j],res%=sm;
	cout<<ma<<" "<<res;
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