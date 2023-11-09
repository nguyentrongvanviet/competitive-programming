/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "dayso"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;
int a[N] ; 
vi V ; 
map<int,ll>HASH; 
map<ll,vll>TYPE ;
vll sum ; 
ll s[N] , H[N] ;
int pos[N] ;  
void doc()
{
    cin>>n ; 
    V.pb(0);
    FOR(i,1,n)cin>>a[i],V.pb(a[i]);
    uni(V) ; 
    for(auto v : V)
    {
    	HASH[v] = rd(0,1e18); 
    }
    H[0] = 0;
    TYPE[0].pb(0);
    sum.pb(0) ; 
    FOR(i,1,n)
    {
    	H[i] = H[i-1]^HASH[a[i]] ;
    	s[i] = s[i-1]+a[i] ;
    	sum.pb(s[i]);
    	TYPE[H[i]].pb(s[i]);
    }
    uni(sum) ; 
}

namespace sub1
{
	int bit[N];
	void up(int id ,int val)
	{
		for(int i=id;i<=n+1;i+=i&-i)bit[i]+=val; 
	}
	int get(int id)
	{
		int ans = 0 ;
		for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
		return ans ; 
	}
    void xuly()
    {
    	ll res = 0 ;
    	for(auto x : TYPE)
    	{
    		vll tmp =x.se ;
    		for(auto v : tmp)
    		{
    			int t = UB(all(sum),v)-sum.begin();
    			res+=get(t-1);
    			up(t,1) ; 
    		}
    		for(auto v : tmp)
    		{
    			int t = UB(all(sum),v)-sum.begin();
    			up(t,-1) ;	
    		}
    	}
    	cout<<res<<el;
    }
}
namespace subtrau
{   
    void xuly()
    {
    	int res  = 0 ;
    	FOR(i,1,n)
    	{
    		map<int,int>cnt ;
    		int le = 0 ;  
    		ll sum = 0 ;
    		FOR(j,i,n)
	    	{
	    		cnt[a[j]]++ ; 
	    		if(cnt[a[j]]&1)le++ ;
	    		else le-- ;
	    		sum+=a[j] ; 
	    		if(le==0&&sum>0)res++ ; 
	    	}
	    }   
	    cout<<res; 
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        subtrau::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}