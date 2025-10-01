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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int a[N] ;
struct DL
{
	int f[1<<5];
	DL(int val=-1)
	{
		FORN(i,0,1<<5)f[i] = N+1 ;  
		if(val>=0)
		{
			FORN(i,0,3)f[1<<i] = 1 ; 
			f[1<<val]=0 ; 
		}
	}

	friend DL operator+(DL& a,DL& b)
	{
		DL res = DL() ;
		FORN(L,1,(1<<5))
		{
			FORN(R,1,(1<<5))if(a.f[L]<N+1&&b.f[R]<N+1)
			{
				if(BIT(L,3)&&BIT(R,2))continue ;
				if(BIT(L,0)&&BIT(R,4))continue ; 
				int msk = (L|R) ;
				if(BIT(L,0)&&BIT(R,1))msk|=(1<<3) ; 
				if(BIT(L,1)&&BIT(R,2))msk|=(1<<4) ; 
				mini(res.f[msk] ,a.f[L]+b.f[R]) ;  
			}
		}
		return res ; 
	}
};
DL st[4*N];
void build(int id ,int l ,int r )
{
	if(l==r)
	{
		st[id] = DL(a[l]) ; 
		return ;  
	}
	int mid = (l+r)>>1 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = st[id<<1]+st[id<<1|1] ; 
}
void up(int id ,int l ,int r ,int pos , int val)
{
	if(r<pos||pos<l)return ; 
	if(l==r)
	{
		st[id] = DL(val) ; 
		return ; 
	}
	int mid =(l+r)>>1 ; 
	up(id<<1,l,mid,pos,val) ; 
	up(id<<1|1,mid+1,r,pos,val) ; 
	st[id] =  st[id<<1]+st[id<<1|1] ; 
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
    int n ,q ; cin>> n >>q ; 
    FOR(i,1,n)
    {
    	char x ; cin>>x ; 
    	a[i] = x-'a' ;
    }
    build(1,1,n) ; 
    while(q--)
    {
    	int pos ; char x ; cin >> pos >> x ; 
    	up(1,1,n,pos,x-'a') ;
    	int res = n+1 ;  
    	for(int i=1;i<(1<<5);i++)
    	{
    		mini(res,st[1].f[i]) ; 
    	}
    	cout<<res<<el;  
    }
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



