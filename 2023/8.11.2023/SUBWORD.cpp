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
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 
str s ,t ; 
bool check(char a, char b)
{
	return abs(a-b)==abs('A'-'a') ;
}
str old; 
void doc()
{
	cin>>s>>t ; 
	old = t;  
	str news  ;  
	for(auto v:s)
	{ 
		if(!news.empty()&&check(news.back(),v))
		{
			news.pk() ;  
		}
		else
		{
			news.pb(v) ; 
		}
	}
	s=news ; 
	str newt ; 
	for(auto v:t)
	{
		if(!newt.empty()&&check(newt.back(),v))
		{
			newt.pk() ; 
		}
		else
		{
			newt.pb(v) ;
		}
	}
	t=newt ;
}

namespace sub1
{
	int f[N][N] ;
	char C(char x)
	{
		if('a'<=x&&x<='z')return x-'a'+'A' ; 
		return x-'A'+'a' ; 
	} 
	void xuly()
	{
		n = SZ(s) ; 
		m = SZ(t) ;
		if(n==0&&m==0)return void(cout<<old) ; 
		if(m==0)
		{
			return void(cout<<old<<s);
		}
		if(n==0)
		{
			cout<<old ; 
			reverse(all(t)) ; 
			cout<<t ;
			return ;
		}
		s="#"+s ; 
		t="$"+t ;
		FOR(i,1,n)FOR(j,1,m)
		{
			if(s[i]==t[j])f[i][j] = f[i-1][j-1]+1; 
			else f[i][j] = 0 ;
		}	
		int res =  oo ; 
		int res_l=0 , res_r=0, res_u=0 , res_v=0 ; 
		FOR(i,1,n)FOR(j,1,m)
		{	
			int len = f[i][j] ; 
			int v = i; 
			int	u = i-len+1 ; 
			int	r = j ; 
			int	l = j-len+1 ; 
			if(mini(res,SZ(old) + m-r + n-v + u-1 + l-1))
			{	
					res_u = u ; 
				res_v = v ; 
				res_l = l ; 
				res_r = r ; 
			}
		}
		int u = res_u ; 
		int v = res_v; 
		int l = res_l ; 
		int r = res_r ;
		str R ; 
		str L ; 
		FORD(i,m,r+1)
		{
			R+=C(t[i]) ; 
		}
		FOR(i,v+1,n)R+=s[i] ; 
		FOR(i,1,u-1)L+=s[i] ; 
		FORD(i,l-1,1)
		{
			L+=C(t[i]) ; 
		}

		cout<<L<<old<<R;
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
