#define TASK "DIST"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll int
#define db long double
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
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
// const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct Pt 
{
	ll x, y;  
	int id;  
	bool operator<(const Pt&a)const
	{
		return x<a.x;  
	}
};
bool cmp(pll a , pll b )
{
	return a.fi<b.fi ; 
}
int n  ; 
Pt a[N] ;
ll k ;  
int bit[N] ; 
pii b[N] ; 
int pos[N] ,value[N] ;
void read()
{
	cin>> n >> k; 
	FOR(i,1,n)cin>>a[i].x>>a[i].y,a[i].id=i,b[i]={a[i].y,i}; 
}
void up(int idx , int val)
{
	for(int i =idx;i<=n;i+=i&-i)bit[i]+=val; 
}
ll get(int  l ,int r )
{
	ll val = 0; 
	for(int i=r ;i; i -=i&-i)val+=bit[i];  
	for(int i=l-1 ;i; i-=i&-i)val-=bit[i]; 
	return val; 
}
int check(ll val)
{
	FOR(i,1,n)up(pos[a[i].id],1);
	int j= 1 ; 
	ll ans= 0 ; 
	FOR(i,1,n)
	{
		while(a[j].x-a[i].x<=val&&j<=n)
		{	
			up(pos[a[j].id],-1) ;
			++j ;  
		} 
		int l = lower_bound(value+1,value+n+1,a[i].y-val)-value;
		int r =upper_bound(value+1,value+n+1,a[i].y+val)-value-1 ;
		ans+=(j-i-1)+get(l,r);
		// if(j-i-1+get(l,r)<0)while(1); 
		if(ans>=k)return 1; 
	}
	return ans>=k;
}
ll tknp()
{
	ll l = 0 ; 
	ll r = 2e6 ; 
	ll ans= 0; 
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			ans =mid  ; 
			r=mid-1; 
		}
		else
		{
			l=mid+1 ; 
		}
	}
	return ans; 
}
void solve()
{
	sort(a+1,a+n+1) ; 
	sort(b+1,b+n+1,cmp) ;
	FOR(i,1,n)value[i]=b[i].fi,pos[b[i].se]= i ; 
	ll res= tknp() ;
	cout<<res ; 
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}