/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TRE"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

// #define             ll  long long 
typedef long long ll ; 
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
// const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
const ll mod = 1e9+7 ; 
ll pw(ll a,ll b)
{
	ll res = 1 ; 
	while(b)
	{
		if(b&1)res = res*a%mod ; 
		a = a*a%mod ; 
		b>>=1 ; 
	}
	return res ; 
}
#define sz(a) a.size() 
const ll MOD = 1e9+7 ;
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

template<ll MOD> vector<ll> conv(const vector<ll> &a, const vector<ll> &b) {
	if (a.empty() || b.empty())
        return {};

	vector<ll> res(sz(a) + sz(b) - 1, 0);
	int B = 32 - __builtin_clz(sz(res));
	int n = 1 << B, cut = ll(sqrt(MOD));
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
		ll av = ll(real(outl[i]) + .5)%MOD, cv = ll(imag(outs[i]) + .5)%MOD;
		ll bv = (ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5))%MOD;
		res[i] = ((av * cut %MOD + bv)%MOD *cut%MOD + cv) % MOD;
	}

	return res;
}
struct poly
{
	vll coef; 
	poly(){} 
	poly(vll a) : coef(a){}  
	friend poly operator*(poly a,poly b){return conv<(ll)1e9+7>(a.coef,b.coef);}
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
	void mod_xk(int k)
	{
		coef.resize(min(k,(int)coef.size())) ; 
	}
	poly mod_xk_here(int k)
	{
		poly r = *this ; 
		r.mod_xk(k) ; 
		return r ; 
	}
	int deg()
	{
		return coef.size()-1 ; 
	}
	poly inv()
	{	
		assert(coef[0]!=0) ;
		poly r({pw(coef[0],mod-2)}) ; 
		for(int d=2;d<=deg()*2;d*=2)
		{
			poly f = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
			poly g = r*f ; 
			g.mod_xk(d) ; 
			poly h = r*(2-g) ; 
			h.mod_xk(d) ; 
			r.coef.resize(d) ; 
			for(int i=0;i<d;i++)r.coef[i] = h.coef[i] ; 
		}
		r.coef.resize(deg()+1) ; 
		return r ; 
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
	// ln(A(x))' = A'(x)/A(x) 
	poly log(int k = -1 )
	{
		if(k==-1)
		{
			k = deg()+1 ; 
		}
		assert(coef[0]==1) ; 
		return (deri()*inv()).mod_xk_here(k).inte().mod_xk_here(k) ; 
	}
	poly exp()
	{
		assert(coef[0]==0) ; 
		poly r({1}) ;
		for(int d=2;d<=deg()*4;d*=2)
		{
			poly f = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
			poly j = r*(1+f-(r.log(d))) ; 
			// cout<<"turn " <<d/2<<" "<<r.log(d).deg()<<endl;
			j.mod_xk(d) ; 
			r.coef.resize(d) ; 
			for(int i=0;i<d;i++)r.coef[i] = j.coef[i] ; 
			// prv(r.coef) ; 
		}	
		r.coef.resize(deg()+1) ;
		return r ;
	}
};
int n , k ; 
int cnt[N] ; 
void doc()
{
	cin>> n >> k; 
    FOR(i,1,n)
    {
        int val; cin>>val; 
        cnt[val]++ ; 
    }
	vll a(k+1,0) ;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j*i<=k;j++)
        {
            if(j&1)a[i*j] = (a[i*j]+cnt[i]*pw(j,mod-2)%mod)%mod; 
            else a[i*j] = (a[i*j]-cnt[i]*pw(j,mod-2)%mod+mod)%mod ;
        }
    }
    // prv(a) ; 
	poly b(a) ;
	// prv(b.coef) ; 
	cout<<b.exp().coef[k] ;  

}
// A(x) = 1+x+x^2 

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
	if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin);
        freopen("text.OUT","w",stdout);
    }
    else if(fopen(INPUT,"r"))
	{
		freopen(INPUT ,"r",stdin);
		freopen(OUTPUT,"w",stdout);
	}
	if(mtt)cin>>test;

	FOR(i,1,test)
	{
		doc() ; 
		sub1::xuly() ; 
	}
	cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}