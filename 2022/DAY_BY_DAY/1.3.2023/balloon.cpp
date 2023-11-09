#define TASK "balloon"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';

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

const int N =2e2+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
str s ; 
int n ; 
int a[N] ;
ll f[N][N][N];
int ok[N][N];
void read()
{
	cin>>s ; 
	n=s.size()  ; 
	FOR(i,1,n)
	{
		char c= s[i-1] ;
		if(c=='B')a[i] = 1 ; 
		else if(c=='R')a[i] =2; 
		else if(c=='G')a[i] =3; 
		else a[i]= 4 ;
	} 
}	
ll tinh(int  l ,int r ,  int k )
{
	if(f[l][r][k]!=-1)return f[l][r][k] ; 
	if(l>r)return f[l][r][k] = 0 ; 
	ll tmp =-inf ; 
	if(k>=1)
	{
		ll x = tinh(l+1,r,0)+sq(k+1) ;
		tmp=max(tmp,x) ; 
	}
	if(ok[l][r]&&r-l+1+k>=2)
	{
		return f[l][r][k]=sq(r-l+1+k) ; 
	}
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]==a[l])
		{
			tmp=max(tmp,tinh(l+1,i-1,0)+tinh(i,r,k+1));
		}
	}
	if(tmp<0)tmp=-inf ; 
	return f[l][r][k] = tmp ; 
}
void solve()
{	
	FOR(i,1,n)FOR(j,1,n)ok[i][j] = 0 ; 
	FOR(i,1,n)
	{ 
		FOR(j,i+1,n)
		{
			if(a[j]==a[i])ok[i][j] = 1; 
			else break; 
		}
	}
	FOR(i,0,n+1)FOR(j,0,n+1)FOR(k,0,n)f[i][j][k] = -1;
	ll res= tinh(1,n,0);
	if(res==-inf)cout<<0<<el; 
	else cout<<res<<el;
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