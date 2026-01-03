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
const ll inf = 1e18 , cs = 331 ; 
ll sm ; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


struct MT
{
    int n , m; 
    vector<vector<int>>mt;
    MT(int _n ,int _m)
    {
        n = _n ;
        m = _m ; 
        mt=vector<vector<int>>(n+1,vector<int>(m+1,0)); 
    }
};
MT mul(MT A , MT B )
{   
    int n = A.n ;
    int m = B.m ; 
    MT ans(n,m) ; 
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=A.m;k++)
                ans.mt[i][j]=(ans.mt[i][j]+1ll*A.mt[i][k]*B.mt[k][j]%sm)%sm;
    return ans ;
}
MT pw(MT A , ll n)
{
    if(n==1)return A ; 
    MT B = pw(A,n/2) ;
    if(n&1)return mul(mul(B,B),A) ; 
    return mul(B,B) ; 
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

    int n , D , k;
    cin>>n >>sm>>D>>k; 
    MT A(1,n); 
    for(int i=1;i<=n;i++)
    {
    	cin>>A.mt[1][i]; 
    }
    MT B(n,n) ; 
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(min(abs(i-j),n-abs(i-j))<=D)B.mt[i][j] = 1; 
    	}
    }
    MT ans = mul(A,pw(B,k)) ; 
   	for(int i=1;i<=n;i++)cout<<ans.mt[1][i]<<" ";
    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


