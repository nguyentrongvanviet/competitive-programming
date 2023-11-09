/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  
#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 998244353; 
const int N = 5e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , q; 
vi g[N] ;
void doc()
{
	cin>> n; 
	FOR(i,2,n)
	{
		int u ;
		cin>> u ; 
		g[u].pb(i) ; 
	}
}
namespace sub1
{
	int tt = 0 ;
	int in[N] , out[N] ;
	int h[N] ; 
	int ID[N] ;  
	ll add(ll a , ll b)
	{
		if(a+b<sm)return a+b;
		return a+b-sm ; 
	}
	void inc(ll &a , ll b)
	{
		a+=b; 
		if(a>=sm)a-=sm ;
	}
	void dfs(int u ,int p)
	{
		in[u]=++tt;  
		ID[tt] = u ; 
		for(auto v: g[u])if(v!=p)
		{
			h[v] = h[u] + 1 ; 
			dfs(v,u) ; 
		}
		out[u]=tt; 
	}
	ll Sum_h[4*N] ;
	ll lz_val[4*N] , lz_k[4*N] ; 
	void build(int id ,int l ,int r )
	{
		if(l==r)
		{
			Sum_h[id] = h[ID[l]] ; 
			return ; 
		}
		int mid =(l+r)/2 ; 
		build(id*2,l,mid) ; 
		build(id*2+1,mid+1,r) ; 
		Sum_h[id] =add(Sum_h[id*2],Sum_h[id*2+1]) ; 
	} 
	ll st[4*N];
	void dolazy(int id , int l ,int r )
	{
		if(lz_val[id]==0&&lz_k[id]==0)return ; 
		ll val = lz_val[id] ;
		ll k = lz_k[id] ;  
		inc(st[id],(val*(r-l+1)+k*Sum_h[id])%sm);  
		if(l!=r)
		{
			inc(lz_val[id*2],val) ;
			inc(lz_val[id*2+1],val) ; 
			inc(lz_k[id*2],k) ;
			inc(lz_k[id*2+1],k) ; 
		}
		lz_val[id] = lz_k[id] = 0;	
	}
	void up(int id ,int l , int r , int t ,int p ,int val , int k)
	{
		dolazy(id,l,r) ; 
		if(t<=l&&r<=p)
		{
			lz_val[id] = val ; 
			lz_k[id] = k ; 
			dolazy(id,l,r) ;
			return ;  
		}
		if(r<t||p<l)return ; 
		int mid =(l+r)/2 ; 
		up(id*2,l,mid,t,p,val,k) ; 
		up(id*2+1,mid+1,r,t,p,val,k) ;
		st[id] = add(st[id*2],st[id*2+1]) ; 
	}
	ll get(int id ,int l, int r, int t, int p)
	{
		dolazy(id,l,r) ; 
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0 ; 
		int mid = (l+r)/2; 
		return add(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
	}
    void xuly()
    {
        dfs(1,0) ; 
        build(1,1,n) ; 
        cin>>q; 
        while(q--)
        {
        	str S ; 
        	cin>>S ; 
        	if(S[0]=='a')
        	{
        		int u ; ll k , l  ; 
        		cin>>u >> k >> l;  
        		up(1,1,n,in[u],out[u],(k+l*h[u]%sm+sm*sm)%sm,(-l+10*sm)%sm) ; 
        	}
        	if(S[0]=='g')
        	{
        		int u ; 
        		cin>> u ;
        		cout<<get(1,1,n,in[u],in[u])<<" "; 
        	}
        	if(S[0]=='s')
        	{
        		int u ; 
        		cin>> u ;
        		cout<<get(1,1,n,in[u],out[u])<<" ";
        	}
        }
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
    	int theta ;cin>>theta ; 
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}