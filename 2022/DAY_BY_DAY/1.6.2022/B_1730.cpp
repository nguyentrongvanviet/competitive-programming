#define TASK "B_1730"
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
const db PI = acos(-1),eps=1e-7 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n;  
db x[N] , t[N] ;
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>x[i] ; 
	FOR(i,1,n)cin>>t[i] ; 
}
db res;  
db check(db val )
{
	db l = (db)-oo ; 
	db r= (db)oo ; 
	FOR(i,1,n)
	{
		db nl = x[i] -max((db)0,val-t[i]) ; 
		db nr = x[i] +max((db)0,val-t[i]) ;
		if((r<nl&&abs(r-nl)>eps)||(nr<l&&abs(nr-l)>eps))return 0 ;
		l=max(l,nl) ; 
		r=min(r,nr) ; 
	}
	res= l ; 
	return 1 ; 
}	
void solve()
{
	db l = 0  ; 
	db r=  (db)2e8 ;
	db ans; 
	while(abs(l-r)>eps&&l<=r)
	{
		db mid= (l+r)/2; 
		if(check(mid))ans=mid,r=mid-eps;
		else l=mid+eps;
	}
	check(ans); 
	cout<<setprecision(6)<<fixed<<res<<el;
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