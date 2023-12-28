/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "BSTR"
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

int n , q ; 
int a[N] ; 
struct query
{
	int id , k ;
};
ve<query>Q[N] ; 

void doc()
{
	str S ; 
    cin>> S; 	
    n = SZ(S) ;
    FOR(i,1,n)
    {
    	a[i] = S[i-1]-'0' ; 
    }
    cin>>q; 
    FOR(i,1,q)
    {
    	int len , k; cin>>len>>k ;
    	Q[len].pb({i,k}) ; 
    }
}

namespace sub1
{
	char res[N] ;
	vi pos[10] ;
	void solve(int len)
	{
		FOR(i,0,9)pos[i].clear() ; 
		FORD(i,n,1)
		{
			pos[a[i]].pb(i) ; 
		}
		int cur = 0 ;
		str ans ; 
		FOR(i,1,len)
		{
			FORD(j,9,0)
			{
				while(!pos[j].empty()&&pos[j].back()<=cur)
				{
					pos[j].pk();
				}
				if(!pos[j].empty()&&n-pos[j].back()+1>=len-i+1)
				{
					ans+=char(j+'0') ;
					cur=pos[j].back() ;
					pos[j].pk() ;
					break;
				}
			}
		}
		for(auto x: Q[len])
		{
			int id = x.id ; 
			int k = x.k ;
			res[id] = ans[k-1] ;
		}
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		solve(i) ; 
    	}
    	FOR(i,1,q)cout<<res[i]<<el;
    }
}
namespace sub2
{
	struct DL
	{
		int ma , pos ; 
		friend DL operator+(DL a , DL b )
		{
			if(a.ma>b.ma)return a ;
			if(a.ma<b.ma)return b ;
			return {a.ma,min(a.pos,b.pos)} ; 
		}
	}; 
	DL st[N][LO+1] ;
	void build_rmq()
	{
		FOR(i,1,n)st[i][0] = {a[i],i} ;
		FOR(j,1,LO)FOR(i,1,n-M(j)+1)
		{
			st[i][j] = st[i][j-1]+st[i+M(j-1)][j-1]; 
		}
	}
	DL get(int l , int r)
	{
		int k= lg(r-l+1) ; 
		return st[l][k]+st[r-M(k)+1][k] ; 
	}	
	int bit[N] ;
	void up(int id)
	{
		for(int i=id;i<=n;i+=i&-i)bit[i]++ ;
	}
	int kth(int k)
	{
		int pos = 0 ;
		int cur = 0 ; 
		FORD(j,LO,0)if(pos+M(j)<=n&&cur+bit[pos+M(j)]<k)
		{
			pos+=M(j) ; 
			cur+=bit[pos] ; 
		}
		return pos+1;
	}
	int res[N] ;
	void xuly()
	{
		build_rmq() ;
		ve<pii>range ; 
		range.pb({1,n}) ;
		FOR(i,1,n)
		{
			int l = range.back().fi ; 
			int r = range.back().se ;
			range.pk() ; 
			DL ans= get(l,r) ;
			int pos = ans.pos ; 
			up(pos) ; 
			for(auto x : Q[i])
			{
				int id =x.id; 
				int k = x.k ; 
				res[id] = a[kth(k)]; 
			}
			if(l<=pos-1)range.pb({l,pos-1}) ;
			if(pos+1<=r)range.pb({pos+1,r}) ; 
		}
		FOR(i,1,q)cout<<res[i]<<el;
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
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}