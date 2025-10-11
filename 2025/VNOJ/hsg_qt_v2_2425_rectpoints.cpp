/*
Name   :   Nguyen Trong Van Viet
Age    :   19                             
School :   VNUHCM - University Of Science                                 
*/
#define TASK "rectpoints"
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
int n ,  W , H ; 
struct A
{
	int x ,y ; 
}a[N] ;
int res = 0 ; 
struct DL
{	
	int sum , maxsum ; 
	DL(int sum=0 , int maxsum=0):sum(sum),maxsum(maxsum)
	{

	}
	friend DL operator+(DL a , DL b)
	{
		return {a.sum+b.sum,max(a.maxsum,a.sum+b.maxsum)} ; 
	}
}; 
struct ST
{
	vector<DL>st ; 
	ST(int n )
	{
		st.resize(4*n) ;  
	}	
	void up(int id , int l, int r , int pos , int val)
	{
		if(pos<l||r<pos)
		{
			return ; 
		}
		if(l==r&&l==pos)
		{
			st[id].sum+=val;
			st[id] = {st[id].sum,max(st[id].sum,0)} ;  
			return ; 
		}
		int mid = (l+r)>>1 ;
		if(pos<=mid)
		{
			up(id<<1,l,mid,pos,val) ; 
		}
		else
		{
			up(id<<1|1,mid+1,r,pos,val) ; 
		}
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}
	int get()
	{
		return st[1].maxsum ; 
	}
} ; 
void solve()
{
	vector<int>X,Y ; 
	for(int i=1;i<=n;i++)
	{
		X.push_back(a[i].x-1) ; 
		X.push_back(a[i].x) ; 
		X.push_back(a[i].x+1) ;


		Y.push_back(a[i].y-1) ;
		Y.push_back(a[i].y) ; 
		Y.push_back(a[i].y+1) ; 
	}
	sort(all(X)) ; 
	sort(all(Y)) ; 
	X.resize(unique(all(X))-X.begin()) ; 
	Y.resize(unique(all(Y))-Y.begin()) ;

	vector<vector<pair<int,int>>>D(X.size()+2) ; 
	for(int i=1;i<=n;i++)
	{
		int posX = UB(all(X),a[i].x)-X.begin() ; 
		D[posX].push_back({a[i].y,1});
		int t = UB(all(X),a[i].x+W)-X.begin()+1 ;
		D[t].push_back({a[i].y,-1}) ; 
	}

	ST tree(Y.size()) ;

	for(int i=1;i<=int(X.size());i++)
	{
		for(auto [y,val]:D[i])
		{
			int posY = UB(all(Y),y)-Y.begin() ; 

			tree.up(1,1,Y.size(),posY,val) ;
			posY = UB(all(Y),y+H)-Y.begin()+1 ; 
			tree.up(1,1,Y.size(),posY,-val) ; 
		}
		res = max(res,tree.get())  ;
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

    cin>> n >> W >> H ; 
    vector<int>X ; 
    vector<int>Y ; 

    for(int i=1;i<=n;i++)
    {
    	int x , y ; cin>>x>>y ; 
   		a[i] = {x,y} ; 
    }
    solve() ; 
    // for(int i=1;i<=n;i++)
    // {
    // 	a[i].x = 1e9-a[i].x ; 
    // }
    // solve(); 
    // for(int i=1;i<=n;i++)
    // {
    // 	a[i].y= 1e9-a[i].y ; 
    // }
    // solve() ; 
    // for(int i=1;i<=n;i++)
    // {
    // 	a[i].x = 1e9-a[i].x ; 
    // }
    solve() ; 
    cout<<res<<endl ;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;

}
// fuck I'm old 


