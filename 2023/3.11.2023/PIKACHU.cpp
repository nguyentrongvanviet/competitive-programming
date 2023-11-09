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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;
#define vvi vector<vector<int>>
const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int oo = 1e9+5; 
int n , m ; 
vvi  a ; 
ve<pii>pos[(int)1000+5] ;
vvi dd; 
vi V ;
void doc()
{
	cin>> n >>m; 
    a.resize(n+2,vi(m+2,0)) ; 
    dd.resize(n+2,vi(m+2,0)) ; 
    FOR(i,1,n)FOR(j,1,m)
    {
    	cin>>a[i][j];
    	if(a[i][j])
    	{
    		pos[a[i][j]].pb({i,j});
    		V.pb(a[i][j]) ; 
	    	dd[i][j]=1;
	    }
	} 
    uni(V) ; 
}

namespace sub1
{
	struct DL
	{
		int x, y ;
		int way; 
		int val; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a, const DL&b)const
		{
			return a.val>b.val;  
		} 
	};
	ve<vvi >f; 
	int go(int val)
	{
		int st_x= pos[val][0].fi ;
		int st_y =pos[val][0].se ;
		int en_x = pos[val][1].fi ;
		int en_y = pos[val][1].se ;
		priority_queue<DL,ve<DL>,cmp>q ; 
		FOR(i,0,n+1)FOR(j,0,m+1)FORN(way,0,4)
		{
			f[i][j][way] = oo ; 
		}
		FORN(way,0,4)q.push({st_x,st_y,way,f[st_x][st_y][way]=1});
		while(!q.empty())
		{
			int x = q.top().x ;  
			int y = q.top().y ;
			int way =q.top().way ; 
			int val =q.top().val ; 
				
			if(x==en_x&&y==en_y)return val ;
			q.pop();
			if(!(x==st_x&&y==st_y)&&(f[x][y][way]<val||dd[x][y]==1))continue ;
			FORN(i,0,4)
			{
				int nx =x+xx[i] ; 
				int ny =y+yy[i] ;
				if(nx<0||nx>n+1||ny<0||ny>m+1)continue ;
				int &d = f[nx][ny][i];
				if(mini(d,val+(i!=way)))
				{
					q.push({nx,ny,i,d});
				}
			}
		}
		return oo;
	}
    void xuly()
    {
    	f.resize(n+2,vvi (m+2,vi(4,0))) ;
    	int res = 0 ;
    	while(!V.empty())
    	{	
    		int ans = oo ;
    		vi tap ;
    		for(auto val:V)
    		{
    			int v = go(val) ;
    			if(mini(ans,v))
    			{	
    				tap.clear() ; 
    				tap.pb(val) ;
    			}
    			else if(ans==v)tap.pb(val) ;
    		}
    		if(ans==oo)return void(cout<<-1<<el) ;

    		maxi(res,ans) ;	
    		for(auto val:tap)
    		{
    			for(auto tmp:pos[val])dd[tmp.fi][tmp.se]=0;
    			V.erase(V.begin()+(find(all(V),val)-V.begin()));
    		}
    	}
    	cout<<res;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}