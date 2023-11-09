/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "sum-min-gcd"
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
const ll inf = 1e18, cs = 331, sm = 1e9+19972207; 
const int N = 25e4+2, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  
int theta ; 
int n ; 
ll a[N] ; 
ll b[N] ; 
ll st[N][LO+1] ;
int L[N] , R[N]; 
void doc()
{
	cin>>theta ; 
	cin>> n; 
	FOR(i,1,n)cin>>a[i],b[i]=a[i]%sm ; 
}
void build_rmq()
{
	FOR(i,1,n)st[i][0] = a[i] ; 
	FOR(j,1,LO)
	{
		FOR(i,1,n)
		{
			st[i][j] = gcd(st[i][j-1],st[min(n,i+(1<<(j-1)))][j-1]);
		}
	}
}
ll get(int l ,int r)
{
	int k = lg(r-l+1) ;
	return gcd(st[l][k],st[r-(1<<k)+1][k]) ;
}
void build_LR()
{
	stack<int>st ;
	a[0] = -oo ; 
	st.push(0) ;   
	FOR(i,1,n)
	{		
		while(a[st.top()]>a[i])st.pop() ;
		L[i] = st.top()+1 ; 
		st.push(i) ; 
	}
	while(!st.empty())st.pop() ;
	a[n+1] = -oo ;
	st.push(n+1) ; 
	FORD(i,n,1)
	{
		while(a[st.top()]>=a[i])st.pop();
		R[i] = st.top()-1 ;
		st.push(i) ;  
	}
}
struct DL
{
	ll val; 
	int len;  
} ; 
ve<DL>VL,VR ; 
void PT1(int id,int L)
{
	int ct = id ; 
	while(ct>=L)
	{
		int l = L ; 
		int r = ct ;
		int ans ;
		ll x = get(ct,id) ; 
		while(l<=r)
		{
			int mid=(l+r)/2 ; 
			if(get(mid,id)==x)
			{
				ans=mid ;
				r=mid-1 ;
			}	
			else l=mid+1 ; 
		}
		VL.pb({x,ct-ans+1});
		ct=ans-1;
	}
}	
void PT2(int id ,int R)
{
	int ct = id ; 
	while(ct<=R)
	{	
		int l = ct ; 
		int r = R ;
		int ans ; 
		ll x = get(id,ct) ;
		while(l<=r)
		{
			int mid= (l+r)/2 ; 
			if(get(id,mid)==x)	
			{
				ans=mid ;
				l=mid+1 ;
			}
			else r=mid-1 ; 
		}
		VR.pb({x,ans-ct+1});
		ct=ans+1 ; 
	}
}

void xuly()	
{
	build_rmq() ;
	build_LR()  ;
	ll res=0 ; 
	FOR(i,1,n)
	{
		VL.clear() ; 
		VR.clear() ;
		PT1(i-1,L[i]) ; 
		PT2(i+1,R[i]) ;
		for(auto v:VL)
		{
			(res+=1LL*gcd(a[i],v.val)%sm*v.len%sm*b[i]%sm)%=sm; 
		}	
		for(auto v:VR)
		{
			(res+=1LL*gcd(a[i],v.val)%sm*v.len%sm*b[i]%sm)%=sm;
		}
		(res+=b[i]*b[i]%sm)%=sm; 
		for(auto u : VL)
		{
			for(auto v : VR)
			{
				(res+=1LL*u.len*(v.len*b[i]%sm)%sm*(gcd(a[i],gcd(u.val,v.val))%sm)%sm)%=sm ;
			}
		}
	}
	cout<<res; 
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