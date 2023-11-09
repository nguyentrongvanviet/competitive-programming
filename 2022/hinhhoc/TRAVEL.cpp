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
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 2e3+1 , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330 ;  
const db PI = acos(-1) , EPS = 1e-9 ;
int n; 
int sm  = 1e9+7 ; 
struct DL
{
	int x , y; 
	bool operator<(const DL&a)const
	{
		return x<a.x||(x==a.x&&y<a.y) ; 
	}
} ; 
void add(int&a, int b )
{
	a+=b ;
	if(a>=sm)a-=sm ; 
}
DL a[N] ; 
int bit[N][N] ; 
int f[N] , dp[N] ; 
unordered_map<int,int>pos ;
void up(int idx, int idy , int val)
{	
	for(int i= idx;i<=n;i+=i&-i)
		for(int j =idy;j<=n;j+=j&-j)
			add(bit[i][j],val) ; 
}
int get(int idx, int idy  )
{
	int ans = 0 ; 
	for(int i= idx;i;i-=i&-i)
		for(int j =idy;j;j-=j&-j)
			add(ans,bit[i][j]);   
	return ans ; 
}
void doc()
{
	cin>> n;
	vi value ; 
	FOR(i,1,n)cin>>a[i].x , value.pb(a[i].x) ; 
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
	FORN(i,0,value.size())pos[value[i]] = value.size()-i;
	FOR(i,1,n)a[i].x=pos[a[i].x];  
	value.clear() ; 
	
	FOR(i,1,n)cin>>a[i].y , value.pb(a[i].y) ; 
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
	FORN(i,0,value.size())pos[value[i]] = i+1;
	FOR(i,1,n)a[i].y=pos[a[i].y];  
}     
void nen()
{
	vi value ; 
	for(int i= 1;i<=n;i++)value.pb(a[i]) ; 
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
	unordered_map<int,int>pos ; 
	for(int i=0;i<value.size();i++)pos[value[i]]=i+1; 
	FOR(i,1,n)a[i] = pos[a[i]] ; 
}
void xuly()
{
	sort(a+1,a+n+1); 
	FOR(i,1,n)cout<<a[i].x<<" "; cout<<el; 
	FOR(i,1,n)cout<<a[i].y<<" "; cout<<el; 
	FOR(i,1,n)up(a[i].x,a[i].y,f[i]=1); 
	cout<<n<<el;
    FOR(t,2,n)
    {
    	int sum =0 ;
    	FOR(i,1,n)
    	{
    		dp[i] = get(a[i].x-1,a[i].y-1) ;
    		add(sum,dp[i]);  
    		cout<<get(a[i].x-1,a[i].y-1)<<" "; 
    	}
    	FOR(i,1,n)
    	{
    		up(a[i].x,a[i].y,(dp[i]-f[i]+sm)%sm);
    		f[i] = dp[i] ;  
    	} 
    	cout<<sum<<el;
    }
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