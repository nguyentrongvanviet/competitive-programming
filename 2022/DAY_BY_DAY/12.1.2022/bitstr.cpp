#define TASK "bitstr"
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

const int N =102 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct ke
{
	int l  ; 
	int c; 
};
int n , k ; 
ll p ; 
ll f[N][(1<<17)+5];
ve<ke>g[N] ;
void read()
{
	cin>> n >> k >> p ;
	FOR(i,1,n)g[i].clear();
	FOR(i,1,k)
	{
		int l , r,  c; 
		cin>>l>>r>>c ; 
		g[r].pb({r-l+1,c}); 
	}
}	
bool check(int bit , int l ,int c )
{
	int nbit =  (bit&((1<<l)-1)); 
	return btpc(nbit)==c;
}
ll tinh(int idx ,int bit)
{
	// cout<<idx<<" "<<bitset<16>(bit)<<el;
	if(f[idx][bit]!=-1)return f[idx][bit] ; 
	if(idx==n+1)return f[idx][bit] = 1;
	f[idx][bit] = 0 ; 
	int nbit = (bit<<1); 
	nbit&=((1<<16)-1);
	bool ok = 1; 
	for(auto x : g[idx])
	{
		int l = x.l; 
		int c= x.c;
		if(!check(nbit,l,c))
		{
			ok = 0 ;
			break; 
		} 
	}
	if(ok)
	{	f[idx][bit]+=tinh(idx+1,nbit);
		f[idx][bit]=min((ll)1e18,f[idx][bit]);	
	}
	ok =1 ; 
	nbit|=1;
	for(auto x : g[idx])
	{
		int l =x.l ; 
		int c= x.c; 
		if(!check(nbit,l,c))
		{
			ok = 0 ;
			break; 
		} 
	}
	if(ok)
	{
		f[idx][bit]+=tinh(idx+1,nbit) ;
		f[idx][bit]=min((ll)1e18,f[idx][bit]);
	}
	return f[idx][bit] ;
}
void solve()
{
	memset(f,-1,sizeof(f)) ;
	ll tmp = tinh(1,0); 
	FOR(i,1,n)FOR(j,0,(1<<16)-1)if(f[i][j]==-1)f[i][j]=0;
	int bit = 0 ; 
	// --p;
	for(int i=1;i<=n;i++)
	{
		// cout<<p<<" BIT: ";
		int nbit =(bit<<1) ; 
		nbit&=((1<<16)-1);

		if(f[i+1][nbit]>=p)
		{
			cout<<0;
			bit=nbit;
		}
		else 
		{
			p-=f[i+1][nbit];
			nbit|=1;
			bit=nbit;
			cout<<1;  
		}
		// cout<<el;
	}
	cout<<el;
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