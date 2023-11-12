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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ; 
str A , B  ;
bool check(char a , char b)
{
	return abs(a-b)==('a'-'A') ; 
}
str trans(str S)
{
	str ans ; 
	for(auto v : S)
	{
		if(!ans.empty()&&check(ans.back(),v))
		{
			ans.pk() ; 
		}
		else ans+=v; 
	}
	return ans ; 
}
str old ; 
void doc()
{
    cin>>A >> B ;
    old = B ;

    A = trans(A) ; 
    B = trans(B) ; 
}

namespace sub1
{
	const int N = 2e3+5; 
	int f[N][N] ;
	char C(char c)
	{
		if('a'<=c&&c<='z')return c-'a'+'A' ;
		return c-'A'+'a' ; 
	}
    void xuly()
    {
    	int n = SZ(A) ; 
    	int m = SZ(B) ; 
    	if(n==0)
    	{
    		cout<<old ; 
    		reverse(all(B)) ; 
    		for(auto c :B)cout<<C(c) ; 
    		return; 
    	}
    	if(m==0)
    	{
    		cout<<old<<A<<el;
    		return ; 
    	}
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		if(A[i-1]==B[j-1])f[i][j] = f[i-1][j-1] + 1 ; 
    		else f[i][j] = 0 ;
    	}

    	int best_A = 0 , best_B = 0 ;
    	int ma = 0 ; 
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		if(maxi(ma,f[i][j]))
    		{
    			best_A = i ;
    			best_B = j ; 
    		}
    	}
    	if(ma==0)
    	{
    		cout<<old ;
    		reverse(all(B)) ;
    		for(auto c :B)cout<<C(c) ;
    		cout<<A<<el; 
    		return ; 
    	}
    	int l = best_A-ma+1; 
    	int r = best_A ; 
    	int L = best_B-ma+1; 
    	int R = best_B ; 
    	FOR(i,1,l-1)cout<<A[i-1] ; 
    	FORD(i,L-1,1)cout<<C(B[i-1]) ; 
    	cout<<old ;
    	FORD(i,m,R+1)cout<<C(B[i-1]);
    	FOR(i,r+1,n)cout<<A[i-1]; 
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