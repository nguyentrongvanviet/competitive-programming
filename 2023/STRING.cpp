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

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int k ; 
str A,B ;  
int n ;  
void doc()
{
	cin>> k;
	cin>>A>>B  ;  
	n=A.size() ; 
	A="$"+A;  
	B="#"+B; 
}
namespace sub1
{
    void xuly()
    {	
    	int res = 0;  
    	FOR(i,1,n-2)
    	{
    		FOR(j,i+1,n-1)
    		{
    			vi p = {0,1,2} ; 
    			vi a ={0,i,j,n};
    			do
    			{
	    			int ok = 1 ; 
    				for(int pos = 1,t=0;pos<=n;pos+=a[p[t]+1]-a[p[t]],t++)
    				{
    					for(int c = pos , d = a[p[t]]+1;d<=a[p[t]+1];c++,d++)
    					{
    						if(abs(B[c]-A[d])>k)
    						{
    							ok = 0 ; 
    						}
    					}
    				}
    				if(ok)
    				{
    					res++ ; 
    					break;
    				}
    			}while(next_permutation(all(p))); 
    		}
    	}
    	cout<<res; 
    }
}
namespace sub2
{
	const int cs  = 10 ; 
	ll mu[N] , ha[N] , hb[N] ; 
	ll get_hash(int l ,int r,ll ha[] )
	{
		return (ha[r]-ha[l-1]*mu[r-l+1]%sm+sm*sm)%sm;
	}
	void xuly()
	{
		mu[0] =1 ;  
		FOR(i,1,n)
		{
			mu[i] = mu[i-1]*cs%sm;  
			ha[i] = (ha[i-1]*cs+A[i])%sm;  
				hb[i] = (hb[i-1]*cs+B[i])%sm;
		}
		int res = 0 ; 
		FOR(i,1,n-2)
    	{
    		FOR(j,i+1,n-1)
    		{
    			vi p = {0,1,2} ; 
    			vi a = {0,i,j,n} ;
    			do
    			{
	    			int ok = 1 ; 
    				for(int pos = 1,t=0;pos<=n;pos+=a[p[t]+1]-a[p[t]],t++)
    				{
    					if(get_hash(pos,pos+a[p[t]+1]-a[p[t]]-1,hb)!=get_hash(a[p[t]]+1,a[p[t]+1],ha))ok=0;
    				}
    				if(ok)
    				{
    					res++ ; 
    					break;
    				}
    			}while(next_permutation(all(p))); 
    		}
    	}
    	cout<<res;
	}
}
namespace sub3
{
	const int N = 3e3+5; 
	int f[N][N] ; 
	void xuly()
	{
		ve<vi>g={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
		FORD(i,n,1)FORD(j,n,1)
		{
			if(abs(A[i]-B[j])<=k)f[i][j] = f[i+1][j+1] + 1; 
			else f[i][j] = 0 ;
		}
		int res= 0 ;
		FOR(i,1,n-2)FOR(j,i+1,n-1)
		{
			vi a = {0,i,j,n} ; 
			for(auto &p:g)
			{
				int ok = 1 ; 
				for(int t = 0 , pos=1  ;t<3; pos+=a[p[t+]+1]-a[p[t]],t++)
				{
					if(f[a[p[t]]+1][pos]<a[p[t]+1]-a[p[t]])ok=0;
				}	
				if(ok)
				{
					res++ ; 
					break ;
				}
			}
		}
		cout<<res ; 
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
    	// if(k==0)sub2::xuly() ;
        // else if(n<=3e2)sub1::xuly() ; 
        // else 
        sub3::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}