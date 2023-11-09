/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1;

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
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
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
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , m ; 
int a[N] ,b[N] ; 
int pa[N] ;  

int goc(int u)
{
	return pa[u] == u ? u : pa[u] = goc(pa[u]); 
}
void hop(int u ,int v)
{
	if(pa[u]==0||pa[v]==0)return ; 
	int chau = goc(u) ;
	int chav = goc(v) ; 
	pa[chau] = chav ; 
}
void doc(int test ,int idx)
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n)cin>>b[i] ; 
	cin>>m ; 
}


void xuly()
{
	map<int,int>sl; 
	map<int,vi>ds ;
	FOR(i,1,m)
	{
		int val ; 
		cin>>val; sl[val]++ ;
	} 
	FOR(i,1,n)if(a[i]<b[i])return void(cout<<"NO"<<el) ; 

	vi cam ;  
	FOR(i,0,n+1)pa[i] = 0 ; 
	FOR(i,1,n)
	{
		if(a[i]>b[i])ds[b[i]].pb(i); 
		else cam.pb(i) ; 
	}	
	sort(all(cam),[](int i , int j ){return b[i]<b[j];});
	int it = 0 ;  
	for(auto v : ds)
	{
		while(it<(int)cam.size()&&b[cam[it]]<=v.fi)
		{
			int x = cam[it] ;
			pa[x]=x ;
			hop(x-1,x) ; 
			hop(x,x+1) ; 
			++it ;  	
		}
		for(auto x : v.se)
		{
			pa[x] = x ; 
			hop(x-1,x) ; 
			hop(x,x+1) ;
		}
		set<int>S ; 
		for(auto x :v.se)S.insert(goc(x)); 

		if(sl.find(v.fi)==sl.end()||sl[v.fi]<(int)S.size())return void(cout<<"NO"<<el) ;
	}
	cout<<"YES"<<el;
	
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
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc(test,i) ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}