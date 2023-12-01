/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "truyvanmax"
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
const int N = 102405 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ; 
ll a[N] ; 

void doc()
{
    cin>>n  ; 
    FORN(i,0,n)cin>>a[i] ; 
}

namespace sub1
{
    void xuly()
    {
    	int q ; cin>>q;
    	FOR(i,1,q)
    	{
    		int type  , l ,r ;
    		--l ;
    		--r ; 
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
    			prt(a,n) ;
    		}
    	}
    }
}
namespace sub2
{
	const int B  = 320 ;
	struct line
	{
		ll a, b ;
		line(ll _a=0 ,ll _b=0)
		{
			a=_a; 
			b=_b; 
		}
		ll operator()(ll x)
		{
			return a*x+b;
		}
		db operator / (const line& x)const 
		{
			return 1.0*(x.b-b)/(a-x.a) ; 
		}
	} ;
	struct CHT
	{
		deque<line>q ;
		void add(const line&a)
		{
			while(SZ(q)>1 && q[SZ(q)-2]/a>=q.back()/a)
			{
				q.pk() ; 
			}
			q.pb(a) ;
		}
		ll get(ll x)
		{
			while(SZ(q)>1&&q[0](x)<=q[1](x))q.pop_front() ; 
			return q[0](x) ;
		}
	}A[B+5] ;
	
	ll lz_x[B]  , lz_val[B] ;

	void build(int id)
	{
		A[id].q.clear() ; 
		FORN(i,id*B,(id+1)*B)
		{
			A[id].add(line(i,a[i])) ;
		}
	}
	ll get_trau(int l ,int r)
	{	
		ll res = 0 ; 
		FOR(i,l,r)
		{
			maxi(res,a[i]+i*lz_x[i/B]+lz_val[i/B]); 
		}
		return res ; 
	}	
	ll get_block(int l ,int r)
	{
		ll res =0 ; 	
		FOR(i,l,r)
		{
			maxi(res,A[i].get(lz_x[i])+lz_val[i]);
		}
		return res; 
	}
	// ll get(int l, int r)
	// {
	//     int BL = (l + B - 1) / B, BR = r / B;
	//     if (BL >= BR) return get_trau(l, r);
	//     ll res = get_block(BL, BR - 1);
	//     if (l < BL * B) maxi(res, get_trau(l, BL * B - 1));
	//     maxi(res, get_trau(BR * B, r));
	//     return res;
	// }

	ll get(int l ,int r)
	{
		ll res = 0 ;
		if(l/B==r/B)
		{
			return get_trau(l,r); 
		}
		int L = (l/B+1)*B-1 ; 
		maxi(res,get_trau(l,L)) ;
		int R = (r/B)*B;
		maxi(res,get_trau(R,r)) ; 
		maxi(res,get_block(l/B+1,r/B-1)) ;
		return res;
	}
	void up_trau(int l ,int r, ll x, ll y)
	{	 
		FOR(i,l,r)a[i]+=x+y*i;
		build(l/B) ; 
	}	
	void up_block(int l ,int r, ll x , ll y )
	{
		FOR(i,l,r)
		{
			lz_x[i]+=y ; 
			lz_val[i]+=x ;
		} 
	}
	void up(int l ,int r , ll x ,ll y )
	{
		if(l/B==r/B)
		{
			up_trau(l,r,x,y);
			return ; 
		}

		int L = (l/B+1)*B-1 ; 
		up_trau(l,L,x,y) ;

		int R = (r/B)*B;
		up_trau(R,r,x,y) ; 
		
		up_block(l/B+1,r/B-1,x,y) ;
	}
	void xuly()
	{
		FORN(i,0,B)build(i) ;
		int q; cin>>q ; 
		FOR(i,1,q)
		{
			int type , l , r ; cin >> type >> l >>r ;
			--l ;
			--r ;
			if(type==1)
			{
				cout<<get(l,r)<<el;
			}	
			else
			{	
				ll x, y; cin >> x >> y;
				up(l,r,x-y*l,y); 
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