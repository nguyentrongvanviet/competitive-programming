/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "DOLL"
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


int n; 
int a[N] ;

void doc()
{
    cin>> n; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }

}

namespace sub1
{
	int f[N] ; 
	int tmp[N] ;
    void xuly()
    {
        set<int>s; 
        FOR(i,1,n)
        {
        	s.insert(a[i]) ; 
        	int cnt = 0 ; 
        	for(auto v:s)
        	{
        		tmp[++cnt] = v;  
        	}
        	FOR(i,1,cnt)
        	{
        		f[i] = 1; 
        		if(tmp[i-1]+1!=tmp[i])f[i]=f[i-1]+1; 
        		else f[i] =f[i-2]+1; 
        	}
        	cout<<f[cnt]<<" ";
        }
    }
}
namespace sub2
{
	const int MAX = 500000; 
	int exist[MAX+4];
	int pa[MAX+5] ; 
	int sz[MAX+5] ; 
	int goc(int u)
	{
		return pa[u] ==u ? u : pa[u] = goc(pa[u]) ; 
	}
	int ANS = 0 ; 
	void xuly()
	{
		FOR(i,1,MAX)pa[i] = i ,sz[i] = 0 ; 

		FOR(i,1,n)
		{
			if(exist[a[i]]==0)
			{
				pa[a[i]] = a[i] ; 
				sz[a[i]] = 1; 
				exist[a[i]] = 1 ;
				if(exist[a[i]-1])
				{
					int chau = goc(a[i]-1) ; 
					ANS-=(sz[chau]+1)/2 ;
					pa[a[i]] = chau ; 
					sz[chau]++ ;
				}
				if(exist[a[i]+1])
				{
					int chav = goc(a[i]+1) ; 
					ANS-=(sz[chav]+1)/2 ;
					sz[chav]+=sz[goc(a[i])] ; 	
					pa[goc(a[i])]=chav ;
				}
				ANS+=(sz[goc(a[i])]+1)/2;
			}
			cout<<ANS<<" ";
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
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}