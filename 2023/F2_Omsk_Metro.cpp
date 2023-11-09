/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1  ;

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

int q; 
int n; 
ve<array<int,3>>quest;
int P[N][LO+2] ;
int h[N] ;
struct DL
{
	int sum = 0; 
	int pre_mi=0,suf_mi=0; 
	int pre_ma=0,suf_ma=0 ; 
	int mi=0,ma=0 ; 
} ; 
DL NODE[N][LO+2]; 
DL merge(DL L , DL R)
{  
	int sum=L.sum+R.sum ; 
	int pre_mi = min(L.pre_mi,L.sum+R.pre_mi) ;  
	int suf_mi = min(R.suf_mi,R.sum+L.suf_mi) ;
	int pre_ma = max(L.pre_ma,L.sum+R.pre_ma) ; 
	int suf_ma = max(R.suf_ma,R.sum+L.suf_ma) ; 
	int mi = min({L.mi,R.mi,L.suf_mi+R.pre_mi}) ;  
	int ma = max({L.ma,R.ma,L.suf_ma+R.pre_ma}) ; 
	return {sum,pre_mi,suf_mi,pre_ma,suf_ma,mi,ma} ; 
}
void doc()
{ 
	quest.clear();
	n = 1 ; 
	NODE[1][0]= {1,0,0,1,1,0,1} ;  
	cin>>q ;
	while(q--)
	{
		char t ; cin>> t ; 
		if(t=='+')
		{
			int u ,v , sign ; 
			cin>>u>>sign ; 
			v=++n ; 
			h[v]=h[u]+1; 
			P[v][0] = u ; 
			NODE[v][0] = {sign,min(0,sign),min(0,sign),max(0,sign),max(0,sign),min(0,sign),max(0,sign)};   
		}
		else
		{
			int u , v , k; cin>>u>>v>>k ; 
			quest.pb({u,v,k}); 	
		}
	}
}
bool check(int u ,int v, int k )
{
	if(h[u]<h[v])swap(u,v); 
	DL a , b ; 
	FORD(i,LO,0)
	{
		if(h[u]-(1<<i)>=h[v])
		{
			a = merge(a,NODE[u][i]) ; 
			u=P[u][i] ;  
		}
	}
	if(u==v)
	{		
		a=merge(a,NODE[u][0]) ;
		return a.mi<=k&&k<=a.ma;
	}
	FORD(i,LO,0)
	{
		int nu = P[u][i] ; 
		int nv = P[v][i] ; 
		if(nu!=nv)
		{
			a=merge(a,NODE[u][i]) ; 
			b=merge(b,NODE[v][i]) ; 
			u=nu ;
			v=nv ; 
		}	
	}
	b=merge(b,NODE[v][0]);
	swap(b.pre_mi,b.suf_mi) ; 
	swap(b.pre_ma,b.suf_ma) ; 
	a=merge(a,NODE[u][1]);
	a=merge(a,b)  ; 
	return a.mi<=k&&k<=a.ma ; 
}	
void xuly()
{   
	FOR(j,1,LO)FOR(i,1,n)
	{
		P[i][j]=P[P[i][j-1]][j-1] ;
		NODE[i][j] = merge(NODE[i][j-1],NODE[P[i][j-1]][j-1]) ; 
	}
	for(auto q : quest)
	{
		int u = q[0] ; 
		int v = q[1];
		int k = q[2] ; 
		cout<< (check(u,v,k)?"YES":"NO")<<el;
	}
}

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
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}