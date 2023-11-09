/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  
#include<bits/stdc++.h>
using namespace std; 


#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n; 
int a[N] , b[N] ; 

void doc()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n)cin>>b[i] ; 
}
namespace sub1
{
	ll f[N] ; 
    void xuly()
    {
    	f[1] = b[1] ;
    	FOR(i,2,n)
    	{
    		f[i] = inf ; 
    		FOR(j,1,i-1)
    		{
    			mini(f[i],f[j]+1LL*(a[i]-1)*b[j]+b[i]);
    		}
    	}
    	cout<<f[n] ; 
    }
}
namespace sub2
{
	struct line
	{
		ll a, b ; 
		line()
		{
			a=0 ; 
			b=inf ; 
		}
		line(ll _a , ll _b)
		{
			a=_a ; 
			b=_b ; 
		}
		ll operator()(ll x)
		{
			return a*x+b; 
		}
	}; 
	line st[4*N]; 
	ll VAL[N] ;
	void up(int id ,int l , int r , line L)
	{
		if(l==r)
		{
			if(st[id](VAL[l])>L(VAL[l]))swap(st[id],L) ; 
			return ; 
		}
		int mid= (l+r)/2 ;
		if(st[id].a>L.a)swap(st[id],L) ;
		if(st[id](VAL[mid])>L(VAL[mid]))
		{
			swap(st[id],L) ; 
			up(id*2+1,mid+1,r,L) ; 
		}
		else
		{
			up(id*2,l,mid,L) ; 
		}
	}	
	ll get(int id , int l ,int r ,int pos )
	{
		if(l==r)
		{
			return st[id](VAL[pos]) ;
		}
		int mid=(l+r)/2 ; 
		if(pos<=mid)
		{ 
			return min(st[id](VAL[pos]),get(id*2,l,mid,pos)) ;
 		}
		return min(st[id](VAL[pos]),get(id*2+1,mid+1,r,pos)) ; 
	}
	vi V; 
	ll f[N] ; 
	void xuly()
	{
		FOR(i,1,n)
		{	
			V.pb(a[i]-1) ; 
		}
		uni(V) ; 
		int MAX = V.size() ; 
		FOR(i,1,MAX)
		{
			VAL[i] = V[i-1] ; 
		}
		up(1,1,MAX,line(b[1],b[1])) ; 
		FOR(i,2,n)
		{
			int pos = LB(VAL+1,VAL+MAX+1,a[i]-1)-VAL ; 
			f[i] = b[i]+get(1,1,MAX,pos); 
			up(1,1,MAX,line(b[i],f[i])); 
		}
		cout<<f[n] ; 
	} 
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}