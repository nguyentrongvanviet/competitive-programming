#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define vll vector<ll> 
#define vi vector<int> 
#define FORN(i,a,b) for(int i=int(a);i<int(b);i++)
const int N =2e5+5 , oo =2e9+5 , LO = 16 ; 
// fft 
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%mod*a%mod;
	return b*b%mod ;
}
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

vll P[LO+5] ; 
signed main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	if(fopen("text.INP","r"))
	{
		freopen("text.INP","r",stdin) ; 
		freopen("text.OUT","w",stdout) ; 
	}
	int n , k; 
	cin>> n >> k ;
	P[0] = vll(10,0) ;
	for(int i=1;i<=k;i++)
	{
		int val; cin>>val ;
		P[0][val] = 1; 
	}
	for(int i=1;i<=LO;i++)
	{
		P[i] = conv(P[i-1],P[i-1]) ; 
	}
	n/=2 ;
	vll B ;  
	for(int i=0;i<=LO;i++)if(n>>i&1)
	{
		if(B.empty())B=P[i] ; 
		else B = conv(B,P[i]) ; 
	}
	ll res = 0 ;
	for(auto x : B)
	{
		(res+=x*x%mod)%=mod ;
	}	
	cout<<res<<'\n' ;
	cerr<<clock()<<"ms"<<endl;
	return 0 ; 
}