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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
const int NT = 5e5+5 ;
int n , q ;
int nt[NT] ; 
int a[N] ;
void sieve()
{
	for(ll i = 2;i<=(ll)5e5;i++)
	{
		if(nt[i]==0)
		{
			nt[i]=i; 
			for(ll j =i*i;j<=(ll)5e5;j+=i)nt[j] = i; 
		}
	}
}
void doc()
{
	cin>> n >> q  ; 
	FOR(i,1,n)
	{
		cin>>a[i] ; 
	}
}

namespace sub1
{
	vi uoc[N]  ; 
	int sl[NT] ;
	int dd[N] ;
	ll res = 0 ;
	void xuly()
    {
    	FOR(i,1,n)
    	{
    		while(a[i]>1)
    		{
    			int u = nt[a[i]] ; 
    			uoc[i].pb(u) ;
    			while(a[i]%u==0)
    			{			
    				a[i]/=u;
    			}
    		}
    	}
    	ll cap= 0 ; 
    	ll on = 0 ;
    	while(q--)
     	{
     		int idx ;cin>>idx; 
    		if(dd[idx]==0)
    		{
    			int k = uoc[idx].size() ;
    			FORN(msk,1,1<<k)
				{
					int tmp = 1; 
					FORN(i,0,k)if(BIT(msk,i))
					{	
						tmp*=uoc[idx][i];
					}
					if(btpc(msk)&1)res+=sl[tmp] ;
					else res-=sl[tmp] ;
				}
				FORN(msk,1,(1<<k))
				{
					int tmp =1 ; 
					FORN(i,0,k)if(BIT(msk,i))
					{
						tmp*=uoc[idx][i] ; 
					}
					sl[tmp]++ ;
				}
				cap+=on ; 
				on++ ;
    			dd[idx] = 1 ; 
    		} 	
    		else
    		{
    			dd[idx] = 0 ;
    			int k = uoc[idx].size();
    			FORN(msk,1,(1<<k))
				{
					int tmp =1 ; 
					FORN(i,0,k)if(BIT(msk,i))
					{
						tmp*=uoc[idx][i] ; 
					}
					sl[tmp]-- ;
				}
				FORN(msk,1,1<<k)
				{
					int tmp = 1; 
					FORN(i,0,k)if(BIT(msk,i))
					{	
						tmp*=uoc[idx][i];
					}
					if(btpc(msk)&1)res-=sl[tmp] ;
					else res+=sl[tmp] ;
				}
				on--;
				cap-=on ;
    		}
    		cout<<cap-res<<el;
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
        sieve() ;
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}