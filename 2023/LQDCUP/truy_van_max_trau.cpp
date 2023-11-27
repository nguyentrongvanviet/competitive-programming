/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "truyvanmax"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ; 
ll a[N] ; 

void doc()
{
    cin>>n  ; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
    void xuly()
    {
    	int q ; cin>>q;
    	FOR(i,1,q)
    	{
    		int type  , l ,r ;
    		cin>>type>>l>>r;
    		if(type==1)
    		{
    			ll res= 0; 
    			FOR(i,l,r)
    			{
    				maxi(res,a[i]);
    			}
    			cout<<res<<el;
    		}
    		else
    		{
    			ll x,y ;
    			cin>> x>>y ;
    			if(y<0)abort();
    			FOR(i,l,r)
    			{
    				a[i]+=x+(i-l)*y;
    			}
    		}
    	}    }
}
namespace sub2
{
	int B ;
	int BLOCK(int x)
	{
		return x/B+1;
	}
	struct line
	{
		ll a, b; 
		ll operator()(ll x)
		{
			return a*x+b;
		}
		line(ll _a=0,ll _b=0)
		{
			a=_a ;
			b=_b ; 
		}
		db operator / ( line x)
		{
			return 1.0*(x.b-b)/(a-x.a) ;
		}
	}; 
	deque<line>q[N] ;
	void add(deque<line>&q , line x)
	{
		while
		(
			SZ(q)>1
			&& 
			q.back()/q[SZ(q)-2] <= q.back()/x
		)
		{
			q.pk();
		}
		q.push_back(x) ;
	}
	ll get(deque<line>& q , ll y) 
	{
		while
		(
			SZ(q)>1
			&&
			q.back()/q[SZ(q)-2]<1.0*y
		)q.pop_front() ;
		return q[0](y);
	}
	int L[N] , R[N] ;
	ll lazy_val[N] , lazy_x[N] ;
	void solve(int l, int r )
	{
		ll res = 0 ;
		int U = BLOCK(l) ; 
		int V = BLOCK(r) ; 
		if(U==V)
		{	
			FOR(i,l,r)
			{
				maxi(res,a[i]+lazy_val[U]+lazy_x[U]*i); 
			}
		}
		else
		{
			FOR(i,l,R[U])
			{
				maxi(res,a[i]+lazy_val[U]+lazy_x[U]*i);
			}
			FOR(i,L[V],r)
			{
				maxi(res,a[i]+lazy_val[V]+lazy_x[V]*i); 
			}
			FOR(i,U+1,V-1)
			{
				maxi(res,get(q[i],lazy_x[i])+lazy_val[i]); 
			}
		}
		cout<<res<<el;
	}
	void up(int l ,int r , ll x , ll y)
	{
		int U = BLOCK(l) ; 
		int V = BLOCK(r) ; 
		if(U==V)
		{
			q[U].clear() ; 
			FOR(i,l,r)
			{
				a[i]+=lazy_x[U]*i+lazy_val[U]+x+(i-l)*y; 
				add(q[U],line(i,a[i])) ; 
			}
		}
		else
		{
			// cout<<"2nd"<<el;
			q[U].clear();
			FOR(i,L[U],R[U])
			{	
				a[i]+=lazy_x[U]*i + lazy_val[U] ;
				
				if(i>=l)a[i]+=x+(i-l)*y ; 
				add(q[U],line(i,a[i])) ; 
			}
			lazy_x[U] = lazy_val[U] = 0 ; 
			q[V].clear() ; 
			FOR(i,L[V],R[V])
			{
				a[i]+=lazy_x[V]*i + lazy_val[V] ; 
				if(i<=r)a[i]+=x+(i-l)*y;
				add(q[V],line(i,a[i]));
			}
			lazy_x[V] = lazy_val[V] = 0 ;
			FOR(i,U+1,V-1)
			{
				lazy_val[i]+=x-y*l ;
				lazy_x[i]+=y;
			} 			
		}
	}
	void xuly()
	{
		B = sqrt(n) ;
		FOR(i,1,n/B+5)L[i]=oo,R[i]=0;
		FOR(i,1,n)
		{
			mini(L[BLOCK(i)],i) ; 
			maxi(R[BLOCK(i)],i) ; 
			add(q[BLOCK(i)],line(i,a[i])) ;
		}
		int Q; 
		cin>> Q; 
		while(Q--)
		{
			int type , l ,r ;cin>>type>>l>>r; 
			if(type==1)
			{
				solve(l,r) ;  
			}
			else
			{
				ll x ,y ; cin>>x>>y;
				up(l,r,x,y) ; 
			}	
		}
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // cout.tie(0);
    srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        // sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}