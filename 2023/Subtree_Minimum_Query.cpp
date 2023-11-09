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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 18 , CH = 26 ; 

int n, root  ; 
int a[N] ; 
vi g[N] ; 
int q; 

void doc()
{
	cin>> n >> root ;
	FOR(i,1,n)cin>>a[i] ;     
	FOR(i,1,n-1)
	{
		int u , v; cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

namespace sub1
{
	int in[N] , out[N] ;
	vi layer[N] ;  
	int h[N]  ; 
	int tt = 0 ;  
	void dfs(int u ,int p)
	{
		h[u] = h[p]+1 ; 
		in[u] = ++tt ;
		layer[h[u]].pb(u) ; 
		for(auto v :g[u])if(v!=p)
		{
			dfs(v,u) ; 
		}
		out[u]=tt; 
	}
	int H[N] ; 
	int st[N*LO] ; 
	int L[N*LO] , R[N*LO] ; 
	int node = 0 ; 
	int up(int old , int l ,int r , int pos , int val)
	{
		int cur = ++node ; 
		if(l==r&&l==pos)
		{
			st[cur] = val; 
			return cur ;  
		}	
		int mid =(l+r)/2 ;
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur]=up(L[old],l,mid,pos,val) ; 
		}
		else
		{
			L[cur] = L[old]; 
			R[cur] = up(R[old],mid+1,r,pos,val) ; 
		}
		st[cur] = min(st[L[cur]],st[R[cur]])  ;
		return cur ; 
	}
	int get(int id, int l ,int r ,int t, int p)
	{
		if(id==0||r<t||p<l)return oo ; 
		if(t<=l&&r<=p)return st[id];  
		int mid =(l+r)/2;
		return min(get(L[id],l,mid,t,p),get(R[id],mid+1,r,t,p)) ; 
	}
    void xuly()
    {
        dfs(root,0) ; 
        st[0] = oo ; 
        FOR(i,1,n)
        {
        	H[i] = H[i-1] ; 
        	for(auto v: layer[i])
        	{
        		H[i] = up(H[i],1,n,in[v],a[v]) ; 
        	}
        }	
		int lres = 0 ; 
		cin>>q ; 
		while(q--)
		{
			int p , q ; cin>>p>> q; 
			int u  = (p+lres)%n+1 ; 
			int k = (q+lres)%n; 	
			cout<<(lres=get(H[min(n,h[u]+k)],1,n,in[u],out[u]))<<el;
		}        
    }	
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}