/***************************************************************
*            Author : Nguyen Trong Van Viet                   *
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
#define sq(a) ((a)*(a))   
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
int T ; 
struct pt
{
	db x,y; 
}; 
pt a[N] ; 
// 
void doc()
{
    cin>> n  ;
    T = n ;
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].y ;
    }
}
	
namespace sub1
{
	bool check(db R)
	{
		FOR(i,1,n)
		{
			ve<pair<db,int>>q  ;
			int ans = 1 ; 
			FOR(j,1,n)if(i!=j)
			{
				db x = a[i].x , y= a[i].y , X = a[j].x , Y = a[j].y ; 
				db BC =sqrt(sq(x-X)+sq(y-Y)) ;
				if(BC>2*R+EPS)continue; 
				pt dv = {(X-x)/BC,(Y-y)/BC} ; 
				db BH = BC/2; 
				db AH = sqrt(sq(R)-sq(BH)) ;
				// {
					pt A = {(dv.x)*BH/R+(dv.y)*AH/R,-(dv.x)*AH/R+(dv.y)*BH/R};
					pt B = {(dv.x)*BH/R-(dv.y)*AH/R,(dv.x)*AH/R+(dv.y)*BH/R};
					db L = atan2(A.y,A.x) ;
					db R = atan2(B.y,B.x) ;
					if(L>R)ans++ ;
					q.pb({L,1}) ;
					q.pb({R+EPS,-1});
				// }
			}
			sort(all(q)) ; 
			for(auto v : q)
			{
				ans+=v.se ;
				if(ans>=T)return 1; 
			}
		}
		return 0 ;
	}
    void xuly()
    {
    	if(T==1)
    	{
    		cout<<"0.000";
    		return ;
    	}
    	db l = 0 ; 
    	db r = 1e9 ;
    	db ans = oo ;
    	while(abs(r-l)>1e-6)
    	{
    		db mid =(l+r)/2; 
    		if(check(mid))ans=mid,r=mid-EPS ;
    		else l=mid+EPS; 
    	}    	
    	cout<<setprecision(3)<<fixed;
    	cout<<ans<<el;
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