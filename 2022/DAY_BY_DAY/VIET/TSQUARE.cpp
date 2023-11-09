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
	pt operator - (const pt &other)const
	{
		return pt{x-other.x,y-other.y}; 
	}
	ll operator *(const pt&other)const
	{
		return x*other.y-y*other.x; 
	}
};
ll ccw(pt a, pt b , pt c)
{
	return (b-a)*(c-b); 
}
ll area(ve<pt>&p)
{
	p.pb(p[0]);	
	ll ans = 0; 
	for(int i=0;i<(int)p.size();i++)
	{
		ans+=(p[i]*p[(i+1)%(int)p.size()]);
	}
	return abs(ans) ;
}
ll check(pt x ,ve<pt>&a)
{
	ll tmp = 0; 
	for(int i =0 ; i<(int)a.size();i++)
	{
		tmp+=abs(ccw(a[i],a[(i+1)%(int)a.size()],x));
	}
	return tmp  ;
}
ve<pt>H1 , H2 ; 
void read()
{
	for(int i = 1;i<=4;i++)
	{
		pt a ; cin>>a.x>>a.y ;
		H1.pb(a) ; 
	}
	for(int i= 1;i<=4;i++)
	{
		pt a ; cin>>a.x>>a.y; 
		H2.pb(a) ;
	}	
	ll x = area(H1) ; 
	ll y = area(H2) ; 
	FOR(i,-100,100)FOR(j,-100,100)
	{
		ll a= (check(pt{i,j},H1)==x) ;
		ll b= (check(pt{i,j},H2)==y);
		if(a&&b)
		{
			cout<<"YES";
			return ;
		}
	}
	cout<<"NO";
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