#define TASK "HELVES"
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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ,  m  ; 
int a[N] , b[N] ;
void read()
{
	cin>> n >>m ;
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)cin>>b[i] ; 
	sort(a+1,a+n+1) ; 
	sort(b+1,b+m+1) ; 
}	
bool check(int k)
{
	int it = 1; 
	for(int i= 1 ;i<=n;i++)
	{
		if(b[it]<a[i]&&a[i]<b[m-k+it])++it ; 
		if(it==k+1)return 1 ; 
	}
	return 0 ; 
}
int tknp()
{
	int l =1; 
	int r = min(n,m/2); 
	int ans= 0  ;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid))ans=mid,l=mid+1 ;
		else r=mid-1; 
	}
	return ans;
}
void solve()
{	
	int res = tknp() ; 
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