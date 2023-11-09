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
#define SZ(a) (int)(a.size())
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , l ,q ;
struct ke
{
	int v, w,T ; 
} ; 
ve<ke>g[N] ;
void doc()
{
    cin>> n>> m >> l >>q; 
    FOR(i,1,m)
    {
    	int u ,v ,w; cin>>u>>v>>w ; 
    	++u , ++v; 
    	g[u].pb({v,w,0}) ;
    }
    FOR(i,1,l)
    {
    	int u ,v, w ; cin>>u>>v>>w;
    	++u , ++v  ;
    	g[u].pb({v,w,1}) ; 
    }
}

namespace sub1
{

	ll f[N][N][2] ;
	struct DL
	{
		int u , dif , T ; 
		ll val; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a, const DL&b)const
		{
			return a.val>b.val ;
		}
	}; 
	void dij()
	{
		FOR(i,1,n)FOR(j,0,n)FOR(T,0,1)f[i][j][T]  = inf ;
		priority_queue<DL,ve<DL>,cmp>q ; 
		q.push({1,0,0,f[1][0][0]=0});
		q.push({1,0,1,f[1][0][1]=0});	
		while(!q.empty())
		{
			auto [u,dif,T,val] = q.top() ;
			q.pop();
			if(f[u][dif][T]<val)continue ;
			for(auto [v,w,nT]:g[u])	
			{
				int ndif = dif+(nT!=T) ; 
				if(mini(f[v][ndif][nT],val+w))
				{
					if(f[v][max(0,ndif-1)][nT]>=f[v][ndif][nT])q.push({v,ndif,nT,val+w}); 
				}
			}
		}
	}
	struct Query
	{
		int c, id ; 
		bool operator<(const Query&a)const
		{
			return c>a.c ; 
		}
	} ; 
	ve<Query>Q[N] ; 
	ll res[(int)1e5+5] ;
	void solve(int u , int l, int r,int oL , int oR )
	{
		if(l>r)return ; 
		int mid = (l+r)/2 ;
		int pos = 0 ;
		int c= Q[u][mid].c; 
		int id= Q[u][mid].id; 
		FOR(i,oL,oR)
		{
			if(mini(res[id],min(f[u][i][0],f[u][i][1])+1ll*i*c))pos=i ; 
		}
		solve(u,l,mid-1,oL,pos) ; 
		solve(u,mid+1,r,pos,oR) ; 
	} 
    void xuly()
    {
    	dij() ;
    	FOR(_,1,q)
    	{
    		int c , u ;cin>>c>>u ; 
    		++u ; 
    		Q[u].pb({c,_}) ;  
    		res[_] = inf ; 
    	}
    	FOR(i,1,n)sort(all(Q[i])) ; 
    	FOR(i,1,n)
    	{
    		solve(i,0,SZ(Q[i])-1,0,n) ; 
    	}
    	FOR(i,1,q)
    	{
    		if(res[i]==inf)cout<<-1<<el;
    		else cout<<res[i]<<el;
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