/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define            tct  template<class T>
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
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , m ,q ; 
int a[11][N] ;

void doc()
{	
	cin>> n >> m >> q ; 
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>>a[i][j] ; 
	}
}
namespace sub1
{
	struct Node
	{ 
		int L[11] ; 
		int R[11] ;
		int cL[11] ; 
		int cR[11] ; 
		int sum ;
		Node(){
			sum = -1 ; 
		}
	}st[4*N] ; 
	int pa[N*10] ;
	int goc(int u)
	{
		return pa[u] ==u  ? u: pa[u] = goc(pa[u]) ;
 	}
 	int hop(int u ,int v)
 	{
 		int chau = goc(u) ; 
 		int chav = goc(v) ; 
 		if(chau==chav)return 0 ; 
 		pa[chau] = chav; 
 		return 1; 
 	}
	Node merge(Node Left , Node Right)
	{	
		if(Left.sum==-1)return Right ; 
		if(Right.sum==-1)return Left ; 
		Node tmp  ; 
		tmp.sum =Left.sum+Right.sum ;  
		FOR(i,1,n)
		{
			pa[Left.L[i]]=Left.L[i] ;  
			pa[Left.R[i]]=Left.R[i] ;
			pa[Right.L[i]]=Right.L[i] ; 
			pa[Right.R[i]]=Right.R[i] ; 
		}
		FOR(i,1,n)
		{
			if(Left.cR[i]==Right.cL[i])
			{
				tmp.sum-=hop(Left.R[i],Right.L[i]);
			}
		}
		FOR(i,1,n)tmp.cL[i] = Left.cL[i] ; 
		FOR(i,1,n)tmp.cR[i] = Right.cR[i] ; 
		FOR(i,1,n)
		{
			tmp.L[i] = goc(Left.L[i]);
			tmp.R[i] = goc(Right.R[i]);
		}
		return tmp ; 
	}
	void build(int id ,int l ,int r )
	{
		if(l==r)
		{
			st[id].sum = 0 ;
			FOR(i,1,n)
			{
				st[id].cL[i] = a[i][l];
				st[id].cR[i] = a[i][l];
				if(a[i][l]!=a[i-1][l])
				{
					++st[id].sum;
					st[id].L[i]=st[id].R[i]=(i-1)*m+l;
				}
				else
				{
					st[id].L[i]=st[id].R[i]=st[id].L[i-1];
				}
			}
			return ; 
		}
		int mid =(l+r)/2 ; 
		build(id*2,l,mid) ; 
		build(id*2+1,mid+1,r) ; 
		st[id] =merge(st[id*2],st[id*2+1]) ; 
	}
	Node get(int id ,int l, int r ,int t, int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return Node();
		int mid =(l+r)/2 ;
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
    void xuly()
    {
        build(1,1,m) ; 
        while(q--)
        {
        	int l ,r ; cin>>l>>r ;
        	Node res=  get(1,1,m,l,r) ; 
        	cout<<res.sum<<el;
        }
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
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}