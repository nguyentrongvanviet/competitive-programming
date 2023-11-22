/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "IV"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
int a[N] ; 

void doc()
{
    cin>> n >> m ; 
    FOR(i,1,n)cin>>a[i] ; 
    sort(a+1,a+n+1,greater<int>()) ; 
}

namespace sub1
{
    void xuly()
    {
    	ll res = 0 ;  
    	FOR(i,1,m)
    	{
    		char x ; cin>>x ; 
    		int TYPE ; cin >>TYPE;  
    		if(TYPE==1)
    		{
    			res+=a[i] ; 
    		}
    		else res-=a[i] ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	pair<char,int>Q[N] ; 
    void xuly()
    {
    	FOR(i,1,m)
    	{
    		cin>>Q[i].fi>>Q[i].se; 
    	}
    	int pick = 0 , ban = 0 ;
    	ll res = 0 ; 
    	FOR(i,1,m)
    	{
    		pick+=(Q[i].fi=='p'&&Q[i].se==1) ; 
    		ban+=(Q[i].fi=='b'&&Q[i].se==1) ; 
    	}
    	FOR(i,1,pick)
    	{
    		res+=a[i] ; 
    	}
    	FOR(i,pick+ban+1,pick+ban+pick)
    	{
    		res-=a[i] ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub3
{
    void xuly()
    {
    	
    }
}
namespace sub4
{
    void xuly()
    {
    	
    }
}
namespace sub5
{
	const int N = 20 ; 
	int f[N][1<<N] ; 
	pair<char,int>Q[N] ;
	int tinh(int pos , int msk)	
	{
		if(pos==m+1)return 0; 
		int &d = f[pos][msk] ;
		if(d!=-oo)return d; 
		int TYPE  = Q[pos].se ; 
		char ok = Q[pos].fi;
		if(TYPE==1)
		{	
			if(ok=='b')
			{

				maxi(d,tinh(pos+1,msk)) ;

				for(int MASK = msk ; MASK;MASK-=MASK&-MASK)
				{
					int  x= ctz(MASK) ; 
					maxi(d,tinh(pos+1,msk^Mask(x))); 
				}
			}
			else
			{
				for(int MASK=msk;MASK;MASK-=MASK&-MASK)
				{
					int x = ctz(MASK)  ; 
					maxi(d,tinh(pos+1,msk^Mask(x))+a[x+1]); 
				}
			}
		}
		else
		{
			d = oo ; 
			if(ok=='b')
			{
				maxi(d,tinh(pos+1,msk)) ;
				for(int MASK = msk ; MASK;MASK-=MASK&-MASK)
				{
					int  x= ctz(MASK) ; 
					mini(d,tinh(pos+1,msk^Mask(x))); 
				}
			}
			else
			{
				for(int MASK=msk;MASK;MASK-=MASK&-MASK)
				{
					int x = ctz(MASK)  ; 
					mini(d,tinh(pos+1,msk^Mask(x))-a[x+1]); 
				}
			}
		}
		return d;  
	}
    void xuly()
    {
    	FOR(i,1,m)
    	{
    		cin>>Q[i].fi>>Q[i].se ; 
    	}
    	mini(n,23) ; 
    	FORN(msk,0,Mask(n))
    	{
    		FOR(pos,1,m)f[pos][msk] = -oo ;  	
    	}
    	cout<<tinh(1,Mask(n)-1)<<el;
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
    int sub ; cin>>sub ; 
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(sub==1)sub1::xuly() ;
        else if(sub==2)sub2::xuly() ;  
        else sub5::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}