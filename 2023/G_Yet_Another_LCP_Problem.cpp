/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

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
const ll inf = 1e18, cs = 10861, sm = 1e9+7; 
const int N = 2e5+2, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , Q ; 
str S ; 
unsigned long long HA[N] ,mu[N] ; 
int sa[N] , lcp[N] ;
int pos[N] ;
// suffix 
int P[N][LO+1] ;
//rmq  
int a[N] , b[N] ;
struct NODE
{
	int mi ; 
	int ma ; 
	ll sum ;
} ; 
NODE st[4*N]; 
int lazy[4*N]; 
void doc()
{		
	cin>> n >>Q  ; 
	cin>>S; 
	S=" "+S ;
}
ll __hash(int l ,int r )
{
	return (HA[r]-HA[l-1]*mu[r-l+1]+sm*sm)%sm;
}
int gap ;
bool cmp(int i, int j)
{
	if(pos[i]!=pos[j])
	{
		return pos[i]<pos[j] ; 
	}  
	i+=gap ; 
	j+=gap ; 
	return (i<=n&&j<=n)?pos[i]<pos[j]:i>j ;
}
int tmp[N] ;
void build_suffix_array()
{
	mu[0] = 1; 
	FOR(i,1,n)mu[i]=mu[i-1]*cs%sm , HA[i] = (HA[i-1]*cs+S[i])%sm;
	FOR(i,1,n)pos[i]=S[i],sa[i]=i ; 
	for(gap=1;;gap<<=1)
	{
		sort(sa+1,sa+n+1,cmp) ;
		tmp[1] = 1; 
		FOR(i,2,n)
		{
			tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
		}
		FOR(i,1,n)pos[sa[i]]=tmp[i] ;
		if(tmp[n]==n)break; 
	}
	FOR(i,2,n)
	{
		int l = 0 ;
		int r = min(n-sa[i],n-sa[i-1]); 
		int ans = -1 ; 
		while(l<=r)
		{
			int mid = (l+r)/2; 
			if(__hash(sa[i-1],sa[i-1]+mid)==__hash(sa[i],sa[i]+mid))ans=mid,l=mid+1; 
			else r=mid-1 ; 
		}
		lcp[i] = ans+1 ; 
	}
}
void build_rmq_lcp()
{
	FOR(i,1,n)P[i][0] = lcp[i] ;  
	FOR(j,1,LO)
	{
		FOR(i,1,n)
		{
			P[i][j] = min(P[i][j-1],P[min(n,i+(1<<j-1))][j-1]) ; 
		}
	}
}
int __lcp(int l ,int r )
{
	if(l>r)return 0 ; 
	if(l==r)return n-sa[l]+1;
	++l; 
	int k = lg(r-l+1) ; 
	return min(P[l][k],P[r-(1<<k)+1][k]);
}
NODE merge(NODE L , NODE R)
{
	int mi = min(L.mi,R.mi) ; 
	int ma = max(L.ma,R.ma) ; 
	ll sum = L.sum+R.sum ; 
	return {mi,ma,sum} ; 
}
void dolazy(int id,int l ,int r ) 
{
	if(lazy[id]==-1)return ; 
	st[id].sum = 1LL*lazy[id]*(r-l+1) ;
	st[id].ma = st[id].mi = lazy[id] ; 
	lazy[id] = -1 ; 
	if(l==r)return ;
	lazy[id*2] =lazy[id] ; 
	lazy[id*2+1] = lazy[id] ; 
}
void kill(int n )
{	
	FOR(id,1,4*n)st[id]={0,0,0},lazy[id]=-1; 
}	
void low(int id,int l ,int r, int val )
{
	dolazy(id,l,r) ; 
	if(st[id].ma<=val)return ; 
	if(st[id].mi>val)
	{
		lazy[id] = val; 
		dolazy(id,l,r); 
		return ;  
	}
	int mid=(l+r)/2 ; 
	low(id*2,l,mid,val) ; 
	low(id*2+1,mid+1,r,val) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
void up(int id ,int l ,int r ,int pos , int val)
{
	dolazy(id,l,r) ;
	if(l==r&&l==pos)
	{
		st[id] = {val,val,val} ; 
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,val) ; 
	up(id*2+1,mid+1,r,pos,val) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
void xuly()
{
	build_suffix_array() ; 

	build_rmq_lcp() ; 

	while(Q--)
	{
		int nA , nB ; 
		cin>>nA>>nB ; 
		FOR(i,1,nA)cin>>a[i],a[i]=pos[a[i]] ; 
		FOR(i,1,nB)cin>>b[i],b[i]=pos[b[i]] ; 

		
		sort(a+1,a+nA+1) ; 
		sort(b+1,b+nB+1) ; 
		ll res = 0 ;
		for(int i =1,j=1 ;i<=nA;i++)
		{	
			low(1,1,nB,__lcp(a[i-1],a[i])) ;
			while(j<=nB && b[j]<=a[i])
			{
				up(1,1,nB,j,__lcp(b[j],a[i]));
				++j ; 
			}
			res+=st[1].sum; 
		}
		kill(nB) ; 
		for(int i= nA,j=nB ;i>=1;i--)
		{
			low(1,1,nB,__lcp(a[i],a[i+1])) ;
			while(j>=1&&a[i]<b[j])
			{
				up(1,1,nB,j,__lcp(a[i],b[j]));
				--j ; 
			}
			res+=st[1].sum ; 
		}
		kill(nB) ; 
		cout<<res<<el; 
	}
}

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
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}