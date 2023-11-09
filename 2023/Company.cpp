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
const int N = 1e5+5 , oo = 2e9 , LO = 19 , CH = 26 ; 

int n , q; 
vi g[N] ; 
void doc()
{
    cin>> n >>q;  
    FOR(i,2,n)
    {
    	int u ;cin>>u ;
    	g[u].pb(i) ; 
    }
}

namespace sub1
{
	int tt= 0 , sl = 0 ; 
	int pos[N] ; 
	int at[N] ; 

	int t[N] ; 	
	int a[2*N] ;
	int h[N] ; 
	void dfs(int u ,int p)
	{
		at[++tt] = u ; 
		t[u]  = tt;  

		pos[u] = ++sl;
		a[sl] = t[u] ;
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1 ;
			dfs(v,u) ; 	
			a[++sl] = t[u] ; 
		} 
	}
	int mi[2*N][LO+1] ;
	void rmq_mi()
	{
		FOR(i,1,sl)mi[i][0] = a[i] ;
		FOR(j,1,lg(sl))FOR(i,1,sl)
			mi[i][j] = min(mi[i][j-1],mi[min(sl,i+(1<<j-1))][j-1]);
	}
	pii L[N][LO] , R[N][LO] ;
	void rmq_LR()
	{
		FOR(i,1,n)L[i][0] = R[i][0] = {pos[i],i} ; 
		FOR(j,1,lg(n))FOR(i,1,n)
		{
			L[i][j] = min(L[i][j-1],L[min(n,i+(1<<j-1))][j-1]);
			R[i][j] = max(R[i][j-1],R[min(n,i+(1<<j-1))][j-1]);
		}
	}
	int get(int l , int r)
	{
		if(l>r)abort(); 
		int k = lg(r-l+1) ; 
		return min(mi[l][k],mi[r-(1<<k)+1][k]);
	}
	pii getL(int l, int r)
	{
		if(l>r)return {oo,0} ; 
		int k = lg(r-l+1) ;
		return min(L[l][k],L[r-(1<<k)+1][k]) ; 
	}
	pii getR(int l, int r)
	{
		if(l>r)return {0,0} ;
		int k = lg(r-l+1) ; 
		return max(R[l][k],R[r-(1<<k)+1][k]) ; 
	}
	int solve(int u ,int l, int r)
	{
		return h[at[get(min(getL(l,u-1).fi,getL(u+1,r).fi),max(getR(l,u-1).fi,getR(u+1,r).fi))]] ;
	}
    void xuly()
    {
    	dfs(1,0) ;
    	rmq_mi() ; 
    	rmq_LR() ; 
    	while(q--)
    	{
    		int l ,r ;cin>>l>>r; 
    		int res = -1 ;
    		int ans = -1; 
    		pii L = getL(l,r) ; 
    		if(maxi(res,solve(L.se,l,r)))ans=L.se ;
			pii R = getR(l,r) ;
    		if(maxi(res,solve(R.se,l,r)))ans=R.se ;
    		cout<<ans<<" "<<res<<el;
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}