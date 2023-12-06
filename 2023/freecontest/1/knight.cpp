/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "knight"
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
const int N = 2e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n, m ,dra, tho ; 
struct ke
{
	int v, dis , msk ; 
}; 
int sword[N] ;
ve<ke>g[N] ;
void doc()
{
    cin>> n >>m>> dra >> tho ;
    FOR(i,1,tho)
    {
    	int u ;cin>> u ;
    	int sl; cin>>sl ; 
    	while(sl--)
    	{
    		int type ;cin>>type ;
    		--type ; 
    		sword[u]|=M(type) ;
    	} 
    }
    FOR(i,1,m)
    {
    	int u ,v , dis ,sl; 
    	cin>> u >>v >>dis>>sl ;
    	int msk = 0 ; 
    	while(sl--)
    	{
    		int type ; cin>>type;
    		--type; 
    		msk|=M(type) ; 
    	}
    	g[u].pb({v,dis,msk}) ;
    	g[v].pb({u,dis,msk}) ; 
    }
}

namespace sub1
{
	ll f[N][M(16)] ;
	struct DL
	{
		int u , msk ; 
		ll val; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a , const DL&b)const
		{
			return a.val>b.val; 
		}
	} ; 
	void dij()
	{
		FOR(i,1,n)FORN(msk,0,M(dra))
		{
			f[i][msk] = inf;  
		}
		priority_queue<DL,ve<DL>,cmp>q ;
		q.push({1,sword[1],f[1][sword[1]]=0}) ; 
		while(!q.empty())
		{
			int u = q.top().u ;
			int have = q.top().msk; 
			ll val = q.top().val; 
			if(u==n)return void(cout<<val<<el) ;
			q.pop() ; 
			if(f[u][have]<val)continue ; 
			for(auto x :g[u])
			{
				int v=x.v; 
				int dis = x.dis; 
				if((have|x.msk)==have)
				{
					if(mini(f[v][have|sword[v]],val+dis))
					{
						q.push({v,have|sword[v],f[v][have|sword[v]]}) ; 
					}
				}
			}
		}

		cout<<-1<<el;
	}
    void xuly()
    {
        dij() ;
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