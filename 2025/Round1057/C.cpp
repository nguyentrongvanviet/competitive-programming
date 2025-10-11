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
    	int n ; cin>>n ;
    	map<int,ll>sl; 
    	for(int i=1;i<=n;i++)
    	{
    		int val ; cin>>val; 
    		sl[val]++ ;   
    	}
    	ll res = 0 ;
    	int Sl = 0 ;
    	vector<int>le ;  
    	ll side = 0 ; 
    	for(auto [x,y]:sl)
    	{
    		if(y&1)
    		{
    			Sl+=(y-1) ; 
    			le.push_back(x) ;
    			side+=(y-1)/2*x ;  
    		}
    		else
    		{
    			Sl+=y ; 
    			side+=y/2*x ; 
    		}
    	}
    	le.push_back(0) ;  
    	sort(all(le)) ;	
    	// cout<<"A"<<side<<endl;
    	if(Sl>2)
    	{
    		res = 2*side ; 
    		for(int i=0;i<le.size();i++)
    		{
    			int l = i+1;
    			int r = le.size()-1 ; 
    			while(l<=r)
    			{
    				int mid = (l+r)>>1; 
    				if(2*side>(le[mid]-le[i]))
    				{
    					res=max(res,2*side+le[mid]+le[i]) ; 
    					l=mid+1; 
    				}
    				else r=mid-1; 
    			}
    		}
    	}
    	else if(Sl==2)
    	{	
    		res = 0 ; 
    		for(int i=0;i<le.size();i++)
    		{
    			int l = i+1;
    			int r = le.size()-1 ; 
    			while(l<=r)
    			{
    				int mid = (l+r)>>1; 
    				if(2*side>(le[mid]-le[i]))
    				{
    					res=max(res,2*side+le[mid]+le[i]) ; 
    					l=mid+1; 
    				}
    				else r=mid-1; 
    			}
    		}
    	}	
    	cout<<res<<'\n'; 
    }


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


