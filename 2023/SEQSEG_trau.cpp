/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "SEQSEG"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ; 
int a[N] ; 
ll s[N] ; 
void doc()
{
    cin>> n >>  k; 
    FOR(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i] ; 
}

namespace sub1
{
	ll f[N][N] ;
    void xuly()
    {
    	++k;
    	FOR(i,1,n)
    	{
    		f[i][1]  =0;
		}
		FOR(j,2,k)
		{
			FOR(i,j,n)
			{
				FOR(ii,j-1,i-1)
				{
					maxi(f[i][j],f[ii][j-1]+(s[i]-s[ii])*s[ii]); 
				}
			}
		}
		FOR(i,1,n)cout<<f[i][2]<<" ";
		cout<<el;
		cout<<f[n][k];
    }
}
namespace sub2
{
	ll f[N][N] ;
	ll cost(int l ,int r)
	{
		return (s[r]-s[l])*s[l];
	}
	void solve(int k, int l, int r, int oL , int oR)
	{
		if(l>r)return ; 
		int mid =(l+r)/2 ;
		int pos ;
		FOR(i,oL,min(mid,oR))
		{
			if(maxi(f[mid][k],f[i-1][k-1]+cost(i-1,mid)))pos=l;
		}
		solve(k,l,mid-1,oL,pos) ; 
		solve(k,mid+1,r,pos,oR) ; 
	}
	void xuly()
	{
		++k ;
		FOR(i,2,k)
		{
			solve(i,i,n,i,n) ;
		}
		cout<<f[n][k];
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        // sub2::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}