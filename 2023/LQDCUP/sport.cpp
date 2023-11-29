/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "sport"
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
	FOR(i,n+1,n+n)cin>>a[i] ; 
}

namespace sub1
{
	struct DL{
		int u ,v;
		int dis ;
		DL(int _u=0,int _v=0)
		{
			u=_u ;
			v=_v ;
			if((u<=n&&v<=n)||(u>n&&v>n))dis=1e9+1 ;
			else dis = abs(a[u]-a[v]) ;
		}  
	} ; 
	struct cmp
	{
		bool operator()(const DL& x,  const DL& y)const
		{
			return x.dis<y.dis||(x.dis==y.dis&&x.u<y.u)||(x.dis==y.dis&&x.u==y.u&&x.v<y.v);
		}
	}; 
	set<DL,cmp>dis ; 
    void xuly()
    {
    	set<pii>s ; 
    	FOR(i,1,n)
    	{
    		s.insert({a[i],i}) ; 
    	}
    	FOR(i,n+1,2*n)
    	{
    		s.insert({a[i],i}) ;
    	}
    	pii prev={0,0} ; 
    	for(auto u :s)
    	{		 
			int id =u.se ; 
			if(prev!=mp(0,0))
			{
				dis.insert(DL(prev.se,id));
			}
    		prev = u ; 
    	}
    	FOR(i,1,n)
    	{
    		DL tmp = (*dis.begin()) ; 
    		dis.erase(dis.begin()) ;
    		int u =tmp.u ; 
    		int v =tmp.v ; 
    		auto L = s.find({a[u],u}) ;
    		auto oldL = L; 
    		auto R = s.find({a[v],v}) ;
    		auto oldR = R ;  
    		bool ok = 1 ;
    		if(L!=s.begin())
    		{
    			--L ; 
    			dis.erase(DL((*L).se,u)) ;
    		}else ok=0 ;
    		
    		++R; 
    		if(R!=s.end())dis.erase(DL(v,(*R).se)) ;
    		else ok = 0 ;
    		
    		if(ok)xzxdis.insert(DL((*L).se,(*R).se));
    		
    		s.erase(oldL) ; 
    		s.erase(oldR) ;

    		if(u<=n)cout<<u<<" "<<v-n<<el;
    		else cout<<v<<" "<<u-n<<el;
    	}
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}