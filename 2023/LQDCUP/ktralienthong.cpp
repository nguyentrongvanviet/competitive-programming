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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int tp[N] ;
vi g[N] ;
void init(int n,ve<pii>	e ){	

	for(auto x:e)g[x.fi].pb(x.se),g[x.se].pb(x.fi) ; 
	FOR(i,1,n)tp[i] = 1 ;
    return;
}
int tt = 1 ;  
int used[N],D[N] ; 
void close(int u,int v)
{
	queue<int>ql  ,qr ; 
	vi nodel,noder ; 
	ql.push(u) ;
	qr.push(v) ;  
	used[u] = 1; 
	used[v] = 1; 
	nodel.pb(u) ; 
	noder.pb(v) ;
	D[u] =SZ(g[u])-1 ;
	D[v] =SZ(g[v])-1 ; 
	int ok ; 
	while(1)
	{
		int U = 0 , V = 0  ; 
		while(!ql.empty())
		{
			int u =ql.front(); 
			while(D[u]>=0)
			{
				int tu= g[u][D[u]] ;
				if(used[tu]||tp[tu]!=tp[u])D[u]--;
				else 
				{
					U=tu ;
					break;
				}
			}
			if(U==0)ql.pop() ;
			else 
			{
				D[u]--; 
				break;
			}
		}
		while(!qr.empty())
		{
			int v =qr.front() ;
			while(D[v]>=0)
			{
				int tv = g[v][D[v]] ;
				if(used[tv]||tp[tv]!=tp[v])D[v]--;
				else 
				{
					V=tv; 
					break;
				}
			}
			if(V==0)qr.pop() ;
			else 
			{
				D[v]--; 
				break;
			}
		}
		if(U==0)
		{
			ok =1 ;
			break;
		}
		if(V==0)
		{
			ok =2 ;
			break; 
		}
		ql.push(U) ;
		nodel.pb(U) ; 
		
		used[U] = used[V] =1 ; 
		
		D[U] = SZ(g[U])-1 ;

		qr.push(V) ; 
		
		noder.pb(V) ; 
		
		D[V] = SZ(g[V])-1 ;
	}
	++tt; 
	for(auto u :nodel)used[u] = 0 ; 
	for(auto u :noder)used[u] = 0 ;

	if(ok==1)
	{
		for(auto u :nodel)tp[u]=tt; 
	}
	else
	{
		for(auto u :noder)tp[u]=tt; 	
	}	
}

bool question(int u,int v){
	return tp[u] == tp[v] ; 
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
    	init(7,{{1,2},{1,3},{1,4},{4,6},{4,5},{6,7}});
    	close(1,4)  ;
    	cout<<question(3,5)<<el;
    	cout<<question(4,7)<<el; 
    	close(4,5) ; 
    	cout<<question(1,2)<<el; 
    	cout<<question(5,7)<<el; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}