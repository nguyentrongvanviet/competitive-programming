/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "dembobaxor"
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
const int N = 2e5+5 , oo = 2e9 , LO = 60 , CH = 26 ; 


int n; 
ll a[N] ; 

void doc()
{
    cin>> n  ; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
}

namespace sub1
{
	unordered_map<ll,int>cntL[LO+1],cntR[LO+1] ;
	ll sl_0_1[LO+1],sl_1_0[LO+1] ;
	void inc(ll val)
	{
		FORN(j,0,LO)
		{
			ll nval = val>>j&(M(LO-j)-1) ; 
			cntL[LO-j][nval]++ ; 
			if(nval&1)
			{
				if(cntR[LO-j].count(nval^1))sl_1_0[LO-j]+=cntR[LO-j][nval^1]; 
			}
			else
			{
				if(cntR[LO-j].count(nval^1))sl_0_1[LO-j]+=cntR[LO-j][nval^1] ;
			}
		}
	}
	void dec(ll val)
	{
		FORN(j,0,LO)
		{
			ll nval = val>>j&(M(LO-j)-1) ; 
			cntR[LO-j][nval]-- ; 
			if(nval&1)
			{
				if(cntL[LO-j].count(nval^1))sl_0_1[LO-j]-=cntL[LO-j][nval^1]; 
			}
			else
			{
				if(cntL[LO-j].count(nval^1))sl_1_0[LO-j]-=cntL[LO-j][nval^1] ;
			}
		}
	}
	ll res = 0 ; 
    void xuly()
    {
    	FORN(j,0,LO)
    	{
    		ll nval = a[1]>>j&(M(LO-j)-1) ;
    		cntL[LO-j][nval]++; 
    	}
    	FOR(i,3,n)
    	{
	    	FORN(j,0,LO)
			{
				ll nval =a[i]>>j&(M(LO-j)-1);
				cntR[LO-j][nval]++;  
				if(nval&1)
				{
					if(cntL[LO-j].count(nval^1))sl_0_1[LO-j]+=cntL[LO-j][nval^1];
				}
				else 
				{
					if(cntL[LO-j].count(nval^1))sl_1_0[LO-j]+=cntL[LO-j][nval^1];
				}
			}
		}
    	FOR(i,2,n-1)
    	{
    		FORN(j,0,LO)
    		{
    			if(BIT(a[i],j))
    			{
    				res+=sl_1_0[LO-j];
    			}
    			else
    			{
    				res+=sl_0_1[LO-j] ; 
    			}
    		}
    		inc(a[i]) ; 
    		dec(a[i+1]) ; 
    	}
    	cout<<res;
    }
}
 namespace sub2
{
	int node = 1 ; 
	int T[(LO+1)*N][2] ; 
	int cntL[(LO+1)*N], cntR[(LO+1)*N] ;
	ll f[LO+1][2] ; 
	void add(int r ,int type ,ll val , int sign , int i )
	{
		if(i==-1)return ; 
		int j= BIT(val,i) ; 

		if(T[r][j]==0)T[r][j]=++node ; 
		
		f[i][0]-=1ll*cntL[T[r][0]]*cntR[T[r][1]]  ;   
		f[i][1]-=1ll*cntL[T[r][1]]*cntR[T[r][0]] ; 	
		
		if(type==0)cntL[T[r][j]]+=sign ; 
		else cntR[T[r][j]]+=sign ;

		add(T[r][j],type,val,sign,i-1) ;
		
		f[i][0]+=1ll*cntL[T[r][0]]*cntR[T[r][1]]  ;   
		f[i][1]+=1ll*cntL[T[r][1]]*cntR[T[r][0]] ; 	 
	}
	ll res = 0; 
	void get(int r, ll val ,int i)
	{
		int j = BIT(val,i) ; 
		if(j) 
			res+=f[i][1] ; 	
		else 
			res+=f[i][0] ;
		if(i==0)return ;
		get(T[r][j],val,i-1) ;
	}
	void xuly()
	{
		add(1,0,a[1],1,LO-1) ; 
		FOR(i,3,n)
		{
			add(1,1,a[i],1,LO-1) ; 
		}
		FOR(i,2,n-1)
		{
			get(1,a[i],LO-1) ;
			add(1,0,a[i],1,LO-1) ; 
			add(1,1,a[i+1],-1,LO-1) ;
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