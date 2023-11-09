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
const int N = 3e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
int h[N] ; 
int a[N] ;  
ll f[N] ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n)
	{
		cin>>h[i] ; 
	}
	FOR(i,1,n)
	{
		cin>>a[i] ;
	}
}
namespace sub1
{
	void xuly()
	{
		FOR(i,1,n)
		{
			f[i] = -inf ;
			int mi = i  ; 
			FORD(j,i,1)
			{
				if(h[mi]>h[j])mi=j; 
				maxi(f[i],f[j-1]+a[mi]);
			}
			cout<<f[i]<<" ";
		}	
		cout<<f[n]<<el;
	}

}
namespace sub2
{
	ll st[8*N] ;
	ll lazy[8*N] ;
	void dolazy(int id)
	{
		st[id] +=lazy[id]; 
		lazy[id*2]+=lazy[id] ; 
		lazy[id*2+1]+=lazy[id] ; 
		lazy[id] = 0 ; 
	}
	void up_range(int id ,int l, int r , int t ,int p  , ll val)
	{
		dolazy(id) ;
		if(t<=l&&r<=p)
		{
			lazy[id]+=val; 
			dolazy(id) ;
			return ; 
		} 
		if(r<t||p<l)return ; 
		int mid =(l+r)/2 ; 
		up_range(id*2,l,mid,t,p,val) ; 
		up_range(id*2+1,mid+1,r,t,p,val) ; 
		st[id] =max(st[id*2],st[id*2+1]) ;
	}
	void up(int id, int l ,int r, int pos ,ll val)
	{
		dolazy(id) ; 
		if(l==r&&l==pos)
		{
			st[id] = val ; 
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid =(l+r)/2 ;
		up(id*2,l,mid,pos,val) ; 
		up(id*2+1,mid+1,r,pos,val) ; 
		st[id] = max(st[id*2],st[id*2+1]) ;
	}
	ll get(int id ,int l, int r , int t ,int p)
	{
		dolazy(id) ; 
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return -inf ; 
		int mid =(l+r)/2 ; 
		return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
	}
	void xuly()
	{
		stack<int>st ;
		st.push(0) ; 
		for(int i =1;i<=n;i++)
		{
			up(1,1,n,i,f[i-1]+a[i]);
			while(st.top()!=0&&h[st.top()]>h[i])
			{
				int r = st.top() ; 
				st.pop() ;
				int l = st.top() ;
				up_range(1,1,n,l+1,r,-a[r]); 
				up_range(1,1,n,l+1,r,a[i]);
			} 	
			st.push(i) ;   
			f[i] = get(1,1,n,1,i);
		}
		cout<<f[n] ;
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
        // sub1::xuly() ;
        sub2::xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}