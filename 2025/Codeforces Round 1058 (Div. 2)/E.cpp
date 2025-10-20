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
    int test ; cin>>test; 
    while(test--)
    {
	    int n , m;  cin>> n >>m ; 
	    vector<vector<char>>a(n+1,vector<char>(m+1)) ; 
	    for(int i= 1;i<=n;i++)
	    {
	    	for(int j=1;j<=m;j++)
	    	{
	    		char x;  cin>>x ; 
	    		a[i][j] = x ; 
	    	}
	    }
	    bool hadswap = 0 ; 
	    if(n<m)
	    {
		    vector<vector<char>>b(m+1,vector<char>(n+1)) ; 
		    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
		    {
		    	b[i][j] = a[j][i] ; 
		    }
		    swap(a,b) ;
		    swap(n,m) ; 
		    hadswap = 1; 
	    }
	    vector<vector<vector<int>>>mini(n+1,vector<vector<int>>(m+2,vector<int>(m+2,1e9)));
	    for(int l = 1;l<=m;l++)
	    {
	    	for(int r = l+1;r<=m;r++)
	    	{
	    		vector<int>possible;  
	    		for(int i=1;i<=n;i++)
	    		{
					if(a[i][l]=='1'&&a[i][r]=='1')possible.push_back(i) ; 			
	    		}
	    		for(int i=0;i<int(possible.size())-1;i++)
	    		{
	    			int up = possible[i] ; 
	    			int down = possible[i+1];
	    			int cost = (possible[i+1]-possible[i]+1)*(r-l+1);  
	    			for(int row = up;row<=down;row++)
	    			{	
						mini[row][l][r]=min(mini[row][l][r],cost) ;
	    			}
	    		}	
	    	}	
	    }
	    vector<vector<int>>res(n+1,vector<int>(m+1,0)) ; 
	    vector<vector<int>>f(m+2,vector<int>(m+2,1e9)) ;  
	    for(int row=1;row<=n;row++)
	    {
	    	for(int l = 1 ;l<=m;l++)
	    	{
	    		for(int r=l;r<=m;r++)
	    		{
	    			f[l][r] = mini[row][l][r] ; 
	    		}
	    	}
	    	for(int len=m-1;len>=1;len--)
	    	{
	    		for(int l=1;l<=m-len+1;l++)
	    		{
	    			int r = l+len-1; 
	    			f[l][r] = min({f[l][r],f[l-1][r],f[l][r+1]}) ;  
	    		}
	    	}
	    	for(int col=1;col<=m;col++)
	    	{
	    		res[row][col] = f[col][col] ;
	    	}
	    }
	    if(!hadswap)
	    {
		    for(int i=1;i<=n;i++)
		    {
		    	for(int j=1;j<=m;j++)
		    	{
		    		cout<<(res[i][j]==1e9?0:res[i][j])<<" ";
		    	}
		    	cout<<'\n';  
		    }
	    }
	    else
	    {
	    	for(int i=1;i<=m;i++)
	    	{
	    		for(int j=1;j<=n;j++)
	    		{
	    			cout<<(res[j][i]==1e9?0:res[j][i])<<" ";
	    		}
	    		cout<<'\n'; 
	    	}
	    }
    }



    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


