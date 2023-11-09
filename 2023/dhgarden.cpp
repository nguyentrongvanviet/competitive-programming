#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 1;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e1+5, oo = 2e9, LO = 17 ; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n,r;
double D;
struct DL
{
	int x,y;
};
DL new_point[N],h[N];
long long ccw(DL A, DL B, DL C){
	long long t = (B.x - A.x)*(C.y - B.y) - (C.x - B.x)*(B.y - A.y);
	if (t<0) return -1;
	if (t>0) return 1;
	return 0;
}
long long KC(DL A, DL B){
	return (pow(A.x-B.x,2) + pow(A.y-B.y,2));
}
vector<DL> g;
bool cmp(DL A, DL B){
	if (A.y==B.y) return A.x<B.x;
	return A.y<B.y;
}
bool cmp1(DL A, DL B){
	if (ccw(new_point[1],A,B) ==0) return (KC(new_point[1],A)<KC(new_point[1],B));
	return (ccw(new_point[1], A, B) >0);
}
bool check(int x)
{
	int m = 0,cnt = 0;
	for(int i=1;i<=n;i++) 
	{
		new_point[i] = {0,0};
		h[i] = {0,0};
	}
	for(int i=0;i<n;i++)
	{
		if(x>>i&1)
		{
			new_point[++m] = g[i];
		}
	}
	sort(new_point + 1,new_point + m + 1,cmp);
	sort(new_point + 1,new_point + m + 1,cmp1);
	new_point[m+1] = new_point[1];
	h[1] = new_point[1];
	h[2] = new_point[2];
	cnt = 2;
	for(int i=3;i<=m+1;i++)
	{
		while(cnt >= 2&& !(ccw(h[cnt - 1],h[cnt],new_point[i]) > 0)) cnt--;
		h[++cnt] = new_point[i];
	}
	cnt--;
	h[cnt+1] = h[1];
	if(cnt < 3)
	{
		double s = 2*sqrt(KC(new_point[1],new_point[m]));
		s+=2*PI*r;
		return (D >= s);
	}
	else
	{
		double s = 0;
		for(int i=1;i<=cnt;i++)
		{
			s += sqrt(KC(h[i],h[i+1]));
		}
		s+=1.0*2*PI*r;
		return (D >= s);		
	}
	return 0;
}
void doc()
{
	cin>>D>>n>>r;
	g.clear();
	for(int i=1;i<=n;i++)
	{
		int x,y; cin>>x>>y;
		g.pb({x,y});
	}
}

void xuly()
{
	int res = 0 ;
	for(int i=1;i<((1<<n));i++)
	{
		if(check(i)) maxi(res,1LL*__builtin_popcount(i));
	}	
	cout<<res<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}