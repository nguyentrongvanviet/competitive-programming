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
#define int long long 
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

ll MA ; 
int q; 
void doc()
{
	cin>>MA>>q ; 
}

namespace sub1
{
	struct DL
	{
		ll l , r ; 
		ll pos ;  
		ll val; 
		DL (ll _l , ll _r)
		{
			l=_l ; 
			r=_r ; 
			if(r>=MA)r=2*MA-l ;
			if(l<=1)l=2-r ;
			pos =(l+r)/2 ; 
			val = pos-l ; 
		}
	}; 
	struct cmp
	{
		bool operator()(const DL&a, const DL&b)const
		{
			return (a.val>b.val)||(a.val==b.val&&a.pos<b.pos);
		}
	}; 	
	set<DL,cmp>s; 
	map<ll,ll>L , R ;
	ll a[N] ;
    void xuly()
    {
    	int sl = 0; 
    	s.insert(DL(0,MA+1));
    	L[DL(0,MA+1).r]=DL(0,MA+1).l;
    	R[DL(0,MA+1).l]=DL(0,MA+1).r;
    	FOR(i,1,q)
        {
        	int TYPE ; cin>>TYPE ; 
        	if(TYPE==1)
        	{
        		++sl ;
        		DL tmp = *s.begin() ;
        		s.erase(s.begin());
        		ll l = tmp.l ; 
        		ll r = tmp.r ;  	
        		R.erase(l) ; 
        		L.erase(r) ; 
        		ll pos = tmp.pos ; 
        		a[sl] =  pos ; 
        		if(pos-1>=max(1ll,l))
        		{
        			s.insert(DL(l,pos-1)) ; 
	        		L[pos-1] = DL(l,pos-1).l ;
	        		R[DL(l,pos-1).l]=pos-1; 
        		}
        		if(pos+1<=min(r,MA))
        		{
        			s.insert(DL(pos+1,r)) ;
        			R[pos+1] = DL(pos+1,r).r ;
        			L[DL(pos+1,r).r] = pos+1; 
        		} 
        	}
       		else
       		{
       			int id; cin>>id ;
       			ll pos = a[id] ;  
       			ll l = pos ; 
	       		if(L.count(pos-1))l=L[pos-1],s.erase(DL(l,pos-1)),L.erase(pos-1) ;
       			ll r = pos ;
       			if(R.count(pos+1))r=R[pos+1],s.erase(DL(pos+1,r)),R.erase(pos+1) ; 
       			s.insert(DL(l,r));
       			L[DL(l,r).r]=DL(l,r).l ; 
       			R[DL(l,r).l]=DL(l,r).r ; 
       		}
        }	
        FOR(i,1,sl)cout<<a[i]<<el;
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
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}