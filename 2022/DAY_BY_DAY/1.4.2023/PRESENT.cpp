#define TASK "PRESENT"
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
int n; 
int a[N] ,b[N] ; 
vi value; 
unordered_map<int,int>pos; 
struct DL
{
	int mi = 0 , s= 0 ;
};
DL st[4*N] ;
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i],value.pb(a[i]) ; 
	FOR(i,1,n)cin>>b[i],value.pb(b[i]) ;
}
void up(int id , int l , int r , int pos , int val )
{
	if(l==r&&l==pos)
	{
		st[id].s+=val;
		st[id].mi=st[id].s;  
		return  ; 
	}
	int mid =(l+r)/2; 
	if(pos<=mid)up(id*2,l,mid,pos,val) ; 
	else up(id*2+1,mid+1,r,pos,val) ; 
	st[id].s=st[id*2].s+st[id*2+1].s; 
	st[id].mi= min(st[id*2].mi,st[id*2].s+st[id*2+1].mi);
}
void solve()
{
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin());
	int m  = value.size() ; 
	FOR(i,1,m)	
	{
		pos[value[i-1]]= i; 
	}
	FOR(i,1,n)
	{
		a[i] = pos[a[i]] ; 
		b[i] = pos[b[i]] ;
	}
	int res= 0; 
	FOR(i,1,n)
	{
		up(1,1,m,a[i],-1);
		up(1,1,m,b[i],+1);  
		if(st[1].mi>=0)res= i ; 
	}
	cout<<res<<el;
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