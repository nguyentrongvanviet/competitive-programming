#define TASK "DRINK"
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
int n , k ; 

void read()
{
	vll xanh , sua ; 
	db res= 0 ; 
	cin>> n >> k ; 
	FOR(i,1,n)
	{
		int t   ; 
		ll val  ;
		cin>>val>>t;
		if(t==1)xanh.pb(val);
		else sua.pb(val);       
	}
	sort(all(xanh),greater<ll>());
	int x = min(k-1,(int)xanh.size()) ; 
	FORN(i,0,x)res+=(db)xanh[i]/2;
	int cl =  k-x ; 
	FORN(i,cl,xanh.size()) sua.pb(xanh[i]); 
	ll mi = inf ;  
	for(auto x : sua)
	{
		mi=min(mi,x) ; 
		res+=x ; 
	}
	cout<<res-(xanh.size()==x?0:(db)mi/2)<<el;
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