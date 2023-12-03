/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PUZZLE"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;
int ST , EN ; 
vi A , B , C , D; 
int dau , cuoi ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n)
	{
		int TYPE , val ; cin>>TYPE >> val; 
		if(TYPE==1)A.pb(val) ; 
		if(TYPE==2)B.pb(val) ; 
		if(TYPE==3)C.pb(val) ; 
		if(TYPE==4)D.pb(val) ; 
		if(TYPE==5)ST = 1,dau=val ; 
		if(TYPE==6)ST = 0,dau=val ; 
		if(TYPE==7)EN = 0 ,cuoi=val;
		if(TYPE==8)EN = 1,cuoi=val ; 
	}
}

namespace sub1
{
    void xuly()
    {
    	sort(all(A),greater<int>()) ; 
    	sort(all(B),greater<int>()) ; 
    	sort(all(C),greater<int>()) ; 
    	sort(all(D),greater<int>()) ; 
    	vi res ; 
    	FOR(i,1,n-2)
    	{
    		if(ST==1)
    		{
    			int ok1 = 0 , ok2 = 0;  
    			if(!D.empty())
    			{		
    				if(A.empty()&&!C.empty())
    				{
    					// cannot 
    				}
    				else if(SZ(A)<SZ(D)-1||SZ(A)>SZ(D))
    				{	

    				}
    				else
    				{ 		
    					ok1 = 1 ;		
    				}
    			}
    			if(!C.empty())
    			{
					if(SZ(A)<SZ(D)-1||SZ(A)>SZ(D))
					{	
					}
					else
					{
						ok2 = 1 ; 
					}
    			}
				if(ok1+ok2==0)return void(cout<<"-1"<<el) ; 
				if(ok1&&(ok2==0||D.back()<C.back()))
				{
					ST = 0 ;  
					res.pb(D.back()) ;
					D.pk() ; 
				}
				else 
				{
					ST= 1  ;
					res.pb(C.back()) ;
					C.pk() ; 
				}

    		}
    		else if(ST==0)
    		{
    			int ok1 = 0 , ok2 = 0;  
    			if(!A.empty())
    			{		
    				if(D.empty()&&!B.empty())
    				{
    					// cannot 
    				}
    				else if(SZ(D)<SZ(A)-1||SZ(D)>SZ(A))
    				{	

    				}
    				else
    				{ 		
    					ok1 = 1 ;		
    				}
    			}
    			if(!B.empty())
    			{
					if(SZ(D)<SZ(A)-1||SZ(D)>SZ(A))
					{	
					}
					else
					{
						ok2 = 1 ; 
					}
    			}
				if(ok1+ok2==0)return void(cout<<"-1"<<el) ; 
				if(ok1&&(ok2==0||A.back()<B.back()))
				{
					ST = 1 ;  
					res.pb(A.back()) ;
					A.pk() ; 
				}
				else 
				{
					ST= 0 ; 
					res.pb(B.back()) ;
					B.pk() ; 
				}
    		}		
    	}
    	if(ST!=EN)return void(cout<<"-1") ; 
    	cout<<dau<<" ";
    	for(auto v:res)cout<<v<<" ";
    	cout<<cuoi<<el;
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
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}