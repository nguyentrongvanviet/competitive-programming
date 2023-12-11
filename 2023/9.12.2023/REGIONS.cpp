/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "REGIONS"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 



int n , area , q;
vi g[N] ;

int tp[N] ; 
vi id[N] ; 
void doc()
{
	cin>> n >>area >> q ; 
 	FOR(i,1,n)
 	{
 		if(i>1)
 		{
 			int p ; cin>> p; 
 			g[p].pb(i) ; 
 		} 
 		cin>>tp[i] ;
 		id[tp[i]].pb(i) ; 
 	}   
}

namespace sub1
{
	const int B = 73;
	int in[N] , out[N] ; 
	int node = 0 ; 
	int H[N] ; 
	int L[3*N*(LO+1)] , R[3*N*(LO+1)] ; 
	int ID[N] ; 
	struct DL
	{
		int x ,y; 
		DL(int _x=0,int _y=0)
		{
			x=_x ;
			y=_y ;
		}
		friend DL operator+(DL a,DL b)
		{
			return DL(a.x+b.x,a.y+b.y) ; 
		}
	}; 
	DL st[4*N*LO] ;
	int add(int old ,int l ,int r, int pos ,DL val)
	{
		int cur = ++node ; 
		if(l==r)
		{
			st[cur]= val ; 
			return cur;  
		}
		int mid=(l+r)>>1; 
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur] = add(L[old],l,mid,pos,val) ; 
		}
		else 
		{
			L[cur] = L[old] ; ;
			R[cur] = add(R[old],mid+1,r,pos,val) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ;
		return cur ;
	}
	DL get(int id ,int l ,int r, int t ,int p)
	{
		if(id==0)return 0 ;
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return DL(0,0); 
		int mid=(l+r)>>1;  
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
	}
	int time_dfs = 0 ;
	void dfs(int u )
	{
		in[u] = ++time_dfs ; 
		for(auto v:g[u])
		{
			dfs(v) ; 
		}
		out[u] = ++time_dfs; 
	}
	vi big;
	ll C[550][550] ; 
    void xuly()
    {
    	dfs(1) ; 
    	int cnt = 0 ; 
    	FOR(i,1,area)if(SZ(id[i])>=B)
    	{
    		big.pb(i) ;
    		ID[i]=++cnt;
    	}
    	FOR(i,1,area)
    	{
    		for(auto u : id[i])
    		{
	    		H[i] = add(H[i],1,2*n,in[u],DL(1,1));
	    		H[i] = add(H[i],1,2*n,out[u],DL(0,-1)) ; 
    		}
    	}
    	for(auto u : big)
    	{
    		for(auto v :big)
    		{
    			for(auto x :id[u])
    			{	
    				C[ID[u]][ID[v]]+=get(H[v],1,2*n,in[x],out[x]).x;
    			}	
    		}
    	}
    	while(q--)
    	{
    		int a ,b ; cin>> a >>b; 
    		if(SZ(id[a])>=B&&SZ(id[b])>=B)
    		{	
    			cout<<C[ID[a]][ID[b]]<<el;
    		}
    		else	 
    		{
    			ll res =0 ; 
    			if(SZ(id[a])<SZ(id[b]))
    			{
    				for(auto u : id[a])
    				{
    					res+=get(H[b],1,2*n,in[u],out[u]).x; 
    				}
    			}	
    			else
    			{
    				for(auto u :id[b])
    				{
    					res+=get(H[a],1,2*n,1,in[u]).y;
    				}
    			}
    			cout<<res<<el;
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}