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

int nt[N] ;
ll pre[(1<<19)] ;
ll cur[1<<19] ; 
ll fac[N] , ifac[N] ;
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
} 
void build()
{
	fac[0] =1 ; 
	FOR(i,1,N-1)fac[i] = fac[i-1]*i%sm; 
	ifac[N-1] = pw(fac[N-1],sm-2) ; 
	FORD(i,N-2,0)
	{
		ifac[i] = ifac[i+1]*(i+1)%sm ; 
	}
} 
ll C(int k ,int n)
{
	return (k>n?0:fac[n]*ifac[k]%sm*ifac[n-k]%sm) ; 
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
    int n; 
    cin>> n; 
    vi sl(71,0) ;
    FOR(i,1,n)
    {
    	int val ; cin>>val;  
    	sl[val]++ ; 
    }
    vi prime ; 
    FOR(i,2,70)
    {
    	if(nt[i]==0)
    	{
    		nt[i] = i ; 
    		prime.push_back(i) ; 
    	}
    	for(auto x :prime)
    	{
    		nt[i*x]=x; 
    		if(x%i==0)break; 
    	}
    }
    build() ; 
    map<int,int>a ; 
    FOR(i,1,70)if(sl[i])
    {
    	int val = i ; 
    	int msk = 0  ;
    	int cnt = 0 ; 
    	for(auto x : prime)
    	{
    		while(val%x==0)
    		{
    			msk^=(1<<cnt) ; 
    			val/=x;
    		}
    		cnt++ ; 
    	}
    	a[msk]+=sl[i] ; 
    }
    pre[0] = 1;  
    for(auto [val,sl]:a)
    {
    	ll odd = 0 , even = 0 ; 
    	FOR(i,0,sl)
    	{
    		if(i&1)(odd+=C(i,sl))%=sm;
    		else (even+=C(i,sl))%=sm ; 
    	}
    	FORN(msk,0,1<<prime.size())
    	{
    		(cur[msk]+=pre[msk]*even%sm)%=sm;
    		(cur[msk^val]+=pre[msk]*odd%sm)%=sm;
    	}
    	FORN(msk,0,1<<prime.size())
    	{
    		pre[msk] = cur[msk] ;
    		cur[msk] = 0 ;
    	}
    }
    cout<<pre[0]-1<<el;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



