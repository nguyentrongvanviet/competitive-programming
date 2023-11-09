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

const int N = 55+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  	
	return b*b%sm ;
}
int n , k ; 
ll C[N][N] ; 
void doc()
{
	cin>> n>> k; 
	C[0][0] =1 ; 
	FOR(i,1,k)
	{
		C[0][i]= 1 ;
		FOR(j,1,i)
		{
			C[j][i] = C[j-1][i-1]+C[j][i-1];
			C[j][i]%=sm; 
		}
	} 
	ll tot =  pw(k,n) ;
	ll tmp = 0 ; 
	FOR(i,1,k-1)
	{
		if(i&1)tmp+=(C[i][k]*(pw(k-i,n))%sm+sm)%sm;
		else tmp-=(C[i][k]*pw(k-i,n)%sm+sm)%sm; 
		tmp%=sm ; 
	}
	cout<<(tot-tmp+sm)%sm;
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