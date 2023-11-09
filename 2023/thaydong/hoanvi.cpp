/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "hoanvi"
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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q ;
int a[N] ; 
int pos[N] ; 
void doc()
{
    cin>> n >>q ;
    FOR(i,1,n)
    {
    	int val; cin>>val; 
    	pos[val] = i ; 
    }
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
}

namespace sub1
{
	int st[4*N] ; 
	void up(int id ,int l ,int r,int pos ,int val)
	{
		if(l==r&&l==pos)
		{
			st[id]+=val; 
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid=(l+r)/2; 
		up(id*2,l,mid,pos,val) ; 
		up(id*2+1,mid+1,r,pos,val) ;
		st[id] = max(st[id*2],st[id*2+1]) ; 
	}
	void up(int x, int y,int val)
	{
		int pos ; 
		if(x<=y)pos=y-x ; 
		else pos=n-x+y; 
		up(1,0,n-1,pos,val) ;  
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
			up(i,pos[a[i]],1) ;   
    	}
		while(q--)
		{
			int x, y  ;
			cin>>x>>y ; 
			up(x,pos[a[x]],-1) ; 
			up(y,pos[a[y]],-1) ; 
			swap(a[x],a[y]) ;
			up(x,pos[a[x]],1) ; 
			up(y,pos[a[y]],1) ; 
			cout<<st[1]<<el; 
		}    	
    }		
}
namespace subtrau
{   
    void xuly()
    {   
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