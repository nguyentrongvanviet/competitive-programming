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
    int test; cin>>test;
    while(test--)
    {
	    int n,k ; cin>> n >> k ;
	    vector<vector<int>>g(n+1) ; 
	    for(int i=2;i<=n;i++)
	    {
	    	int p ; cin>>p ;
	    	g[p].push_back(i) ;  
	    }
	    vector<int>h(n+1,0) ; 
	    int mi = n; 
	    auto dfs = [&](int u,int dep, auto&&dfs_ref )->void
	    {
	   		if(g[u].size()==0)mi = min(mi,dep) ; 
	   		h[dep]++ ; 
	    	for(auto v : g[u])
	    	{
	    		dfs_ref(v,dep+1,dfs_ref) ; 
	    	}
	    };	
	    dfs(1,1,dfs) ;
	    auto check =[&](int pos)->bool 
	    {
	    	map<int,int>a; 
	    	int tot = 0 ; 
	    	for(int i=1;i<=pos;i++)
	    	{
	    		a[h[i]]++ ;
	    		tot+=h[i] ; 
	    	}
		    vector<int>cur(n+1,0) ;
		    vector<int>nex(n+1,0) ;
		    int ma = 0 ; 
		    auto up =[&](int val)->void
		    {
		    	for(int i=val;i<=n;i++)nex[i]|=cur[i-val];
		    	for(int i=val;i<=n;i++)
				{
					cur[i] = nex[i] ; 
		    		if(cur[i]&&i<=k) ma = max(ma,i) ; 
		    	}
		    }; 
		    cur[0] = 1;
		   	for(auto [val,sl]:a)
		   	{		 
		   		// if(pos==2)cout<<val<<" "<<sl<<endl;
		   		for(int x=1;x<=sl;x<<=1)
		   		{
		   			up(val*x) ; 
		   			sl-=x;
		   		}
		   		if(sl)
		   		{
		   			up(val*sl) ; 
		   		}
		   	}
		   	return tot-ma<=n-k ; 
	    } ; 
	    int l = 1 ; 
	    int r = mi ; 
	    int ans = 0 ; 
	    while(l<=r)
	    {
	    	int mid =(l+r)>>1 ; 
	    	if(check(mid))ans=mid,l=mid+1; 
	    	else r=mid-1 ; 
	    }
	    cout<<ans<<endl; 
    }
    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


