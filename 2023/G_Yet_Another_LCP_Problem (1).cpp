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
const ll inf = 1e18, cs = 329, sm = 1e9+7; 
const int N = 2e5+2, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , Q ; 
str S ;  
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
int ct[N],cnt[N]  ;
int tmp[N] ; 
int pos1[N];
void build_suffix_array()
{
	memset(ct, 0, sizeof ct);
	memset(pos, 0, sizeof pos);
	for (int i=1; i<=n; i++) ct[S[i]]=1;
	for (int i=1; i<256; i++) ct[i]+=ct[i-1];
	for (int i=1; i<=n; i++) pos[i]=ct[S[i]];
	for (int k=0, p=1; k!=n; p<<=1)
	{
		memset(cnt, 0, sizeof cnt);
		for (int i=1; i<=n; i++) cnt[pos[i+p]]++;
		for (int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
		for (int i=n; i>=1; i--) tmp[cnt[pos[i+p]]--]=i;
		memset(cnt, 0, sizeof cnt);
		for (int i=1; i<=n; i++) cnt[pos[i]]++;
		for (int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
		for (int i=n; i>=1; i--) sa[cnt[pos[tmp[i]]]--]=tmp[i];
		memcpy(pos1, pos, sizeof pos1);
		pos[sa[1]]=k=1;
		for (int i=2; i<=n; i++)
		{
			if (pos1[sa[i]]!=pos1[sa[i-1]]||pos1[sa[i]+p]!=pos1[sa[i-1]+p])
				k++;
			pos[sa[i]]=k;
		}
	}
	for (int i=1, k=0; i<=n; i++)
	{
		if (pos[i]==1)
		{
			lcp[pos[i]]=k=0;
			continue;
		}
		if (--k<0) k=0;
		while (S[i+k]==S[sa[pos[i]-1]+k]) k++;
		lcp[pos[i]]=k;
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

	// prt(sa,n);
	// prt(pos,n);
	// prt(lcp,n);
	// FOR(i,1,n)cout<<S.substr(sa[i])<<el; 
	build_rmq_lcp() ; 

	while(Q--)
	{
		int nA , nB ; 
		cin>>nA>>nB ; 
		FOR(i,1,nA)cin>>a[i],a[i]=pos[a[i]] ; 
		FOR(i,1,nB)cin>>b[i],b[i]=pos[b[i]] ; 

		
		sort(a+1,a+nA+1) ; 
		sort(b+1,b+nB+1) ;
		// prt(a,nA) ; 
		// prt(b,nB) ; 
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