/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "MSEQ"
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


int n; 
int a[N] ;

void doc()
{	
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	int f[N] ; 
    void xuly()
    {	 
    	f[0] = 0 ;
    	FOR(i,1,n)
    	{
    		FOR(j,1,i)
    		{
    			int cnt = 0 ;
    			FOR(k,j,i)
    			{
    				cnt+=(a[k]==k-j+1) ;
    			}
    			maxi(f[i],f[j-1]+cnt) ;
    		}
    	}
    	cout<<n-f[n]<<el;
    }
}
namespace sub2
{
	int f[N] ; 
	void xuly()
	{
		f[0] = 0 ; 
		FOR(i,0,n-1)
		{
			int cnt = 0 ;
			FOR(j,i+1,n)
			{
				cnt+=(a[j]==j-i) ;
				maxi(f[j],f[i]+cnt);
			}
		}	
		cout<<n-f[n]<<el; 
	}
}
namespace sub3
{
	int st[4*N] ; 
	vi q[N] ;
	void dolazy(int id)
	{
		maxi(st[id<<1],st[id]) ; 
		maxi(st[id<<1|1],st[id]) ;
	}
	void up(int id, int l, int r, int t, int p,int val)
	{
		dolazy(id) ; 
		if(t<=l&&r<=p)
		{
			maxi(st[id],val) ;
			dolazy(id) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid=(l+r)>>1;
		up(id<<1,l,mid,t,p,val) ;
		up(id<<1|1,mid+1,r,t,p,val) ;
	}
	int get(int id ,int l ,int r, int pos )
	{
		dolazy(id) ;
		if(l==r)
		{
			return st[id] ; 
		}
		int mid=(l+r)>>1; 
		if(pos<=mid)
		{
			return get(id<<1,l,mid,pos) ; 
		}
		return get(id<<1|1,mid+1,r,pos) ; 
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			if(i-a[i]+1>=1&&i>=i-a[i]+1)
			{
				q[i-a[i]+1].pb(i) ;
			}	
		}
		FOR(i,0,n-1)
		{
			int val =get(1,0,n,i) ;
			if(q[i+1].empty())
			{
				continue ;
			}
			else
			{
				int cnt = 0 ;
				int pre=i+1;
				for(auto cur : q[i+1])
				{
					up(1,0,n,pre,cur-1,val+cnt) ;
					pre = cur ;
					++cnt; 
				}
				up(1,0,n,pre,n,val+cnt) ;
			}
		}
		cout<<n-get(1,0,n,n)<<el; 
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
        if(n<=200)sub1::xuly() ;
        else if(n<=3000)sub2::xuly() ; 
        else sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}