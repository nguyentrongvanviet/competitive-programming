/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int sl_mt , sl_dh ; 
struct DL
{
	int c ,f , v ; 
	bool operator<(const DL&a)const
	{
		return f>a.f ;  
	}
}; 
DL mt[N] , dh[N] ; 
void doc() 
{
	cin>> sl_mt ; 
	FOR(i,1,sl_mt)
	{
		cin>>mt[i].c>>mt[i].f>>mt[i].v; 
	}	
	cin>>sl_dh ; 
	FOR(i,1,sl_dh)
	{
		cin>>dh[i].c>>dh[i].f>>dh[i].v ; 
	}
}
ll f[N] ;
ll cur[N] ; 
int s[N] ;
void up(int id,int S)
{
	FOR(i,0,S)cur[i] = f[i] ; 
	FOR(i,0,S)
	{
		maxi(cur[i+mt[id].c],f[i]-mt[id].v);
	}	
	FOR(i,0,S)f[i] = cur[i] ; 
} 
void ban(int id,int S)
{
	FOR(i,0,S)cur[i] = f[i] ; 
	FOR(i,0,S)if(i-dh[id].c>=0)
	{
		maxi(cur[i-dh[id].c],f[i]+dh[id].v);
	}	
	FOR(i,0,S)f[i] = cur[i] ;
}
void xuly()
{
    sort(mt+1,mt+sl_mt+1) ; 
    sort(dh+1,dh+sl_dh+1) ; 
    
    FOR(i,1,sl_mt)
    	s[i] = s[i-1]+mt[i].c ;
    FOR(i,1,s[sl_mt])
    	f[i] = -inf ; 
    
    s[sl_mt+1] = s[sl_mt] ; 
    
    int it = 1 ; 
    FOR(i,1,sl_dh)
    {
    	while(dh[i].f<=mt[it].f&&it<=sl_mt)
    	{
    		up(it,s[it+1]) ; 
    		++it ; 
    	}
    	ban(i,s[it]) ; 
    }
    ll res = 0 ; 
    FOR(i,0,sl_mt)maxi(res,f[i]) ; 
    cout<<res; 
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}