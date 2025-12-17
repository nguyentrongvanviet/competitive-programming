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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
}
ll P_Q(int p ,int q)
{
	return p*pw(q,sm-2)%sm ; 
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
    int test ;
    cin>>test ; 
    while(test--)
    {
    	int n; cin>> n;
    	vector<vector<int>>g(n+1) ; 
    	vector<int>pa(n+1,0) ; 
    	for(int i=1;i<=n-1;i++)
    	{
    		int u ,v ; cin>> u >>v ; 
    		g[u].push_back(v) ; 
    		g[v].push_back(u) ; 
    	}
    	vector<int>dep(n+1) ; 
    	vector<int>leaves ; 
    	auto dfs =[&](int u ,int p,int h ,auto&& dfs_ref)->void
    	{
    		bool leaf = 1 ; 
    		dep[u] = h ; 
    		for(auto v:g[u])if(v!=p)
    		{
    			leaf = false ; 
    			pa[v] = u ;   
    			dfs_ref(v,u,h+1,dfs_ref);
    		}
    		if(leaf)
    		{
    			leaves.push_back(u) ; 
    		}
    	};	
    	dfs(1,0,1,dfs) ; 
    	sort(all(leaves),[&](int u ,int v){return dep[u]<dep[v];});
    	vector<int>res(n+1,0) ; 
    	res[1] = 1; 
    	for(auto leave : leaves)
    	{
    		int head = leave ; 
    		int len = 1 ; 
    		while(res[head]==0)
    		{
    			head = pa[head] ; 
    			len++ ; 
    		}
    		int pos = len; 
    		int cur = leave;  
    		while(pos>1)
    		{
    			res[cur] = res[head]*P_Q(len-pos,len-1)%sm; 
    			pos-- ; 
    			cur=pa[cur] ; 
    		}
    	}
    	for(int i=1;i<=n;i++)
    	{
    		cout<<res[i]<<" "; 
    	}
    	cout<<'\n' ; 
    }


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


