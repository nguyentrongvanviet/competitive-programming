#define TASK "READERS"
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
#define pp cout<<"MDMDMDMDDMDMDMDMDDMDMDD"<<el;
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
	ll operator *(const pt&other)const
	{
		return x*other.y-y*other.x; 
	}
}; 
ll ccw(const pt&a , const pt&b , const pt&c)
{
	return (b-a)*(c-b) ; 
}
ll dis(const pt& a, const pt& b )
{	
	return sq(a.x-b.x)+sq(a.y-b.y);
}
bool cmp1(const pt&a ,const pt&b)
{
	return (a.x<b.x)||(a.x==b.x&&a.y<b.y) ; 
}
pt goc; 

bool cmp2(const pt&a ,const pt&b)
{
	if(ccw(goc,a,b)==0)return dis(goc,a)<dis(goc,b); 
	return ccw(goc,a,b)<=0 ; 
}
int n , m; 
ll t[N] ,c[N],s[N];		
void read()
{
	cin>> n >> m ; 
	FOR(i,1,n)cin>>t[i] ; 
	FOR(i,1,m)cin>>c[i] ; 
	FOR(i,1,n)s[i] =s[i-1]+t[i];
}
ve<pt> convexhull(vector<pt>& p)
{
	ve<pt>q; 
	sort(all(p),cmp1) ;
	goc=p[0] ; 
	sort(p.begin()+1,p.end(),cmp2);
	for(int i= 0 ;i<p.size();i++)
	{	
		while(q.size()>=2&&ccw(q[q.size()-2],q[q.size()-1],p[i])>=0)q.pk() ;
		q.pb(p[i]);  
	} 	
	return q; 
}
ll tknp(pt x , ve<pt>&hull)
{
	int ans =0;
	int l = 1;
	int r= hull.size()-1;
	while(l<=r)
	{
		int mid = (l+r)/2; 
		if(x*(hull[mid]-hull[mid-1])>=0)
		{
			ans= mid ; 
			l=mid+1;  
		}
		else
		{
			r=mid-1;
		}
	}
	return max(0LL,x*hull[ans]);
}

void solve()
{
	ve<pt> p ;
	
	FOR(i,1,n) p.pb({s[i-1],s[i]}) ;
	p.pb({(ll)2e9,0});
	ve<pt> hull = convexhull(p) ;
	hull.pk();
	ll res= 0 ; 
	FOR(i,2,m)
	{	
		res+=tknp(pt{c[i-1],c[i]},hull);
	}
	cout<<res+c[m]*s[n];
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