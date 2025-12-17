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

    int test ; cin>>test ;
    auto solve = [&]()->void
    {
    	int n , color , sum , q;  cin >> n >> color >>  sum >> q ; 
    	vector<vector<int>>g(n+1) ; 
    	for(int i=1;i<=n-1;i++)
    	{
    		int u ,v ; cin>> u>>v ;
    		g[u].push_back(v) ; 
    		g[v].push_back(u) ; 
    	}
    	vector<vector<int>>NodeList(color+1) ;
    	for(int i=1;i<=sum;i++)
    	{	
    		int vertex , color ; cin>> vertex >> color ;  
    		NodeList [color] .push_back(vertex) ; 
    	}
    	vector<int>parent(n+1,0) ; 
    	auto dfs = [&](int u ,int p,auto&& dfs_ref)->void
    	{
    		for(auto v : g[u])if(v!=p)
    		{
    			parent[v] = u ; 
    			dfs_ref(v,u,dfs_ref) ; 
    		}
    	} ; 
    	dfs(1,0,dfs) ;
    	vector<int>pa(n+1,0) ; 
    	int tplt = 0 ;
    	auto goc = [&](int u,auto&& goc_ref)->int
    	{
    		return pa[u] == u ? u : goc_ref(pa[u],goc_ref) ; 
    	} ; 
    	auto hop = [&](int u ) -> void 
    	{
    		if(pa[parent[u]]) pa[u] = goc(parent[u],goc) ; 
    	} ; 
    	vector<int>tp(n+1,0) ;
    	vector<vector<int>>TPNode(n+1) ;  
    	for(int c=1;c<=color;c++)
    	{
	    	for(auto node : NodeList[c])
	    	{
	    		pa[node] = node ; 
	    	}

	    	for(auto node : NodeList[c])
	    	{
	    		hop(node) ; 
	    	}

	    	for(auto node : NodeList[c])
	    	{
	    		int root = goc(node,goc) ; 
	    		if(tp[root]==0)
	    		{
	    			tp[root] = ++tplt ; 
	    		}
	    		TPNode[node].push_back(tp[root]) ; 
	    	}	
	    	for(auto node:NodeList[c])
	    	{
	    		pa[node] = 0 ; 
	    		tp[node] = 0 ; 
	    	}
    	}	
    	for(int i=1;i<=n;i++)
    	{
    		sort(all(TPNode[i])) ; 
    	}
		vector<int>res(q,0) ; 	
		vector<vector<pair<int,int>>>query(n+1);
    	for(int i=0;i<q;i++)
    	{
    		int u , v ; cin>> u >>v ; 
    		if(TPNode[u].size()>TPNode[v].size())swap(u,v) ; 
    		if(TPNode[u].size()<sqrt(sum))
    		{
    			int l = 0 ;
    			for(auto tp : TPNode[u])
    			{
	    			int r = TPNode[v].size()-1 ; 
    				int ans = -1 ; 
    				while(l<=r)
    				{
    					int mid = (l+r)>>1 ;
    					if(TPNode[v][mid]>=tp)
    					{
    						ans=mid ; 
    						r=mid-1 ;
    					}
    					else l=mid+1 ;
    				}
    				if(ans==-1)break; 
    				if(TPNode[v][ans]==tp)
    				{
    					res[i]++ ; 
    					l=ans ;
    				}
    				else l = ans; 
    			}
    		}
    		else
    		{
    			query[u].push_back(make_pair(i,v)) ; 
    		}
    	}
    	vector<int>exist(sum+1,0) ; 
    	vector<vector<int>>need_answer(n+1) ;  

    	auto SOL =[&](int u , int p , auto&&SOL_ref)->void
    	{
    		int sum = 0 ; 
    		for(auto tp : TPNode[u])
    		{
    			sum+=exist[tp] ; 
    		}
    		for(auto id:need_answer[u])
    		{
    			res[id]=sum ; 
    		}
    		for(auto v : g[u])if(v!=p)
    		{
    			SOL_ref(v,u,SOL_ref) ; 
    		}
    	}; 
    	for(int u=1;u<=n;u++)if(!query[u].empty())
    	{
    		for(auto tp : TPNode[u])exist[tp] = 1 ;
    		for(auto [id,v]:query[u])
    		{
    			need_answer[v].push_back(id) ;
    		}
    		SOL(u,0,SOL) ;
    		for(auto [id,v]:query[u])
    		{
    			need_answer[v].clear() ; 
    		}
    		for(auto tp : TPNode[u])exist[tp] = 0 ;
    	}
    	for(auto x : res)cout<<x<<" "; 
    	cout<<'\n';  
    }; 
    while(test--)
    {
    	solve() ; 
    }
    


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


