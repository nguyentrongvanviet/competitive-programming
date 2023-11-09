#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;

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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 2e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

struct MT
{
	int n ,m ;
	ve<vll>mt; 
	void init(int _n , int _m)
	{
		n=_n ;
		m=_m ; 
		mt.resize(n+1) ;
		FOR(i,0,n)mt[i]=vll(m+1,0) ;
	}
}; 
MT mul(MT a , MT b)
{
	int n =a.n ;
	int m =b.m ;
	MT ans.init(n,m) ;
	FOR(i,1,n)FOR(j,1,m)
	{	
		ll tmp = 0 ;
		FOR(k,1,a.m)
		{
			tmp+=(a.mt[i][k]*b.mt[i][j])%sm;
			tmp%=sm; 
		}
		ans.mt[i][j]=tmp ;
	}	
	return ans; 
}
MT pw(MT a,int n)
{
	if(n==1)return a; 
	MT b = pw(a,n/2) ; 
	if(n&1)return mul(mul(b,b),a) ;
	return mul(b,b);
}

void doc()
{
	MT a  ; 
	a.init() ;  
	MT b ; 
	b.init() ; 
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