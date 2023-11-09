#define TASK "RIDER"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
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
const int N =1e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct pt 
{
	ll x, y  ;
	pt operator - (const pt&a)const
	{
		return pt{x-a.x,y-a.y} ; 
	}
	ll operator * (const pt&a)const
	{
		return x*a.y-y*a.x;  
	}
}; 
ll ccw(pt a, pt b , pt c)
{
	return (b-a)*(c-b) ; 
}
ll dis_2(pt a , pt b )
{
	return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
db dis(pt a , pt b)
{
	return sqrt(dis_2(a,b)); 
}
int m , n ; 
ll a[N] ;
ll t[N] ; 
ve<pt>p; 
void read()
{
	cin>> m ; 
	FOR(i,1,m )cin>>a[i],p.pb({i,a[i]}); 
	cin>> n; 
	FOR(i,1,n)cin>>t[i] ; 
}
bool cmp1(pt a, pt b)
{
	return (a.x<b.x)||(a.x==b.x&&a.y<b.y) ; 
}
pt goc ; 
bool cmp2(pt a, pt b)	
{
	if(ccw(goc,a,b)==0)return dis(goc,a)<dis(goc,b) ; 
	return ccw(goc,a,b)>0 ;
}
ve<pt>convexhull(ve<pt>p)
{  
	sort(all(p),cmp1) ; 
	goc = p[0] ; 
	sort(p.begin()+1,p.end(),cmp2); 
	p.pb(goc) ;
	ve<pt>q ; 
	for(int i = 0 ;i<p.size();i++)
	{	
		while(q.size()>=2&&ccw(q[q.size()-2],q[q.size()-1],p[i])<=0)q.pk() ;
		q.pb(p[i]) ; 
	}
	q.pk() ;
	return q ;  
}
int tangent(ll x ,ve<pt>&p )
{
	int ans = 0 ; 
	int l = 0; 
	int r = p.size()-1; 
	pt tmp = {0,x} ; 
	while(l<=r)
	{
		int mid =(l+r)/2;
		if(ccw(tmp,p[mid],p[mid+1])<=0)
		{
			ans=mid ; 
			r=mid-1; 
		}
		else
		{
			l=mid+1; 
		}
	}
	return ans ; 
}
void solve()	
{
	p.pb({1,-1});
	p.pb({n,-1});
	ve<pt>hull = convexhull(p) ; 
	reverse(all(hull));
	for(int i= 1;i<=n;i++)
	{
		int idx = tangent(t[i],hull);
		ll x = hull[idx].x ; 
		ll y = hull[idx].y;
		y-=t[i];
		cout<<x/gcd(x,y)<<" "<<y/gcd(x,y)<<el; 
	} 
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