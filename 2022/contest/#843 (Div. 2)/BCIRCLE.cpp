#define TASK "BCIRCLE"
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
	ll x ,y;
	pt operator - (const pt&a)const
	{
		return pt{x-a.x,y-a.y}; 
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
ll ccw(const pt&a , const pt&b , const pt&c)
{
	return (b-a)*(c-b) ;	
}
bool cmp1(const pt&a , const pt&b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y)  ; 
}
pt goc;  
bool cmp2(const pt&a, const pt&b)
{
	if(ccw(goc,a,b)==0)
	{
		return dis(goc,a)<dis(goc,b) ; 
	}
	return ccw(goc,a,b)>0 ; 
}
int n ; 
ve<pt>q;
void read()
{
	cin>> n; 
	FOR(i,1,n)
	{
		db x, y ; 
		cin>>x>>y ; 
		q.pb({(ll)(x*100),(ll)(y*100)});  
	}
}

void solve()
{
	sort(all(q),cmp1) ; 
	sort(q.begin()+1,q.end(),cmp2) ;
	q.pb(q[0]); 
	ll res= inf  ;
	for(int i=1 ;i<q.size();i++)
	{
		res=min(res,dis(q[i],q[i-1])) ; 
	} 
	db ans=(db)res/10000;
	cout<<setprecision(2)<<fixed<<round(sqrt(ans)*100)/100;
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