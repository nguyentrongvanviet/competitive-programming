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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 400000+5 , oo = 2e9 , LO = 18 , CH = 26 ; 

int Q ; 
int P[N][LO+1] ;  
ll MA[N][LO+1] ; 
int UP[N][LO+1] ;
ll S[N][LO+1] ;
void doc()
{
	cin>>Q ; 
}

namespace sub1
{
    void xuly()
    { 
    	FOR(i,0,4e5)
    		FOR(j,0,LO)MA[i][j] =oo ,S[i][j]=inf; 
    	MA[1][0] = 0 ;
    	S[1][0] =  0 ;  
    	P[1][0] = 0 ; 
    	ll lres = 0 ; 
		int node= 1 ; 
		while(Q--)
		{	
			int t ; ll p ,q ;  cin>>t>>p>>q ; 
			ll u = (p^lres) ;
			ll val = (q^lres);
			if(t==1)
			{
				++node ;
				P[node][0] = u ;
				MA[node][0] = val ; 
				FORD(i,LO,0)
				{
					if(MA[u][i]<val)
					{
						u=P[u][i] ;
					}
				}
				S[node][0] = val; 
				UP[node][0] = u ; 
				FOR(j,1,LO)
				{
					P[node][j]=P[P[node][j-1]][j-1]; 
					MA[node][j] = max(MA[node][j-1],MA[P[node][j-1]][j-1]) ; 
					UP[node][j] = UP[UP[node][j-1]][j-1] ; 
					S[node][j]=min(inf,S[node][j-1]+S[UP[node][j-1]][j-1]); 
				}
			}
			else
			{		
				lres = 0 ;
				FORD(i,LO,0)
				{
					cout<<S[u][i]<<" ";
					if(u&&val>=S[u][i])
					{
						lres+=(1<<i) ; 
						val-=S[u][i] ; 
						u=UP[u][i] ; 
					}
				}			
				cout<<el;

				cout<<lres<<el;
			}
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}