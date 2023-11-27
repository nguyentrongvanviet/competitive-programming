/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "xap_xep_lai_day"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q, k ;	
int p[N] ; 
int id[N]; 
void doc()
{
    cin >> n >>q >> k; 
    FOR(i,1,n)cin>>p[i] ,id[p[i]]=i ; 
}

namespace sub1
{
	int a[N] ; 
	int b[N] ; 
    void xuly()
    {
        FOR(i,1,n)a[i] = i; 
        FOR(i,1,q)
        {
        	int l,r ;cin>> l >>r;
        	FOR(i,l,r)
        	{
        		b[a[i]] = p[i-l+1] ; 
        	}
        	sort(a+l,a+r+1,[](int x,int y ){return b[x]<b[y];});
        	// prt(a,n) ;
        }
        cout<<a[k]<<el;
    }
}
namespace sub2
{
	struct PIT
	{
		int n;  
		vi st, H , L , R; 
		int node = 0; 
		PIT(int _n=0)
		{
			n=_n ;
			st.resize(n*(LO+2),0) ; 
			H.resize(n*(LO+2),0)  ;
			L.resize(n*(LO+2),0) ;
			R.resize(n*(LO+2),0) ; 
		}
		int up(int old ,int l ,int r, int pos)
		{
			int cur = ++node ;
			if(l==r)
			{
				st[cur] = 1; 
				return cur; 
			}
			int mid=(l+r)>>1; 
			if(pos<=mid)
			{
				R[cur] = R[old] ;
				L[cur] = up(L[old],l,mid,pos) ; 
			}
			else
			{
				L[cur] = L[old] ; 
				R[cur] = up(R[old],mid+1,r,pos) ;
			}
			st[cur] =st[L[cur]]+st[R[cur]] ;
			return cur; 
		}
		int get(int id ,int l ,int r , int val)
		{
			if(l==r)return l ;
			int mid=(l+r)>>1; 
			if(st[L[id]]>=val)
			{
				return get(L[id],l,mid,val) ; 
			}
			return get(R[id],mid+1,r,val-st[L[id]]) ;
		}
		void up(int pos ,int val)
		{
			H[pos] = up(H[pos-1],1,n,val);
		}
		int get(int pos ,int val)
		{
			return get(H[pos],1,n,val) ;
		}
	}tree;
	struct DL
	{
		int l, r; 
	}; 
	DL Q[N] ;
	void xuly()
	{
		tree=PIT(n) ; 
		FOR(i,1,n)
		{	
			tree.up(i,p[i]) ;
		}
		FOR(i,1,q)
		{
			cin>>Q[i].l>>Q[i].r ;
		}
		FORD(i,q,1) 
		{	
			int l = Q[i].l ;
			int r = Q[i].r ;
			if(r<k||k<l)continue;
			int len = r-l+1 ;
			int prev = tree.get(len,k-l+1);
			int nk = id[prev] ;
			k=l+nk-1;
		}
		cout<<k<<el;
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}