#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
#define ll long long 
#define int long long 
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
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 2e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n; 
int a[N] ; 
void doc()
{	
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ;  
}       
ll f[N] ; 
ll sum[N] ; 
ll sc[N] ; 
map<int,int>pos ; 
ll la[N] ; 
void xuly()
{	
	pos.clear() ; 
	vi value ; 
	FOR(i,1,n)value.pb(a[i]) ; 
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
	FORN(i,0,value.size())pos[value[i]] = i+1 ; 
	FOR(i,1,n)a[i] = pos[a[i]] ; 
	FOR(i,1,n)
	{
		f[i]=(f[i-1]+sc[a[i]]) ; 
		sum[a[i]]=(sum[a[i]]+1LL*i-la[a[i]]);  
		sc[a[i]]=(sc[a[i]]+sum[a[i]]) ; 
		la[a[i]] = i ; 
	}
	ll res=0;  
	FOR(i,1,n)res+=f[i] ; 
	cout<<res<<el; 
	FOR(i,1,n)f[i]=0,sum[i]=0,la[i]=0,sc[i]=0;
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