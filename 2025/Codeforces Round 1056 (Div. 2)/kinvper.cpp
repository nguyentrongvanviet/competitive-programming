#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 


// const ll sm = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef long long ll  ; 
typedef vector<long long> vll ;  
typedef long double ld;
typedef complex<double> C;
const ll sm = 1e9+7 ; 
ll pw(ll a,ll b)
{
    ll res = 1 ; 
    while(b)
    {
        if(b&1)res = res*a%sm ; 
        a = a*a%sm ; 
        b>>=1 ; 
    }
    return res ; 
}
#define sz(a) a.size() 
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
                auto x = (double*) &rt[j + k], y = (double*) &a[i + j + k]; 
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);  
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

template<ll sm> vector<ll> conv(const vector<ll> &a, const vector<ll> &b) {
    if (a.empty() || b.empty())
        return {};

    vector<ll> res(sz(a) + sz(b) - 1, 0);
    int B = 32 - __builtin_clz(sz(res));
    int n = 1 << B, cut = ll(sqrt(sm));
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
        ll av = ll(real(outl[i]) + .5)%sm, cv = ll(imag(outs[i]) + .5)%sm;
        ll bv = (ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5))%sm;
        res[i] = ((av * cut %sm + bv)%sm *cut%sm + cv) % sm;
    }

    return res;
}
struct poly
{
    vector<ll> coef; 
    poly(){} 
    poly(vll a) : coef(a){}  
    friend poly operator*(poly a,poly b){return conv<(ll)1e9+7>(a.coef,b.coef);}
    friend poly operator+(int a , poly b )
    {
        b.coef[0] = (a+b.coef[0])%sm ;
        return b ;
    }
    friend poly operator-(int a , poly b )
    {
        for(auto &x:b.coef)x=(sm-x)%sm ; 
        return a+b ; 
    }
    friend poly operator+(poly a,poly b)
    {
        a.coef.resize(max(a.coef.size(),b.coef.size())) ; 
        for(int i=0;i<b.coef.size();i++)a.coef[i] = (a.coef[i]+b.coef[i])%sm ; 
        return a ; 
    }
    friend poly operator-(poly a,poly b)
    {
        for(auto &x : b.coef)x = (sm-x)%sm ;
        return a+b ; 
    }
    void sm_xk(int k)
    {
        coef.resize(min(k,(int)coef.size())) ; 
    }
    poly sm_xk_here(int k)
    {
        poly r = *this ; 
        r.sm_xk(k) ; 
        return r ; 
    }
    int deg()
    {
        return coef.size()-1 ; 
    }
    poly inv()
    {   
        assert(coef[0]!=0) ;
        poly r({pw(coef[0],sm-2)}) ; 
        for(int d=2;d<=deg()*2;d*=2)
        {
            poly f = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
            poly g = r*f ; 
            g.sm_xk(d) ; 
            poly h = r*(2-g) ; 
            h.sm_xk(d) ; 
            r.coef.resize(d) ; 
            for(int i=0;i<d;i++)r.coef[i] = h.coef[i] ; 
        }
        r.coef.resize(deg()+1) ; 
        return r ; 
    }
    poly deri()
    {
        vll r ; 
        for(int i=1;i<=deg();i++)r.push_back(coef[i]*i%sm) ; 
        return poly(r) ;
    }
    poly inte()
    {
        vll r = {0} ; 
        for(int i=0;i<=deg();i++)r.push_back(coef[i]*pw(i+1,sm-2)%sm) ; 
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
        return (deri()*inv()).sm_xk_here(k).inte().sm_xk_here(k) ; 
    }
    poly exp()
    {
        assert(coef[0]==0) ; 
        poly r({1}) ;
        for(int d=2;d<=deg()*4;d*=2)
        {
            poly f = poly({coef.begin(),coef.begin()+min((int)coef.size(),d)}) ; 
            poly j = r*(1+f-(r.log(d))) ; 
            j.sm_xk(d) ; 
            r.coef.resize(d) ; 
            for(int i=0;i<d;i++)r.coef[i] = j.coef[i] ; 
        }   
        r.coef.resize(deg()+1) ;
        return r ;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
    int n , k ; cin>> n >> k ;
    if(n==1)
    {
    	cout<<(k==0)<<endl;
    	return 0 ; 
    }
    // --n ; 
    vector<ll>coef(k+1,0) ; 
	for(int val=2;val<=n;val++)
	{
    	for(int i=1;i<=k/val;i++)coef[val*i]= (coef[val*i]+sm-pw(i,sm-2))%sm ;  
		// taylor(i) ; 
	}
	for(int i=1;i<=k;i++)
	{
		coef[i] = (coef[i]+(n-1)*pw(i,sm-2)%sm)%sm;
	}
	poly A(coef) ; 

	// prv(A.coef) 
	// prv(A.exp().coef) 
	cout<<A.exp().coef[k]<<'\n' ; 


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


