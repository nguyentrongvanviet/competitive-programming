/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "coci2021_r1_3dhistogram"
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
ll a[N] , b[N] ; 

void doc()
{
    cin>> n ; 
    FOR(i,1,n)cin>>a[i]>>b[i] ; 
}

namespace sub1
{
    void xuly()
    {
    	ll res = 0 ; 
    	int l = 0 ,r = 0 ;
    	FOR(i,1,n)	
    	{
    		ll mia = oo , mib = oo ; 
    		FOR(j,i,n)
	    	{
	    		mini(mia,a[j]) ; 
	    		mini(mib,b[j]) ;
	    		if(maxi(res,mia*mib*(j-i+1)))l=i,r=j;   
	    	}
	    }
	    // cout<<l<<" "<<r<<el;
	    cout<<res<<el; 
	    // int mid =(l+r)/2 ; 
	    // ll miA = oo , miB = oo ; 
	    // // cout<<l<<" "<<r<<el;
	    // FOR(i,l,mid)
	    // {
	    // 	mini(miA,a[i]) ; 
	    // 	mini(miB,b[i]) ; 
	    // }
	    // cout<<miA<<" "<<miB<<el;
		// miA = oo , miB = oo ; 
	    // FORD(i,r,mid)
	    // {
	    // 	mini(miA,a[i]) ; 
	    // 	mini(miB,b[i]) ; 
	    // }
	    // cout<<miA<<" "<<miB<<el;
    }
}
namespace sub2
{
	const int MAX = 2e5 ; 
	struct line
	{
		ll a,  b ; 
		line()
		{
			a=0 ; 
			b=-inf ; 
		}
		line(ll _a , ll _b)
		{
			a=_a ; 
			b=_b ; 
		}
		ll operator()(ll x)
		{
			return a*x+b ;
		}
	} ; 
	struct lichao
	{
		line st[MAX*4+5] ; 
		int L , R; 
		vi node ; 
		void up(int id ,int l, int r ,line L)
		{
			node.pb(id); 
			if(l==r)
			{
				if(st[id](l)<L(l))swap(st[id],L) ; 
				return ; 
			}
			int mid = (l+r)/2 ; 
			if(st[id].a>L.a)swap(st[id],L) ; 
			if(st[id](mid)<L(mid))
			{
				swap(st[id],L); 
				up(id*2,l,mid,L) ; 
			}
			else
			{
				up(id*2+1,mid+1,r,L) ; 
			}
		}
		ll get(int id, int l  ,int r, int pos)
		{
			if(l==r)
			{
				return st[id](pos) ; 
			}
			int mid= (l+r)/2; 
			if(pos<=mid)return max(st[id](pos),get(id*2,l,mid,pos)) ; 
			return max(st[id](pos),get(id*2+1,mid+1,r,pos)) ; 
		}
		void up(ll a , ll b)
		{
			up(1,L,R,line(a,b)) ; 
		}
		ll get(int x)
		{
			return get(1,L,R,x) ; 
		}
		void reset()
		{
			for(auto u :node)st[u]=line() ; 
			node.clear();
		}
	}CHT;
	ll miaL[N],mibL[N] ; 
	ll miaR[N],mibR[N] ;
	ll res = 0 ;
	void solve(int l ,int r)
	{
		CHT.L=l ; 
		CHT.R=r ;
		if(l>r)return ; 
		int mid=(l+r)>>1;  
		miaL[mid+1]=mibL[mid+1]=miaR[mid-1]=mibR[mid-1]=oo;
		
		FORD(i,mid,l)
		{
			miaL[i]=min(miaL[i+1],a[i]);
			mibL[i]=min(mibL[i+1],b[i]);
		}
		FOR(i,mid,r)
		{
			miaR[i]=min(miaR[i-1],a[i]) ; 
			mibR[i]=min(mibR[i-1],b[i]) ; 
		}
		// L , L 
		int it = r; 
		FOR(i,l,mid)
		{
			while(it > mid &&(miaL[i] > miaR[it] || mibL[i] > mibR[it]))--it; 
			maxi(res,miaL[i]*mibL[i]*(it-i+1)); 
		}
		// L ,R ; 
		int ita = mid ; 
		int itb = r+1 ; 
		FORD(i,mid,l)
		{
			while(ita+1<=r&&miaL[i]<=miaR[ita+1])
			{	
				++ita; 
				if(itb<=ita)
				{
					CHT.up(-mibR[ita],mibR[ita]*(ita+1)) ;
				}
			}
			while(itb-1>=mid+1&&mibL[i]>=mibR[itb-1])
			{
				--itb; 
				if(itb<=ita)
				{
					CHT.up(-mibR[itb],mibR[itb]*(itb+1)) ;
				}
			}
			maxi(res,miaL[i]*CHT.get(i)) ;
		}
		CHT.reset() ;
		// R R  

		it=l;
		FORD(i,r,mid)
		{
			while(it<mid && (miaR[i]>miaL[it]||mibR[i]>mibL[it]))++it;
			maxi(res,miaR[i]*mibR[i]*(i-it+1)) ; 
		}

		// R , L
		ita = l-1;
		itb = mid; 
		FOR(i,mid,r)
		{
			while(ita-1>=l&&miaR[i]<=miaL[ita-1])
			{
				--ita; 
				if(ita<=itb)CHT.up(mibL[ita],mibL[ita]*(-ita+1));
			}
			while(itb+1<=mid-1 && mibR[i]>=mibL[itb+1])
			{
				++itb;
				if(ita<=itb)CHT.up(mibL[itb],mibL[itb]*(-itb+1)) ; 
			}
			CHT.get(miaR[i]*CHT.get(i)) ; 
		}
		CHT.reset() ; 

		solve(l,mid-1) ; 
		solve(mid+1,r) ; 
	}
	void xuly()
	{
		solve(1,n) ;
		cout<<res<<el;   
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