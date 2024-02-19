/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "chemistry"
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


int n ; 
int a[N] ; 

void doc()
{
    FOR(i,1,n)cin>>a[i] ; 
}		
namespace sub1
{
	bitset<M(10)>f[N][M(10)]; 
	char res[N] ; 	
	void xuly()
	{
		FOR(i,1,n)FORN(val1,0,M(10))FORN(val2,0,M(10))f[i][val1][val2] = 0;  	
		f[0][0][0] =1  ;  
		FOR(i,1,n)
		{
			FORN(val1,0,M(10))FORN(val2,0,M(10))
			{
				if(f[i-1][val1][val2]==1)
				{
					f[i][val1^a[i]][val2] = 1 ; 
					f[i][val1][val2^a[i]] = 1 ;
					f[i][val1][val2] = 1 ;
				}
			}
		}
		int tot = 0; 
		FOR(i,1,n)tot^=a[i] ;
		int ma = 0 ; 
		int res_val1 = 0 ,res_val2 = 0 ; 
		FORN(val1,0,M(10))FORN(val2,0,M(10))if(f[n][val1][val2])
		{	
			if(maxi(ma,val1+val2+(tot^val1^val2)))res_val1=val1,res_val2=val2 ;  
		}
		vi sf1, sf2, sf3 ; 
		FORD(i,n,1)
		{
			if(f[i-1][res_val1][res_val2])
			{
				sf3.pb(i) ; 
			}
			else if(f[i-1][res_val1^a[i]][res_val2])
			{
				res_val1^=a[i] ; 
				sf1.pb(i) ; 
			}
			else 
			{
				res_val2^=a[i] ;
				sf2.pb(i) ; 
			}
		}
		if(SZ(sf2)<SZ(sf3))swap(sf2,sf3) ; 
		if(SZ(sf1)<SZ(sf2))swap(sf1,sf2) ; 
		if(sf2.empty())
		{
			sf2.pb(sf1.back()) ;  
			sf1.pk() ; 
		}
		if(sf3.empty())
		{
			sf3.pb(sf1.back()) ; 
			sf1.pk() ; 
		} 
		for(auto u :sf1)res[u] = 'P' ; 
		for(auto u :sf2)res[u] = 'V' ;
		for(auto u :sf3)res[u] = 'H' ;
		FOR(i,1,n)cout<<res[i];
		cout<<el;
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
    int sub ; 
    cin>>sub ;
    FOR(i,1,test)
    {
    	while(cin>>n)
    	{
    		if(n==0)break;
    		doc() ; 
	        sub1::xuly() ; 
    	} 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}