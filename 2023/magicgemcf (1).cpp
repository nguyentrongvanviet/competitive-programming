#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
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
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
// tct bool mini(Tx& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
#define int ll
const int N = 1e6+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
ll n;
int m;
struct MT
{
    int n , m; 
    ve<vll> mt ; 
    void init(int _n ,int _m)
    {
        n = _n ;
        m = _m ; 
        mt=ve<vll>(n+1,vll(m+1,0)); 
    }
};
MT mul(MT A , MT B )
{   
    int n = A.n ;
    int m = B.m ; 
    MT ans ; ans.init(n,m) ; 
    FOR(i,1,n)
        FOR(j,1,m)
            FOR(k,1,A.m)
                ans.mt[i][j]=(ans.mt[i][j]+A.mt[i][k]*B.mt[k][j]%sm)%sm;
    return ans ;
}
MT pw(MT A , ll n)
{
    if(n==1)return A ; 
    MT B = pw(A,n/2) ;
    if(n&1)return mul(mul(B,B),A) ; 
    return mul(B,B) ; 
}
void doc()
{
	cin>>n>>m;
	if(n < m) 
	{
		cout<<1;
		return;
	}
	else if(n == m)
	{
		cout<<2;
		return;
	}
	MT A; A.init(m,1);
	for(int i=1;i<=m;i++)
	{
		A.mt[i][1] = 1;
	}
	MT B;B.init(m,m);
	B.mt[m][1] = 1;
	B.mt[m][m] = 1;
	for(int i = 1;i<m;i++)
	{
		B.mt[i][i+1] = 1;
	}
	MT D = pw(B,n-m+1);
	MT C = mul(D,A);
	cout<<C.mt[m][1];
}

void xuly()
{

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
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}