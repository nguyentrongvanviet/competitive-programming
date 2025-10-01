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

struct SegTree
{
	int n; // 0->n 
	vector<long long>st; 
	SegTree(int n=0):n(n)
	{
		st.resize(4*(n+2),0) ; 
	}
	void up(int id ,int l ,int r ,int pos ,ll val)
	{
		if(r<pos||pos<l)return ; 
		if(l==r)
		{
			st[id] = val; 
			return ; 
		}
		int mid = (l+r)>>1; 
		up(id<<1,l,mid,pos,val) ; 
		up(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}
	ll get(int id ,int l ,int r ,int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ;
		if(r<t||p<l)return -inf ; 
		int mid =(l+r)>>1 ;
		return max(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
	}
	void up(int pos ,ll val)
	{
		up(1,0,n+1,pos,val) ; 
	}
	ll get(int l ,int r)
	{
		return get(1,0,n+1,l,r) ; 
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

    int n , p ; cin>> n >> p ;
    vector<vector<int>>a(4,vector<int>(n+2,0)) ; 
    vector<SegTree>rows(4,SegTree(n)) ; 
    for(int i=1;i<=3;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cin>>a[i][j] ; 
    	}
    }
    for(int j=1;j<=n+1;j++)
    {
    	int l = max(0,j-p) ; 
    	int r = j-1 ; 
    	rows[1].up(j,rows[2].get(l,r)+a[1][j]) ;
    	rows[3].up(j,rows[2].get(l,r)+a[3][j]) ; 
    	rows[2].up(j,max(rows[1].get(l,r),rows[3].get(l,r))+a[2][j]) ; 
    }	
    ll res = -inf ; 
    for(int i=1;i<=3;i++)
    {
    	maxi(res,rows[i].get(n+1,n+1)) ; 
    }
    cout<<res<<endl;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



