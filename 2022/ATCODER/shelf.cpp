#define TASK "shelf"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define int long long 
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
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct DL
{
	int l , r,  y; 
	bool operator<(const DL&a)const
	{
		return y<a.y ; 
	}
}a[N] ; 
int n , m ; 
vi value  ; 
int lazy[8*N] ;
int st[8*N]; 
ll res =0 ; 
unordered_map<int,int>pos;
void read()
{
	cin>> n;  
	FOR(i,1,n)cin>>a[i].l>>a[i].r>>a[i].y,value.pb(a[i].l),value.pb(a[i].r);  
} 
void dolazy(int id )
{
	if(lazy[id]==-1)return ; 
	st[id] =  lazy[id] ;
	lazy[id*2]=lazy[id] ; 
	lazy[id*2+1]=lazy[id] ;
	lazy[id] = -1;  
}
// max 
void up(int id ,int l , int r, int t, int p , int val)
{
	dolazy(id) ; 
	if(t<=l&&r<=p)
	{
		lazy[id] =val;  
		dolazy(id) ;
		return ;  
	}
	if(r<t||p<l)return ; 
	int mid =(l+r)/2 ; 
	up(id*2,l,mid,t,p,val) ; 
	up(id*2+1,mid+1,r,t,p,val) ; 
	st[id] =max(st[id*2],st[id*2+1]) ;
}
int get(int id , int l, int r, int pos )
{
	dolazy(id) ; 
	if(l==pos&&r==pos)	
	{
		return st[id] ; 
	}
	if(r<pos||pos<l)return  0; 
	int mid =(l+r)/2; 
	return max(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos)); 
}
void solve() 
{
	sort(all(value));
	value.resize(unique(all(value))-value.begin()) ;
	int m = value.size() ; 
	FOR(i,1,m)pos[value[i-1]]= i ; 
	FOR(i,1,8*m)lazy[i]=-1;  
	sort(a+1,a+n+1) ; 
	int j= 1; 
	FOR(i,1,n)
	{
		res+=a[i].y-get(1,1,m,pos[a[i].l]); 
		// cout<<get(1,1,m,pos[a[i].l])<<" ";
		res+=a[i].y-get(1,1,m,pos[a[i].r]);
		// cout<<get(1,1,m,pos[a[i].r])<<el;
		up(1,1,m,pos[a[i].l],pos[a[i].r],a[i].y);
		// cout<<res<<el;
	}	
	cout<<res;
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