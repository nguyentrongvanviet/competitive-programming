/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "FFORG"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N = (int)2e5 + 5 , oo = 2e9 , LO = 17 , CH = 26 ; 
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 

	
int n ; 
ll c[N] ;
int L[N] , P[N] ; 

void doc()
{
    cin>> n ;  
    FOR(i,1,n)
    {
    	int x , y;  cin>>x>>y; 
    	c[i] = x-y;
    	cin>>L[i]>>P[i] ; 
    }
}

namespace sub1
{
	ll st[4*N] ; 
	void up(int id ,int l ,int r ,int pos ,ll val)
	{
		if(l==r&&l==pos)return void(st[id]=val) ; 
		if(r<pos||pos<l)return ; 
		int mid = (l+r)>>1 ;
		up(id<<1,l,mid,pos,val) ; 
		up(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}
	ll get(int id ,int l ,int r ,int t ,int p )
	{
		if(t<=l&&r<=p)return st[id] ;
		if(r<t||p<l)return -inf ;
		int mid = (l+r)>>1 ;
		return max(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
	}
	ll f[N] ; 
    void xuly()
    {
    	FOR(i,1,4*n)st[i] = -inf ;
    	f[1] = c[1] ; 
    	up(1,1,n,1,f[1]+1) ;
    	FOR(i,2,n) 
    	{
    		ll X = get(1,1,n,i-L[i],i-P[i]-1) - i ; 

    		ll Y  = get(1,1,n,i-min(P[i],L[i]),i-1) - i ;
    		if(Y>=0)
    		{
    			Y+=c[i] ; 
    		}
    		maxi(X,Y) ;
    		f[i] = X ; 
    		if(X>=0)
    		{
    			up(1,1,n,i,f[i]+i) ; 
    		}
    	}
    	// prt(f,n) ;
    	cout<<*max_element(f+1,f+n+1) ; 	
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}