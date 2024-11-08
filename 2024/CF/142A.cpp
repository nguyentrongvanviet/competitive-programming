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

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
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
};

int n ; 
void doc()
{
	cin>> n  ;
	vll a(n) ; 
	for(int i=0;i<n;i++)cin>>a[i]  ; 
	poly b = poly(a) ;
	prv(b.exp().coef) ;  
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