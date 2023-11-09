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
const int N = 5e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
int n,m,q  , shop  ; 
struct Shop
{
	int u , sl , tien ; 
} ; 
Shop a[N] , b[N] ;   
vi g[N] ; 
int f[N] ; 

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
		a[i]={u,sl,tien} ; 
	}
	sort(a+1,a+shop+1,[&](Shop x , Shop y){return x.tien<y.tien;});
}
namespace sub1
{
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
	int check(int T , ll tien, int sl )
	{
		FOR(i,1,shop)if(f[a[i].u]<=T)
		{
			if(tien>=1LL*a[i].tien*a[i].sl)
			{
				sl-=a[i].sl;  
				tien-=1LL*a[i].sl*a[i].tien;  
				if(sl<=0)return 1;  
			}
			else
			{
				sl-=tien/a[i].tien; 
				if(sl<=0)return 1 ; 
				else break ; 
			}
		}
		return 0 ; 

	}
    void xuly()
    {
		cin>>q ;
		FOR(i,1,q)
		{
			int u , sl ;ll tien; 
			cin>> u >>sl >>tien ; 
			bfs(u) ; 
			int l= 0; 
			int r = n-1 ; 
			int ans = -1 ; 
			while(l<=r)
			{
				int mid= (l+r)/2 ; 
				if(check(mid,tien,sl))ans=mid,r=mid-1; 
				else l=mid+1 ;
			}
			cout<<ans<<" ";
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