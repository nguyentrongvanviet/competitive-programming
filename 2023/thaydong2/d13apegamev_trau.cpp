/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define int long long 
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
#define        Mask(i)  (1ll<<(i))
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


int n , q ; 
int p[N] , w[N] ; 
struct ke
{
	int v , w ; 
};
ve<ke>g[N] ;
void doc()
{
    cin>> n >> q; 
    FOR(i,2,n)
    {
    	cin>>p[i] ; 
    }
    FOR(i,2,n)
    {
    	cin>>w[i] ; 
    	g[p[i]].pb({i,w[i]}) ; 
    }
}

namespace sub1
{
	ll f[N] , ma[N];   
	ll VAL[N] ; 
	int tt = 0; 
	int exist[N] ; 
	int s, d ; 
	void dfs(int u )
	{
		exist[u] = (u<=d) ; 
		ma[u] = f[u] ; 
		for(auto [v,w]:g[u])
		{
			f[v] = f[u] + w; 
			dfs(v) ;
			if(exist[v]==0)continue ; 
			maxi(ma[u],ma[v]) ; 
			exist[u] = 1 ;
		}
	}
	void build(int u , int p , int ok ) 
	{
		if(ok)
		{
			int ans = 0  ;
			for(auto [v,w] :g[u])if(exist[v])
			{	
				if(ma[ans]<ma[v])
				{
					ans=v ;
				}
			}
			if(ans==0)ans= u ;
			if(ans!=u)build(ans,u,1) ; 
			for(auto [v,w]:g[u])if(exist[v]&&v!=ans)
			{
				build(v,u,0) ; 
			}
		}
		else
		{
			int ans = 0 ;  
			for(auto [v,w] :g[u])if(exist[v])
			{	
				if(ma[ans]<ma[v])
				{
					ans=v ;
				}
			}
			++tt;
			if(ans==0)ans=u;
			VAL[tt] = ma[ans]-f[p];
			if(ans!=u)build(ans,u,1) ;
			for(auto [v,w]:g[u])if(exist[v]&&v!=ans)
			{
				build(v,u,0) ; 
			}	
		}
	}		
    void xuly()
    {
    	while(q--)
    	{
    		cin>>s>>d;
	    	dfs(1) ; 
	    	build(1,0,0) ;
	    	ll res = 0 ; 
	    	sort(VAL+1,VAL+tt+1,greater<ll>());
	    	FOR(i,1,min(s,tt))res+=VAL[i] ; 
	    	cout<<2*res<<el; 
    		FOR(i,1,n)exist[i] = f[i] = ma[i] =0  ;
    		FOR(i,1,tt)VAL[i] = 0 ;
    		tt =  0;
    	}
    }
}
namespace sub2
{
	ll f[N] ; 
	struct query
	{
		int id ; 
		int sl , val; 
		bool operator<(const query&a)const
		{
			return val<a.val ; 
		}
	}Q[N] ; 
	struct node
	{
		int cnt ;
		ll val ;  
		node(){cnt=val=0;}
		node(int _cnt ,ll _val){
			cnt=_cnt; 
			val=_val; 
		}
		node operator + (node a)
		{
			return node(cnt+a.cnt,val+a.val) ; 
		}
	} ; 
	vll V ; 	
	struct tree_bit
	{
		int n ; 
		ve<node>bit; 
		int LO ; 
		tree_bit(){}
		tree_bit(int _n)
		{
			n=_n ;
			FOR(i,1,n+2)bit.pb({0,0}); 
			LO = lg(n) ; 
		}
		void up(ll val , int cnt)
		{
			if(val==0)return ; 
			int id =LB(all(V),val,[](ll a, ll val){return a>val;})-V.begin()+1;
			for(int i = id;i<=n;i+=i&-i)
			{
				bit[i]=(bit[i]+node(cnt,cnt*val)) ; 
			}
		}
		ll get(int k)
		{
			int pos = 0 ;
			int cnt = 0 ; 
			ll ans = 0 ; 
			FORD(i,LO,0)if(pos+(1<<i)<=n)
			{
				if(cnt+bit[pos+(1<<i)].cnt<=k)
				{
					pos+=(1<<i) ; 
					cnt+=bit[pos].cnt;  
					ans+=bit[pos].val;  
				}
			}	
			return ans; 
		}
	}bit ; 
	void dfs(int u )
	{
		for(auto x:g[u])
		{
			int v= x.v ;
			int w= x.w ;
			f[v]=f[u]+w;
			dfs(v) ; 
		}
	}
	int best[N] ;
	ll res[N] ;
	void up(int u)
	{
		if(best[u])return;  
		int need = 0 ;
		int cur=u ;
		for(; cur!=0;cur=p[cur])
		{
			if(best[cur]==need)
			{
				best[cur] = u ;
				if(best[p[cur]]!=need)
				{
					if(need)bit.up(f[need]-f[p[cur]],-1) ; 
				}
			}
			else
			{
				if(f[best[cur]]>=f[u])break;
				need = best[cur] ; 
				best[cur] = u ; 
			}
		}
		bit.up(f[u]-f[cur],1) ;
	}
	void xuly()
	{
		dfs(1) ;
		FOR(i,1,n)
		{
			int u = p[i]; 
			do
			{
				V.pb(f[i]-f[u]) ; 
				u=p[u] ; 
			}while(u) ;
		}
		V.pb(0) ;
		uni(V) ; 
		reverse(all(V)) ;  
		FOR(i,1,q)
		{
			Q[i].id = i ; 
			cin>>Q[i].sl>>Q[i].val;  
		}
		sort(Q+1,Q+q+1) ;
		bit=tree_bit(SZ(V)); 
		int it = 1 ;
		FOR(i,1,q)
		{
			while(it<=Q[i].val)
			{
				up(it) ; 
				++it; 
			}
			int id = Q[i].id ;
			if(it!=2)res[id] = bit.get(Q[i].sl)*2 ; 
		}
		FOR(i,1,q)cout<<res[i]<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ;
        // sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}