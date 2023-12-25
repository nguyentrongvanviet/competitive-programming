/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "LQUERY"
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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n, q; 
struct Query
{
	int type , l ,r , val; 
}Q[N] ;
int a[N] ; 
int LEN ; 
void doc()
{
    cin>> n >>q ;
    FOR(i,1,n)cin>>a[i] ; 
    LEN = n ;
    FOR(i,1,q)
    {
    	int type ;cin>>type ; 
    	Q[i].type= type ;
    	if(type==1)cin>>Q[i].val,++LEN; 
    	else if(type==2){}
    	else if(type==3)cin>>Q[i].val; 
    	else cin>>Q[i].l>>Q[i].r>>Q[i].val;
    }
}

namespace sub1
{
    void xuly()
    {
    	FOR(i,1,q)
    	{
    		int type = Q[i].type; 
    		if(type==1)
    		{
    			++n ;
    			a[n] = Q[i].val;
    		} 
	    	else if(type==2)--n;
	    	else if(type==3)
	    	{
				FOR(pos,1,n)a[pos]=(a[pos]^Q[i].val) ;
	    	}
	    	else
	    	{
	    		int l =Q[i].l; 
	    		int r = Q[i].r ;
	    		int val = Q[i].val; 
	    		if(type==4)
	    		{
	    			int res =0 ; 
	    			FOR(pos,l,r)
	    			{
	    				maxi(res,a[pos]^val) ; 
	    			}
	    			cout<<res<<el;
	    		}
	    		if(type==5)
	    		{
	    			int res = 0 ;
	    			FOR(pos,l,r)res+=(a[pos]<=val) ; 
	    			cout<<res<<el;
	    		}
	    		if(type==6)
	    		{ 
	    			vi  V; 
	    			FOR(pos,l,r)
	    			{
	    				V.pb(a[pos]) ; 
	    			}
	    			sort(all(V)) ;
	    			cout<<V[val-1]<<el;
	    		}
	    	}
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
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(max(n,q)<=1e3)sub1::xuly() ; 
        // sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}