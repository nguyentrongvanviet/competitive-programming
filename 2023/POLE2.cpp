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
#define          SZ(_)  (int)(_.size())
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
const int N = 4e3+5 , oo = 2e9 , LO = 12 , CH = 26 ; 

int n , d ; 
ll c[N] ;
int h[N] ;
ll f[N][N];
int hmax;
void doc()
{
    cin>> n >>d ; 
    FOR(i,1,n-1)cin>>c[i] ; 
  	FOR(i,1,n)cin>>h[i] , maxi(hmax,h[i]) ; 
}

namespace sub1
{
	struct DL
	{
		ll miL , miR; 
	} ; 
	DL merge(DL L , DL R)
	{
		ll miL = min(L.miL,R.miL) ; 
		ll miR = min(L.miR,R.miR) ; 
		return {miL,miR} ; 
	} 
	DL st[N][LO+2] ; 
	void build(int id)
	{
		FOR(i,1,hmax)
		{
			st[i][0] = {f[id][i]-i*c[id],f[id][i]+i*c[id]};
		}
		FOR(j,1,LO)
		{
			FOR(i,1,4e3-(1<<j)+1)
			{	
				st[i][j] = merge(st[i][j-1],st[min(hmax,i+(1<<(j-1)))][j-1]) ; 
			}
		} 
	}
	DL get(int l,int r )
	{
		int k = lg(r-l+1) ; 
		return merge(st[l][k],st[r-(1<<k)+1][k]) ; 
	}
    void xuly()
    {
    	FOR(i,1,n)FOR(j,1,hmax)f[i][j]=inf ; 
        FOR(i,h[1],hmax)
        {	
        	f[1][i] = sq(i-h[1]) ; 
        }
        FOR(i,2,n)
        {
        	deque<ll>dq; 
        	FOR(j,1,hmax)
        	{
        		while(!dq.empty() && dq.front()<j-d)dq.pop_front() ;        		
        		while(!dq.empty() && f[i-1][dq.back()]-dq.back()*c[i-1]>=f[i-1][j]-j*c[i-1])
        		{	
        			dq.pk() ;
        		}
        		dq.pb(j) ; 
        		if(j>=h[i])
        		{
        			mini(f[i][j],f[i-1][dq.front()]-dq.front()*c[i-1]+sq(j-h[i])+j*c[i-1]);
        		}
        	}
        	dq=deque<ll>{} ;
        	FORD(j,hmax,h[i])
        	{
        		while(!dq.empty()&&dq.front()>j+d)dq.pop_front() ; 
        		while(!dq.empty()&& f[i-1][dq.back()]+dq.back()*c[i-1]>=f[i-1][j]+j*c[i-1]) 
        		{
        			dq.pk();
        		}
        		dq.pb(j) ; 
        		mini(f[i][j],f[i-1][dq.front()]+dq.front()*c[i-1]+sq(j-h[i])-j*c[i-1]) ;
        	}
        }
        ll res = inf ; 
        FOR(i,1,hmax)
        {
        	mini(res,f[n][i]) ; 
        }
        FOR(i,1,n)
        {
        	FOR(j,h[i],hmax)cout<<f[i][j]<<" ";
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}