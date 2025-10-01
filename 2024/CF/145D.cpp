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
typedef unsigned long long ull;

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


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
    int n; cin>> n; 
    vector<int>a(n+1,0) ;
    vector<int>dd(n+1,0) ;  
    auto check = [&](int val)->bool
    {
    	while(val)
    	{
    		if(val%10!=4&&val%10!=7)return 0 ; 
    		val/=10 ;
    	}
    	return 1;  
    } ;
    vi spec ; 
    vi V ;
    FOR(i,1,n)
    {
    	cin>>a[i] ;  
	 	dd[i] = check(a[i]) ;
	 	if(dd[i])V.pb(a[i]) ; 
	 	if(dd[i])spec.pb(i) ;  
    }
    sort(all(V)) ; 
    uni(V) ; 
    int D =  spec.size() ; 
    ve<vi>same(V.size());
    vi VALUE(n+1,0) ; 
    FOR(i,1,n)
    {
    	if(dd[i])
    	{
    		int val = LB(all(V),a[i])-V.begin() ; 
    		same[val].pb(i) ; 
    		VALUE[i] = val; 
    	}
    }
    // prv(spec) ;
    
   	ve<vi>left(D,vi(D,0)) ; 
   	ve<vi>right(D,vi(D,n+1)) ;
   	vi ID(n+1,0) ;  	
   	FORN(i,0,D)
   	{
   		ID[spec[i]] = i ; 
   	}
   	FORN(x,0,D)
    {
    	FORN(y,0,D)
    	{
			if(y<x)
			{
				// cout<<x+1<<" "<<VALUE[spec[y]]<<" "<<spec[y]<<el;
				left[x][VALUE[spec[y]]] = spec[y] ; 
			}    		
			if(y>x)
			{
				mini(right[x][VALUE[spec[y]]],spec[y]) ;   
			}
    	}
    }
    // return 0 ;
 	ll ans = 0 ; 
    ull res = 0 ;
    // return 0 ;
    FOR(i,1,n)
    {	
    	ans+=ull(n-i)*(n-i+1)/2*i; 
    }
    vector<int>L(n+1,0) ; 
    vector<int>R(n+1,0) ; 
    auto get= [](int i ,int j ,int L, int R)->ull 
	{
	    	// cout<<i<<" "<<j<<" "<<L<<" "<<R<<el;
		ull res = ull(L-i)*ull(j-L+1)*(R-j+1); // i<L ; 
		res += ull(j*ull(j-L)-ull(L+j-1)*(j-L)/2)*(R-j+1);
		return res;  
	}
    FORN(i,0,D)
    {
    	int cur = spec[i] ;
    	int t = 0 ; 
    	FORN(j,0,same[VALUE[cur]].size())
    	{
    		if(same[VALUE[cur]][j]==cur)
    		{
    			t = j ; 
    			break ; 
    		}
    	}
    	++t ; 
    	int lastsame = cur ;
    	FORN(j,t,same[VALUE[cur]].size())
    	{	
			L[j] = lastsame+1 ;
    		R[j] = n ; 
    		lastsame= same[VALUE[cur]][j] ; 
    		res+=ull(cur-(i==0?0:spec[i-1]))*(get(cur,same[VALUE[cur]][j],L[j],R[j])) ; 
    	}
    	FORD(k,i-1,0)
    	{
    		int pre = spec[k] ;
    		if(VALUE[pre]==VALUE[cur])break;
    		FORN(j,t,same[VALUE[cur]].size())
    		{
    			maxi(L[j],left[ID[same[VALUE[cur]][j]]][VALUE[pre]]+1) ; 
    			mini(R[j],right[ID[same[VALUE[cur]][j]]][VALUE[pre]]-1) ;
    			res+=ull(pre-(k==0?0:spec[k-1]))*get(cur,same[VALUE[cur]][j],L[j],R[j]) ; 
    		}
    	}
    }
    ans-=res; 
    cout<<ans ;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



