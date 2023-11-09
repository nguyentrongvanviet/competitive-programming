/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "formation"
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
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k;  
int a[N][N] ;
ve<pii>Q;
void doc()
{
    cin>> n >> m >> k  ; 
    FOR(i,1,n)FOR(j,1,m)
    {
    	cin>>a[i][j]  ;
    	if(a[i][j])Q.pb({i,j}) ;
	} 
}

namespace sub1	
{
    void xuly()
    {
    	ll res= 0; 
 		FOR(i,1,n)FOR(j,1,m)
 		{
 			vi ans ; 
 			for(auto v: Q)
 			{	
 				ans.pb(abs(i-v.fi)+abs(j-v.se)) ;
 			}
 			sort(all(ans)) ; 
 			FORN(t,0,k)res+=ans[t]; 
 		}       
 		cout<<res;
    }
}
namespace sub2_5
{
	int f[N][N] ; 
	void xuly()
	{
		queue<pii>q ; 
		FOR(i,1,n)FOR(j,1,m)f[i][j] = oo ; 
		for(auto x: Q)q.push(x) ,f[x.fi][x.se] = 0; 
		while(!q.empty())
		{
			int x = q.front().fi; 
			int y = q.front().se ;
			q.pop();
			FOR(i,1,4)
			{
				int nx=x+xx[i] ; 
				int ny=y+yy[i] ; 
				if(f[nx][ny]==oo)
				{
					f[nx][ny]=f[x][y]+1;
					q.push({nx,ny}) ; 
				}
			}
		}
		ll res = 0 ;
		FOR(i,1,n)FOR(j,1,m)res+=f[i][j] ; 
		cout<<res; 
	}
}
namespace sub3
{
	#define pil pair<int,ll> 
	const int N = 9e2+2 ; 	
	pil a1[N][N], a2[N][N] ,a3[N][N] , a4[N][N] ; 
	pil s1[N][N],s2[N][N],s3[N][N],s4[N][N] ;
	pil sum1[N][N],sum2[N][N] ,sum3[N][N] , sum4[N][N] ;
	pil operator +(pil a , pil b)
	{
		return {a.fi+b.fi,a.se+b.se} ; 
	}
	pil operator - (pil a, pil b)	
	{
		return {a.fi-b.fi,a.se-b.se} ; 
	}
	pil hcn1(int x, int y ,int u ,int v){return sum1[u][v]-sum1[u][y-1]-sum1[x-1][v]+sum1[x-1][y-1];}
	pil hcn2(int x, int y ,int u ,int v){return sum2[u][v]-sum2[u][y-1]-sum2[x-1][v]+sum2[x-1][y-1];} 
	pil hcn3(int x, int y ,int u ,int v){return sum3[u][v]-sum3[u][y-1]-sum3[x-1][v]+sum3[x-1][y-1];} 
	pil hcn4(int x, int y ,int u ,int v){return sum4[u][v]-sum4[u][y-1]-sum4[x-1][v]+sum4[x-1][y-1];}	
	pil get1(int i ,int j , int d){++d;return s1[i-d+1][j]-s1[i+1][j-d]-hcn1(i+1,j-d+1,3*n,j);} 
	pil get2(int i ,int j , int d){++d;return s2[i-d+1][j]-s2[i+1][j+d]-hcn2(i+1,j,3*n,j+d-1);} 
	pil get3(int i,int j  , int d){++d;return s3[i+d-1][j]-s3[i-1][j-d]-hcn3(1,j-d+1,i-1,j);}
	pil get4(int i ,int j , int d){++d;return s4[i+d-1][j]-s4[i-1][j+d]-hcn4(1,j,i-1,j+d-1);}
	pil check(int val ,int i ,int j )
	{		
		return get1(i,j,val)+get2(i,j+1,val-1)+get3(i+1,j,val-1)+(val>=2?get4(i+1,j+1,val-2):pil{0,0}) ;  
	} 
	void xuly()
	{		
		FOR(i,1,n)FOR(j,1,m)if(a[i][j])
		{
			a1[i+n][j+m] = {1,-i-j} ;
			a2[i+n][j+m] = {1,-i+j} ; 
			a3[i+n][j+m] = {1,i-j} ; 
			a4[i+n][j+m] = {1,i+j} ; 
		}
		FOR(i,1,3*n)FOR(j,1,3*m)
		{
			sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+a1[i][j] ; 
			sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+a2[i][j] ; 
			sum3[i][j]=sum3[i-1][j]+sum3[i][j-1]-sum3[i-1][j-1]+a3[i][j] ; 			
			sum4[i][j]=sum4[i-1][j]+sum4[i][j-1]-sum4[i-1][j-1]+a4[i][j] ; 
		}
		FORD(i,3*n,1)
		{
			FOR(j,1,3*m)s1[i][j] = s1[i+1][j]+s1[i+1][j-1]-s1[i+2][j-1]+a1[i][j]; 
			FORD(j,3*m,1)s2[i][j] = s2[i+1][j]+s2[i+1][j+1]-s2[i+2][j+1]+a2[i][j] ; 
		}
		FOR(i,1,3*n)
		{
			FOR(j,1,3*m)s3[i][j]=s3[i-1][j]+s3[i-1][j-1]-s3[i-2][j-1]+a3[i][j] ;
			FORD(j,3*m,1)s4[i][j]=s4[i-1][j]+s4[i-1][j+1]-s4[i-2][j+1]+a4[i][j] ; 
		}

		ll res = 0; 
		FOR(i,n+1,2*n)
		{
			FOR(j,m+1,2*m)
			{
				int l =0 ; 	
				int r = n+m; 
				int ans = -1 ;
				int cnt =0 ; 
				while(l<=r)
				{
					int mid =(l+r)/2;
					pil tmp = check(mid,i,j) ; 
					if(tmp.fi>=k)cnt=tmp.fi,ans=mid,r=mid-1;  
					else l=mid+1; 
				}
				ll pre =res ; 
				res+=get1(i,j,ans).fi*(i-n+j-m)+get1(i,j,ans).se;
				res+=get2(i,j+1,ans-1).fi*(i-n-(j-m))+get2(i,j+1,ans-1).se; 
				res+=get3(i+1,j,ans-1).fi*(n-i+j-m)+get3(i+1,j,ans-1).se; 
				res+=get4(i+1,j+1,ans-2).fi*(n-i+m-j)+get4(i+1,j+1,ans-2).se ;
				res-= ans*(cnt-k);	
				cout<<res-pre<<" ";
			}
			cout<<el;
		}
		cout<<res<<el;
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
        if(k==1)sub2_5::xuly(),exit(0) ;
        // sub1::xuly(),exit(0) ; 
        sub3::xuly();
        exit(0);
    	
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}