/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


bool check(int val)
{
	while(val)
	{
		if(val%10!=4&&val%10!=7)return 0 ;
		val/=10 ; 
	}
	return 1; 
}
#define sz(a) int(a.size())
const ll mod = 1e9+7 ;
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
vll st[4*N] ;
vll a[N] ;
void build(int id, int l ,int r)
{
	if(l==r)
	{
		st[id] = a[l] ; 
		// prv(st[id]);
		return ; 
	}
	int mid= (l+r)>>1; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = conv(st[id<<1],st[id<<1|1]) ; 
}
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
}
ll fac[N] , ifac[N] ; 
ll CK(int k ,int n)
{
	if(k>n||k<0)return 0 ; 
	return fac[n]*ifac[k]%sm*ifac[n-k]%sm; 
}
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
    int n , k; cin>> n >> k; 
    int notbeauty = 0 ; 
    map<int,int>sl; 
    FOR(i,1,n)
    {
    	int val; cin>>val;
    	if(check(val)==0)
    	{
    		notbeauty++ ;
    	}
    	else
    	{
    		sl[val]++ ; 
    	}
    }
    int D = 0 ; 
    for(auto [val,t]:sl)
    {
    	a[++D] = {1,t} ;
    }	
    fac[0] = 1; 
    FOR(i,1,n)
    {
    	fac[i] = fac[i-1]*i%sm ;
    }
    ifac[n] = pw(fac[n],sm-2) ; 
    FORD(i,n-1,0)
    {
    	ifac[i] = ifac[i+1]*(i+1)%sm; 
    }
    if(D==0)
    {
    	cout<<CK(k,n) ;
    	return 0 ;
    }
    build(1,1,D) ;
    // cout<<st[1].size()<<el;
    // for(auto x : st[1])cout<<x<<" ";
    // // return 0 ;
    // FOR(i,0,D)
    // {
    // 	cout<<st[1][i]<<" ";
    // }
    // if(notbeauty==0&&n==100&&k==7)
    // {	
	//     cout<<D<<el;
	//     return 0 ;
    // } 
    ll res = 0 ; 
    FOR(i,0,D)
    {
    	(res+=st[1][i]*CK(k-i,notbeauty)%sm)%=sm ; 
    }	
    cout<<res ; 
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



