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

int n; 
vi c[N] ; 
int a[N] ;
vi V ;  
void doc()
{	
	cin>> n; 
	FOR(i,1,n)
	{
		a[i] = i ;
		int len;cin>>len ;
		FOR(j,1,len)
		{	
			int val ; cin>>val ; 
			if(c[i].empty()||c[i].back()<val)
			{
				c[i].pb(val) ;
				V.pb(val);
			}
		}
	}
}
int st[4*N] ;
void update(int id ,int l ,int r ,int pos , int val)
{
	if(l==r&&l==pos)
	{
		st[id] = max(st[id],val) ; 
		return ; 
	}
	if(r<pos||pos<l)return ;
	int mid= (l+r)/2; 
	update(id*2,l,mid,pos,val)  ; 
	update(id*2+1,mid+1,r,pos,val) ;
	st[id] = max(st[id*2],st[id*2+1]) ; 
}
int get(int id ,int l, int r, int t ,int p)
{
	if(t<=l&&r<=p)return st[id] ;
	if(r<t||p<l)return 0 ; 
	int mid= (l+r)/2; 
	return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
}

void xuly()
{	
	sort(a+1,a+n+1,[](int i ,int j )
		{
			return c[i].back()<c[j].back() ; 
		}	
	) ;
	uni(V) ; 
	int VAL = V.size() ; 
	FOR(i,1,n)
	{
		FORN(j,0,c[i].size())
		{
			c[i][j] = UB(all(V),c[i][j])-V.begin();
		}
	}
	FOR(i,1,n)
	{
		int id  = a[i] ;  
		int ma = c[id].size() ; 
		FORN(j,0,c[id].size())
		{
			int u = c[id][j]-1 ; 
			maxi(ma,(int)c[id].size()-j+get(1,1,VAL,1,u));
		}
		update(1,1,VAL,c[id].back(),ma) ; 
	}
	cout<<st[1]<<el;
	FOR(id,1,4*VAL)st[id]=0; 
	V.clear() ;
	FOR(i,1,n)c[i].clear() ;
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
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}