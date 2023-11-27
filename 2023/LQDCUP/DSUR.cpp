/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "DSUR"
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


int n ,q ;


void doc()
{
	cin>> n >>q; 
}

namespace sub1
{
	map<pii,vi>last; 
	struct edge
	{
		int u ,v ; 
	}; 
	int pa[N] , SZ[N]  ;
	stack<edge>st ;
	ve<edge>canh[4*N] ; 
	int res[N] ; 
	edge Q[N] ;
	int goc(int u )
	{
		return pa[u] == u ? u : goc(pa[u]) ; 
	}
	void hop(int u ,int v)
	{
		int chau = goc(u)  ; 
		int chav = goc(v) ;
		if(chau==chav)return ;
		if(SZ[chau]>SZ[chav])swap(chau,chav); 
		pa[chau] = chav; 
		SZ[chav]+=SZ[chau] ;
		st.push({chau,chav}) ;  
	}
	void roll_back(int sz)
	{
		while(SZ(st)>sz)
		{
			int u =st.top().u ; 
			int v =st.top().v; 
			st.pop() ; 
			pa[u] = u ;
			SZ[v]-=SZ[u] ; 
		}
	}
	void up(int id ,int l, int r, int t, int p , edge e)
	{
		if(t<=l&&r<=p)return void(canh[id].pb(e)) ; 
		if(r<t||p<l)return ;
		int mid=(l+r)>>1;
		up(id<<1,l,mid,t,p,e) ;
		up(id<<1|1,mid+1,r,t,p,e) ;
	}
	void solve(int id ,int l ,int r )
	{
		int sz =SZ(st) ;
		for(auto e:canh[id])hop(e.u,e.v);  
		if(l==r)
		{
			if(Q[l].u&&Q[l].v)
			{
				res[l]=(goc(Q[l].u)==goc(Q[l].v)) ; 
			}
			roll_back(sz) ; 
			return;  
		}	
		int mid=(l+r)>>1; 
		solve(id<<1,l,mid) ; 
		solve(id<<1|1,mid+1,r) ; 
		roll_back(sz) ; 
	}
    void xuly()
    {
    	FOR(i,1,n)pa[i] = i ,SZ[i] =1 ; 
		FOR(i,1,q)
		{ 
			int TYPE  , u ,v ;cin>>TYPE >> u >> v;
			if(u>v)swap(u,v) ; 
			if(TYPE==1)
			{
				last[mp(u,v)].pb(i) ;  
			}
			else if(TYPE==2)
			{
				if(!last[mp(u,v)].empty())
				{
					up(1,1,q,last[mp(u,v)].back(),i-1,edge{u,v});
					last[mp(u,v)].pk() ; 
				}
			}
			else
			{
				Q[i]={u,v} ;  
			}
		}
		for(auto x:last)if(!x.se.empty())up(1,1,q,x.se[0],q,edge{x.fi.fi,x.fi.se});
		solve(1,1,q) ;
        FOR(i,1,q)if(Q[i].u&&Q[i].v)
        {
        	if(res[i])cout<<"YES"<<el;
        	else cout<<"NO"<<el;
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
    else 
    {
        // freopen("text.INP","r",stdin) ; 
        // freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}