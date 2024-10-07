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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n , q ;
int a[N] ; 

void doc()
{
    cin>> n >> q; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	int node = 0  ;
	int H[N] ;// dinh goc cua cay i 
	int L[N*LO] ;  // dinh ben trai cua node i , l,mid 
	int R[N*LO] ; // dinh ben phai cua node i ,mid+1,r
	int st[N*LO] ; // gia tri tong cua doan l ,r 
	int up(int old ,int l , int r ,int pos ,int val)
	{
		int cur = ++node ; // tao dinh moi 
		if(l==r)
		{
			//cap nhat lai gai tri moi 
			st[cur] = st[old] + val ; 
			// st[cur] = 1 ; 
			// trong bai nay van ko sai 
			return cur ; 
		}
		int mid = (l+r)>>1 ; 
		if(pos<=mid)
		{
			// dung lai nut ben phai vi gia tri cap nhat nam ben trai 
			R[cur] = R[old] ; 
			// cap nhat nut trai 
			L[cur] = up(L[old],l,mid,pos,val) ; 
		}
		else
		{
			// dung lai nut ben trai vi gia tri cap nhat nam ben phai 
			L[cur] = L[old] ; 
			// cap nhat nut phai 
			R[cur] = up(R[old],mid+1,r,pos,val) ; 
		}
		// cap nhat gia tri cho nut cur 
		st[cur] = st[L[cur]]+st[R[cur]] ;
		// tra lai de bien dinh nao  
		return cur; 
	}
	int get(int id ,int l, int r, int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0 ; 
		int mid = (l+r)>>1 ;
		return get(L[id],l,mid,t,p) + get(R[id],mid+1,r,t,p) ; 
	} 
	 
	vi pos[N] ; 
    void xuly()
    {
    	vi V ; 
        FOR(i,1,n)V.pb(a[i]) ; 
        sort(all(V)) ;
        uni(V) ; 
        FOR(i,1,n)a[i]=UB(all(V),a[i])-V.begin() ; 
        FOR(i,1,n)pos[a[i]].pb(i) ; 
        FOR(i,1,n)
        {
        	// cay thu i chua cap nhat se la cay i-1 
        	H[i] = H[i-1] ; 
        	for(auto v : pos[i])
        	{
        		// cap nhat cho cay i 
        		H[i] = up(H[i],1,n,v,1) ; 
        	}
        }
        FOR(i,1,q)
        {
        	int type  ; cin>>type ; 
        	int T ,P ; cin>> T >>P ;
        	if(type==2)
        	{
        		int l =1 ; 
        		int r= n ; 
        		int ans = -1 ; 
        		while(l<=r)
        		{
        			int mid = (l+r)>>1 ;
        			if(get(H[mid],1,n,T,P)>=(P-T+2)/2)
        			{
        				ans=mid  ;
        				r=mid-1 ;
        			}
        			else l=mid+1 ;
        		}
        		cout<<V[ans-1]<<el;
        	}
        }
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}