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
#define SZ(a) int(a.size())
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct inline bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct inline bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


struct DL
{
	int val , pos ; 
	DL(int val=0 ,int pos = 0):val(val),pos(pos){} 
} ;
struct cmp
{
	bool operator()(const DL& a , const DL& b)const
	{
		return a.val>b.val||(a.val==b.val&&a.pos<b.pos) ; 
	}
} ; 

int n , len , k; 
int a[N] ;
set<DL,cmp>inqueue ;
set<DL,cmp>kmin ;
set<int>chosen ; 
ll solve()
{
	inqueue.clear() ; 
	kmin.clear() ; 
	chosen.clear() ;
	ll res = 0 ; 
	ll sum = 0 ; 
	FOR(i,1,n)
	{
		sum+=a[i] ;
		if(i-len>=1)
		{
			sum-=a[i-len] ; 
		}
		if(!chosen.empty()&&*chosen.begin()<=i-len)
		{
			kmin.erase(DL(a[*chosen.begin()],*chosen.begin()));
			sum+=2*a[*chosen.begin()]; 
			chosen.erase(chosen.begin()) ; 
		}
		while(!inqueue.empty()&&SZ(kmin)<k)
		{
			if((*inqueue.rbegin()).pos>i-len)
			{
				kmin.insert(*inqueue.rbegin()) ; 
				chosen.insert((*inqueue.rbegin()).pos) ; 
				sum-=2*a[(*inqueue.rbegin()).val];
			}
			inqueue.erase(inqueue.find(*inqueue.rbegin())) ; 
		}
		if(a[i]<0)
		{
			kmin.insert(DL(a[i],i)) ; 
			chosen.insert(i) ; 
			sum-=2*a[i] ;
			assert(SZ(kmin)<=k+1); 
			if(SZ(kmin)>k)
			{
				chosen.erase((*kmin.begin()).pos) ;
				inqueue.insert(*kmin.begin()) ; 
				sum+=2*(*kmin.begin()).val; 
				kmin.erase(kmin.begin()) ;
			}
		}
		if(i>=len)maxi(res,sum) ; 
	}
	return res ; 
};
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
    FOR(i,1,2e5)
    {
    	inqueue.insert(DL(i,i)) ; 
    	inqueue.erase(inqueue.begin()) ; 
    	inqueue.insert(DL(i+2e5,i+2e5)) ; 
    }
    inqueue.erase(DL(1,1)) ; 
    // cin>> n >> len ; 
   	
   	// FOR(i,1,n) cin >> a[i] ; 
   	
   	// cin>> k; 
   	// mini(k,len) ;


   	// ll res = 0 ; 

   	// maxi(res,solve()) ; 
   	// FOR(i,1,n)a[i]=-a[i] ;  
   	// maxi(res,solve()) ; 

   	// cout<<res<<el;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



