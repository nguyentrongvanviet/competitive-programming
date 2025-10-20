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
    int test ; 
    cin>>test; 
    while(test--)
    {
    	int val; cin>>val; 
    	if(val==0)
    	{
    		cout<<"Yes"<<'\n' ;
    		continue ; 
    	}
    	while(val%2==0)
    	{
    		val>>=1 ;  
    	}
    	int len = 32-__builtin_clz(val) ;
    	bool ok = 1 ; 
    	for(int i=0;i<len/2;i++)
    	{
    		if((val>>i&1)^(val>>(len-1-i)&1))
    		{
    			ok = 0 ; 
    		}
    	}
    	if(ok==0)
    	{
    		cout<<"No\n";
    		continue ;
    	}
    	if(len&1)
    	{
    		if(val>>(len/2)&1)
    		{
    			cout<<"No\n" ;
    		}
    		else cout<<"Yes\n";
    	}
    	else cout<<"Yes\n";
    }


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


