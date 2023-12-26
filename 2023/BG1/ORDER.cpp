/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "ORDER"
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
struct DL
{
	ll cost ,val; 
}a[4][N] ;
void doc()
{	
	cin>> n ;
	FOR(i,1,3)
	{
		FOR(j,1,n)cin>>a[i][j].cost; 
		FOR(j,1,n)cin>>a[i][j].val ; 
	} 
}

namespace sub1
{
	int b[4] ;
    void xuly()
    {
    	ll res = 0 ;
        FOR(i,0,n)FOR(j,0,n)FOR(k,0,n)
        {
        	b[1] = i; 
        	b[2] = j;
        	b[3] = k;
        	map<ll,int>dd; 
        	ll sum = 0 ; 
        	bool ok = 1;
        	FOR(x,1,3)
        	{
        		FOR(pos,1,b[x])
        		{
        			if(dd.count(a[x][pos].cost))
        			{
        				ok =0 ; 
        				break; 
        			}
        			sum+=a[x][pos].val ;
        			dd[a[x][pos].cost]=1;
        		}
        	}
        	if(ok)maxi(res,sum) ; 
        }
        cout<<res<<el; 
    }
}
namespace sub2
{
	const int MA = 1e6+5 ;	
	int dd[MA]; 
	int b[4] ; 
	ll s[4][N] ; 
	ll ma[N] ;
	int D[4][MA] ; 
	void xuly()
	{
		FOR(i,1,3)
		{
			b[i] = n ;
			FOR(pos,1,n)
			{
				if(dd[a[i][pos].cost])
				{
					b[i] = pos-1; 
					break;
				}
				dd[a[i][pos].cost] = 1; 
			}
			FOR(pos,1,n)dd[a[i][pos].cost] = 0; 
		}
		FOR(i,1,3)
		{
			FOR(j,1,n)
			{
				s[i][j] = s[i][j-1]+a[i][j].val ;
				if(i==3)ma[j]=max(ma[j-1],s[i][j]) ;
			}
		}
		ll res = 0;
		FOR(i,0,b[1])
		{
			int it = b[3] ; 
			FOR(j,1,b[3])D[3][a[3][j].cost] = 1; 
			FOR(j,1,i)
			{
				D[1][a[1][j].cost] = 1 ; 
				while(it&&D[3][a[1][j].cost])
				{
					D[3][a[3][it].cost]=0;
					--it;
				}
			}
			FOR(j,0,b[2])
			{
				if(D[1][a[2][j].cost])break;
				D[2][a[2][j].cost]=1;
				while(it&&D[3][a[2][j].cost])
				{
					D[3][a[3][it].cost]=0 ;
					--it ;
				}
				maxi(res,s[1][i]+s[2][j]+ma[it]) ;	
			}

			FOR(j,1,3)
			{
				FOR(i,1,n)
				{
					D[j][a[j][i].cost]= 0; 
				}
			}
		}
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
        if(n<=30)sub1::xuly() ; 
        else 
        if(n<=5e3)sub2::xuly() ; 
        if(i!=test)
        {
        	ll e , s; cin>>e>>s ; 
        	FOR(x,1,3)
        	{
        		FOR(pos,1,n)
        		{
        			a[x][pos].val=(( ( (a[x][pos].val+M(20)) ^e ) + s )%M(21))-M(20);
        		}
        	}
        }
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}