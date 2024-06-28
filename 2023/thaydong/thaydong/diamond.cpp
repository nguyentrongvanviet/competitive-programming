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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define          SZ(_)  (int)(_.size())
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
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 



int n ,  m , TIEN , KC ; 
int a[N] ; 
struct ke
{
	int v; ll w ; 
} ; 
ve<ke>g[N]; 
void doc()
{
	cin>> n >> m >>TIEN>>KC; 
	FOR(i,1,n)cin>>a[i] ;     
	FOR(i,1,m)
	{
		int u ,v  ; 
		ll w ;cin>>u>>v>>w ;
		g[u].pb({v,w}) ;
	}
}

namespace sub1
{
	struct DL
	{
		ll kc , tien ; 
		bool operator<(const DL&a)const
		{
			return kc>a.kc||(kc==a.kc&&tien>a.tien) ; 
		}
		bool operator>(const DL&a)const
		{
			return kc<a.kc||(kc==a.kc&&tien<a.tien) ; 
		}
	}; 
	struct BG
	{
		int u , ma ;	
		DL tmp; 
	}; 
	struct cmp
	{
		bool operator()(const BG&a ,const BG&b)const
		{
			return a.tmp>b.tmp ; 
		}
	}; 
	DL f[N][N] ;
	ll dij()
	{
		priority_queue<BG,ve<BG>,cmp>q ; 
		FOR(i,1,n)FOR(j,1,n)f[i][j] = {-1,-1} ; 
		q.push({1,1,f[1][1]=DL{KC,TIEN}});
		while(!q.empty())
		{
			int u =q.top().u ; 
			int ma = q.top().ma; 
			ll kc = q.top().tmp.kc ;
			ll tien = q.top().tmp.tien;  
			q.pop() ; 
			if(f[u][ma]<DL{kc,tien})continue ; 
			for(auto x:g[u])
			{
				int v= x.v; 
				int w= x.w; 
				int nma = (a[ma]<a[v]?v:ma) ; 
				if(tien>=w)
				{
					if(mini(f[v][nma],DL{kc,tien-w}))q.push({v,nma,f[v][nma]}) ; 
				}
				else
				{
					w-=tien; 
					ll use =  w/a[ma]+(w%a[ma]!=0) ; 
					if(kc>=use)
					{
						if(mini(f[v][nma],{kc-use,use*a[ma]-w}))q.push({v,nma,f[v][nma]}) ; 
					}
				}
			}
		}
		ll res =-1; 
		FOR(i,1,n)maxi(res,f[n][i].kc) ; 
		return res; 
	} 
    void xuly()
    {
    	cout<<dij() ;     
    }
}
namespace subtrau
{   
    void xuly()
    {   
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}