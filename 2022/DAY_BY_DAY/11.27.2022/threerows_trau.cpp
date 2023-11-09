#define TASK "threerows"
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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
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

struct DL
{
	int l , r; 
	ll w;  
}; 
int n , m ; 
ll a[4][N] ;
ll sum[4][N] ;

DL edge[N] ;

vi g[N] ; 


ll s[N] , f[N]   ;

ll st[8*N] ; 
ll T[8*N] ; 
ll dp[N] ;
void read()
{
	cin>> n >>m ; 
	FOR(i,1,3)
	{
		FOR(j,1,n)
		{
			cin>>a[i][j]  ; 
			sum[i][j] = sum[i][j-1] + a[i][j] ; 
		}
	}
	FOR(i,1,m)
	{
		int l ,r ; ll w;  
		cin>>l>>r>>w; 
		edge[i] ={l,r,w}  ; 
		g[r].pb(i) ;
	}
	FOR(i,1,n)
	{
		s[i] = sum[1][i] - sum[2][i-1] ; 
		f[i] = sum[3][n] - sum[3][i-1] + sum[2][i] ;  
	}
}
void build(int id, int l , int r ,ll st[] , ll a[])
{
	if(l==r)
	{
		st[id] = a[l] ;
		return ; 
	}
	int mid =(l+r)/2; 
	build(id*2,l,mid,st,a) ; 
	build(id*2+1,mid+1,r,st,a) ; 
	st[id] = max(st[id*2],st[id*2+1]) ; 
}
void update(int id , int l ,int r ,int pos ,  ll val, ll st[] )
{
	if(l==r&&l==pos)
	{
		st[id]  = val ; 
		return ; 
	}
	if(r<pos||pos<l)return ;
	int mid=(l+r)/2; 
	update(id*2,l,mid,pos,val,st) ; 
	update(id*2+1,mid+1,r,pos,val,st) ; 
	st[id] =max(st[id*2],st[id*2+1]) ;
}
ll get(int id , int l , int r , int t , int p , ll st[])
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return -inf ; 
	int mid =(l+r)/2; 
	return max(get(id*2,l,mid,t,p,st),get(id*2+1,mid+1,r,t,p,st)) ; 
}
struct Q
{
	ll s , f  ; 
	ll ma ; 
}; 
Q M[8*N ] ; 
Q merge(Q l , Q r  )
{
	return {max(l.s,r.s),max(l.f,r.f),max({l.ma,r.ma,l.s+r.f})};
}
void build2(int id, int l ,int r  )
{
	if(l==r)
	{
		M[id]  = {s[l],f[l],s[l]+f[l]};
		return ;  
	}
	int mid =(l+r)/2; 
	build2(id*2,l,mid) ; 
	build2(id*2+1,mid+1,r) ; 	
	M[id] = merge(M[id*2],M[id*2+1]);
}
Q get2(int id ,int l ,int r ,int t , int p)
{	
	if(t<=l&&r<=p)return M[id] ; 
	if(r<t||p<l)return Q{-inf,-inf,-inf};
	int mid =(l+r)/2; 
	return merge(get2(id*2,l,mid,t,p),get2(id*2+1,mid+1,r,t,p));
}
void solve()
{ 
	build(1,1,n,st,s);
	FOR(i,1,n)dp[i]  = -inf ; 
	build(1,1,n,T,dp);
	for(int i= 1;i<=n;i++)
	{
		for(auto j : g[i])
		{
			int l = edge[j].l;  
			int r =edge[j].r ; 
			ll w =edge[j].w ; 
			//alone  
			dp[i] = max(dp[i],get(1,1,n,l,r,st)-w);
			dp[i] = max(dp[i],get(1,1,n,l-1,r,T)-w);
		}
		update(1,1,n,i,dp[i],T);
	}
	for(int i= 1;i<=n;i++)s[i] = max(s[i] , dp[i]) ;
	// FOR(i,1,n)cout<<dp[i]<<" ";
	build2(1,1,n) ; 
	ll res= -inf ;
	for(int i= 1;i<=m;i++)
	{	
		int l = edge[i].l ; 
		int r = edge[i].r ; 
		ll w= edge[i].w ; 
		res= max(res,get2(1,1,n,l,r).ma-w);
		if(l-1>=1)res=max(res,dp[l-1]+get2(1,1,n,l,r).f-w);
	}
	// cout<<get2(1,1,n,3,3).f<<el;
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