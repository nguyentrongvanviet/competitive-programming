/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "MAKELIST"
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


int n , k;  
str s[55][1505] ;
void doc()
{
    cin>> n >> k;
    FOR(i,1,n)
    {
    	FOR(j,1,k)
    	{ 
			cin>>s[i][j] ;
    	}
    }
}

namespace sub1
{
	ll f[55][105] ; 
	vll ha[55][105] ; 
    void xuly()
    {	
		ll mu[N] ; 
	    mu[0] = 1; 
	    FOR(i,1,n)mu[i]=mu[i-1]*cs%sm;  
    	FOR(i,1,n)
    	{
    		FOR(j,1,k)
    		{
    			ha[i][j].pb(0) ; 
    			FOR(t,1,i)
	    		{
	    			ha[i][j].pb((ha[i][j].back()*cs+s[i][j][t-1])%sm) ;
	    		}
	    	}
    	}
       	FOR(i,1,k)
       	{
       		f[1][i] = 1; 
       	} 
       	FOR(i,2,n)FOR(cur,1,k)
       	{
       		FOR(pre,1,k)
       		{
       			ll d= ha[i][cur][i-1] ; 
       			ll c= (ha[i][cur].back()-ha[i][cur][1]*mu[i-1]%sm+sm)%sm;
       			if(d==ha[i-1][pre].back()||c==ha[i-1][pre].back())
       			{
       				(f[i][cur]+=f[i-1][pre])%=sm; 
       			}
       		}
       	}
       	ll res = 0 ;
       	FOR(i,1,k)(res+=f[n][i])%=sm ; 
       	cout<<res;
    }
}
namespace sub2
{
	int T[75005][CH];
	ll sc[75005] ; 
	int node = 1;  
	void up(str &a , ll val)
	{
		int r = 1;
		for(auto c:a)
		{
			int j = c-'a' ;
			if(T[r][j]==0)
			{
				T[r][j]=++node; 
			}
			r=T[r][j] ; 
		} 
		(sc[r]+=val)%=sm; 
	}
	ll get(str &a ) 
	{
		int r =1 ;
		for(auto c:a)
		{
			int j= c-'a'; 
			r=T[r][j] ; 
			if(r==0)return 0 ; 
		}
		return sc[r] ; 
	}
	ll f[55][1505] ; 
	void xuly()
	{	
		FOR(i,1,k)
		{
			up(s[1][i],f[1][i]=1) ;  
		}
		FOR(i,2,n)
		{
			FOR(j,1,k)
			{
				str d = s[i][j].substr(0,i-1);
				f[i][j]=get(d) ;
				str c = s[i][j].substr(1) ;
				if(d!=c)(f[i][j]+=get(c))%=sm;
			}
			FOR(i,1,node)
			{
				sc[i] = 0  ; 
				FORN(j,0,CH)T[i][j] = 0; 
			}
			node = 1 ; 
			FOR(j,1,k)
			{
				up(s[i][j],f[i][j]) ; 
			}
		}
		ll res =0 ; 
		FOR(i,1,k)
		{
			(res+=f[n][i])%=sm; 
		}
		cout<<res; 
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
    else 
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