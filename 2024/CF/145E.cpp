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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct DL
{
	int s4 , s7 , s47 , s74 ; 
	DL(int s4=0 ,int s7=0, int s47=0 ,int s74=0):s4(s4),s7(s7),s47(s47),s74(s74){} 
	friend DL operator+(DL a , DL b )
	{
		return DL(a.s4+b.s4,a.s7+b.s7,max(a.s4+max(b.s7,b.s47),a.s47+b.s7),max(a.s7+max(b.s4,b.s74),a.s74+b.s4)) ; 
	}
};
char a[N] ; 
DL st[4*N] ;
short lazy[4*N] ;
void build(int id ,int l ,int r)
{
	if(l==r)
	{
		st[id] = {a[l]=='4',a[l]=='7',0,0} ; 
		return ; 
	}
	int mid = (l+r)>>1; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = st[id<<1]+st[id<<1|1] ; 
}
void dolazy(int id, int l ,int r)
{
	if(lazy[id])
	{
		swap(st[id].s4,st[id].s7) ;
		swap(st[id].s47,st[id].s74) ;  
		if(l!=r)
		{
			lazy[id<<1]^=1 ; 
			lazy[id<<1|1]^=1  ; 
		}
		lazy[id] = 0; 
	}
}
void up(int id, int l ,int r ,int t, int p)
{
	dolazy(id,l,r) ; 
	if(t<=l&&r<=p)
	{
		lazy[id] = 1; 
		dolazy(id,l,r) ; 
		return ; 
	}
	if(r<t||p<l)return ; 
	int mid = (l+r)>>1 ; 
	up(id<<1,l,mid,t,p) ; 
	up(id<<1|1,mid+1,r,t,p) ; 
	st[id] = st[id<<1] + st[id<<1|1] ; 
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
    int n , m ; 
    cin >> n >> m;  

    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
    build(1,1,n) ; 
    FOR(_,1,m)
    {
    	string s; cin>>s; 
    	if(s[0]=='c')
    	{
    		cout<<max({st[1].s4,st[1].s7,st[1].s47})<<el ;
    	}
    	else
    	{
    		int l ,r ; cin>> l >>r ; 
    		up(1,1,n,l,r) ; 
    	}
    }
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



