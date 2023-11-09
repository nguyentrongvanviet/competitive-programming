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

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n; 
int a[N] ; 

void doc()
{	
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 

}
namespace sub1
{
	ll tot=0,S_a[N]; 
    void xuly()
    {
        FOR(i,1,n)
        {
        	tot+=1LL*i*a[i] ; 
        	S_a[i] = S_a[i-1]+a[i] ; 
        }
        ll res = -inf;
        FOR(i,1,n)
        {
        	FOR(j,1,i)
        	{
        		maxi(res,1LL*(i-j)*a[j]-S_a[i]+S_a[j]); 
        	}
        }	
        FORD(i,n,1)
        {
        	FOR(j,i,n)
        	{
        		maxi(res,1LL*(i-j)*a[j]+S_a[j-1]-S_a[i-1]);
        	}
        }
        cout<<res+tot<<el;
    }
}
namespace sub2
{
	struct line
	{
		ll a,  b ; 
		line()
		{
			a=0 ; 
			b=-inf ; 
		}
		line(ll _a , ll _b)
		{
			a=_a ; 
			b=_b ; 
		}
		ll operator()(ll x)
		{
			return a*x+b ;
		}
	} ; 
	const int MAX = 1e6 ; 
	line st[MAX*4+5] ;  
	void up(int id ,int l, int r ,line L)
	{
		if(l==r)
		{
			if(st[id](l)<L(l))swap(st[id],L) ; 
			return ; 
		}
		int mid = (l+r)/2 ; 
		if(st[id].a>L.a)swap(st[id],L) ; 
		if(st[id](mid)<L(mid))
		{
			swap(st[id],L); 
			up(id*2,l,mid,L) ; 
		}
		else
		{
			up(id*2+1,mid+1,r,L) ; 
		}
	}
	ll get(int id, int l  ,int r, int pos)
	{
		if(l==r)
		{
			return st[id](pos) ; 
		}
		int mid= (l+r)/2; 
		if(pos<=mid)return max(st[id](pos),get(id*2,l,mid,pos)) ; 
		return max(st[id](pos),get(id*2+1,mid+1,r,pos)) ; 
	}
	ll tot=0,S_a[N]; 
    void xuly()
    {
        FOR(i,1,n)
        {
        	tot+=1LL*i*a[i] ; 
        	S_a[i] = S_a[i-1]+a[i] ; 
        }
        ll res = -inf ; 
        FOR(i,1,n)
        {
        	up(1,1,MAX,line(a[i],S_a[i]-1LL*i*a[i])) ; 
        	maxi(res,get(1,1,MAX,i)-S_a[i]) ; 
        }
        FOR(id,1,4*MAX)
        {
        	st[id] = line() ; 
        }
        FORD(i,n,1)
        {
        	up(1,1,MAX,line(a[i],S_a[i-1]-1LL*i*a[i])) ;
        	maxi(res,get(1,1,MAX,i)-S_a[i-1]) ; 
        }
        cout<<res+tot<<el;
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}