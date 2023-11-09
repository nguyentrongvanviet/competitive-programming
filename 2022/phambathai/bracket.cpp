#define TASK "BRCNT2"
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
const int N =1e7+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ; 
int a[N] ;
ll mu[N] , fac[N] , inv_fac[N];
void read()
{
	cin>> n ; 
	FOR(i,1,n)
	{
		char x;  cin>>x ; 
		if(x=='(') a[i] =1 ; 
		if(x=='[') a[i] =2 ; 
		if(x=='{') a[i] =3 ;  
		if(x==')') a[i] =4 ;
		if(x==']') a[i] =5 ;
		if(x=='}') a[i] =6 ;
	}
}
ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  
	else return b*b%sm;
}

void buildpow()
{
	mu[0] = 1 ; 
	fac[0] = 1 ;  
	inv_fac[0] = 1 ; 
	FOR(i,1,n)
	{
		mu[i] = mu[i-1]*3%sm ; 	
		fac[i] = fac[i-1]*i%sm;
		inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm;
	}	
}
ll C(int  k , int n )
{
	if(k>n)return 0 ; 
	return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
}
ll tinh(int h1 , int h2 , int n)
{
	int u = abs(h1-h2) ; 
	int a= (n+u)/2 ; 
	if((n+u)%2==0&&n-a>=0)
	{
		return C(a,n);
	}
	return 0 ; 
}
ll Ca(int h1 , int h2 , int n)
{
	return (tinh(h1,h2,n)-tinh(h1,-2-h2,n)+sm)%sm;
}
void solve()
{	
	buildpow();
	int s= 0  ;
	ll res=0 ; 
	FOR(i,1,n)
	{
		int u = min(4,a[i]);
		int ns =s+1;
		if((n-i-ns)%2==0)
		{
			res+=mu[(n-i-ns)/2]*Ca(ns,0,n-i)*(u-1)%sm;
		}
		res%=sm ;
		if(a[i]<=3)s++ ; 
		else s--;
	}
	res= (res+1)%sm ; 
	cout<<res;
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