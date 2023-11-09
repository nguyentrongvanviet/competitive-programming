/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "shipping"
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
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 250000+5 , oo = 1e9, LO = 17 , CH = 26 ; 
int n,m,q  , shop  ; 
struct Shop
{
	int u , sl , tien , id ; 
} ; 
struct Query
{
	int sl ; 
	ll tien ; 
	int id ; 
} ; 
Shop a[N] , b[N] ;
ve<Query> Q[N] ;   
vi g[N] ; 
int pos[N] ;   
void doc()
{
	cin>> n >> m; 
	FOR(i,1,m)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}

	cin>>shop ; 
	FOR(i,1,shop)
	{
		int u , sl , tien ; cin>>u>>sl >>tien ;
		a[i]={u,sl,tien,i} ; 
	}
	sort(a+1,a+shop+1,[&](Shop x , Shop y){return x.tien<y.tien;});
	FOR(i,1,shop)
	{
		pos[a[i].id] = i ; 
		b[i] = a[i] ; 
	}
	cin>>q ;
	FOR(i,1,q)
	{
		int u , sl ;ll tien; 
		cin>> u >>sl >>tien ; 
		Q[u].pb({sl,tien,i}) ; 
	}
}

namespace sub1
{
	int f[N] ; 
	int res[500*500+5] ; 
	struct Node
	{
		int sl ; 
		ll tien; 
	} ; 
	Node bit[N] ;    
	inline void bfs(int u)
	{	
		queue<int>q;
		FOR(i,1,n)f[i] = oo ; 
		q.push(u) ; 
		f[u] = 0 ; 
		while(!q.empty())
		{
			int u= q.front() ; 
			q.pop() ; 
			for(auto v :g[u])if(f[v]==oo)
			{
				f[v] = f[u]+1 ;
				q.push(v) ; 
			}
		}
	}
	inline void up(int idx , int sl ,int tien )
	{
		for(int i=idx;i<=shop;i+=i&-i)
		{
			bit[i].sl+=sl ; 
			bit[i].sl=min(bit[i].sl,oo);
			bit[i].tien+=1LL*tien*sl ; 
			bit[i].tien = min(bit[i].tien,inf+1);
		}
	}
	inline ll get(ll tien)
	{
		int pos = 0 ; 
		ll ans = 0 ; 
		FORD(i,LO,0)
		{
			if(pos+(1<<i)<=shop&&tien >= bit[pos+(1<<i)].tien)
			{
				pos+=(1<<i) ; 
				ans+=bit[pos].sl;  
				tien-=bit[pos].tien ; 
			}
		}
		++pos ; 	
		if(pos<=shop)
		{
			ans+=tien/b[pos].tien ; 
		}
		return ans ; 
	}
	pii range[500*500+5] ; 
	vi ques[500*500+5] ; 
	inline void solve(int u)
	{	
		bfs(u) ; 
		sort(a+1,a+shop+1,[&](Shop x ,Shop y)
		{		
			return f[x.u]<f[y.u] ; 
		});	 
		FORN(i,0,Q[u].size())range[i] = {1,shop} ;
		while(1)
		{	
			bool ok = 1 ;
			FOR(i,1,shop)bit[i] = {0,0} , ques[i].clear() ; 
			FORN(i,0,Q[u].size())
			{
				int l,r; 
				tie(l,r) = range[i] ; 
				if(l<=r)
				{		
					ques[(l+r)/2].pb(i) ; 
					ok = 0 ; 
				}
			}
			if(ok)break;  
			FOR(i,1,shop)
			{
				up(pos[a[i].id],a[i].sl,a[i].tien) ; 
				for(auto v : ques[i])
				{
					if(get(Q[u][v].tien)>=Q[u][v].sl)
					{
						range[v].se = i-1 ; 
						res[Q[u][v].id] = f[a[i].u]; 
					}
					else range[v].fi = i+1;
				}
			}
		}	
	}	
    void xuly()
    {
    	FOR(i,1,q)res[i] = oo ; 
    	FOR(i,1,min(n,10))
    	{	
    		solve(i) ; 
    	}
    	FOR(i,1,q)
    	{
    		if(res[i]==oo)cout<<-1<<" "; 
    		else cout<<res[i]<<" ";	
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}