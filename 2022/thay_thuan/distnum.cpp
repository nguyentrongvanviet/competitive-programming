#define TASK "distnum"
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
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N = 1e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
str L , R ; 
int n ;
void read()
{
	cin>>L>>R ; 
	while(L.size()<R.size())L="0"+L ; 
	n=R.size() ;
	L=" "+L ; 
	R=" "+R ; 
	// cout<<n<<el;
	// cout<<L<<" "<<R<<el;
}
ll f[N][2][2][2][2] ; 
ll S[N][2][2][2][2] ; 
void solve()
{
	f[0][0][0][0][0] = 1 ; 
	FOR(idx,0,n-1)FOR(ok1,0,1)FOR(ok2,0,1)FOR(ok3,0,1)FOR(ok4,0,1)
	{
		FOR(i,0,9)FOR(j,0,9)
		{
			int nok1=ok1  , nok2 = ok2 , nok3 = ok3 , nok4 = ok4; 
			if(nok1==0)
			{
				if(i>L[idx+1]-'0')nok1= 1 ;
				else if(i<L[idx+1]-'0')continue ; 
			}
			if(nok2==0)
			{
				if(i<R[idx+1]-'0')nok2= 1 ;
				else if(i>R[idx+1]-'0')continue ;
			}
			if(nok3==0)
			{	
				if(j>L[idx+1]-'0')nok3=1 ;
				else if(j<L[idx+1]-'0')continue ;
			}
			if(nok4==0)
			{
				if(j<R[idx+1]-'0')nok4 =1; 
				else if(j>R[idx+1]-'0')continue ;
			}

			f[idx+1][nok1][nok2][nok3][nok4]+=f[idx][ok1][ok2][ok3][ok4] ;
			f[idx+1][nok1][nok2][nok3][nok4]%=sm;
			// cout<<f[idx+1][nok1][nok2][nok3][nok4]<<el;
		}
	}
	// cout<<f[n][1][1][1][1]<<el;
	FOR(idx,0,n-1)FOR(ok1,0,1)FOR(ok2,0,1)FOR(ok3,0,1)FOR(ok4,0,1)
	{
		FOR(i,0,9)FOR(j,0,9)
		{
			int nok1=ok1  , nok2 = ok2 , nok3 = ok3 , nok4 = ok4; 
			if(nok1==0)
			{
				if(i>L[idx+1]-'0')nok1= 1 ;
				else if(i<L[idx+1]-'0')continue ; 
			}
			if(nok2==0)
			{
				if(i<R[idx+1]-'0')nok2= 1 ;
				else if(i>R[idx+1]-'0')continue ;
			}
			if(nok3==0)
			{	
				if(j>L[idx+1]-'0')nok3=1 ;
				else if(j<L[idx+1]-'0')continue ;
			}
			if(nok4==0)
			{
				if(j<R[idx+1]-'0')nok4 =1; 
				else if(j>R[idx+1]-'0')continue ;
			}
			S[idx+1][nok1][nok2][nok3][nok4]+=S[idx][ok1][ok2][ok3][ok4]+abs(i-j)*f[idx][ok1][ok2][ok3][ok4] ;
			S[idx+1][nok1][nok2][nok3][nok4]%=sm;
		}
	}
	ll res=0  ;
	FOR(i,0,1)FOR(j,0,1)FOR(x,0,1)FOR(y,0,1)
	{
		res+=S[n][i][j][x][y] ;
		res%=sm;
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