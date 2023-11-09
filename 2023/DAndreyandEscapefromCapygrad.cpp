/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n; 
struct DL
{
	int l, r , a ,b ;
	bool operator<(const DL&other)const
	{
		return l<other.l ; 
	}
} ; 
struct pt 
{
	int pos  , id ; 
	bool operator<(const pt&a)const
	{
		return pos>a.pos ;
	}	
} ; 
DL a[N] ; 
int f[N] ;
void doc()
{	
	cin>> n; 
	FOR(i,1,n)
	{
		cin>>a[i].l>>a[i].r>>a[i].a>>a[i].b ; 
	}
}
namespace sub1
{
	int ma[N] ; 
    void xuly()
    {
    	sort(a+1,a+n+1) ;
		ve<pt>q ;
		FOR(i,1,n)q.pb({a[i].b,i}) ;
		ma[1] = 1 ; 
    	FOR(i,2,n)
    	{
    		if(a[ma[i-1]].b<a[i].b)ma[i] = i ;
    		else ma[i] = ma[i-1] ;  
    	}     
    	int it = n ; 
    	sort(all(q)) ;
    	FOR(i,1,n)f[i] = 0 ;  
    	for(auto x : q)
    	{
    		while(it>=1&&a[it].l>x.pos)--it; 
    		f[x.id] = max(x.pos,f[ma[it]]) ; 
    		// cout<<x.pos<<" "<<f[x.id]<<el;
    	}
    	// prt(f,n) ; 
    	int Q ; 
    	cin>>Q; 
    	FOR(i,1,Q)
    	{
    		int val; cin>>val;
    		int l =1 ; 
    		int r =n ;
    		int ans= -1 ;  
    		while(l<=r)
    		{	
    			int mid = (l+r)/2;
    			if(a[mid].l<=val)ans=mid,l=mid+1; 
    			else r=mid-1; 
    		}
    		if(ans==-1)cout<<val<<" ";
    		else cout<<max(val,f[ma[ans]])<<" ";
    	}
    	cout<<el;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}