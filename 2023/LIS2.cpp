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

int n , k ;
int a[N] ; 

void doc()
{
	cin>> n >> k; 
	FOR(i,1,n)cin>>a[i] ; 
}
namespace sub1
{
	int b[N] ; 
	int f[N] ; 
	void xuly()
	{
		int res= 0 ; 
		FOR(l,1,n)
		{
			int r = n;
			FOR(i,1,n)
			{	
				b[i]=a[i] ; 
				if(l<=i&&i<=r)b[i]+=k ;
			}	
			FOR(i,1,n)
			{
				f[i] = 1 ; 
				FOR(j,1,i-1)
				{
					if(b[j]<b[i])maxi(f[i],f[j]+1) ; 
				}
			}
			maxi(res,*max_element(f+1,f+n+1)) ; 
		}
		cout<<res<<el;
	}
}	
namespace sub2
{	
	struct DL
	{
		int id ;
		int val; 
		bool operator<(const DL&a)const
		{
			return val<a.val||(val==a.val&&id>a.id); 
		}
	} ;
	int st[4*N][2] ;
	void up(int id ,int l, int r ,int pos ,int val,  int T)
	{	
		if(l==r&&l==pos)
		{
			st[id][T] = val;  
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid = (l+r)/2; 
		up(id*2,l,mid,pos,val,T) ; 
		up(id*2+1,mid+1,r,pos,val,T) ; 
		st[id][T] = max(st[id*2][T],st[id*2+1][T]) ;
	}
	int get(int id, int l , int  r , int t, int p ,int T )
	{
		if(t<=l&&r<=p)return st[id][T] ; 
		if(r<t||p<l)return 0 ;
		int mid = (l+r)/2; 
		return max(get(id*2,l,mid,t,p,T),get(id*2+1,mid+1,r,t,p,T)); 
	}
	DL tmp[N] ; 
	int pos[N] ;
	int f[N][2] ; 
	void xuly()
	{
		FOR(i,1,n)tmp[i] = {i,a[i]} ; 
		sort(tmp+1,tmp+n+1) ; 
		FOR(i,1,n)pos[tmp[i].id] = i ; 
		FOR(i,1,n)
		{
			f[i][0] = get(1,1,n,1,pos[i],0)+1; // 0->0   
			f[i][1] = get(1,1,n,1,pos[i],1)+1; // 1->1 
			int u = LB(tmp+1,tmp+n+1,a[i]+k,[](const DL&a , int val){return a.val<val;})-tmp-1 ; 
			maxi(f[i][1],get(1,1,n,1,u,0)+1) ; // 0->1 ; 
			up(1,1,n,pos[i],f[i][0],0) ; 
			up(1,1,n,pos[i],f[i][1],1) ;
		}
		int res= 0 ;
		FOR(i,1,n)
		{
			maxi(res,f[i][1]) ;  
		}
		cout<<res; 
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
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
    	sub2::xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}