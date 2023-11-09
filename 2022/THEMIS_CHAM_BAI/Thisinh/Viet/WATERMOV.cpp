#define TASK "WATERMOV"
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
const int N =1e6+5 ,   CH = 26 ;
const ll oo = 1e12 ; 
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct pt 
{
	ll x,  y;
	pt operator -(const pt&a)const
	{
		return pt{x-a.x,y-a.y} ;
	} 
	ll operator *(const pt&a)const
	{
		return x*a.y-y*a.x; 
	}
};
ll dis(const pt&a , const pt&b)
{
	return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
int n ; 
ll a[N] ; 
ve<pt>p ; 
void read()
{
	cin>> n ; 
	p.pb({0,oo});
	p.pb({0,0});
	FOR(i,1,n)
	{
		cin>>a[i];
		a[i]+=a[i-1] ; 
		p.pb({i,a[i]});  
	}

}
ll area(ve<pt>p) 
{
	ll ans = 0 ;	
	for(int i= 0;i<p.size()-1;i++)ans+=(p[i]*p[i+1]);
	ans+=(p.back()*p[0]);
	return abs(ans); 
}
ll ccw( pt a, pt b, pt c)
{
	return (b-a)*(c-b);  
}
bool cmp1(pt a , pt  b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y) ; 
}
pt tmp ; 
bool cmp2(pt a , pt b)
{  
	if(ccw(tmp,a,b)==0)return dis(a,tmp)<dis(b,tmp) ;
	return ccw(tmp,a,b)>0;
}
ve<pt> convexhull(ve<pt>&p )
{
	sort(all(p),cmp1) ;
	tmp = p[0] ;  
	sort(p.begin()+1,p.end(),cmp2);
	p.pb(p[0]);		
	ve<pt>q;
	for(int i= 0 ;i<p.size();i++)
	{	
		while(q.size()>=2&&ccw(q[q.size()-2],q[q.size()-1],p[i])<=0)q.pk() ;
		q.pb(p[i]) ;
	}
	q.pk();
	p.pk();
	return q; 
}	
void solve()
{		
	ll  x = area(p) ; 
	ve<pt> hull = convexhull(p); 
	ll res = area(hull)-x ; 
	cout<<res/2 ; 
	if(res&1)cout<<".5"; 
	else cout<<".0";
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