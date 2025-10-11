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
// const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


const int N = 17; 
int f[1<<N+5] ; 
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
    f[0] = 0 ;
    auto mex = [](vector<int>&a)->int
    {	
    	sort(all(a)) ; 
    	int id = 0;  
    	for(int i=0;i<a.size();i++)
    	{
    		if(id<a[i])break;
    		if(id==a[i])++id ; 
    	}
    	return id ; 
    }; 
    for(int i=1;i<=N;i++)
    {
    	for(int j=0;j<(1<<i-1);j++)
    	{
    		vector<int>val ; 
    		int msk = (j^(1<<(i-1))) ; 
    		for(int tmp=msk;tmp;tmp-=tmp&-tmp)
    		{
    			int u = __builtin_ctz(tmp) ; 
    			val.push_back(f[msk^(1<<u)]) ;
    			for(int v=u-1;v>=0;v--)
    			{
    				val.push_back(f[msk^(1<<u)^(1<<v)]) ;
    				for(int t = v-1;t>=0;t--)
    				{
    					val.push_back(f[msk^(1<<u)^(1<<v)^(1<<t)]); 
    				}
    			}
    		} 
    		f[msk] = mex(val) ; 
            // if(j==0)
            // {   
            //     // cout<<"VALUE " << bitset<N>(msk)<<endl;
            //     map<int,int>sl ; 
            //     for(int tmp=msk;tmp;tmp-=tmp&-tmp)
            //     {
            //         int u = __builtin_ctz(tmp) ; 
            //         val.push_back(f[msk^(1<<u)]) ;
            //         sl[f[msk^(1<<u)]]++ ; 
            //         for(int v=u-1;v>=0;v--)
            //         {
            //             sl[f[msk^(1<<u)^(1<<v)]]++;
            //             for(int t = v-1;t>=0;t--)
            //             {
            //                 sl[f[msk^(1<<u)^(1<<v)^(1<<t)]]++ ; 
            //             }
            //         }
            //     }
                // for(auto [x,y]:sl)
                // {
                //     cout<<x<<" "<<y<<endl;
                // }   
            // }
        }	
    }
    for(int i=0;i<(1<<N);i++)
    {
        cout<<i<<" "<<bitset<N>(i)<<" "<<f[i]<<endl;
    	// cout<<i<<" "<<bitset<N>(1<<i)<<" "<<f[1<<i]<<" ";
        // if(f[1<<i]==i*2)
        // {
        //     cout<<0<<'\n';
        // }
        // else cout<<"+1\n";

    }
    int test ; cin>>test; 
    while(test--)
    {
        int n ; cin>>n ; 

        for(int i=1;i<=n;i++)
        {
            ll val;  cin>>val; 

        }
    }

    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


