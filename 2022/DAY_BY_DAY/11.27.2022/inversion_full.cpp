#define TASK "inversion"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define int long long
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
const int N =1e6+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n  ; 
ll m ; 
ll mu[N] ;

void read()
{
	cin>> n >> m; 
	ll res=0 ; 
	for(ll i= 1;i<=n;i++)
	{
		if((n-i-1)*(n-i)/2<m)
		{
			ll cl = n-i+1; 
			ll x=  m - (cl-2)*(cl-1)/2+i;
			res+=mu[i-1]*x;
			int p=i+1; 
			// cout<<x<s<" ";
			for(int j = n;j>=x+1;j--,p++)
			{
				res+=mu[p-1]*j;
				res%=sm; 
			}
			for(int j = x-1;j>=i;j--,p++)
			{
				res+=mu[p-1]*j;
				res%=sm; 
			}
			break; 
		}
		else res+=mu[i-1]*i;
		res%=sm;
	}
	cout<<res<<el;
}

void solve()
{

}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    mu[0] = 1;  
    FOR(i,1,1e6)mu[i] = mu[i-1]*2%sm;
    while(test--)
    {
        read(); 
        solve();
    }
}