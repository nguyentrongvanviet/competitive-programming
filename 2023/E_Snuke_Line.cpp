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

bool mtt = 0;

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
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 3e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n ,  m ;
int L[N] , R[N] ; 
vi Div[N] ;
int bit[N] ; 
int bit_len[N] ;
int s_len[N] ; 
ve<pii> g[N] ;
void up(int idx ,int val,int bit[])
{
	for(int i=idx;i<=m;i+=i&-i)bit[i]+=val ; 
}
int get(int idx,int bit[])
{
	int ans =0 ; 
	for(int i =idx;i;i-=i&-i)ans+=bit[i] ;
	return ans;  
}	
int res[N] ;
void doc()
{
	cin>> n >> m ;
	FOR(i,1,n)
	{
		cin>>L[i]>>R[i] ; 
		int len = R[i]-L[i]+1 ; 
		g[L[i]].pb(mp(1,len)) ; 
		g[R[i]+1].pb(mp(-1,len)) ;
		s_len[len]++ ;  
	}
}

void xuly()
{
	FOR(i,1,m)for(int j=i;j<=m;j+=i)
	{
		Div[j].pb(i) ; 
	}
	FOR(i,1,m)
	{
		for(auto x : g[i])
		{
			int val = x.fi ;
			int len = x.se ; 
			up(i,val,bit) ; 
			up(len,val,bit_len) ;
		}
		for(auto x : Div[i])
		{	
			res[x]+=get(i,bit)-(get(m,bit_len)-get(x-1,bit_len)); 
		}
	}
	FORD(i,m-1,1)s_len[i]+=s_len[i+1] ;
	FOR(i,1,m)res[i]+=s_len[i];
	FOR(i,1,m)cout<<res[i]<<el;
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