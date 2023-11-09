/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "MSGAME"
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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e4+5 , oo = 2e9 , LO = 13 , CH = 26 ; 

int n , k ; 
int a[N]; 

void doc()
{
    cin>> n >> k;  
    FOR(i,1,n)cin>>a[i] ;
}

namespace sub1
{
	pii st[N][LO+5]  ;
	void rmq()
	{
		FOR(i,1,n)st[i][0] = {a[i],i}; 
		FOR(j,1,LO)FOR(i,1,n-(1<<j)+1)
		{	
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}	
	}
	pii get_ma(int l,int r)
	{
		int k = lg(r-l+1); 
		return max(st[l][k],st[r-(1<<k)+1][k]) ; 
	}
	vll f[N] ;
	int solve(int l,int r )
	{
		if(l>r)return 0; 
		pii node = get_ma(l,r) ; 
		int u = node.se ;
		int val = node.fi; 
		if(l==r)
		{
			f[u].pb(0) ; 
			f[u].pb(val) ; 
			return u ;
		}
		int x =  solve(l,u-1) ; 
		int y = solve(u+1,r) ; 
		if(x<y)swap(x,y) ; 
		if(y==0)
		{
			swap(f[u],f[x]) ; 
			f[u].pb(f[u].back()+1ll*val*f[u].size()); 
			FORD(i,(int)f[u].size()-1,1)
			{
				mini(f[u][i],f[u][i-1]+1ll*val*i) ;
			}
			return u ; 
		}
		f[u]=vll(r-l+2,inf) ; 
		FORN(i,0,f[x].size())
		{
			FORN(j,0,f[y].size())
			{
				mini(f[u][i+j],f[x][i]+f[y][j]+1ll*i*j*val);
				mini(f[u][i+j+1],f[x][i]+f[y][j]+1ll*i*j*val+1ll*val*(i+j+1)) ;
			}
		}
		return u ; 
	}
    void xuly()
    {
        rmq() ; 
        int u = solve(1,n) ;
    	cout<<f[u][k] ;
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