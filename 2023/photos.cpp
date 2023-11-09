/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "photos"
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
#define ce cerr 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define MSK(a) (1ll<<(a)) 
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm =  998244353; 
const int N = 1e5+5 , oo = 2e9 , LO = 29 , CH = 26 ; 

int n ; 
ll k ; 
int a[N] ; 
int s[N][LO+1] ; 
void doc()
{
    cin>> n >> k ; 
    FOR(i,1,n)cin>>a[i] ;  
    sort(a+1,a+n+1) ;
	FOR(i,1,n)
	{
	    FOR(j,0,LO)
	    {
			s[i][j] = s[i-1][j]+BIT(a[i],j) ; 
	    } 
	}
}

namespace sub1
{
	void add(int &a ,int b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	}
	pair<ll,int> count(int res ,int id)
	{
		ll ans = 0 ;
		int sum = 0 ; 
		FOR(i,1,n)
		{
			int val = (a[i]^res) ; 
			int l =(val&((MSK(LO+1)-1)<<id)) ; 
			int r =(val|(MSK(id)-1)); 
			l = LB(a+1,a+n+1,l)-a;	
			r = UB(a+1,a+n+1,r)-a-1 ;
			if(r<i||r<l)continue;
			ans+=r-l+1 ; 
			FOR(j,0,LO)
			{
				if(BIT(a[i],j))
				{
					add(sum,MSK(j)*(r-l+1-(s[r][j]-s[l-1][j])+sm)%sm) ; 
				}
				else add(sum,MSK(j)*(s[r][j]-s[l-1][j]+sm)%sm) ; 
			}
			if(ans>=k)return {inf,0};
		}  
		return mp(ans,sum);  
	}	
    void xuly()
    {
    	int res =0 ; 	
    	int sum = 0 ; 
    	FORD(i,LO,0)
    	{
    		pair<ll,int> val = count(res|(1ll<<i),i) ;
    		if(val.fi>=k) res|=(1<<i) ;
    		else k-=val.fi,add(sum,val.se) ; 
    	}
    	cout<<(sum+k*res%sm)%sm;
    }
}
namespace subtrau
{

	void xuly()
	{
		vi V ; 
		FOR(i,1,n)FOR(j,i+1,n) 
		{
			V.pb(a[i]^a[j]) ; 
		}
		sort(all(V),greater<int>());
		ll res =0 ; 
		FORN(i,0,k)(res+=V[i])%=sm ; 
		ce<<res<<el;
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
    // cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}