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

struct DL
{
	int id  ; 
	ll val ; 
} ; 
DL a[N] ;
ll s[N] ; 
ll value[N] ;
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
    ll A , cf , cm , m  ; 
    cin>> n >> A >> cf >> cm >> m  ; 
    FOR(i,1,n)
    {
    	cin>>a[i].val ;
    	a[i].id = i ; 
    }
    sort(a+1,a+n+1,[](DL a , DL b ){return a.val<b.val;}) ; 
    FOR(i,1,n)
    {
    	s[i] = s[i-1]+a[i].val ; 
    }
    int to_A = n+1 ; 
    FORD(i,n,1)
    {
    	if(a[i].val==A)
    	{
    		to_A = i ; 
    	}
    }
    ll res = -inf;
    
    int P = 0 ,  T = 0 ; 
    ll MI = 0 ;
    if(n*A-s[n]<=m)
    {
    	res=n*cf+A*cm;
    	P=1 ; 
    }
   	ll D = A-1 ;
    FORD(i,to_A,1)
    {
    	ll rest = m-(A*(n-i+1)-(s[n]-s[i-1])); 
    	if(rest<0)break;
    	ll l = 0 ;
    	ll r = D  ;
    	D = -1 ; 
    	while(l<=r)
    	{
    		ll mid = (l+r)>>1;
    		int pos = LB(a+1,a+i,mid,[&](const DL& a , const ll& b ){return a.val<b;})-a-1 ; 
    		if(rest>=pos*mid-s[pos])
    		{
    			D=mid ; 
    			if(maxi(res,(n-i+1)*cf+cm*mid))P=i,MI=mid,T=pos; 
    			l =mid+1 ; 
    		}
    		else r=mid-1 ; 
    	} 
    }
    FOR(i,1,T)
    {
    	value[a[i].id] = MI ; 
    }
    FOR(i,T+1,P-1)
    {
    	value[a[i].id] = a[i].val; 
    }
    FOR(i,P,n)value[a[i].id] = A ; 
    cout<<res<<el;
    FOR(i,1,n)cout<<value[i]<<" ";
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



