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


int n; 
int L; 
struct pt
{
	int x, y , c ;
} ; 
pt a[N] ; 
void doc()
{	
    cin>> n >> L ;
    FOR(i,1,n)cin>>a[i].x>>a[i].y>>a[i].c ;
}

namespace sub1
{
	const int N = 2e3+5 ;
	ll s[N][N];
	ll get(int x ,int y ,int len)
	{
		int u = x-len+1; 
		int v = y-len+1;
		maxi(u,1) ; 
		maxi(v,1) ; 
		return s[x][y] - s[x][v-1] - s[u-1][y] + s[u-1][v-1] ;
	}
    void xuly()
    {
    	FOR(i,1,n)s[a[i].x][a[i].y]+=a[i].c ; 
    	FOR(i,1,2000)FOR(j,1,2000)
    	{
    		s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    	}
    	ll res = 0 ;
    	int len =0 ; 
    	FOR(i,1,2e3)FOR(j,1,2e3)
    	{
    		ll val =get(i,j,L) ; 
    		if(val<res)continue ; 
    		int l= 1 ; 
    		int r = L; 
    		int ans =0 ;
    		while(l<=r)
    		{
    			int mid=(l+r)/2;
    			if(get(i,j,mid)==val)ans=mid,r=mid-1 ;
    			else l=mid+1 ;
    		}
    		if(maxi(res,val))len=ans;
    		else mini(len,ans) ;
    	}
    	cout<<res<<" "<<len<<el;
    }
}
namespace sub2
{
	ll lazy[8*N] ; 
	ll st[8*N] ; 
	struct ke
	{
		int x , val; 
	} ; 
	ve<ke> P[N] ;
	void dolazy(int id)
	{
		st[id]+=lazy[id] ; 
		lazy[id*2]+=lazy[id] ; 
		lazy[id*2+1]+=lazy[id] ;
		lazy[id] = 0 ;
	}
	void up(int id ,int l, int r, int t, int p ,int val)
	{
		dolazy(id) ;
		if(t<=l&&r<=p)
		{
			lazy[id]=val; 
			dolazy(id) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid=(l+r)/2;
		up(id*2,l,mid,t,p,val) ; 
		up(id*2+1,mid+1,r,t,p,val) ; 
		st[id] = max(st[id*2],st[id*2+1]) ; 
	}
	ll res  ; 
	ll solve(int len)
	{
		ll ans =0 ; 
		FOR(i,1,4*1e5)st[i]=lazy[i] = 0;
		FOR(i,1,1e5)
		{
			for(auto tmp : P[max(0,i-len)])
			{
				int x = tmp.x; 
				int val = tmp.val;
				up(1,1,1e5,x,min((int)1e5,x+len-1),-val);
			}		 
			for(auto tmp : P[i])
			{
				int x=tmp.x; 
				int val =tmp.val; 
				up(1,1,1e5,x,min((int)1e5,x+len-1),val) ; 
			}
			maxi(ans,st[1]) ;
		}
		return ans; 
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			P[a[i].y].pb({a[i].x,a[i].c}) ; 
		}
		res = solve(L) ;
		int l= 1; 
		int r = L; 
		int ans = 0 ; 
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(solve(mid)==res)ans=mid,r=mid-1 ;
			else l=mid+1 ;
		}
		cout<<res<<" "<<ans<<el;;
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
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}