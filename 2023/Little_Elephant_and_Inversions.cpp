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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ; 
ll k; 
int a[N] ;
vi V ; 
void doc()
{
	cin>> n >> k; 
	FOR(i,1,n)cin>>a[i] ,V.pb(a[i]) ; 
}

namespace sub1
{
	int sL[N] ;
	int sR[N] ;  
	void up(int idx,int val,int bit[])
	{
		for(int i=idx;i<=n;i+=i&-i)bit[i]+=val; 
	}
	int get(int idx,int bit[])
	{
		int ans = 0 ; 
		for(int i=idx;i;i-=i&-i)ans+=bit[i] ; 
		return ans;  
	}
	int get(int l, int r,int bit[])
	{
		return get(r,bit)-get(l-1,bit) ;
	}
    void xuly()
    {    
    	uni(V) ; 
    	FOR(i,1,n)
    	{
    		a[i] = UB(all(V),a[i])-V.begin() ; 
    	}
    	ll inv = 0 ;
    	FORD(i,n,1)
    	{	
    		inv+=get(a[i]-1,sR) ; 
    		up(a[i],1,sR) ; 
    	}
    	if(inv<=k)
    	{
    		cout<<1ll*n*(n-1)/2<<el;
    		exit(0) ;
    	}
    	int r=2 ;
    	ll res = 0 ;  
    	inv-=get(a[1]-1,sR);
    	up(a[1],-1,sR) ; 
    	FOR(l,1,n)
    	{
    		inv+=get(a[l]+1,n,sL) ;
    		inv+=get(a[l]-1,sR) ; 
	    	up(a[l],1,sL) ; 
    		while(r<=n&&inv>k)
    		{
    			inv-=get(a[r]+1,n,sL) ; 
    			inv-=get(a[r]-1,sR) ; 
    			up(a[r],-1,sR) ; 
    			++r;
    		}
    		if(inv<=k)res+=(n-r+1);
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
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}