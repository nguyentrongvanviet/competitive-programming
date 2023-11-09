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

bool mtt = 1 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
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
#define SZ(a) (int)(a.size())
const db PI = acos(-1) , EPS = 1e-9;
// const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e2+5 , oo = 1e9 , LO = 17 , CH = 26 ; 

int F , m ; 
struct DL
{
	int du , Div; 
} E[105] ;
int f[N][N] ; 
ve<pii>node ;
void doc()
{
	cin>>F>>m ;
	FOR(i,1,m)
	{
		int Div , du ; 
		cin>>du >>Div ; 
		E[i] = {du,Div} ; 
		FOR(j,0,min(1000,(Div==0?oo:F/Div)))
		{	
			if(Div*j+du>=F)break ; 
			node.pb({Div*j+du,i}) ; 
		}
	} 
	node.pb({0,++m}) ;
	node.pb({F-1,++m}) ;
	sort(all(node)) ;   
	FOR(i,1,m)FOR(j,1,m)
	{
		if(i!=j)f[i][j] = oo ;
	}
	FORN(i,1,node.size())
	{
		int u ,v ,x ,y ; 
		tie(u,x) = node[i-1] ; 
		tie(v,y)  = node[i] ; 
		mini(f[x][y],v-u) ;
		mini(f[y][x],v-u);
	}	
	FOR(k,1,m)FOR(i,1,m)FOR(j,1,m)
	{	
		mini(f[i][j],f[i][k]+f[k][j]) ; 
	}	
}

namespace sub1
{
    void xuly()
    {  
		pii res={0,0} ;
		FORN(i,1,node.size())
		{
			int u ,v ,x ,y ; 
			tie(x,u) = node[i-1] ; 
			tie(y,v)  = node[i] ;
			int X = x ;  
			int U= f[m-1][u] ; 
			int V= f[m-1][v] ;
			if(U<V)x+=V-U ;
			else y-=U-V ; 
			int mid = (x+y)/2 ;
			if(res.fi<U+mid-X)
			{
				res={U+mid-X,mid} ; 
			} 
		}   
		cout<<res.fi<<" "<<res.se<<el;
		node.clear() ; 
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