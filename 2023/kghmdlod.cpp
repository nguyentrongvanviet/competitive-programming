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
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct DL
{
	int id , val;
	bool operator<(const DL&a)const
	{
		return val>a.val; 
	}
}; 
int n , q; 
DL a[N] ;
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)cin>>a[i].val,a[i].id=i; 
}

namespace sub1
{
	int bit[N] ;
	int ans ;  
	pii Q[N] ;
	vi ques[N] ; 
	int L[N] , R[N] ; 
    int res[N] ;
    bool ok ;
    int l ,r ; 
    int it ; 
	void up(int idx)
	{
		for(int i=idx;i<=n;i+=i&-i)bit[i]++ ;
	}
	int get(int idx)
	{
		ans= 0 ; 
		for(int i=idx;i;i-=i&-i)ans+=bit[i] ; 
		return ans; 
	}
	int get(int l ,int r)
	{
		return get(r)-get(l-1) ;
	}
    void xuly()
    {
	    sort(a+1,a+n+1) ; 
	    FOR(i,1,q)
	    {
	    	cin>>l>>r;
	    	Q[i]={l,r} ;  
    		L[i] = 1 ; 
    		R[i] = r-l+1 ; 
	    }
	    while(1)
	    {
	    	ok = 1; 
	    	FOR(i,1,n)ques[i].clear(),bit[i]=0 ; 
	    	FOR(i,1,q)
	    	{
	    		if(L[i]<=R[i])
	    		{
	    			ok = 0 ; 
	    			ques[(L[i]+R[i])/2].pb(i) ; 
	    		}
	    	}
	    	if(ok)break ; 
	    	it = 1; 	
	    	FORD(i,n,1)
	    	{
	    		while(it<=n&&a[it].val>=i)
	    		{
	    			up(a[it].id) ; 
	    			++it;
	    		}
	    		for(auto x : ques[i])
	    		{
	    			if(get(Q[x].fi,Q[x].se)>=i)
	    			{
	    				res[x] = i ; 
	    				L[x] = i+1; 
	    			}	
	    			else R[x] = i-1 ;
	    		}
	    	}
	    }
	    prt(res,q) ;
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}