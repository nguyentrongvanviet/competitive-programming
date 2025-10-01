/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool mtt = 0 ; 
int test = 1 ; 
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
#define tct template<class T>
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
void MAKE_THEM_BELIEVE(); 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.OUT","w",stdout) ; 
        freopen("text.INP","r",stdin) ; 
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        MAKE_THEM_BELIEVE() ; 
    }
    cerr<<el<<clock()<<" ms"<<el;
}



int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 



map<int,int>phi ;
vi snt ;
int nt[int(5e4)+5] ;
int a[N]; 
void sieve()
{
	FOR(i,2,5e4)
	{
		if(nt[i]==0)
		{
			nt[i] = i; 
			FOR(j,i,5e4/i)
			{
				nt[i*j] = i ;
			}
		}
	}
	FOR(i,2,5e4)if(nt[i]==i)
	{
		snt.push_back(i) ; 
	}
}
int cal_phi(int val)
{
	int res = val;  
	for(auto x : snt)
	{
		if(val<x)break;
		if(val%x==0)
		{
			while(val%x==0)
			{
				val/=x; 
			}
			res-=res/x; 
		}
	}
	if(val!=1)res-=res/val;
	return res;  
}
void precal_phi(int val )
{
	while(val!=1)
	{
		int nex =  cal_phi(val) ; 
		phi[val] = nex ; 
		val = nex ;
	}
}
ll pw(ll a, ll n, ll sm )
{
	if(n==0) return 1;   
	ll b = pw(a,n/2,sm); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
}
ll solve(int l ,int r ,int m) 
{
	if(m==1)return 0 ; 
	if(a[l]==1)return 1%m ; 
	int pos1 = 0 ; 
	for(int i=l+1;i<=l+4;i++)
	{		
		if(a[i]==1||i>r)
		{
			pos1= i ; 
			break; 
		}
	}
	if(pos1==0)goto t1 ;
	else
	{
		--pos1 ; 
		ll res = 1; 
		FORD(i,pos1,l+1)
		{
			ll cur = 1; 
			FOR(j,1,res)
			{
				cur*=a[i] ; 
				if(cur>=lg(m))goto t1 ;  
			}
			res=cur ; 
		}
		return pw(a[l],res,m) ; 
	}

	t1:  
	return pw(a[l],phi[m]+solve(l+1,r,phi[m]),m) ; 
};
void MAKE_THEM_BELIEVE()
{
	int n , m ; 
	cin>>n >> m  ;
	FOR(i,1,n)cin>>a[i] ;
	sieve() ;
	// cout<<cal_phi(4)<<el;
	precal_phi(m) ; 
	// return ;
	int q ;
	cin>>q ;
	while(q--)
	{
		int l, r ; cin>> l >>r ; 
		cout<<solve(l,r,m)<<el;
	}
}

