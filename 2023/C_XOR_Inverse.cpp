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
const int N = 3e5+5, oo = 2e9, LO = 29, CH = 26 ; 

int n; 
int a[N] ; 

void doc()
{
	cin>> n; 
	FOR(i,1,n)
	{
		cin>>a[i];
	}
}
namespace sub1
{
	int T[N*(LO+1)][2] ;
	vi pos[N*(LO+1)]; 
	int node = 1  ;
	int h[N] ; 
	vi q[LO+5] ; 
	void up(int val)
	{
		int r= 1; 
		FORD(i,LO,0)
		{
			int j = (val>>i&1);
			pos[r].pb(j);
			if(T[r][j]==0)
			{
				T[r][j]=++node;  
				if(i-1>=0)q[i-1].pb(node);
			}
			r=T[r][j]; 
		}
	} 
	ll sum(int idx,int c)
	{
		ll ans= 0 ;
		for(auto u:q[idx])
		{
			int bit1 = 0 ; 
			for(auto v : pos[u])
			{
				if((v^c)==0)ans+=bit1 ; 
				else bit1++;
			}	
		}
		return ans ; 
	}
    void xuly()
    {
    	q[LO].pb(1) ; 
    	FOR(i,1,n)
    	{
    		// cout<<bitset<LO+1>(a[i])<<el;
    		up(a[i]) ; 
    	}
    	// cout<<node<<el;
    	ll res = 0 ; 
    	int ans =0  ;
    	FORD(i,LO,0)
    	{
    		ll sl1= sum(i,0) ; 
    		ll sl2= sum(i,1) ; 
    		// cout<<sl1<<" "<<sl2<<el;
    		if(sl1>sl2)
    		{
    			res+=sl2 ; 
    			ans|=(1<<i) ;
    		}
    		else res+=sl1; 
    	}
    	cout<<res<<" "<<ans<<el;
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