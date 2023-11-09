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
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 
int q; 
struct DL
{
	int v , id; 
	int i , j ; 
} ; 
ve<DL>g[(int)1e5+5] ;
int res[(int)1e5+5] ; 
void doc()
{
	cin>>n >> m >> q; 
	int pre = 0 ; 
	FOR(u,1,q)
	{
		int t ; cin>>t; 
		int i = 0 , j = 0 ; 
		if(t==1)
		{
			cin>>i>> j  ; 
		}
		if(t==2)
		{		
			cin>>i>>j ;
		}
		if(t==3)
		{
			cin>> i ; 
		}
		if(t==4)
		{
			int k; cin>> k; 
			pre=k ; 
		}
		g[pre].pb({u,t,i,j}) ; 
		pre = u ; 
	}
}

namespace sub1
{
	int st[N][4*N] ; 
	int lazy[N][4*N] ; 
	int tot = 0 ; 
	void dolazy(int row,int id,int l, int r )
	{
		st[row][id] = r-l+1-st[row][id] ; 
		if(l!=r)	
		{
			(lazy[row][id*2]+=1)%=2;
			(lazy[row][id*2+1]+=1)%=2; 
		}
		lazy[row][id] = 0 ; 	
	}
	bool ok  ; 
	void up_pos(int row,int id,int l,int r ,int pos, int val)
	{	
		if(lazy[row][id])dolazy(row,id,l,r) ;
		if(r<pos||pos<l)return ;
		if(l==r&&l==pos)
		{
			if(st[row][id]!=val)ok=1 ; 
			st[row][id] = val; 
			return ; 
		}
		int mid =(l+r)/2 ;
		up_pos(row,id*2,l,mid,pos,val) ; 
		up_pos(row,id*2+1,mid+1,r,pos,val) ; 
		st[row][id] = st[row][id*2]+st[row][id*2+1] ; 
	} 
	void inv(int row)
	{
		if(lazy[row][1])dolazy(row,1,1,m) ; 
		lazy[row][1]++ ; 
		dolazy(row,1,1,m) ;
	}
	void dfs(int u )
	{
		res[u] = tot ; 
		for(auto x :g[u])
		{
			int v = x.v ; 
			int id = x.id ;
			int i = x.i ; 
			int j = x.j ;
			ok = 0; 
			if(id==1)
			{	
				tot-=st[i][1] ; 
				up_pos(i,1,1,m,j,1) ; 
				tot+=st[i][1] ; 
			}	
			else if(id==2)
			{
				tot-=st[i][1] ; 
				up_pos(i,1,1,m,j,0) ; 
				tot+=st[i][1] ; 
			}
			else if(id==3)
			{
				tot-=st[i][1] ; 
				inv(i) ;
				tot+=st[i][1] ; 
				ok = 1;  
			}
			int tmp = ok ;
			dfs(v) ; 
			if(tmp)
			{	
				if(id==1)
				{
					tot-=st[i][1] ; 
					up_pos(i,1,1,m,j,0) ; 
					tot+=st[i][1] ; 
				}
				if(id==2)
				{
					tot-=st[i][1] ; 
					up_pos(i,1,1,m,j,1) ; 
					tot+=st[i][1] ;
				}
				if(id==3)
				{
					tot-=st[i][1] ; 
					inv(i) ;
					tot+=st[i][1] ;  		
				}
			}
		}
	} 
    void xuly()
    {
		dfs(0) ;
		FOR(i,1,q)cout<<res[i]<<el;
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