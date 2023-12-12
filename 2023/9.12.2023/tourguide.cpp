/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tourguide"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+22071997; 
const int N = 2500005 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;
str a ; 
void doc()
{
	cin>>a; 
	n = SZ(a) ; 
	a="%"+a;     
}

// namespace sub1
// {
// 	int s[CH+2]; 
// 	int bit[CH+2][2*N] ;
// 	void add(int &a, int b)
// 	{
// 		a+=b ;
// 		if(a>=sm)a-=sm; 
// 	}
// 	void sub(int &a, int b)
// 	{
// 		a-=b; 
// 		if(a<0)a+=sm ;
// 	}
// 	void up(int c, int pos ,int val)
// 	{
// 		pos+=n+1; 
// 		for(int i=pos;i<=2*n+1;i+=i&-i)add(bit[c][i],val) ; 
// 	}
// 	int get(int c, int pos)
// 	{
// 		pos+=n ;
// 		int ans = 0 ; 
// 		for(int i=pos;i;i-=i&-i)add(ans,bit[c][i]) ;
// 		return ans ; 
// 	}
//     void xuly()
//     {
//     	int tot = 1 ; 
//     	int sum = 1 ; 
//     	FOR(i,1,n)
//     	{
//     		FORN(j,0,CH)
//     		{
//     			s[j]+=(a[i-1]-'a'==j) ;
//     			up(j,2*s[j]-i+1,tot); 
//     		}
//     		tot=sum;
//     		FORN(j,0,CH)
//     		{
//     			sub(tot, get( j , 2 * ( s[j] + (a[i]-'a'==j) ) -i ) ) ;
//     		}	
//     		add(sum,tot);
//     	}
//     	cout<<tot<<el;
//     }
// }
namespace sub2
{
	void add(int &a ,int b)
	{
		a+=b; 
		if(a>=sm)a-=sm ; 
	}
	void sub(int &a ,int b)
	{
		a-=b; 
		if(a<0)a+=sm; 
	}
	pii cur[CH] ; 
	int pre[CH];
	int s[CH][2*N] ;
	int f[N] ; 

	void up(int j ,int pos , int val)
	{
		pos+=n+1; 
		add(s[j][pos],val) ;
		if(pos<=cur[j].fi)add(cur[j].se,val) ;
	} 
	int get(int j ,int pos)
	{		
		pos+=n+1 ; 
		while(cur[j].fi<pos)
		{
			++cur[j].fi ;
			add(cur[j].se,s[j][cur[j].fi]) ;
		}
		while(pos<cur[j].fi)
		{
			sub(cur[j].se,s[j][cur[j].fi]) ;
			--cur[j].fi; 
		}
		return cur[j].se; 
	}
	void xuly()
	{
		FORN(j,0,CH)cur[j].fi=1;
		f[0] = 1; 
		int tot = 1 ; 
		FOR(i,1,n)
		{
			f[i] = tot ; 
			FORN(j,0,CH)
			{
				up(j,pre[j],f[i-1]) ;
				if(a[i]-'a'==j)pre[j]++ ; 
				else pre[j]-- ; 
				sub(f[i],get(j,pre[j]-1)) ; 
			}
			add(tot,f[i]) ;
		}
		cout<<f[n]<<el;
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
        sub2::xuly();
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}