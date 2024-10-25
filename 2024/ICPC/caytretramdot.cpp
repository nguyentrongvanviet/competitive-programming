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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n , k ; 
int a[N] ;
int sl[N] ;
ll fac[N] , ifac[N] ; 
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
}
namespace fft {
    using ftype = double;
    struct point {
        ftype x, y;
        
        ftype real() {return x;}
        ftype imag() {return y;}
        
        point(): x(0), y(0){}
        point(ftype x, ftype y = 0): x(x), y(y){}
        
        static point polar(ftype rho, ftype ang) {
            return point{rho * cos(ang), rho * sin(ang)};
        }
        
        point conj() const {
            return {x, -y};
        }
        
        point operator +=(const point &t) {x += t.x, y += t.y; return *this;}
        point operator +(const point &t) const {return point(*this) += t;}
        point operator -(const point &t) const {return {x - t.x, y - t.y};}
        point operator *(const point &t) const {return {x * t.x - y * t.y, x * t.y + y * t.x};}
    };

    point w[N]; // w[2^n + k] = exp(pi * k / (2^n))
    int bitr[N];// b[2^n + k] = bitreverse(k)
    const ftype pi = acos(-1);
    bool initiated = 0;
    void init() {
        if(!initiated) {
            for(int i = 1; i < N; i *= 2) {
                int ti = i / 2;
                for(int j = 0; j < i; j++) {
                    w[i + j] = point::polar(ftype(1), pi * j / i);
                    if(ti) {
                        bitr[i + j] = 2 * bitr[ti + j % ti] + (j >= ti);
                    }
                }
            }
            initiated = 1;
        }
    }
    
    void fft(auto &a, int n) {
        init();
        if(n == 1) {
            return;
        }
        int hn = n / 2;
        for(int i = 0; i < n; i++) {
            int ti = 2 * bitr[hn + i % hn] + (i > hn);
            if(i < ti) {
                swap(a[i], a[ti]);
            }
        }
        for(int i = 1; i < n; i *= 2) {
            for(int j = 0; j < n; j += 2 * i) {
                for(int k = j; k < j + i; k++) {
                    point t = a[k + i] * w[i + k - j];
                    a[k + i] = a[k] - t;
                    a[k] += t;
                }
            }
        }
    }
    
    void mul_slow(vector<ll> &a, const vector<ll> &b) {
        if(a.empty() || b.empty()) {
            a.clear();
        } else {
            int n = a.size();
            int m = b.size();
            a.resize(n + m - 1);
            for(int k = n + m - 2; k >= 0; k--) {
                a[k] *= b[0];
                for(int j = max(k - n + 1, 1); j < min(k + 1, m); j++) {
                    a[k] += a[k - j] * b[j];
                }
            }
        }
    }
    template<int m>
    struct dft {
        static constexpr int split = 1 << 15;
        vector<point> A;
        
        dft(vector<modular<m>> const& a, size_t n): A(n) {
            for(size_t i = 0; i < min(n, a.size()); i++) {
                A[i] = point(
                    a[i].rem() % split,
                    a[i].rem() / split
                );
            }
            if(n) {
                fft(A, n);
            }
        }
    
        auto operator * (dft const& B) {
            assert(A.size() == B.A.size());
            size_t n = A.size();
            if(!n) {
                return vector<modular<m>>();
            }
            vector<point> C(n), D(n);
            for(size_t i = 0; i < n; i++) {
                C[i] = A[i] * (B[i] + B[(n - i) % n].conj());
                D[i] = A[i] * (B[i] - B[(n - i) % n].conj());
            }
            fft(C, n);
            fft(D, n);
            reverse(begin(C) + 1, end(C));
            reverse(begin(D) + 1, end(D));
            int t = 2 * n;
            vector<modular<m>> res(n);
            for(size_t i = 0; i < n; i++) {
                modular<m> A0 = llround(C[i].real() / t);
                modular<m> A1 = llround(C[i].imag() / t + D[i].imag() / t);
                modular<m> A2 = llround(D[i].real() / t);
                res[i] = A0 + A1 * split - A2 * split * split;
            }
            return res;
        }
        
        point& operator [](int i) {return A[i];}
        point operator [](int i) const {return A[i];}
    };
    
    size_t com_size(size_t as, size_t bs) {
        if(!as || !bs) {
            return 0;
        }
        size_t n = as + bs - 1;
        while(__builtbin_popcount(n) != 1) {
            n++;
        }
        return n;
    }
    
    void mul(vector<ll> &a, vector<ll> b) {
        if(min(a.size(), b.size()) < magic) {
            mul_slow(a, b);
            return;
        }
        auto n = com_size(a.size(), b.size());
        auto A = dft<m>(a, n);
        if(a == b) {
            a = A * A;
        } else {
            a = A * dft<m>(b, n);
        }
    }
}
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
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
struct poly
{
	vector<ll>a ;
	poly(vector<ll>_a )
	{
		a =  _a ; 
	}	
    void normalize() { // get rid of leading zeroes
        while(!a.empty() && a.back() == 0) {
            a.pop_back();
        }
    }
	bool is_zero()
	{
		return a.empty() ; 
	}
	poly mod_xk(int n )
	{
		return vector<ll>(a.begin(),a.begin()+min(n,a.size())); 
	}
	poly mul_dk(int k )
	{
		vll  res = a  ; 
		res.insert(a.begin(),k,0);
		return poly(res) ; 
	}
    int deg()
    {
        return a.size()-1 ; 
    }
	// calculate derivative
	poly substr(size_t l, size_t r) const { // return mod_xk(r).div_xk(l)
            return vector<ll>(
                begin(a) + min(l, a.size()),
                begin(a) + min(r, a.size())
            );
        }
	poly deriv(int k = 1) { 
		if(deg() + 1 < k) {
			return poly(0);
		}
		vector<ll> res(deg() + 1 - k);
		for(int i = k; i <= deg(); i++) {
			res[i - k] = fact<T>(i) * rfact<T>(i - k) * a[i];
		}
		return res;
	}\
    poly operator *= (const poly &t) {fft::mul(a, t.a); normalize(); return *this;}
    poly operator * (const poly &t) const {return poly(*this) *= t;}
	poly integr() 
	{ // calculate integral with C = 0
		vector<T> res(deg() + 2);
		for(int i = 0; i <= deg(); i++) {
			res[i + 1] = a[i] / T(i + 1);
		}
		return res;
	}
	// calculate log p(x) mod x^n
	poly log(size_t n) 
	{ 
		assert(a[0] == T(1));
		return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
	}
	pair<poly, poly> bisect() const 
	{
		vector<T> res[2];
		res[0].reserve(deg() / 2 + 1);
		res[1].reserve(deg() / 2 + 1);
		for(int i = 0; i <= deg(); i++) {
			res[i % 2].push_back(a[i]);
		}
		return {res[0], res[1]};
	}
	poly mulx(T a) const { // component-wise multiplication with a^k
            T cur = 1;
            poly res(*this);
            for(int i = 0; i <= deg(); i++) {
                res.coef(i) *= cur;
                cur *= a;
            }
            return res;
        }
	poly inv(int n) const 
	{ // get inverse series mod x^n
		auto Q = mod_xk(n);
		if(n == 1) {
			return Q[0].inv();
		}
		// Q(-x) = P0(x^2) + xP1(x^2)
		auto [P0, P1] = Q.mulx(-1).bisect();
		
		int N = fft::com_size((n + 1) / 2, (n + 1) / 2);
		
		auto P0f = fft::dft(P0.a, N);
		auto P1f = fft::dft(P1.a, N);
		
		auto TTf = fft::dft(( // Q(x)*Q(-x) = Q0(x^2)^2 - x^2 Q1(x^2)^2
			poly(P0f * P0f) - poly(P1f * P1f).mul_xk(1)
		).inv((n + 1) / 2).a, N);
		
		return (
			poly(P0f * TTf).x2() + poly(P1f * TTf).x2().mul_xk(1)
		).mod_xk(n);
	}
	poly exp(size_t n) { // calculate exp p(x) mod x^n
        if(is_zero()) {
            return T(1);
        }
        assert(a[0] == 0);
        poly ans = 1;
        ll a = 1;
        while(a < n) {
            poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
            ans -= (ans * C).mod_xk(a).mul_xk(a);
            a *= 2;
        }
        return ans.mod_xk(n);
    }
}
void doc()
{
	cin>> n >> k; 
	for(int i=1;i<=n;i++)cin>>a[i] ,sl[a[i]]++ ; 
	fac[0] = 1;  
	for(int i=1;i<=int(1e5);i++)fac[i] = fac[i-1]*i%sm; 
	ifac[n] = pw(fac[int(1e5)],sm-2) ;
	for(int i=int(1e5)-1;i>=0;i--)
	{
		ifac[i] = ifac[i+1]*(i+1)%sm; 
	}
	vector<ll>coef(k+1);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j*i<=k;j++)
		{
			(coef[i*j]+=(j&1?1:-1)*sl[i]*ifac[j]%sm)%=sm;
			if(coef[i*j]<0)coef[i*j]+=sm;
		}
	}

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