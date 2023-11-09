/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "lis4"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1;

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
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  
const int MAX = 3e5 ; 
int n ; 

struct line
{
	ll a,b ; 
	int left , right ; 
	line()
	{
		a = 0 ;
		b = -inf ;
		left = -1 ;  
		right = -1 ; 
	}
	line(ll _a , ll _b)
	{
		a = _a ; 
		b = _b ;
	}
	line (ll a,ll b,ll left,ll right):a(a),b(b),left(left),right(right){}
	ll operator()(ll x)
	{
		return a*x+b; 
	}
}; 
line L[(int)2e7] ; 
ll get(int id ,int l ,int r, ll x)
{
	if(id==-1)return -inf ; 

	if(l==r)return L[id](x) ;

	int mid =(l+r)/2; 
	
	if(x<=mid)
		return max(L[id](x), get(L[id].left,l,mid,x));
	else 
		return max(L[id](x),get(L[id].right,mid+1,r,x)) ; 
}
int SL = 0 ;
int add(int id ,int l ,int r, line New  )
{		
	if(id==-1)
	{
		New.left  = -1 ; 
		New.right = -1 ; 
		L[++SL]   = line(New.a,New.b,-1,-1) ;  
		return SL; 
	}
	line Old = L[id] ; 

	ll ylnew = New(l) ; 
	ll yrnew = New(r);
	
	ll ylold = Old(l) ; 
	ll yrold = Old(r) ; 
	
	New.left= Old.left , New.right=Old.right; 

	if ( ylnew>=ylold && yrnew>=yrold )
	{
		swap(L[id],New) ; 
		return id  ;
	}
	if(ylnew<=ylold&&yrnew<=yrold)return id ;
	
	if(L[id].a>New.a) swap(L[id],New) ; 
	
	int mid =(l+r)/2 ; 	
	if(L[id](mid)<New(mid))
	{
		swap(L[id],New) ;
		L[id].left=add(L[id].left,l,mid,New) ; 
	}
	else L[id].right=add(L[id].right,mid+1,r,New) ; 
	return id ; 
}	
struct lichao
{	
	int root ; 
	lichao()
	{
		root = -1 ; 
	}
	ll operator()(ll x)
	{
		return get(root,0,MAX,x) ;  
	}
	void up(line New)
	{
		root = add(root,0,MAX,New) ; 
	}
};
 
lichao st[4*N] ;  

ll Find(int id , int l, int r, ll x , ll y )
{
	if(id==-1)return -inf ; 
	
	if(l==r)return l ; 
	int mid = (l+r)/2 ; 
	if(st[id*2+1](x)>=y)
		return Find(id*2+1,mid+1,r,x,y) ; 
	else 
		return Find(id*2,l,mid,x,y) ; 
}
void up(int id, int l, int r, int pos , line L  )
{	
	if(r<pos||pos<l)return ;
	st[id].up(L) ;  
	if(l==r)return ; 
	int mid = (l+r)/2 ;
	up(id*2,l,mid,pos,L) ;
	up(id*2+1,mid+1,r,pos,L) ; 
}
void doc_xuly()
{ 
	cin>> n ; 
	int res= 0 ; 
	FOR(i,1,n)
	{
		ll a, b , x ,y ; 
		cin>>a>>b>>x>>y ;
		int ans ;  
		if(st[1](x)<y)ans=1 ; 
		else ans = Find(1,1,n,x,y)+1 ;  
		maxi(res,ans) ; 
		up(1,1,n,ans,line(a,b)) ; 
	}
	cout<<res<<el;
	FOR(i,1,4*n)st[i] = lichao() ; 
	SL = 0 ; 
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
        doc_xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}