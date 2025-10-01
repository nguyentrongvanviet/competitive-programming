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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

double A , B ; 

struct pt
{
	int x ,y ;
	pt(int x = 0 ,int y = 0):x(x),y(y) {}  
} ; 
struct Node
{
	pt endpoint[2] ;  
	Node(int x=0,int y =0 ,int u =0 ,int v =0)
	{
		endpoint[0] = pt(x,y) ; 
		endpoint[1] = pt(u,v) ;
	} 
};
db dis(pt a , pt b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y)) ; 
}
db len(Node a)
{
	return abs(a.endpoint[0].x-a.endpoint[1].x)+abs(a.endpoint[0].y-a.endpoint[1].y);
}
void rotate(Node&a)
{
	FOR(i,0,1)swap(a.endpoint[i].x,a.endpoint[i].y) ; 
}
bool check(int l ,int r ,int val)
{
	return abs(l-val)+abs(r-val)==abs(r-l) ; 
}
db dis(Node a , Node b)
{
	db ans = inf ;
	FOR(i,0,1)
	{
		FOR(j,0,1)
		{
			mini(ans,dis(a.endpoint[i],b.endpoint[j])) ; 
		}
	}
	if(len(a)<len(b))swap(a,b) ; 
	if(a.endpoint[0].y==a.endpoint[1].y)
	{
		rotate(a) ; 
		rotate(b) ; 
	}
	FOR(i,0,1)
	{
		if(check(b.endpoint[0].x,b.endpoint[1].x,a.endpoint[i].x))
		{
			mini(ans,1.0*abs(a.endpoint[i].y-b.endpoint[0].y)) ; 
		}
	}
	FOR(i,0,1)
	{
		if(check(a.endpoint[0].y,a.endpoint[1].y,b.endpoint[i].y))
		{
			mini(ans,1.0*abs(a.endpoint[0].x-b.endpoint[i].x));
		}
	}
	return (ans>A?inf:ans) ; 
}

struct DL
{
	int u ; 
	double val;  
}; 
struct cmp
{
	bool operator()(const DL&a,const DL&b)const
	{
		return a.val>b.val;  
	}
} ;
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
    cin>>A>>B ;
    ve<Node>trend ; 
    FOR(i,1,2)
    {
    	int x , y ; cin>>x >> y ; 
    	trend.pb(Node(x,y,x,y)) ; 
    }
    int n; 
    cin>> n;
    FOR(i,1,n)
    {
    	int x ,y , u ,v ; cin>> x >> y >> u >> v; 
    	trend.pb(Node(x,y,u,v)) ; 
    }
    priority_queue<DL,ve<DL>,cmp>q ;
    ve<db>f(n+2,inf) ;  
    q.push({0,f[0]=0}) ; 
    auto NEXT = [&](db val)->db
    {
    	return ceil(val/(A+B))*(A+B) ; 
    };
    while(!q.empty())
    {
    	auto [u,val] = q.top() ; 
    	q.pop() ; 
    	if(abs(val-f[u])>EPS)continue ; 
    	FOR(v,1,n+1)
    	{
    		if(mini(f[v],NEXT(f[u])+dis(trend[u],trend[v])))
    		{
    			q.push({v,f[v]}) ; 
    		}
    	}
    }

  	if(abs(f[1]-inf)<EPS)
  	{
  		cout<<-1 ; 
  		return 0;  
  	}
  	cout<<setprecision(6)<<fixed<<f[1]<<el; 
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



