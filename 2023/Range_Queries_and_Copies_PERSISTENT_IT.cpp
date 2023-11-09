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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 2e5+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

struct DL  
{
	int L , R ; 
	ll sum ; 
} ; 
int n ,q ; 
int a[N] ;
int Head[N] ;  
DL st[4*N+N*25] ; 
int node = 0 ,root =  0 ; 
void doc()
{
    cin>> n >> q ; 
    FOR(i,1,n)cin>>a[i] ; 
}       
int build(int l ,int r )
{
	++node; 
	int cur = node ; 
	if(l==r)
	{
		st[cur]={-1,-1,a[l]}; 
		return cur  ; 
	}	
	int mid=(l+r)/2 ; 
	st[cur].L=build(l,mid) ; 
	st[cur].R=build(mid+1,r) ; 
	st[cur].sum=st[st[cur].L].sum+st[st[cur].R].sum; 
	return cur ; 
}
int update(int old ,int l ,int r, int pos , ll val )
{
	++node ; 
	int cur = node ; 
	if(l==r&&l==pos)
	{
		st[cur] = {-1,-1,val} ; 
		return cur ;
	}
	int mid=(l+r)/2 ; 
	if(pos<=mid)
	{
		st[cur].R=st[old].R ; 
		st[cur].L=update(st[old].L,l,mid,pos,val) ; 	
	}
	else
	{
		st[cur].L=st[old].L  ; 
		st[cur].R=update(st[old].R,mid+1,r,pos,val) ; 
	}
	st[cur].sum=st[st[cur].L].sum+st[st[cur].R].sum ; 
	return cur ; 
}
ll get(int id ,int l, int r, int t, int p )
{
	if(t<=l&&r<=p)return st[id].sum ;
	if(r<t||p<l)return 0 ;
	int mid=(l+r)/2; 
	return get(st[id].L,l,mid,t,p)+get(st[id].R,mid+1,r,t,p); 
}
void xuly()
{	   
	Head[++root]=build(1,n) ; 
	while(q--)
	{
		int T ; cin>>T ; 
		if(T==1)
		{
			int k , pos ; ll val ; cin>>k>>pos>>val; 
			Head[k]=update(Head[k],1,n,pos,val) ; 
		}
		else if(T==2)
		{
			int k , L , R ; 
			cin>>k>>L>>R ; 
			cout<<get(Head[k],1,n,L,R)<<el; 
		}
		else
		{		
			int k ; cin>> k; 
			Head[++root]=Head[k]  ; 
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