#define TASK "HOUSES"
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
const int N =1e3+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , m ; 
int a[N][N] ;
bool dd[N][N]; 
int res= 0 ;
set<ve<pii>>exist; 
ve<pii>q;
void read()
{
	cin>> n >>m ; 
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
}
bool rotate(ve<pii>&q)
{
	int mix=oo;
	int miy=oo;
	for(int i =0 ;i<q.size();i++)
	{
		int x= q[i].fi ;
		int y= q[i].se ; 
		q[i].fi=-y ;
		q[i].se= x ;
		mix=min(mix,q[i].fi) ; 
		miy=min(miy,q[i].se) ; 
	}
	mix=0-mix;
	miy=0-miy;
	for(int i = 0 ;i<q.size();i++)
	{	
		q[i].fi+=mix; 
		q[i].se+=miy; 
	}
	sort(all(q));
	// for(int i=0;i<q.size();i++)cout<<q[i].fi<<" "<<q[i].se<<" - ";
		// cout<<el;
	if(exist.find(q)!=exist.end())return 1 ; 
	return 0 ; 
}
bool dx(ve<pii>&q)
{	
	int mix= oo ; 
	int miy= oo ; 
	for(int i= 0 ;i<q.size();i++)
	{
		int x= q[i].fi ;    
		int y = q[i].se ;
		q[i].fi=-x; 
		q[i].se= y; 
		mix=min(mix,q[i].fi) ; 
		miy=min(miy,q[i].se) ; 
	}	
	mix=-mix; 
	miy=-miy;
	for(int i=0 ;i<q.size();i++)
	{
		q[i].fi+=mix; 
		q[i].se+=miy; 
	}
	sort(all(q));
	// for(int i=0;i<q.size();i++)cout<<q[i].fi<<" "<<q[i].se<<" - ";
		// cout<<el;
	if(exist.find(q)!=exist.end())return 1;  
	return 0;
}
void check(ve<pii>& q)
{	 
	for(int i= 1 ;i<=4;i++)
	{
		if(rotate(q))return ;
		// if(dx(q))return ;  
	}
	int u = dx(q) ; 
	for(int i=1;i<=4;i++)
	{
		if(rotate(q))return ;
	}
	// for(int i= 0 ;i<q.size();i++) cout<<q[i].fi<<" "<<q[i].se<<" A ";cout<<el;
	exist.insert(q) ; 
}
void dfs(int x ,int y )
{
	dd[x][y] = 1; 
	q.pb({x,y});
	FOR(i,1,4)
	{
		int nx =x+xx[i] ; 
		int ny =y+yy[i] ; 
		if(dd[nx][ny]||a[nx][ny]==0)continue; 
		dfs(nx,ny); 
	}
}
void solve()
{	
	FOR(i,1,n)FOR(j,1,m)if(dd[i][j]==0&&a[i][j]==1)
	{
		dfs(i,j) ;
		check(q) ;
		// for(auto x : q)cout<<x.fi<<" "<<x.se<<el;cout<<"_____"<<el;
		// cout<<"___________"<<el;
		// cout<<q.size()<<" ";
		// cout<<exist.size()<<" ";
		q.clear() ; 
	}
	int res = exist.size() ; 
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
/*
9 9 
1 1 1 0 1 0 0 0 1
1 0 0 0 1 1 0 1 1 
1 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0
1 0 0 1 0 0 0 0 0 
0 0 1 1 0 1 0 0 0 
1 0 0 0 0 1 0 0 1 
1 0 1 0 0 1 1 0 1 
1 1 1 1 1 0 0 1 1 

*/