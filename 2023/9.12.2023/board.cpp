/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "board"
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
const ll inf = 1e18 , cs = 331 , sm = 1e7+1203; 
const int N = 16e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , q; 
bool a[N][N] ;

void doc()
{
    cin>> n >> m >> q; 

    FOR(i,1,n)FOR(j,1,m)
    {
    	char x; cin>>x ; 
    	a[i][j] = (x=='X') ;
    }
}

namespace sub1
{
	int s[N][N] ; 
	int get(int x ,int y ,int u ,int v)
	{
		return s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1] ; 
	}

	void cal()
	{
		FOR(i,1,n)FOR(j,1,m)
		{
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j] ;  
		}
		ll res = 0 ;
		FOR(x,1,n)FOR(y,1,m)FOR(u,x,n)FOR(v,y,m)
		{
			if(get(x,y,u,v)==(u-x+1)*(v-y+1))(res+=(u-x+1)*(v-y+1))%=sm ; 
		}
		cout<<res<<" ";
	}
    void xuly()
    {
    	cal() ;
    	while(q--)
    	{
    		int x ,y , u ,v ; cin>>x>>u>>y>>v;
    		FOR(i,x,u)FOR(j,y,v)a[i][j] =1 ; 
    		cal() ; 
    	}
    }
}
namespace sub2
{
	int h[N] ; 
	void cal()
	{
		h[0] = -oo;
		FOR(i,1,m)h[i] = 0 ; 
		ll res = 0 ; 
		FOR(row,1,n)
		{
			FOR(i,1,m)
			{
				if(a[row][i])h[i]++ ; 
				else h[i] = 0 ; 
			}
			stack<int>st ; 
			ll THA = 0 ; 
			ll S = 0 ; 
			st.push(0) ;
			FOR(i,1,m)
			{
				while(h[st.top()]>=h[i])
				{
					int cur = st.top() ; 
					st.pop() ; 
					int pre = st.top() ;
					THA+=1ll*h[cur]*(h[cur]+1)/2*( (pre+1+cur)*(cur-pre)/2 )%sm;
					(S-=1ll*h[cur]*(h[cur]+1)/2*(cur-pre)%sm-sm)%=sm; 
				}
				int pre = st.top() ;
				st.push(i) ; 
				int cur = st.top() ; 
				(THA-=1ll*h[cur]*(h[cur]+1)/2*( (pre+1+cur)*(cur-pre)/2 )%sm-sm)%=sm;
				(S+=1ll*h[cur]*(h[cur]+1)/2*(cur-pre)%sm)%=sm; 
				(res+=THA + S*(i+1))%=sm; 
			}
		}
		cout<<res<<" ";
	}
	void xuly()
	{
		cal() ;  
		while(q--)
		{
			int x ,y , u ,v ; cin>>x>>u>>y>>v ;
			FOR(i,x,u)FOR(j,y,v)a[i][j] = 1; 
			cal();
		}
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