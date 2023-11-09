/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "GCD_QUERY"
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

int n ,q ;
int a[N] ; 
int T[N][LO+2] ; 
struct Query
{
	int id ; 
	int l ,r ; 
	int val;  
	bool operator<(const Query&a)const
	{
		return val>a.val ; 
	}
}Q[N] ;
ll res[N] ;
void build_rmq()
{
	FOR(i,1,n)T[i][0]=a[i] ; 
	FOR(j,1,lg(n))FOR(i,1,n-(1<<j)+1)
	{
		T[i][j] = gcd(T[i][j-1],T[i+(1<<(j-1))][j-1]) ; 
	}
}
int get_gcd(int l ,int r)
{
	int k = lg(r-l+1) ;
	return gcd(T[l][k],T[r-(1<<k)+1][k]) ; 
}

void doc()
{
	cin>> n >>q ;
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,q)
	{
		cin>>Q[i].l>>Q[i].r>>Q[i].val; 
		Q[i].id = i ;
	}
}
struct Node
{
	ll sum ;  
	int ma ; 
}; 
Node st[4*N] ; 
Node merge(Node L , Node R)
{
	ll sum = L.sum+R.sum; 
	int ma= max(L.ma,R.ma) ;
	if(sum<0)while(1);
	return {sum,ma} ; 
}
void build(int id, int l ,int r)
{
	if(l==r)
	{
		st[id] = {l,a[l]} ;
		a[l]=l; 
		return ; 
	}
	int mid= (l+r)/2 ;
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
void up(int id ,int l ,int r, int d)
{
	if(st[id].ma<=d)return ; 
	if(l==r)
	{		
		int L = l ; 
		int R = n ; 
		int ans = n+1 ; 
		while(L<=R)
		{
			int mid= (L+R)/2;
			if(get_gcd(l,mid)<=d)ans=mid,R=mid-1; 
			else L=mid+1;
		}
		if(ans==n+1)st[id]={0,0} ; 
		else st[id]= {ans,get_gcd(l,ans)};
		a[l] = ans;
		return ; 
	}
	int mid =(l+r)/2 ; 
	up(id*2,l,mid,d); 
	up(id*2+1,mid+1,r,d) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
ll get(int id, int l, int r, int t, int p)
{
	if(t<=l&&r<=p)return st[id].sum ; 
	if(r<t||p<l)return 0 ;
	int mid =(l+r)/2; 
	return get(id*2,l,mid,t,p)+get(id*2+1,mid+1,r,t,p) ;
}
void xuly()
{
	build_rmq() ; 
	build(1,1,n) ;
	sort(Q+1,Q+q+1) ;
	for(int i=1;i<=q;i++)
	{
		up(1,1,n,Q[i].val) ;
		int l = Q[i].l; 
		int r= Q[i].r ; 
		int ans = -1 ;
		while(l<=r)
		{
			int mid= (l+r)/2 ;
			if(a[mid]<=Q[i].r)
			{
				ans=mid; 
				l=mid+1; 
			}
			else r=mid-1 ;
		}
		if(ans!=-1)
		{
			res[Q[i].id] = 1LL*(Q[i].r+1)*(ans-Q[i].l+1)-1LL*get(1,1,n,Q[i].l,ans);
		}
	}	
	FOR(i,1,q)
	{	
		cout<<res[i]<<el;
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