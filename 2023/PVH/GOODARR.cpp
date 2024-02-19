/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "GOODARR"
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
#define        M(i)  (1ll<<(i))
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


int n ; 
int a[N] ;

void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	struct DL
	{
		int val; 
		int sl ; 
		friend DL operator +(DL a , DL b)
		{
			if(a.val==b.val)return {a.val,a.sl+b.sl}; 
			else 
			{
				if(a.sl<=b.sl)return {b.val,b.sl-a.sl} ;
				return {a.val,a.sl-b.sl}; 
			}
		}
	} ;
	struct IT
	{	
		DL st[4*N] ; 
		void build(int id ,int l ,int r)
		{
			if(l==r)
			{
				st[id] = {a[l],1} ;
				return ; 
			}
			int mid = (l+r)>>1; 
			build(id<<1,l,mid) ; 
			build(id<<1|1,mid+1,r ); 
			st[id] =  st[id<<1] + st[id<<1|1] ; 
		}
		DL get(int id ,int l ,int r, int t, int p)
		{
			if(t<=l&&r<=p)return st[id] ;
			if(r<t||p<l)return {0,0} ;
			int mid = (l+r)>>1;  
			return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ;
		}
	}st; 
	vi pos[N] ; 
	int get(int val ,int l ,int r)
	{
		return UB(all(pos[val]),r)-LB(all(pos[val]),l);
	}
    void xuly()
    {
        st.build(1,1,n) ;
        FOR(i,1,n)pos[a[i]].pb(i) ;
        int res = n*(n+1)/2;
        FOR(i,1,n)
        {
        	FOR(j,i,n)
        	{
        		int tmp = st.get(1,1,n,i,j).val; 
        		if(get(tmp,i,j)*2>(j-i+1))
        		{
        			--res;
        		} 
        	}
        }
        cout<<res<<el;
    }
}
namespace sub2
{
	struct treebit
	{
		vi bit ; 
		treebit(int _n = 0 )
 		{ 
			n=_n ;
			bit=vi(3*n+5,0) ; 
		} 
		void init()
		{
			FOR(i,1,3*n)bit[i] = 0; 
		}
		void up(int id ,int val)
		{
			id+=n; 
			for(int i=id;i<=3*n;i+=i&-i)bit[i]+=val; 
		}
		int get(int id)
		{
			id+=n; 
			int ans = 0; 
			for(int i=id;i;i-=i&-i)ans+=bit[i] ;
			return ans ; 
		}
	}bit; 
	ll res ; 
	int s[N] ;
	void solve(int val)
	{
		bit.init() ; 
		bit.up(0,1) ;
		FOR(i,1,n)
		{
			s[i] = s[i-1]+(a[i]==val) ; 
			res-=bit.get(2*s[i]-i-1) ;
			bit.up(2*s[i]-i,1) ; 
		}

	}
	void xuly()
	{
		bit=treebit(n) ;
		res=1ll*n*(n+1)/2; 
		vi V; 
		FOR(i,1,n)V.pb(a[i]) ; 
		uni(V) ; 
		for(auto val : V)solve(val) ; 
		cout<<res<<el;
	}
}
namespace sub3
{
	ll lazy[8*N] ; 
	int time[8*N] ; 
	void dolazy(int id ,int l, int r)
	{
		st[id]+=lazy[id] ; 
	}
	struct seg
	{

	};
	void xuly()
	{
		vi V; 
		FOR(i,1,n)V.pb(a[i]) ;
		uni(V) ;
		FOR(i,1,n)
		{
			int val = UB(all(V),a[i])-V.begin() ; 
			pos[val].pb(i) ; 
		}
		FOR(i,1,SZ(V))solve(pos[i]); 
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(n<=5000)sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}