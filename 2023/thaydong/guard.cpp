/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai, Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "guard"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int place , num , day ; 
int cost[N] ; 
vi g[N] ; 

void doc()
{
	cin >> place >> num >>day ;   
	FOR(i,1,day)cin >> cost[i] ;
	FOR(i,1,day)
	{
		int sl ; cin >> sl; 
		FOR(j ,1,sl )
		{
			int u ; cin >> u  ;
			g[i].pb(u) ; 
		}
	} 
	cost[1] = 0 ; 
}

namespace sub1
{
	bool exist[N] ; 
	ll f[N] ; 
    void xuly()
    {		
        FOR(i,1,day)f[i] = inf ; 
    	FOR(i,1,day)
    	{
            int cnt = 0 ;
    		FORD(j , i, 1 )
    		{
    			for(auto v : g[j])
    		  	{
                    cnt += (exist[v]==0) ; 
                    exist[v] = 1; 
    			}
                if(cnt<=num)mini(f[i],f[j-1]+cost[j]) ;
                else break;
    		} 
            FOR(j,1,i)for(auto v:g[j])exist[v] = 0 ;
        }
        cout<<f[day]<<" ";
        FOR(i,1,day)g[i].clear() ;
    }
}
namespace sub2
{
    ll f[N] ; 
    int exist[N] ;
    struct DL
    {
        int id ; 
        ll val ; 
    }; 
    void xuly()
    {
        FOR(i,1,day) f[i] = inf ;
        int cnt = 0 ;  
        deque<DL>dq;
        int it = 1 ; 
        dq.pb({0,0}); 
        FOR(i,1,day)
        {
            for(auto v: g[i])
            {   
                cnt+=(exist[v]==0) ;
                exist[v]++ ; 
            }
            while(cnt>num)
            {
                for(auto v: g[it])
                {
                    exist[v]-- ; 
                    cnt-=(exist[v]==0) ; 
                }
                ++it ; 
            }
            while(dq.front().id+1 < it )dq.pop_front();
            f[i] = dq.front().val; 
            while(!dq.empty()&&dq.back().val>=f[i]+cost[i+1])dq.pk() ; 
            dq.pb({i,f[i]+cost[i+1]}); 
        }
        cout<<f[day]<<" ";
        FOR(i,1,place)exist[i] = 0  ; 
        FOR(i,1,day)g[i].clear() ; 
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
    int sub ; cin>>sub ; 
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(sub==1)sub1::xuly() ; 
        sub2::xuly();  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}