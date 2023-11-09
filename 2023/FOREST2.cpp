#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e3+5, oo = 2e9, LO = lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;
 
int n , m; 
int bit[N][N] ; 
int a[N][N] ; 
void up(int idx ,int idy ,int val)
{
	for(int i=idx;i<=n;i+=i&-i)for(int j=idy;j<=n;j+=j&-j)bit[i][j]+=val; 
}
int get(int idx, int idy)
{	
	int ans = 0 ; 
	for(int i=idx;i;i-=i&-i)for(int j=idy;j;j-=j&-j)ans+=bit[i][j] ; 
	return ans ; 
}
void doc()
{
	int q ;
    cin>>n >> q; 
    FOR(i,1,n)FOR(j,1,n)
    {
   		char x ; cin>>x ;
   		a[i][j] = (x=='*'?1:0);
   		up(i,j,a[i][j]) ; 
    }
 
    while(q--)
    {
    	int t ; cin>>t ; 
    	if(t==2)
    	{
    		int x, y , u , v; cin>>x>>y>>u>>v ;
    		cout<<get(u,v) - get(u,y-1)-get(x-1,v)+get(x-1,y-1)<<el ; 
    	}
    	else
    	{
    		int x,y ; cin>>x>>y ; 
    		up(x,y,1-a[x][y]-a[x][y]) ; 
    		a[x][y]=1-a[x][y] ; 
    	}
    } 
}       
 
void xuly()
{
    
}
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}