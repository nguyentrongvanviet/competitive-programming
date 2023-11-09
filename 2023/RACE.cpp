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
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 50+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , q ; 
int kc[N][N][N] ;
void doc()
{
    cin>> n >> m >>q ;  
    FOR(c,1,m)
    {
    	FOR(i,1,n)FOR(j,1,n)
    	{
    		cin>>kc[c][i][j] ; 
    	}
    	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
    	{
    		mini(kc[c][i][j],kc[c][i][k]+kc[c][k][j]) ; 
    	}
    }
}

namespace sub1
{
	struct BG
	{
		int u ,  c , change;  
		ll dis; 
	}; 
	struct cmp
	{
		bool operator()(const BG&a , const BG&b)const
		{
			return a.dis>b.dis ;
		}
	} ; 
	ll f[N][N][N] ;
	ll res[N][N][N] ;  
	void dij(int start)
	{
		priority_queue<BG,ve<BG>,cmp>q ; 
		FOR(u,1,n)FOR(c,1,m)FOR(change,0,n)
		{
			f[u][c][change]=oo ;  
		}
		FOR(c,1,m)
		{
			q.push({start,c,0,f[start][c][0]=0}) ;  
		}
		while(!q.empty())
		{
			int u = q.top().u ; 
			int c = q.top().c ; 
			int change = q.top().change ; 
			ll dis = q.top().dis ; 
			q.pop() ; 
			if(dis>f[u][c][change])continue ; 
			FOR(v,1,n)
			{
				if(mini(f[v][c][change],dis+kc[c][u][v]))
				{
					q.push({v,c,change,f[v][c][change]}) ; 
				}
			}
			FOR(nc,1,m)
			{
				if(mini(f[u][nc][change+1],dis))
				{
					q.push({u,nc,change+1,f[u][nc][change+1]}) ; 
				}
			}
		}
		FOR(u,1,n)
		{
			res[start][u][0]=inf;
			FOR(c,1,m)
			{
				mini(res[start][u][0],f[u][c][0]) ;
			} 
		}
		FOR(change,1,n)
		{
			FOR(u,1,n)
			{
				res[start][u][change] = res[start][u][change-1] ; 
				FOR(c,1,m)
				{
					mini(res[start][u][change],f[u][c][change]) ;
				}
			}
		}		
	}

    void xuly()
    {
    	FOR(i,1,n)dij(i) ;
    	FOR(i,1,q)
    	{
    		int s ,t , k; 
    		cin>>s>>t>>k ;
    		mini(k,n) ; 
    		cout<<res[s][t][k]<<el;
    	}
    }
}
namespace sub2
{
	ll f[N][N][N] ; 
	void xuly()
	{

		FOR(u,1,n)FOR(v,1,n)
		{
			FOR(change,0,n)
			{
				f[u][v][change] = inf ; 
			}
		}
		FOR(u,1,n)
		{
			FOR(v,1,n)
			{
				FOR(c,1,m)
				{
					mini(f[u][v][0],1LL*kc[c][u][v]) ; 
				}	
			}
		}
		FOR(change,1,n)
		{
			FOR(u,1,n)FOR(v,1,n)
			{
				FOR(c,1,n)mini(f[u][v][change],f[u][c][change-1]+f[c][v][0]);
			}
		}
		while(q--)
		{
			int s ,t , k; 
    		cin>>s>>t>>k ;
    		mini(k,n) ; 
    		cout<<f[s][t][k]<<el;
		}
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
        // sub1::xuly() ;
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}