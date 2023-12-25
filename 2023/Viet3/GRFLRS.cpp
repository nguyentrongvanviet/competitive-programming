/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "GRFLRS"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ,q , k; 
struct pt
{
	int x ,y ;
};
pt a[N] ,b[N];
void doc()
{
	cin>> n >> m >>q  >>k ;
	FOR(i,1,q)
	{
		cin>>a[i].x>>a[i].y ;
	}
	FOR(i,1,k)
	{
		cin>>b[i].x>>b[i].y ;
	}
}

namespace sub1
{ 
	const int N = 3e3+5; 	
	int s[N][N] ; 
	int  get(int x ,int y, int u ,int v)
	{
		return s[u][v]-s[u][y-1]-s[x-1][v]+s[x-1][y-1]; 
	}
	int dd[N][N] ;
    void xuly()
    {
    	FOR(i,1,q)
    	{
    		FOR(x,a[i].x,n)FOR(y,a[i].y,m)if(s[x][y]==0)s[x][y]+=1;
    	}
    	FOR(i,1,k)
    	{
    		FOR(x,1,b[i].x)FOR(y,1,b[i].y)if(dd[x][y]!=2)dd[x][y]=2,s[x][y]+=2;
    	}
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    	}
    	int res = 0; 
    	FOR(i,1,n)FOR(j,1,m)FOR(u,i,n)FOR(v,j,m)
    	{
    		if(get(i,j,u,v)==(u-i+1)*(v-j+1)*3)res++ ;
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	int L[N] , R[N] ; 
	ll pw(ll a, ll n)
	{
		if(n==0)return 1; 
		ll b = pw(a,n/2) ;
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm;
	}
	void xuly()
	{
		FOR(i,0,n+1)L[i] = m+1;
		FOR(i,1,q)
		{
			mini(L[a[i].x],a[i].y) ;
		}
		FOR(i,1,n)
		{
			mini(L[i],L[i-1]) ;
		}
		FOR(i,1,k)
		{
			maxi(R[b[i].x],b[i].y) ; 	
		}
		FORD(i,n,1)maxi(R[i],R[i+1]) ;	
		deque<int>q; 
		// prt(L,n);
		// prt(R,n) ;

		ll res = 0; 
		ll tmp = 0 ; 
		ll sum = 0 ; 
		FOR(i,1,n)
		{
			while(!q.empty()&&q.front()>R[i])
			{
				(sum-=2*q.front()%sm-3-sm)%=sm;
				(tmp-=1ll*(q.front()-1)*(q.front()-2)%sm-sm)%=sm;
				q.pop_front() ;
			}
			if(L[i]<=R[i])
			{
				q.pb(L[i]) ;
				(sum+=2*L[i]%sm-3+sm)%=sm; 
				(tmp+=1ll*(L[i]-1)*(L[i]-2)%sm)%=sm;
				(res+=1ll*SZ(q)%sm*(sq(R[i])%sm)%sm-1ll*R[i]*sum%sm+tmp+sm)%=sm;
			}
			else 
			{
				while(!q.empty())q.pk() ;
				tmp=sum=0;
			}
		}
		cout<<res*pw(2,sm-2)%sm<<el;	
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}