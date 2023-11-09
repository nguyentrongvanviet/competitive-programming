/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "mixpotions"
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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e6+5 , oo = 2e9 , LO = 59 , CH = 26 ; 

int n; 	
ll k ; 
ll a[N] ; 
void doc()
{
    cin>> n >> k; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	int node = 1; 
	int T[N*(LO+1)][2] ;
	int f[N*(LO+1)] ;
	void up(ll val)
	{	
		int r= 1 ;
		FORD(i,LO,0)
		{
			int j=BIT(val,i); 
			if(T[r][j]==0)
			{
				T[r][j]=++node ; 
			}
			r=T[r][j] ; 
			f[r]++ ; 
		}
	}
	ll get(ll val, ll tmp)
	{
		ll cnt = 0 ; 
		int r=1 ; 
		FORD(i,LO,0)
		{
			int j=BIT(val,i); 
			int c=BIT(tmp,i);
			if(c==0)
			{
				r=T[r][j];
			} 
			else
			{
				cnt+=f[T[r][j]];
				r=T[r][j^1];  
			}
		}
		return cnt ; 
	}
	int check(ll tmp)
	{
		FOR(i,1,node)
		{
			f[i] = 0 ;
		}
		ll cnt = 0; 
		FOR(i,1,n)
		{	
			cnt+=get(a[i],tmp) ; 
			up(a[i]) ;  
		}
		return (cnt<=k-1);
	}
    void xuly()
    {	
    	ll res = 0 ;
    	FOR(i,1,n)up(a[i]) ; 
    	FORD(i,LO,0)
    	{
    		if(check(res|(1ll<<i)))
    		{
    			res|=(1ll<<i) ; 
    		}
    	}
    	cout<<res ; 
    }	
}
namespace sub2
{
	bool check(ll VAL)
	{
		int cnt = 0; 
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				ll val = (a[i]^a[j]);
				if(val<=VAL)cnt++;
			}
		} 
		cnt-=n;
		cnt/=2 ;
		return cnt>=k ; 
	}		
	void xuly()
	{
		ll l = 0 ;
		ll r=  (1ll<<60)-1 ; 
		ll ans = 0 ; 
		while(l<=r)
		{ 
			ll mid= (l+r)/2; 
			if(check(mid))ans=mid,r=mid-1 ;
			else l=mid+1 ;
		}
		cout<<ans ; 
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
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}