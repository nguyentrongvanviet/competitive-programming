/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "biconnected"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
const int N = 250005 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
struct ke
{
	int v, id ; 
} ; 
ve<ke>g[N] ;

void doc()
{	
	cin >> n >> m ;
	FOR(i,1,m)
	{
		int u ,v ; cin>> u >>v ;
		g[u].pb({v,i}) ; 
		g[v].pb({u,i}) ; 
	}
}

namespace sub1
{
	int ID[N] ,low[N] , tp[N] , tt= 0 , tplt = 0  ; 
	stack<int>st; 
	int sf[N] ; 
	void dfs(int u ,int p)
	{
		ID[u] = low[u] = ++tt; 
		st.push(u) ; 
		for(auto x:g[u])
		{
			int v=x.v; 
			int id = x.id ;
			if(p==id)continue ;
			if(ID[v])mini(low[u],ID[v]); 
			else dfs(v,id),mini(low[u],low[v]) ;
		}
		if(ID[u]==low[u])
		{
			++tplt; 
			int t; 
			do
			{
				t=st.top() ; 
				st.pop() ; 
				tp[t]=tplt;
			}
			while(t!=u) ; 
			sf[tplt] = u ;
		}
	}
	vi adj[N] ; 
	vi leaf ; 
	void go(int u ,int p)
	{
		if(SZ(adj[u])==1)leaf.pb(u) ; 
		for(auto v:adj[u])if(v!=p)
		{
			go(v,u) ;
		}
	}
    void xuly()
    {
        dfs(1,0) ; 
        FOR(u,1,n)for(auto [v,id]:g[u])
        {
        	int tpu = tp[u] ; 
        	int tpv = tp[v] ; 
        	if(tpu!=tpv)
        	{
        		adj[tpu].pb(tpv) ;
        	}
      	}
      	// cout<<tplt<<el; 
      	// prt(tp,n) ;
     	if(tplt==1||tplt==2)
     	{
     		cout<<tplt-1<<el;
     		if(tplt==2)cout<<sf[1]<<" "<<sf[2]<<el;
     	}
     	else
     	{
     		FOR(i,1,tplt)if(SZ(adj[i])>1)
     		{
     			go(i,0) ;
     			cout<<SZ(leaf)/2+(SZ(leaf)&1)<<el; 
     			int mid = SZ(leaf)/2 ; 
     			FORN(i,0,SZ(leaf)/2)
     			{
     				cout<<sf[leaf[i]]<<" "<<sf[leaf[i+mid]]<<el;
     			}
				if(leaf.size()&1)cout<<sf[leaf[0]]<<" "<<sf[leaf.back()]<<el;
     			break; 
     		}
     	}
     	FOR(i,1,n)leaf.clear(),g[i].clear(),adj[i].clear(),sf[i]=ID[i]=low[i]=tt=tplt=0;
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