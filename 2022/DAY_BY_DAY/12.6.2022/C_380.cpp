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
const int N =1e6+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct DL
{
	int len ; 
	int a , b ; 
};
str s ; 
int n; 
DL st[4*N] ;
void read()
{
	s ; cin>>s ; 
	n = s.size() ;
	s=' '+s;  
}
DL join(DL b ,DL c)
{
	int u = min(b.a,c.b) ; 
	int len =  b.len+c.len+2*u;
	int na = b.a+c.a-u ; 
	int nb = b.b+c.b-u ;
	return {len,na,nb};  
}
void build(int id , int l , int r )
{		
	if(l==r)
	{
		if(s[l]==')')st[id] = {0,0,1} ; 
		else st[id] ={0,1,0} ;
		return  ;  
	}
	int mid =(l+r)/2; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] = join(st[id*2],st[id*2+1]) ; 
}
DL get(int id , int l , int r ,int t, int p )
{
	if(t<=l&&r<=p)return st[id];  
	if(r<t||p<l)return {0,0,0};
	int mid =(l+r)/2; 
	return join(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
}
void solve()
{
	build(1,1,n);
	int q; cin>>q; 
	while(q--)
	{
		int l ,r  ;cin>>l>>r ;
		DL ans = get(1,1,n,l,r) ;
		cout<<ans.len<<el;
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