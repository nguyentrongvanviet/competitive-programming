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
const int N = 50+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int M , S ; 
int n; 
int a[N] ;
ll cur[N][(int)sqrt(1e9)+5] ; 
ll pre[N][(int)sqrt(1e9)+5] ; 
ll f[N][(int)sqrt(1e9)+5] ; 
void doc()
{
    cin>> M >> S ; 
    cin>> n; 
    int AVE = sqrt(M) ;
    cur[0][0] =1 ;
    FOR(j,1,AVE)
    {
    	cur[0][j]=1;
    	int above = min(M/j,S-j);
    	if(above<=AVE)continue ; 
    }

	FOR(i,1,n)
	{
		FOR(j,1,AVE)
		{	
			int above = min({AVE,S-j,M/j}) ;
			if(above>=1)(f[i][j]+=cur[i-1][above])%=sm ;
		}
		FOR(j,1,AVE)
		{
			(pre[i][j]+=pre[i][j-1])%=sm ; 
			(f[i][j]  += pre[i][j])%=sm;
			int above = min(M/j,S-j);
			if(above<=AVE)continue ;
			if(i>=2)(f[i][j]+=1ll*(above-AVE)*cur[i-2][j]%sm)%=sm; 
		}
		FOR(j,1,AVE)
		{
			cur[i][j]=(cur[i][j-1]+f[i][j])%sm ; 
			int above = min(M/j,S-j) ;
			if(above<=AVE)continue ;
			(pre[i+2][1]+=f[i][j]*(above-AVE)%sm)%=sm ;
			(pre[i+2][j]-=f[i][j]*(above-AVE)%sm-sm)%=sm;
		}
	}
	ll res =0 ; 
	FOR(j,1,AVE)(res+=f[n][j])%=sm ;
	if(n>=2)`
	{
		FOR(j,1,AVE)
		{
			int above = min(M/j,S-j) ;
			if(above<=AVE)continue;
			(res+=f[n-1][j]*(above-AVE)%sm)%=sm ; 
		}
	}
	cout<<res<<el; 
}

namespace sub1
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