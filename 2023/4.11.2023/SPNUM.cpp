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
const int N = 1e7+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int nt[205] ; 
void snt()
{
	nt[0] = -1 ; 
	FOR(i,2,200)
	{
		if(nt[i]==0)
		{
			nt[i] =i ; 
			FOR(j,i,200/i)nt[i*j]= i ;
		}
	}
} ; 
int n ;
bool check(ll val)
{
	int sum_cs = 0 ;

	while(val)
	{
		sum_cs+=val%10 ; 
		val/=10 ; 
	}
	return nt[sum_cs] ==sum_cs ;
}
int s[N] ; 
void doc()
{
	FOR(i,1,1e7)
	{
		ll val = sq(i) ; 
		s[i] = s[i-1]+check(val) ; 
	}
}

namespace sub1
{
	ll f[15][2][200];	
	int c[N] ;
	ll cal(int id ,int ok ,int sum)
	{
		if(id==0)return nt[sum] ==sum ; 
		ll &val =f[id][ok][sum] ;
		if(val!=-1)return val ; 
		val = 0 ;
		if(ok)
		{	
			FOR(i,0,9)
				val+=cal(id-1,1,sum+i) ;
		}	
		else
		{	
			val+=cal(id-1,0,sum+c[id]);  
			FORN(i,0,c[id])
				val+=cal(id-1,1,sum+i) ; 
		}
		return val; 
	}
	ll tinh(ll val)
	{	
		if(val==0)return 0 ;
		int cnt = 0; 
		while(val)
		{
			c[++cnt]=val%10 ; 
			val/=10 ; 
		}
		FOR(i,1,cnt)FOR(ok,0,1)FOR(j,0,9*cnt)f[i][ok][j]=-1;
		ll res =0  ;
		FORN(i,0,c[cnt])
		{
			res+=cal(cnt-1,1,i);
		}
		res+=cal(cnt-1,0,c[cnt]) ; 
		return res ; 
	}
    void xuly()
    {
    	ll L , R; 
    	cin>> L >> R ; 
    	ll r = sqrt(R) ; 
    	ll l = sqrt(L) ;  
    	if(l*l!=L)++l ;
    	cout<<tinh(R)-tinh(L-1)-(s[r]-s[l-1])<<el;
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
    snt() ; 
    doc() ; 
    FOR(i,1,test)
    {
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}