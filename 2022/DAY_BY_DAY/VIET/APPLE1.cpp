#define TASK "text"
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
struct pt 
{
	ll x , y;  
	pt operator - (const pt& other)const
	{
		return pt{x-other.x,y-other.y}; 
	}
	ll operator * (const pt &other)const
	{
		return x*other.y-y*other.x;
	}
}; 
ll ccw(pt a, pt b , pt c)
{
	return abs((b-a)*(c-b));
}
int n;
pt x[N] ; 
bool check(pt p )
{
	ll area = ccw(x[1],x[2],x[3]) ;
	ll ans = 0 ;  
	for(int i= 1;i<=3;i++)
	{	
		ans+=ccw(x[i],x[i+1],p);
	}	
	return area== ans; 
}
void read()
{
	FOR(i,1,3)cin>>x[i].x>>x[i].y; 
	x[4] =x[1] ; 
	cin>> n  ;
	int cnt= 0 ;	 
	for(int i= 1;i<=n;i++)
	{
		pt z;  cin>>z.x>>z.y ; 
		if(check(z))cnt++ ;
	}
	ll area = ccw(x[1],x[2],x[3]) ; 
	if(area%2==0)cout<<area/2<<".0"<<el;
	else cout<<area/2<<".5"<<el;
	cout<<cnt;
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