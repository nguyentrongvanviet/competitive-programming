/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool mtt = 1 ; 
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
const int N = 6e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
ll mu[N] ; 
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
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
    mu[0] = 1 ; 
    FOR(i,1,6e6)mu[i] = mu[i-1]*2%sm; 
    FOR(i,1,test)
    {
        MAKE_THEM_BELIEVE() ; 
    }
    cerr<<el<<clock()<<" ms"<<el;
}



int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;


ll a[N];
struct DL
{
	ll base , num2 ; 
} ; 
void MAKE_THEM_BELIEVE()
{
	int n; cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	ll res = 0 ; 
	ve<DL> q;  
	FOR(i,1,n)
	{
		ll num = 0 ;
		while(a[i]%2==0)
		{
			a[i]/=2 ; 
			++num ; 
		} 
		while(!q.empty())
		{
			auto [base,num2] = q.back() ; 
			if(num>=31||base<=a[i]*mu[num])
			{
				(res-=base*mu[num2]%sm-sm)%=sm;
				(res+=base)%=sm ;
				num+=num2 ;
				q.pk() ;
			}
			else break; 
		}
		if(num==0)(res+=a[i])%=sm ; 
		else
		{
			q.push_back({a[i],num}) ; 
			(res+=a[i]*mu[num]%sm)%=sm ; 
		}
		cout<<res<<" ";
	}
	cout<<el ; 
}
