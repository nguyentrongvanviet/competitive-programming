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

// typedef long long ll 
typedef long long ll ;  
typedef vector<long long> vll ; 
// #define             ll  long long 
// #define             db  double 
#define             ve  vector 
#define             vi  vector<int>
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
#define sz(a) (int)a.size() 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}



const ll mod = 998244353 ;
typedef complex<double> C;
typedef long double ld;
void fft(vector<C> &a) {
	int n = a.size(), L = 31 - __builtin_clz(n);
	static vector<complex<ld>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)

	for (int k = 2; k < n; k *= 2) {
		R.resize(n), rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for (int i = k; i < 2 * k; ++i)
            rt[i] = R[i] = (i & 1) ? R[i / 2] * x : R[i / 2];
	}

	vector<int> rev(n);
	for (int i = 0; i < n; ++i)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

	for (int i = 0; i < n; ++i) {
        if(i < rev[i])
            swap(a[i], a[rev[i]]);
	}

	for (int k = 1; k < n; k <<= 1) {
		for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; ++j) {
				// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  ///
				// include-line

				auto x = (double*) &rt[j + k], y = (double*) &a[i + j + k];  /// exclude-line
				C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);  /// exclude-line
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
		}
	}
}

vector<ll> conv(const vector<ll> &a, const vector<ll> &b) {
	if (a.empty() || b.empty())
        return {};

	vector<ll> res(sz(a) + sz(b) - 1, 0);
	int B = 32 - __builtin_clz(sz(res));
	int n = 1 << B, cut = ll(sqrt(mod));
	vector<C> L(n), R(n), outs(n), outl(n);

	for (int i = 0; i < sz(a); ++i)
        L[i] = C(ll(a[i] / cut), ll(a[i] % cut));

	for (int i = 0; i < sz(b); ++i)
        R[i] = C(ll(b[i] / cut), ll(b[i] % cut));

	fft(L), fft(R);
	for (int i = 0; i < n; ++i) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / C(1.0i);
	}

	fft(outl), fft(outs);
	for (int i = 0; i < sz(res); ++i) {
		ll av = ll(real(outl[i]) + .5)%mod, cv = ll(imag(outs[i]) + .5)%mod;
		ll bv = (ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5))%mod;
		res[i] = ((av * cut %mod + bv)%mod *cut%mod + cv) % mod;
	}
	return res;
}
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%mod*a%mod;
	return b*b%mod ;
}
struct poly
{
	vll coef; 
	poly(){} 
	poly(vll a) : coef(a){}  
	int deg(){return coef.size()-1;}
	friend poly operator*(poly a,poly b){return conv(a.coef,b.coef);}
	friend poly operator+(int a , poly b )
	{
		b.coef[0] = (a+b.coef[0])%mod ;
		return b ;
	}
	friend poly operator-(int a , poly b )
	{
		for(auto &x:b.coef)x=(mod-x)%mod ; 
		return a+b ; 
	}
	friend poly operator+(poly a,poly b)
	{
		a.coef.resize(max(a.coef.size(),b.coef.size())) ; 
		FORN(i,0,b.coef.size())a.coef[i] = (a.coef[i]+b.coef[i])%mod ; 
		return a ; 
	}
	friend poly operator-(poly a,poly b)
	{
		for(auto &x : b.coef)x = (mod-x)%mod ;
		return a+b ; 
	}
	poly mod_xk(int k)
	{
		poly p(coef);
		p.coef.resize(min(k,(int)coef.size())) ; 
		return p ; 
	}
	poly deri()
	{
		vll r ; 
		for(int i=1;i<=deg();i++)r.pb(coef[i]*i%mod) ; 
		return poly(r) ;
	}
	poly inte()
	{
		vll r = {0} ; 
		for(int i=0;i<=deg();i++)r.pb(coef[i]*pw(i+1,mod-2)%mod) ; 
		return poly(r) ; 
	}
	poly inv()
	{	
		assert(coef[0]!=0) ;
		poly Q({pw(coef[0],mod-2)}) ; 
		for(int d=2;d<=deg()*2;d*=2)
		{
			poly P = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
			poly r = (Q*(2-(P*Q).mod_xk(d))).mod_xk(d) ;  
			Q.coef.resize(d) ; 
			for(int i=0;i<d;i++)Q.coef[i] = r.coef[i] ; 
		}
		Q.coef.resize(deg()+1) ; 
		return Q ; 
	}
	// log(A(x))' = A'(x)/A(x) 
	poly log(int k = -1 )
	{
		assert(coef[0]==1) ; 
		if(k==-1)k=deg()+1 ; 
		return (deri()*inv()).mod_xk(k).inte().mod_xk(k) ; 
	}
	// Q(x) = Q*(1-P+log(Q(x)))
	poly exp()
	{
		assert(coef[0]==0) ; 
		poly Q({1}) ;
		for(int d=2;d<=deg()*4;d*=2)
		{
			poly P = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
			poly r = (Q*(1+P-(Q.log(d)))).mod_xk(d) ; 
			Q.coef.resize(d) ; 
			for(int i=0;i<d;i++)Q.coef[i] = r.coef[i] ; 
		}	
		Q.coef.resize(deg()+1) ;
		return Q ;
	}
	poly pow(ll k)
	{
		if(k==0)
		{
			vll ans(deg()+1,0) ; 
			ans[0] =1 ; 
			return poly(ans) ;
		} 
		poly b = pow(k/2) ; 
		if(k&1)
		{
			return ((b*b).mod_xk(deg()+1)*(*this)).mod_xk(deg()+1) ; 
		}	 
		return (b*b).mod_xk(deg()+1) ; 
	}
} ; 
void doc()
{
	int n ; 
	ll k ; 
    cin>> n >> k;
    vll coef ;  
    for(int i=0;i<n;i++)
    {
    	int u ; cin>> u ; 
    	coef.pb(u) ; 
    }
    poly f(coef) ; 
    prv(f.pow(k).coef) ; 
}

namespace sub1
{
    void xuly()
    {
        
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