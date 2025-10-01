/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
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
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ; 
vi g[N] ; 
int C[N][N] ;
int pre[N] ; 
bool find(int s = 1 ,int t = n)
{
	queue<int>q ; 
	q.push(1) ; 
	FOR(i,1,n)
	{
		pre[i] = 0 ; 
	}
	pre[1] = 1; 
	while(!q.empty())
	{
		int u = q.front()  ; 
		q.pop() ; 
		if(u==n)return 1 ; 
		for(auto v :g[u])if(C[u][v]&&pre[v]==0)
		{	
			q.push(v) ; 
			pre[v] = u ;
		}
	}
	return 0 ; 
}
void go()
{
	vector<vector<int>> res ; 
	while(find())
	{
		vector<int>node ; 
		for(int v = n;v!=1;v=pre[v])
		{
			int u = pre[v] ; 
			C[u][v] = 0 ; 
			node.push_back(v) ; 
		}
		for(int v = n;v!=1;v=pre[v])
		{
			int u = pre[v] ; 
			C[u][v] =  ; 
			node.push_back(v) ; 
		}
		node.pb(1) ; 
		reverse(all(node)) ; 
		res.push_back(node) ; 
	}
	cout<<res.size()<<el; 
	for(auto &node:res)
	{
		cout<<node.size()<<el; 
		for(auto &u:node)cout<<u<<" "; 
		cout<<el; 
	}
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

    cin>> n >> m ;
    for(int i=1;i<=m;i++)
    {
    	int u ,v ; cin>> u >>v  ; 
    	g[u].push_back(v) ; 
    	C[u][v] = 1 ; 
    }
    go() ; 

    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



