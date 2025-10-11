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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


ll f[N] ; 
ll a[N] ; 
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
    int test ; cin>>test;  
    while(test--)
    {
    	int n;  cin>> n ; 
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i] ; 
    	}
    	ll res = 1e18 ; 
    	for(int _=1;_<=10;_++)
    	{
    		a[n+1] = a[n] ; 
    		for(int i=n;i>=1;i--)
    		{
    			a[i] = a[i-1]; 
    		}
    		a[1] = a[n+1] ; 
    		// for(int i=1;i<=n;i++)
    		// {
    		// 	cout<<a[i]<<" " ; 
    		// }
    		// cout<<'\n' ; 
    		f[1] = 1e18 ; 
    		for(int i=2;i<=n;i++)
    		{
    			if(i>=2)
    			{
    				f[i] =  f[i-2] + 1ll*abs(a[i]-a[i-1]) ; 
    			}
    			if(i>=3)
    			{
    				f[i] =  min(f[i],max({a[i],a[i-1],a[i-2]}) - min({a[i],a[i-1],a[i-2]}) +f[i-3]) ; 
    			}	
    		}
    		res = min(res,f[n]) ; 
    		// if(res==0)
    		// {
    		// 	for(int i=1;i<=n;i++)cout<<a[i]<<" ";  
    		// 		cout<<'\n';  
    		// }
    	}
    	cout<<res<<'\n' ; 
    }


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


