/*
Name   :   Nguyen Trong Van Viet
DoB    :   29 - 10 - 2006                      
School :   VNUHCM - University Of Science         
Donate :   VCB    - 1026950589                         
*/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;

#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
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

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e7+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int nt[N] ;
vector<int>primeDiv[N] ;
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

    for(int i=2;i<N;i++)
    {
    	if(nt[i]==0)
    	{
    		nt[i] = i ; 
    		for(ll j=1ll*i*i;j<ll(N);j+=i)
    		{
    			nt[j] =  i ;
    		}	
    	}
    }
    auto calc = [](int p , int n )->int 
    {
    	int sum = 0 ; 
    	for(int i=1;i<=n;)
    	{
    		if(i<=n/p)i*=p ; 
    		else break; 
    		sum+=n/i ; 
    	}
    	return sum ; 
    }; 
    int n , m ;
    int test ; cin>>test ;
    while(test--)
    {
    	 cin >> n >> m ;
    	int largestPrime = 1 ; 
    	for(int i=n;i>=2;i--)
    	{
    		if(nt[i]==i)
    		{
    			largestPrime = i ; 
    			break;
    		}
    	}
    	assert(largestPrime!=1) ;
    	vector<int>primes ;  
    	for(int i=largestPrime;i<=n;i++)
    	{
    		int val = i ; 
    		while(val!=1)
    		{
    			int d = nt[val] ; 
    			while(val%d==0)
    			{
    				val/=d ; 
    			}
    			primes.push_back(d) ; 
    		}
    	}	
    	ll sum = 0 ; 
    	for(int i=largestPrime;i<n;i++)
    	{
    		int res = 1e9 ; 
    		for(int j=0;j<primes.size();j++)
    		{
    			int p = primes[j] ; 
    			int u = calc(p,i) ; 
	    		int v = calc(p,n) ;
    			if(u<v)
    			{
    			 	res = min(res,u) ; 
	   				int cnt = 1 ; 
	    			while(p<=m/primes[j])
	    			{
	    				++cnt ; 
	    				p*=primes[j] ; 
	    				if(u/cnt<v/cnt)
	    				{
	    					res = min(res,u/cnt) ; 
	    				}
	       			}	
    			}
    		}	
    		sum+=res; 
    	}
    	cout<<sum<<'\n' ; 
    }

    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


