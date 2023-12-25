/*
DOANHONGBAO
1505
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0 ;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
// #define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n ; 
ll k; 
int a[N];

void doc()
{
	cin>>n>>k;
	FOR(i,1,n) 
	{
		cin>>a[i];
		// if(s.count(a[i]))exit(3) ; 
		// s.insert(a[i]) ; 
	}
}

namespace sub1	
{
	int f[5001];
	int tms = 0;
	vi val;
	void add(int &a, int b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	}
	void xuly()
	{
		FOR(i,1,n) val.pb(a[i]);
		sort(all(val));
		val.resize(unique(all(val)) - val.begin());
		f[0] =1 ;
		tms = 0;
		for(auto u : val)
		{
			FORD(i,k,1)
			{	
				for(int cnt = 1 ;cnt * u <= i;cnt++) 
				add(f[i] , f[i - cnt * u]);
			} 
		}
		cout<<f[k] ; 
	}
}
namespace sub3
{
	#define int long long 
	// int ex_gcd(int a, int b, int& x, int& y) 
	// {
	// 	if (b == 0) {
	// 	    x = 1;
	// 	    y = 0;
	// 	    return a;
	// 	}
	// 	int x1, y1;
	// 	int d = ex_gcd(b, a % b, x1, y1);
	// 	x = y1;
	// 	y = x1 - y1 * (a / b);
	// 	return d;
	// }
	int ex_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
	void xuly()
	{
		// cout<<1<<el;
		// exit(0) ;
		// int A , B , k ;
		// cin>>A>>B>>k;
		int A = a[1] ;
		int B = a[2] ;
		int C = gcd(A,B) ;
		if(A>B)swap(A,B);
		if(k%C)return void(cout<<0<<el) ;
		k/=C;
		A/=C;
		B/=C;
		int U=0,V=0;
		int RAC = ex_gcd(A,B,U,V) ;
		// assert(U*A+V*B==1) ;
		U*=k; 
		V*=k;
		if(U<=0&&V>=0)
		{
			int l =	abs(U)/B+(abs(U)%B!=0);
			int r= V/A;
			cout<<r-l+1<<el;
		}
		else if(U>=0&&V<=0)
		{
			int l = -V/A+(V!=0&&-V/A==0) ;
			int r = U/B;
			cout<<r-l+1<<el;
		}

	}
}
namespace sub4
{
	struct MT
	{
	    int n , m; 
	    int mt[577][577];
	    MT(int _n=0 ,int _m=0)
	    {
	        n = _n ;
	        m = _m ; 
	        FOR(i,1,n)FOR(j,1,m)mt[i][j] = 0;
	    }
	};
	void add(int &a, int b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	}
	MT mul(MT A , MT B )
	{    
	    MT ans(A.n,B.m) ; 
	    FOR(i,1,A.n)
	        FOR(j,1,B.m)
	            FOR(k,1,A.m)
	                add(ans.mt[i][j],1ll*A.mt[i][k]*B.mt[k][j]%sm);
	    return ans ;
	}
	MT pw(MT A , ll n)
	{
	    if(n==1)return A ; 
	    MT B = pw(A,n/2) ;
	    if(n&1)return mul(mul(B,B),A) ; 
	    return mul(B,B) ; 
	}
	int f[105][20] ;		    
	int tms = 0;
	vi val;
	#define state(x,y) (x-1)*n+y 
	void xuly()
	{
		sort(a+1,a+n+1) ; 
		int ma = a[n] ; 
		f[0][1]=1 ;
		FOR(i,1,ma)
		{
			FOR(j,1,n)
			{	
				FOR(pre,1,j)if(i-a[j]>=0)
				{
					add(f[i][j],f[i-a[j]][pre]) ;
				}
			} 
		}
		MT A(1,n*ma) ;
		FOR(i,1,ma)FOR(j,1,n)
		{
			A.mt[1][state(i,j)]=f[i][j] ;
		}
		MT B(n*ma,n*ma); 
		FOR(i,2,ma)FOR(j,1,n)
		{	
			B.mt[state(i,j)][state(i-1,j)]=1;
		}
		FOR(i,1,n)
		{
			int row = ma+1-a[i] ;
			FOR(col,1,i)
			{
				B.mt[state(row,col)][state(ma,i)]=1;
			}
		}
		MT C = mul(A,pw(B,k-1)) ;
		int res =0 ; 
		FOR(i,1,n)
		{
			add(res,C.mt[1][i]) ;
		}
		cout<<res<<el;
	}
}	
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // ll sum =0 ;
        // FOR(j,1,n)sum+=a[j] ;
        // if(n <= 5000 && k <= 5000) sub1::xuly();
        // else 
        if(n==2)sub3::xuly() ;
        // else if(sum<=100ll)sub4::xuly() ;
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}