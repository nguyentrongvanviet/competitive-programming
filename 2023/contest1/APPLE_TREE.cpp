/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "APPLE_TREE"
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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ;
vi g[N] ; 
int a[N] ;
ll S=0 ; 
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i],S+=a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v; cin>>u>>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	ll f[N];
	void dfs(int u ,int p)
	{
		f[u] = 1 ; 
		if(g[u].size()-(u!=1)==0)
		{ 
			return ; 
		} 
		for(auto v :g[u])if(v!=p)
		{
			dfs(v,u) ; 
			f[u] = lcm(f[u],f[v]); 
		}
		if(f[u]>S)
		{
			cout<<S;
			exit(0) ; 
		}
		f[u]*=(g[u].size()-(u!=1)); 
		mini(f[u],inf) ;
	}
	bool ok  ; 
	void CK(int u ,int p, ll val)
	{		
		if(g[u].size()-(u!=1)==0)
		{
			if(a[u]<val)ok = 0 ; 
			return ; 
		}
		for(auto v : g[u])if(v!=p)
		{
			CK(v,u,val/(g[u].size()-(u!=1))) ; 
		}
	}
    void xuly()
    {
        dfs(1,0) ;
        ll l = 0 ; 
        ll r = inf/f[1] ;
        ll ans = 0 ; 
        while(l<=r)
        {
        	ll mid=(l+r)/2 ;
        	ok = 1;  
        	CK(1,0,mid*f[1]) ; 
        	if(ok)
        	{
        		ans=mid ;
        		l=mid+1; 
        	}
        	else
        	{
        		r=mid-1; 
        	}
        }
        cout<<S-ans*f[1] ;
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