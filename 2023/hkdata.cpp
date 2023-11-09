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
#define          SZ(_)  (int)(_.size())
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , q ;
int a[N] ;

void doc()
{
    cin>> n >> q ;
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	struct DL
	{
		ll premi , sufmi , prema , sufma ,sum ,resmi , resma ; 
		DL(){}
		DL(ll _premi, ll _sufmi , ll _prema , ll _sufma , ll _sum , ll _resmi , ll _resma)
		{
			premi = _premi ; 
			sufmi = _sufmi ; 
			prema = _prema ;  
			sufma = _sufma ; 
			sum   = _sum ; 
			resmi = _resmi ; 
			resma = _resma ;
		}
		DL(int val)
		{
			premi = min(0,val) ;
			sufmi = min(0,val) ;  
			prema = max(0,val) ; 
			sufma = max(0,val) ;
			sum   = val; 
			resmi = min(0,val) ; 
			resma = max(0,val) ; 
		}
	} ; 
	DL st[4*N] ;
	DL merge(DL L , DL R ) 
	{	
		ll premi = min(L.premi,L.sum+R.premi) ; 
		ll sufmi = min(R.sufmi,R.sum+L.sufmi) ; 

		ll prema = max(L.prema,L.sum+R.prema) ; 
		ll sufma = max(R.sufma,R.sum+L.sufma) ; 

		ll sum = L.sum+R.sum ;

		ll resmi = min({L.resmi,R.resmi,L.sufmi+R.premi}) ;
		ll resma = max({L.resma,R.resma,L.sufma+R.prema}) ;
		return DL{premi,sufmi,prema,sufma,sum,resmi,resma};  
	}
	void build(int id ,int l ,int r)
	{
		if(l==r)
		{
			st[id] = DL(a[l]) ;  
			return ;
		}
		int mid = (l+r)/2 ;
		build(id*2,l,mid)  ;
		build(id*2+1,mid+1,r) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ; 
	}
	void up(int id ,int l ,int r , int pos , int val)
	{
		if(l==r&&l==pos)
		{
			st[id]= DL(val) ;  
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid =(l+r)/2 ; 
		up(id*2,l,mid,pos,val) ; 
		up(id*2+1,mid+1,r,pos,val) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ;
	}
    void xuly()
    {
        build(1,1,n) ; 
    	while(q--)
    	{
    		int l,r,k ; cin>>l>>r>>k ;
    		// if(r-l>20)abort() ; 
    		FOR(i,l,r)
    		{
    			up(1,1,n,i,a[i]+k) ; 
    		}
    		cout<<max(st[1].resma,abs(st[1].resmi))<<el; 
    		FOR(i,l,r)
    		{
    			up(1,1,n,i,a[i]) ; 
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
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
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}