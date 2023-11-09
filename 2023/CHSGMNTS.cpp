/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                                *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
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
int a[N] ; 
vi pos[N]; 
void doc()
{
   	cin>> n; 
   	FOR(i,1,n)pos[i].clear() ; 
   	vi V;
   	FOR(i,1,n)cin>>a[i] ,V.pb(a[i]);
   	uni(V) ; 
   	FOR(i,1,n)a[i]=UB(all(V),a[i])-V.begin(),pos[a[i]].pb(i) ;  
}

namespace sub1
{
	int dd[N] ; 
	struct range
	{
		int l, r; 
	}; 
	struct cmp
	{
		bool operator()(const range&a, const range&b)const
		{
			return a.l<b.l||(a.l==b.l&&a.r<b.r ) ; 
		}
	} ; 
	ll C(int l ,int r)
	{
		return 1ll*(r-l+1)*(r-l+2)/2;
	}
    void xuly()
    {
    	ll res = 0 ;
        FOR(i,1,n-1)
        {
        	FOR(j,1,n)dd[j] = 0 ;
        	set<range,cmp>S; 
        	S.insert({i+1,n});
        	ll tot = C(i+1,n) ; 
        	FOR(j,i,n)
        	{
	        	int val = a[j] ; 
        		if(dd[val]==0)
        		{
	        		dd[val]= 1; 
	        		for(auto v: pos[val])
	        		{
	        			auto it = S.UB({v,oo});
	        			if(it==S.begin())continue ;
	        			--it;
	        			int l =(*it).l ; 
	        			int r =(*it).r ;
	        			if(r<v)continue ; 
	        			tot-=C(l,r) ; 
	        			S.erase(it) ; 
	        			if(l<=v-1)
	        			{
	        				tot+=C(l,v-1) ;
	        				S.insert({l,v-1});
	        			}
	        			if(v+1<=r)
	        			{
	        				tot+=C(v+1,r) ;
	        				S.insert({v+1,r}) ;
	        			}
	        		}
	        	}
        		res+=tot; 
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