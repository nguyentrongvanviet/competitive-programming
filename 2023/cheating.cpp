/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "cheating"
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
const int N = (1<<18)+10, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , m  ; 
ll TIEN ; 

struct candidate
{
	int id ; 
	int trinhdo ; 
	int tien ; 
	bool operator<(const candidate&a)const
	{
		return trinhdo>a.trinhdo ; 
	}
} ; 
candidate a[N] ;
candidate dif[N] ;
int res[N] ;
struct cmp 
{
	bool operator()(const candidate&a ,const candidate&b)const
	{
		return a.tien>b.tien ; 
	}
} ; 
void doc()
{
	cin>>n >>m  >> TIEN; 
	FOR(i,1,m)
	{
		cin>>dif[i].trinhdo ;
		dif[i].id = i ; 
	}
	FOR(i,1,n)
	{
		cin>>a[i].trinhdo ;
		a[i].id = i; 
	}
	FOR(i,1,n)cin>>a[i].tien ; 
}	
bool check(int val)
{
	priority_queue<candidate,ve<candidate>,cmp>q ;
	ll cost = 0 ;
	int cl = 0 ; 
	int it = 1 ; 
	int id ;
	for(int i=1;i<=m;i++)
	{
		while(it<=n && a[it].trinhdo>=dif[i].trinhdo)
		{
			q.push(a[it]);
			++it ; 
		}
		if(cl==0)
		{	
			if(q.empty())return 0 ; 
			cost += q.top().tien ; 
			id = q.top().id; 
			cl = val; 
			q.pop() ; 
			if(cost>TIEN)return 0 ;
		}
		cl-- ; 
		res[dif[i].id] = id ;
	}	
	return 1; 
}
void xuly()
{
	sort(dif+1,dif+m+1) ; 
	sort(a+1,a+n+1) ;
	int l = 1; 
	int r = m ; 
	int ans= -1 ; 
	while(l<=r)
	{
		int mid =(l+r)/2 ; 
		if(check(mid))ans=mid,r=mid-1 ;
		else l=mid+1; 
	}
	if(ans==-1)
	{
		cout<<"NO"<<el<<el;
	}
	else
	{
		cout<<"YES"<<el;
		check(ans) ; 
		prt(res,m) ;		
	}
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
    int theta ; cin>>theta ; 
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}