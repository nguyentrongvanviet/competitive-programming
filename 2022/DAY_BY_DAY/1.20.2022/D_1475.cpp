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
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , m , p ;
ll T  ; 
ll a[N] ; 
ll b[N] , c[N] ; 
void doc()
{
	cin>> n >>T ; 
	FOR(i,1,n)cin>>a[i] ;
	m = 0 ; p  =0 ;
	FOR(i,1,n)
	{
		cin>>b[i] ;
		if(b[i]==1)
		{
			b[++m] =  a[i] ; 
		}
		else	
		{
			c[++p] = a[i] ; 
		}
	}
}
bool check(int val)
{
	ll ans= 0 ;
	FOR(i,0,min(m,val))
	{
		int cl = val-i ; 
		if(cl/2<=p)
		{
			ans= max(ans,b[i]+c[cl/2]);
		}
	}
	return ans>=T;
}
int tknp()
{
	int l = 1; 
	int r = m+2*p; 
	int ans= -1;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid))ans=mid , r= mid-1 ; 
		else l=mid+1; 
	}
	return ans ;
}
void xuly()
{
	sort(b+1,b+m+1,greater<ll>()) ; 
	sort(c+1,c+p+1,greater<ll>()) ; 
	FOR(i,1,m)b[i] = b[i-1]+b[i] ; 
	FOR(i,1,p)c[i] = c[i-1]+c[i] ; 
	int res =tknp() ; 
	cout<<res<<el;
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