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
const int N = 35000+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , k ;
int a[N] ;  
void doc()
{
	cin>> n >> k ;
	FOR(i,1,n)cin>>a[i] ; 
}
namespace sub1
{
	int sl[N] ; 
	int L = 1; 
	int R = 1 ; 

	int cost = 1 ;
	int f[N][55]; 
	void cal(int l ,int r)
	{
		while(R<r)
			cost+=(++sl[a[++R]]==1); 
		while(l<L)
			cost+=(++sl[a[--L]]==1);
		while(r<R)
			cost-=(--sl[a[R--]]==0);
		while(L<l)
			cost-=(--sl[a[L++]]==0);
	}
	void solve(int l, int r , int oL ,int oR , int k )
	{
		if(l>r)return ; 
		int mid = (l+r)/2 ;
		int pos ; 
		FOR(i,oL,min(mid,oR))
		{
			cal(i,mid) ; 
			if(maxi(f[mid][k],f[i-1][k-1]+cost))pos=i;
		}
		solve(l,mid-1,oL,pos,k) ; 
		solve(mid+1,r,pos,oR,k) ; 
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		f[i][1] = f[i-1][1]+(++sl[a[i]]==1);
    	}
    	L =1 , R = 1 ; 
    	FOR(i,1,n)sl[a[i]] = 0 ;
    	cost=sl[a[1]]=1; 
    	FOR(i,2,k)
    	{
    		solve(i,n,i,n,i);
    	}
    	cout<<f[n][k];
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