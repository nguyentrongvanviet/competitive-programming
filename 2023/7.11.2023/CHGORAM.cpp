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

bool mtt = 1 ;
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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;
vi g[N] ;  
int a[N] ; 
int P[5] ; 
int val; 
void doc()
{	
    cin>> n; 
	FOR(i,1,3)
	{
		cin>>P[i] ; 
	}
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>> u >>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int in[N] , out[N] ;
	int sz[N] ; 
	int tt = 0; 
	int node = 0 ; 
	int H[N] ;
	int L[N*(LO+1)],R[N*(LO+1)] ; 
	int st[N*(LO+1)] ;
	void dfs(int u ,int p)
	{
		in[u] = ++tt; 
		sz[u] = 1 ; 
		for(auto v: g[u])if(v!=p)
		{
			dfs(v,u) ; 
			sz[u]+=sz[v];
		}
		out[u] = tt; 
	}
	int up(int old ,int l, int r,int pos)
	{
		int cur = ++node ; 
		if(l==r)
		{
			st[cur]=1 ;
			return cur ; 
		}
		int mid=(l+r)/2 ;
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur] = up(L[old],l,mid,pos) ; 
		}
		else
		{
			L[cur] = L[old] ; 
			R[cur] = up(R[old],mid+1,r,pos) ; 
		}	
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur ;
	}
	int get(int id ,int l ,int r, int t ,int p)
	{
		if(id==0)return 0 ;
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0; 
		int mid=(l+r)/2; 
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ;
	}
	ll res  ;
	void solve(int u ,int p)
	{
		for(auto v: g[u])if(v!=p)
		{
			solve(v,u) ;
		}
		int sum1 = 0 ;// <u  
		int sum2 = 0 ;// >u 
		for(auto v:g[u])if(v!=p)
		{
			if(P[2]==2)
			{
				int val1 = get(H[u],1,n,in[v],out[v]);
				int val2 = sz[v]-val1; 
				res+=1ll*val1*sum2 ; 
				res+=1ll*val2*sum1 ;
				sum1+=val1 ;
				sum2+=val2 ; 
			}
			else if(P[2]==1)
			{
				int val2= sz[v]-get(H[u],1,n,in[v],out[v]) ;
				res+=1ll*val2*sum2 ;
				sum2+=val2; 
			}
			else 
			{
				int val1 =get(H[u],1,n,in[v],out[v]) ;
				res+=1ll*val1*sum1 ;
				sum1+=val1; 
			}
		}
		if(P[2]==2)
		{
			int val1 = st[H[u-1]]-sum1;
			int val2 = (n-st[H[u]])-sum2;
			res+=1ll*val1*sum2;
			res+=1ll*val2*sum1;
		}
		else if(P[2]==1)
		{
			int val2 = n-st[H[u]]-sum2; 
			res+=1ll*val2*sum2 ;
		}	
		else
		{
			int val1 = st[H[u-1]]-sum1 ; 
			res+=1ll*val1*sum1;
		}
	}
    void xuly()
    {

    	res = 0 ;
    	dfs(1,0) ; 		
    	FOR(i,1,n)H[i]=up(H[i-1],1,n,in[i]) ;
    	solve(1,0) ; 
    	cout<<res<<el;
    	FOR(i,1,n)g[i].clear();
    	FOR(i,1,node)st[i] = 0 ;
    	tt = 0 ;
    	node = 0 ;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}