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
const int N = 2e5+5 , oo = 2e9 , LO = 29 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 


int n , q; 
int a[N] ;
void doc()
{
    cin>> n  ; 
   	for(int i=1;i<=n;i++)cin>>a[i] ;  
}

namespace sub1
{
	const ll mod = (119 << 23) + 1, root = 62; // = 998244353
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%mod*a%mod;
		return b*b%mod ;
	}
	// const ll mod = (119 << 23) + 1, root = 62; // = 998244353
	// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
	// and 483 << 21 (same root). The last two are > 10^9.
	void ntt(vll &a) 
	{
	    int n = a.size(), L = 31 - __builtin_clz(n);
	    static vll rt(2, 1);
	    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
	        rt.resize(n);
	        ll z[] = {1, pw(root, mod >> s)};
	        FORN(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	    }
	    vi rev(n);
	    FORN(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	    FORN(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	    for (int k = 1; k < n; k *= 2)
	        for (int i = 0; i < n; i += 2 * k) FORN(j,0,k) {
	            ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
	            a[i + j + k] = ai - z + (z > ai ? mod : 0);
	            ai += (ai + z >= mod ? z - mod : z);
	        }
	}
	vll conv(vll a, vll b) {
	    if (a.empty() || b.empty()) return {};
	    int s = (int)a.size() + (int)b.size() - 1, B = 32 - __builtin_clz(s),
	        n = 1 << B;
	    int inv = pw(n, mod - 2);
	    vll L(a), R(b), out(n);
	    L.resize(n), R.resize(n);
	    ntt(L), ntt(R);
	    FORN(i,0,n)
	        out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	    ntt(out);
	    return {out.begin(), out.begin() + s};
	}
	ll fac[N] , ifac[N] , power2[N] ; 
	ll C(int k ,int n)
	{
		return fac[n]*ifac[k]%mod*ifac[n-k]%mod ;
	}
	ll res[LO+2][N] ; 
	ll sum[N] ; 
	void solve(int bit)
	{
		int sl1 = 0 ; 
		for(int i=1;i<=n;i++)
		{
			sl1+=(BIT(a[i],bit)) ; 
		}
		int sl0 = n-sl1 ; 
		vll A(sl1+1,0) ; 
		vll B(sl0+1,0) ; 
		for(int i=1;i<=sl1;i+=2)
		{
			A[i] = C(i,sl1) ; 
		}
		for(int i=0;i<=sl0;i++)
		{
			B[i] = C(i,sl0) ; 
		}
		vll C =  conv(A,B) ;
		for(int i=1;i<=n;i++)
		{
			res[bit][i]=C[i] ; 
		}
	}
    void xuly()
    {
    	power2[0] = 1; 
    	for(int i=1;i<=n;i++)power2[i] = power2[i-1]*2%mod ; 
    	fac[0] = 1 ;
    	for(int i=1;i<=n;i++)fac[i] = fac[i-1]*i%mod; 
    	ifac[n] = pw(fac[n],mod-2) ; 
    	for(int i=n-1;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod; 
    	for(int bit=0;bit<=LO;bit++)
    	{
    		solve(bit) ; 
    	}
    	FOR(i,1,n)
    	{
    		sum[i] = sum[i-1] ;
    		FOR(bit,0,LO)
    		{
    			(sum[i] += (1ll<<bit)*res[bit][i]%mod)%=mod ; 
    		}
    	}
    	cin>>q ; 
       	for(int i=1;i<=q;i++)
       	{
       		int val; cin>> val ; cout<<sum[val]<<endl;
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