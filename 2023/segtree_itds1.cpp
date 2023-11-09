#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
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
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 1e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n , q ; 
int a[N] ;
multiset<int>st[4*N] ;  
void doc()
{
    cin>>n>>q;
    FOR(i,1,n)cin>>a[i] ; 
}       
void build(int id, int l, int r)
{
	if(l==r)
	{
		st[id].insert(a[l]) ; 
		return ; 
	}
	int mid =(l+r)/2 ; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ;
	for(auto x : st[id*2])st[id].insert(x) ;  
	for(auto x : st[id*2+1])st[id].insert(x) ; 
}
void update(int id, int l ,int r, int pos , int val)
{
	if(l==r&&l==pos)
	{
		st[id].clear();
		st[id].insert(val); 
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid = (l+r)/2; 
	if(pos<=mid)
	{
		update(id*2,l,mid,pos,val) ; 
		st[id].erase(st[id].find(a[pos])) ;
		st[id].insert(val) ; 
	}
	else 
	{
		update(id*2+1,mid+1,r,pos,val) ; 
		st[id].erase(st[id].find(a[pos])) ;
		st[id].insert(val) ; 
	}
}
int get(int id ,int l, int r ,int t,int p ,int val)
{
	if(r<t||p<l)return oo ; 
	if(t<=l&&r<=p)
	{
		auto it = st[id].lower_bound(val)  ; 
		if(it!=st[id].end())return *it ; 
		return oo;
	}
	int mid =(l+r)/2; 
	return min(get(id*2,l,mid,t,p,val),get(id*2+1,mid+1,r,t,p,val)) ; 
}	
void xuly()
{
	build(1,1,n) ; 
    FOR(i,1,q)
    {
    	int t ; cin>>t ;
    	if(t==1)
    	{
    		int pos , val; cin>>pos>>val; 
    		update(1,1,n,pos,val) ; 
    		a[pos]=val;
    	}
    	else
    	{
    		int l,r,val; 
    		cin>>l>>r>>val; 
    		int res=get(1,1,n,l,r,val) ; 
    		if(res==oo)cout<<-1<<el; 
    		else cout<<res<<el;
    	}
    }
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