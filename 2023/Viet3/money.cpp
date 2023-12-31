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
ll k ;
int a[N] ; 
void doc()
{
	cin>>n>>k;
	FOR(i,1,n) 
	{
		cin>>a[i];
	}
}

namespace sub12
{
	int f[5001];
	int tms = 0;
	vi val;
	void add(int &a, int b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	}
	void xuly()
	{
		FOR(i,1,n) val.pb(a[i]);
		sort(all(val));
		val.resize(unique(all(val)) - val.begin());
		f[0] =1 ;
		tms = 0;
		for(auto u : val)
		{
			FORD(i,k,1)
			{	
				for(int cnt = 1 ;cnt * u <= i;cnt++) 
				add(f[i] , f[i - cnt * u]);
			} 
		}
		cout<<f[k] ; 
	}
}
namespace sub3
{
	void xuly()
	{
		if(a[1]>=sqrt(k))
		{
			int res = 0 ; 
			FOR(i,0,k/a[1])
			{
				if((k-a[1]*i)%a[2]==0)res++;
			}
			cout<<res<<el;
		}
		else
		{
			int st = -1 ; 
			int en = -1 ;
			FOR(i,0,k/a[2])
			{	
				if(a[2]*i%a[1] == k%a[1] )
				{
					if(st==-1)st=i ;
					else if(en==-1)en=i ;
				}
			}		
			if(st==-1&&en==-1)
			{
				cout<<0<<el;
			}
			else
			{
				if(en==-1)cout<<1<<el;
				else 
				{
					cout<<(k/a[2]-st)/(en-st)+1<<el;
				}	
			}
		}
	}	
}
namespace sub4
{
	const int N = 105 ;
	void add(int &a ,int b)
	{
		a+=b ;
		if(a>=sm)a-=sm ; 
	}
	int f[60][N] ;
	int way[N] ; 
	int S = 0 ; 
	int tinh(int id , int pre)
	{
		if(id==-1)
		{
			return pre==0 ;
		}
		int &val = f[id][pre] ;
		if(val!=-1)return val ;
		val = 0 ;
		FOR(i,0,S)
		{
			int cl = (pre<<1) + BIT(k,id)-i ;
			if(0<=cl&&cl<=S)add(val,1ll*tinh(id-1,cl)*way[i]%sm) ;
		} 
		return val ;
	}
	void xuly()
	{
		FOR(i,1,n)S+=a[i] ; 
		way[0] = 1; 
		FOR(i,1,n)
		{
			FORD(j,S,0)if(j>=a[i])add(way[j],way[j-a[i]]) ;
		}
		FORD(i,59,0)FOR(j,0,S)f[i][j] = -1 ;
		int res = tinh(59,0) ;
		cout<<res<<el;
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
        if(k<=1ll*5e3)sub12::xuly() ; 
        else 
        if(n==2)sub3::xuly() ;
        else
         sub4::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}