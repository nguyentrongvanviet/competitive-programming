/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "divsubset"
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
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
ll k ;
ll a[N] ; 
void doc()
{
    cin>> n >> k;  

    FOR(i,1,n)
    {
    	cin>>a[i] ;
    }
}	

namespace sub3
{
	struct DL
	{
		int len ; 
		ll sum ; 
		bool operator<(const DL&a)const
		{
			return len<a.len||(len==a.len&&sum<a.sum) ;
		}
		bool operator>(const DL&a)const
		{
			return len>a.len||(len==a.len&&sum>a.sum) ;
		}
	} ; 
	map<ll,DL>f[N]  ; 
	map<ll,ll>pre[N] ; 
	void trace(int n ,ll k )
	{
		if(k==1)return ; 
		ll x= pre[n][k]; 
		if(x!=k)
		{
			cout<<n<<" ";
		}
		trace(n-1,x) ;
	}	
	void xuly()
	{
		if(k==1)
		{
			cout<<1<<el; 
			cout<<min_element(a+1,a+n+1)-a<<el;
			exit(0) ;
		}
		f[0][1]  = {0,0};
		pre[0][1] = 1  ;
		FOR(i,1,n)
		{
			f[i] = f[i-1] ; 
			for(auto x : pre[i-1])pre[i][x.fi] = x.fi ;
			for(auto x : f[i-1])
			{
				ll j = x.fi ;
				int len = x.se.len ;
				ll sum = x.se.sum ;  
				ll d= gcd(a[i],k)*gcd(k/gcd(a[i],k),j) ; 
				if(f[i].count(d)==0)
				{
					f[i][d]={len+1,sum+a[i]} ;
					pre[i][d] =j;
				}  
				else if(mini(f[i][d],DL{len+1,sum+a[i]}))
				{
					pre[i][d] = j ;
				}
			}
		}
		if(f[n].count(k)==0)
		{
			return void(cout<<-1) ; 
		}
		cout<<f[n][k].len<<el;
		trace(n,k) ; 
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
    int sub ; cin>>sub ; 
    FOR(i,1,test)
    {
        doc() ; 
       	// if(sub==1)sub1::xuly() ; 
    	// if(sub==2)sub2::xuly() ; 
    	sub3::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}	