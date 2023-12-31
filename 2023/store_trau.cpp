/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "store"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct Query
{
	int TYPE , pos ; 
	ll val; 
}; 

int n ,q ; 
int a[N] ; 
Query Q[N]; 
void doc()
{
 	cin>> n ; 
 	FOR(i,1,n)cin>>a[i] ;   
 	cin>>q; 
 	FOR(i,1,q)
 	{
 		cin>>Q[i].TYPE>>Q[i].pos>>Q[i].val; 
 	}
}

namespace sub1
{
    void xuly()
    {

        FOR(_,1,q)
        {
        	int TYPE = Q[_].TYPE; 
        	int pos =Q[_].pos ;
        	ll val =Q[_].val; 
        	if(TYPE==1)
        	{
        		FOR(i,1,pos)maxi(a[i],val) ;
        	}
        	else
        	{
        		int res= 0 ;
        		FOR(i,pos,n)if(val>=a[i])res++,val-=a[i];
        		cout<<res<<el;
        	}
        }
    }
}
bool OK3()
{
	FOR(i,2,q)
	{
		if(Q[i].TYPE<Q[i-1].TYPE)return 0 ;
	}
	return 1 ;
}
namespace sub3
{
	int ma[N] ;
	ll bit[N] ;
	ll s[N] ; 
	void xuly()
	{
		FOR(i,1,q)
		{
			int TYPE = Q[i].TYPE  ; 
        	int pos =Q[i].pos ;
        	ll val =Q[i].val; 	
        	if(TYPE==1)
        	{
        		maxi(ma[pos],val) ; 
        	}
		}
		FORD(i,n,1)
		{
			maxi(ma[i],ma[i+1]) ; 
			maxi(a[i],ma[i]) ;
		}
		FOR(i,1,n)
		{
			s[i] =s[i-1]+a[i] ; 
		}
		FOR(i,1,q)
		{
			int TYPE = Q[i].TYPE  ; 
        	int pos = Q[i].pos ;
        	ll val = Q[i].val;
        	if(TYPE==1)continue ; 
        	int st  = pos; 
        	int res = 0 ; 
        	while(1)
        	{
        		int l = st ; 
        		int r = n ;
        		int ans = n+1 ;
        		while(l<=r)
        		{
        			int mid =(l+r)/2 ;
        			if(a[mid]<=val)ans=mid,r=mid-1; 
        			else l=mid+1; 
        		}
        		if(ans==n+1)break; 
        		l = ans; 
        		r = n ;
        		int tmp = ans;
        		while(l<=r)
        		{
        			int mid=(l+r)/2; 
        			if(s[mid]-s[ans-1]<=val)tmp = mid ,l=mid+1 ;
        			else r=mid-1  ;
        		}
        		res+=(tmp-ans+1) ; 
        		val-=s[tmp]-s[ans-1];
        		st = tmp+1;
        	}
        	cout<<res<<el;
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
        // sub1::xuly() ; 
        if(OK3())sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}