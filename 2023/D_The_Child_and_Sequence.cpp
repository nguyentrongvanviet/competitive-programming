/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
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
// end of macros and constant  

int n, q ; 
int a[N] ; 
void doc()
{
	cin>> n >>q ; 
	FOR(i,1,n)cin>>a[i] ; 
}
struct Node
{
	ll sum ;
	int ma ; 
} ;
Node st[4*N] ; 
Node merge(Node L , Node R)
{
	ll sum = L.sum+R.sum ;
	int ma =  max(L.ma,R.ma) ; 
	return {sum,ma} ;
}
void build(int id, int l,int r )
{
	if(l==r)
	{
		st[id] = {a[l],a[l]} ;
		return ; 
	}
	int mid= (l+r)/2; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ;
}
void up_mod(int id, int l ,int r, int t ,int p ,int val)
{
	if(p<l||r<t||st[id].ma<val)return ;
	if(l==r)
	{
		st[id].ma%=val; 
		st[id].sum = st[id].ma;  
		return ; 
	} 
	int mid =(l+r)/2; 
	up_mod(id*2,l,mid,t,p,val) ; 
	up_mod(id*2+1,mid+1,r,t,p,val) ; 
	st[id] =merge(st[id*2],st[id*2+1]) ; 
}
void up(int id ,int l,int r ,int pos ,int val)
{
	if(l==r&&l==pos)
	{
		st[id].ma = st[id].sum = val; 
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid= (l+r)/2 ;
	up(id*2,l,mid,pos,val) ; 
	up(id*2+1,mid+1,r,pos,val) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ;
}
ll sum(int id ,int l, int r, int t , int p)
{
	if(t<=l&&r<=p)return st[id].sum ; 
	if(r<t||p<l)return 0 ; 
	int mid =(l+r)/2;
	return sum(id*2,l,mid,t,p) + sum(id*2+1,mid+1,r,t,p) ; 
}	
void xuly()
{
	build(1,1,n);
    while(q--)
    {
    	int t ;cin>>t;  
    	if(t==1)
    	{
    		int l ,r ; 
    		cin>>l>>r; 
    		cout<<sum(1,1,n,l,r)<<el;
    	}
    	if(t==2)
    	{
    		int l ,r , x; cin>>l>>r>>x ;
    		up_mod(1,1,n,l,r,x) ;
    	}
    	if(t==3)
    	{
    		int pos , val ;cin>>pos>>val; 
    		up(1,1,n,pos,val) ; 
    	}
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
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}