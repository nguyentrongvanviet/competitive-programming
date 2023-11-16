/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tabishop"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k  ; 
int L ; 
void doc()
{
    cin>> L >> m >> k; 
    // FOR(i,1,L)
    // {
    // 	FOR(j,1,L)cout<<(i+j)%2;
    // 	cout<<el;
    // }
}

namespace sub1
{
	const int N =  5e3+5 ; 
	int dd[N][N] ; 
	struct pt
	{
		int x ,y; 
	}a[N] ; 
    void xuly()
    {
	    FOR(i,1,m)
	    {
	    	cin>>a[i].x>>a[i].y ; 
	    }
	    FOR(i,1,k)
	    {
	    	int x ,y;  cin>>x>>y; 
	    	dd[x][y] = -1 ; 
	    }
	    FOR(_,1,m)
	    {
	    	int x= a[_].x ;
	    	int y =a[_].y ; 
	    	for(int i=x,j=y;i>=1&&j>=1;i--,j--)
	    	{
	    		if(dd[i][j]==-1)break; 
	    		dd[i][j] = 1 ; 
	    	}
	    	for(int i=x,j=y;i<=n&&j<=n;i++,j++)
	    	{
	    		if(dd[i][j]==-1)break;
	    		dd[i][j] = 1 ; 
	    	}
	    	for(int i=x,j=y;i<=n&&j>=1;i++,j--)
	    	{
	    		if(dd[i][j]==-1)break; 
	    		dd[i][j] = 1 ; 
	    	}
	    	for(int i=x,j=y;i>=1&&j<=n;i--,j++)
	    	{
	    		if(dd[i][j]==-1)break; 
	    		dd[i][j] = 1; 
	    	}
	    }
	    int res = 0 ;
	    FOR(i,1,n)FOR(j,1,n)
	    {
	    	res+=(dd[i][j]==1) ;  
	    }
	    cout<<res;
    }
}
namespace sub2
{
	struct pt
	{
		int TYPE ; 
		int x ,y ; 
		int X , Y ; 
		pt(){}  	 	
		pt(int _TYPE , int _x, int _y)
		{
			TYPE = _TYPE ;
			x = _x ;
			y = _y ;
			X = x-y ; 
			Y = x+y ; 
		}
		pt(int _x ,int _y)
		{
			x=_x ;
			y=_y ;
		}
		pt operator +( const pt &a)const
		{
			return pt(TYPE,x+a.x,y+a.y) ;
		}
	}; 
	pt a[N] ;
	ll res = 0 ;
	struct treebit 
	{
		int n; 
		vi bit ;
		treebit(int _n)
		{
			n = _n ; 
			bit=vi(n+1,0) ;  
		}
		void up(int id, int val )
		{
			for(int i=id;i<=n;i+=i&-i)bit[i]+=val; 
		}
		int get(int id )    
		{
			int ans = 0 ;
			for(int i= id;i;i-=i&-i)ans+=bit[i] ; 
			return ans ; 
		}
		int get(int l ,int r)
		{
			return get(r)-get(l-1) ; 
		}
	} ; 
	struct range
	{
		int TYPE ;   
		int x, y , u , v ;
		bool operator<(const range&a)const
		{
			return x<a.x||(x==a.x&&abs(TYPE)>abs(a.TYPE)) ; 
		}
	} ; 
	ve<range> R[2] ; 
	void add(int ok , pt a , pt b  )
	{	
		if(ok==1)
		{
			int du = ((a.x+a.y)%2+2)%2;
			R[du].pb({1,a.X,a.Y,b.X,b.Y}) ;
		}
		else
		{
			swap(a,b) ; 
			int du = ((a.x+a.y)%2+2)%2;

			R[du].pb({2,a.X,a.Y,b.X,b.Y}) ; 
		}
	}		
	void solve1()
	{
		sort(a+1,a+n+1,
		[](pt A , pt B)
		{
			return ( A.X < B.X ) || ( A.X == B.X && A.x<B.x ) ; 
		}) ; 
		FOR(i,1,n)
		{
			// cout<<a[i].x<<" "<<a[i].y<<" X "<<a[i].X<<el;
		}
		 
		// cout<<"G"<<el;
		FOR(i,1,n)
		{
			if(a[i].TYPE)
			{
				if(a[i].X!=a[i-1].X)
				{
					int tmp =  min(a[i].y,a[i].x) ; 
					res+=tmp ;  
					add(1,a[i]+pt(-tmp+1,-tmp+1),a[i]);
				}
				else
				{
					res+=a[i].x-a[i-1].x ;  
					add(1,a[i-1]+pt(1,1),a[i]) ; 
				}
				if(a[i+1].X!=a[i].X)
				{
					int tmp = L-max(a[i].x,a[i].y) ; 
					if(tmp==0)continue ; 
					res+=tmp ; 
					add(1,a[i]+pt(1,1),a[i]+pt(tmp,tmp)) ;
				}
			}
			else if(a[i].X==a[i-1].X&&a[i-1].TYPE)
			{
				int tmp = a[i].x-a[i-1].x-1 ; 
				if(tmp==0)continue;
				res+=tmp ;	
				add(1,a[i-1]+pt(1,1),a[i]+pt(-1,-1)) ; 
			}
			// cout<<i<<" "<<res<<el;
		}	
	} 
	void solve2()
	{
		sort(a+1,a+n+1,
		[](pt A , pt B)
		{
			return ( A.Y < B.Y ) || ( A.Y == B.Y && A.y<B.y ) ; 
		}) ; 
		FOR(i,1,n)
		{
			if(a[i].TYPE)
			{
				if(a[i].Y!=a[i-1].Y)
				{
					int tmp = min(L-a[i].x+1,a[i].y) ; 
					res+=tmp ;	
					add(2,a[i]+pt(tmp-1,-tmp+1),a[i]) ; 
				}
				else
				{
					res+=a[i].y-a[i-1].y ;
					add(2,a[i-1]+pt(-1,1),a[i]) ; 
				}
				if(a[i+1].Y!=a[i].Y)
				{
					int tmp = min(a[i].x-1,L-a[i].y) ;
					if(tmp==0)continue ; 
					res +=tmp;
					add(2,a[i]+pt(-1,1),a[i]+pt(-tmp,tmp));
				}
			}
			else if(a[i-1].Y==a[i].Y&&a[i-1].TYPE)
			{
				int tmp = a[i].y-a[i-1].y-1 ;
				if(tmp==0)continue ; 
				res+=tmp ; 		
				add(2,a[i-1]+pt(-1,1),a[i]+pt(1,-1)); 
			}
		}
	}
	void giao(int ok)
	{
		vi V;
		ve<range>tmp ; 
		for(auto [tpe,x,y,u,v]:R[ok])
		{
			if(tpe==1)
			{
				tmp.pb({0,x,y,x,v});
				V.pb(y) ; 
				V.pb(v) ; 
			}
			else
			{
				tmp.pb({1,x,y,x,y})  ; 
				tmp.pb({-1,u+1,y,u+1,y}) ; 
				V.pb(y) ; 
			}
		}
		uni(V);
		treebit bit(SZ(V)) ; 
		sort(all(tmp)) ;
		for(auto t : tmp)
		{
			int TYPE = t.TYPE;
			if(TYPE==0)
			{
				int l = UB(all(V),t.y)-V.begin(); 
				int r = UB(all(V),t.v)-V.begin();
				res-=bit.get(l,r) ; 
			}
			else
			{
				int pos = UB(all(V),t.y)-V.begin();
				bit.up(pos,TYPE) ; 
			}
		}
	}
	void xuly()
	{
		FOR(i,1,m)
		{
			int x ,y ; cin>>x>>y ; 
			++n;
			a[n]=pt(1,x,y) ;  
		}
		FOR(i,1,k)
		{
			int x, y; cin>>x >>y; 
			++n; 
			a[n]=pt(0,x,y) ; 
		}
		a[n+1].X = (int)-3e9; 
		a[n+1].Y= (int)-3e9 ;
		solve1() ; 
		solve2() ;
		FOR(i,0,1)giao(i) ; 
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
    	sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}