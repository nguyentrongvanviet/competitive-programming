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
const int N = 2e5+5 , oo = 1e9 , LO = 17 , CH = 26 ; 

int n ; 
struct Seg
{
	int id  ,  l ,r   , c; 
} ; 
Seg a[N] ,b[N] ;
void doc()
{
    cin>> n ; 
    FOR(i,1,n)
    {
    	cin>>a[i].l>>a[i].r>>a[i].c;
    	a[i].id = i ; 
    	b[i] = a[i] ;
    }
}

namespace sub1
{
	pii ma1 , ma2 ; 
	void up(pii x )
	{
		if(ma1.se==x.se)
		{
			maxi(ma1.fi,x.fi) ;
		}
		else 
		{
			if(ma1.fi<=x.fi)
			{
				ma2 = ma1 ;  
				ma1 = x ;  
			}
			else if(ma2.fi<x.fi) 
			{
				ma2 = x ; 
			}
		}
	}
	int res[N] ;
	void solve()
	{
    	ma1 = {-oo,0}; 
    	ma2 = {-oo,0};
    	sort(b+1,b+n+1,[](Seg x , Seg y )
		{	
			return x.l<y.l ; 
		}) ; 
		sort(a+1,a+n+1,[](Seg x , Seg y)
		{
			return x.r<y.r; 
		}) ;
		int it = 1 ; 
		FOR(i,1,n)
		{
			while(it<=n&&b[it].l<=a[i].r)
			{
				up(mp(b[it].r,b[it].c)); 
				++it ; 
			}  
			if(ma1.se==a[i].c)
			{	
				mini(res[a[i].id],max(0,a[i].l-ma2.fi));
			}
			else
			{	
				mini(res[a[i].id],max(0,a[i].l-ma1.fi));
			}
		}
	}
    void xuly()	
    {	
    	FOR(i,1,n)res[i]= oo ;
    	solve();
    	FOR(i,1,n)
    	{
    		int l = 1e9-a[i].r+1; 
    		int r = 1e9-a[i].l+1 ; 
    		a[i].l=l ; 
    		a[i].r=r ;
    		b[i] = a[i] ; 
    	}
    	solve() ;
		prt(res,n) ;
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}