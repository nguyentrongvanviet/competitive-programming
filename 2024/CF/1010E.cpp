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

struct pt
{
	int x ,y , z , id ; 
	bool operator<(const pt&a)const
	{
		return z<a.z ; 
	}
};
struct DL
{
    int XL,XR,YL,YR,ZL,ZR ;
    DL(int XL=oo ,int XR=0 ,int YL=oo ,int YR=0 , int ZL=oo ,int ZR=0 ):XL(XL),XR(XR),YL(YL),YR(YR),ZL(ZL),ZR(ZR) {}
    void operator[](const pt& a)
    {
		mini(XL,a.x) ; 
    	maxi(XR,a.x) ; 
    	mini(YL,a.y) ; 
    	maxi(YR,a.y) ; 
    	mini(ZL,a.z) ; 
    	mini(ZR,a.z) ; 
    }
    DL up(int x ,int y ,int z)
    {
    	return DL(min(XL,x),max(XR,x),min(YL,y),max(YR,y),min(ZL,z),max(ZR,z)) ;
    }
}; 
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
    int xmax, ymax , zmax , n , m , k ;
    cin>>xmax>>ymax>>zmax>>n>>m>>k ;  
    DL A ; 
    FOR(i,1,n)
    {
    	int x , y , z ; cin>> x>> y >>z ; 
    	A=A.up(x,y,z) ; 
    }
    ve<pt>a ; 
   	FORN(i,0,m)
    {
    	int x,y,z ; cin>>x>>y>>z ;
    	if(A.XL<=x&&x<=A.XR&&A.YL<=y&&y<=A.YR&&A.ZL<=z&&z<=A.ZR)
    	{
    		cout<<"INCORRECT"<<el;
    		return 0 ; 
    	}
    	a.pb({x,y,z,0}) ; 
    }
    cout<<"CORRECT"<<el;
    ve<pt>q ; 
    FORN(i,0,k)
    {
    	int x,y,z ; cin>>x>>y>>z ;
    	q.pb({x,y,z,i}) ; 
    }
    ve<vi>node(xmax+1) ; 
    auto fakeup =[&](int x, int y)->void
    {
    	for(;x<=xmax;x+=x&-x)
    	{
    		node[x].pb(y) ; 
    	}
    };
    auto fakeget = [&](int x, int y)->void
    {
    	for(;x;x-=x&-x)
    	{
    		node[x].pb(y) ; 
    	}
    };
    auto FAKEGET = [&](DL X)->void
    {
    	int u = X.XL ; 
    	int v = X.YL ; 
    	int x = X.XR ; 
    	int y = X.YR ; 
    	fakeget(x,y) ; fakeget(x,v-1) ; fakeget(u-1,y);fakeget(u-1,v-1) ;
    };
    for(auto [x,y,z,id]:a)
    {
    	fakeup(x,y) ; 
    }
    for(auto [x,y,z,id]:q)
    {
    	FAKEGET(A.up(x,y,z)) ; 
    }
    ve<vi>bit(xmax+1);
    FOR(i,1,xmax)
    {
    	sort(all(node[i])) ; 
    	uni(node[i]) ; 
    	bit[i] = vi(node[i].size()+1,0) ; 
    }
    auto up = [&](int x ,int y, int val )->void
    {	
		for(;x<=xmax;x+=x&-x)
    	{
    		for(int j = UB(all(node[x]),y)-node[x].begin();j<=(int)node[x].size();j+=j&-j)
    		{
    			bit[x][j]+=val; 
    		}
    	}
    };
    auto get = [&](int x, int y)->int
    {
    	int ans = 0 ; 
    	for(;x;x-=x&-x)
    	{
    		for(int j= UB(all(node[x]),y)-node[x].begin();j;j-=j&-j)
    		{
    			ans+=bit[x][j] ; 
    		}
    	}
    	return ans ; 
    };
    auto GET = [&](DL X )->int
    {
    	int u = X.XL ; 
    	int v = X.YL ; 
    	int x = X.XR ; 
    	int y = X.YR ; 
    	return get(x,y)-get(x,v-1)-get(u-1,y)+get(u-1,v-1) ;
    };

    sort(a.begin(),a.end()) ; 
    sort(q.begin(),q.end());

    for(auto [x,y,z,id]:a)
	{
		if(A.ZL<=z&&z<=A.ZR)
		{
			up(x,y,1) ; 
		}
	}
    vector<int>res(k,0);
    // z>=ZL 
    int it = 0 ; 
	for(auto [x,y,z,id]:q)if(z>=A.ZL)
	{
		while(it<m&&a[it].z<=z)
		{
			auto [x,y,z,id] = a[it] ; 
			if(z>A.ZR)
			{
				up(x,y,1) ; 
			}
			++it  ;
		}
		if(A.XL<=x&&x<=A.XR&&A.YL<=y&&y<=A.YR&&A.ZL<=z&&z<=A.ZR)res[id]=-1;
		else 
		{
			DL X = A.up(x,y,z) ;  
			res[id] = (GET(X)==0);
		}
	}
	it = 0 ; 
	for(auto [x,y,z,id]:q)if(z>=A.ZL)
	{
		while(it<m&&a[it].z<=z)
		{
			auto [x,y,z,id] = a[it] ; 
			if(z>A.ZR)
			{
				up(x,y,-1) ; 
			}
			++it  ;
		}
	}
	reverse(a.begin(),a.end());
	reverse(q.begin(),q.end()); 
	it = 0 ; 
	// z<ZL 
	for(auto [x,y,z,id]:q)if(z<A.ZL)
	{
		while(it<m&&a[it].z>=z)
		{
			auto [x,y,z,id] = a[it] ; 
			if(z<A.ZL)
			{
				up(x,y,1) ; 
			}
			++it  ;
		}
		DL X = A.up(x,y,z) ;  
		res[id] = (GET(X)==0);
	}
	FORN(i,0,k)
	{
		if(res[i]==0)
		{
			cout<<"CLOSED"<<el;  
		}
		else if(res[i]==1)
		{
			cout<<"UNKNOWN"<<el;
		}
		else
		{
			cout<<"OPEN"<<el;
		}
	}
	cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



