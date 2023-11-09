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

const int N = 2e5+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

int n ; 
ll k ;
ll a[N] ; 
ll s[N] ; 
ll bit[N] ;
void up(int idx, ll val)
{
    for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
}
ll get(int idx )
{
    ll ans =0 ; 
    for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
    return ans ;
}

unordered_map<ll,int>pos ;  
vll value ; 
	
void doc()
{
    cin>> n  >> k; 
    FOR(i,1,n)cin>>a[i] , s[i]=s[i-1]+a[i] ;
  	FOR(i,0,n)value.pb(s[i]) ; 
  	sort(all(value)) ; 
 	value.resize(unique(all(value))-value.begin()) ; 
 	FORN(i,0,value.size())
 	{
 		pos[value[i]]= i+1;  
 	}
}       

void xuly()
{
	ll res =0 ; 
	up(pos[s[0]],1) ; 
	for(int i=1;i<=n;i++)
	{
		int u = upper_bound(all(value),s[i]-k)-value.begin();
		res+=get(u) ;  
		up(pos[s[i]],1) ; 
	}
	cout<<res; 
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