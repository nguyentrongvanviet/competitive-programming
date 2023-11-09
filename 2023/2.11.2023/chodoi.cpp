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
const int N = 4e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
vi V; 
struct range
{
	int L , R ; 
} ;
range a[N] ;
int q[N] ;
void doc()
{
    cin>> n >> m ; 
    FOR(i,1,n)
    {
    	cin>>a[i].L>>a[i].R ;
    	--a[i].R; 
 		V.pb(a[i].L) ; 
 		V.pb(a[i].R) ; 
    }
    FOR(i,1,m)
    {
    	int tiem ;
    	cin>>tiem ; 
    	V.pb(tiem) ; 
    	q[i] = tiem; 
    }
    uni(V) ; 
}

namespace sub1
{
	int s[N] ;
	int L[N] ;
    void xuly()
    {
        FOR(i,1,n)
        {
        	a[i].L = UB(all(V),a[i].L)-V.begin() ; 
        	a[i].R = UB(all(V),a[i].R)-V.begin() ; 
        	s[a[i].L]++ ; 
        	s[a[i].R+1]-- ;
        }
        FOR(i,1,SZ(V)) 
        {
        	s[i]+=s[i-1] ; 
        }
        L[SZ(V)+1] = oo ; 
        FORD(i,SZ(V),1)
        {
        	L[i] = L[i+1] ; 
        	if(s[i])L[i]= V[i-1];
        }
        FOR(i,1,m)
        {
        	int pos = UB(all(V),q[i])-V.begin() ; 
        	if(s[pos])cout<<0<<el; 
        	else if(L[pos]==oo) cout<<-1<<el; 
        	else cout<<L[pos]-q[i]<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}