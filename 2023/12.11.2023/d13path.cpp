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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e4+5 , oo = 1e9+5 , LO = 17 , CH = 26 ; 

int n , m , S ; 
int q; 
vi g[N] ; 

void doc()
{
	cin>> n >> m >> S; 
	FOR(i,1,m)
	{
		int u , v ; cin>> u >> v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}

namespace sub1
{
	const int N = 1e2+5 ; 
	int f[N][N] ;
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		FOR(j,1,n)f[i][j] = oo ; 
    		f[i][i] = 0 ; 
    	}
    	FOR(u,1,n)for(auto v:g[u])f[u][v] = 1 ; 
    	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)mini(f[i][j],f[i][k]+f[k][j]) ; 
    	cin>> q ; 
    	while(q--)
    	{
    		int u , k ; cin>> u >> k ; 
    		if(f[S][u]<k||f[S][u]==oo)
    		{
    			cout<<0<<el;
    			continue ; 
    		}
    		int res = 0 ;  
    		FOR(i,1,n)if(f[S][i]==k && f[S][i]+f[i][u]==f[S][u])
    		{    			
    			if(res)
    			{
    				res= oo ; 
    				break;
    			}
    			res = i ; 
    		}
    		if(res==oo)cout<<-1<<el; 
    		else cout<<res<<el;
    	} 
    }
}

namespace sub2
{
    bitset<N>onpath[N] ;
    int f[N] ; 
    bitset<N>at[N] ; 
    void bfs()
    {
        queue<int>q ; 
        FOR(i,1,n)f[i] = oo ; 

        f[S] = 0 ; 
        q.push(S) ; 
        while(!q.empty())
        {
            int u = q.front() ; 
            q.pop() ; 
            for(auto v : g[u])
            {
                if(f[v]==f[u]+1)
                {
                    onpath[v]|=onpath[u] ; 
                }
                else if(f[v]==oo)
                {
                    f[v] = f[u]+1; 
                    onpath[v] = onpath[u]; 
                    onpath[v].set(v,1) ;
                    q.push(v) ; 
                }
            }
        }
    }   
	void xuly()
	{
        bfs() ;
        FOR(i,1,n)if(f[i]!=oo)
        {
            at[f[i]].set(i,1) ; 
        }
        cin>> q ; 
        bitset<N>common;
        while(q--)
        {
            int u , k; 
            cin >> u >> k ; 
            if(f[u]==oo||f[u]<k)
            {
                cout<<0<<el; 
                continue ;
            }
            common= (onpath[u]&at[k]) ; 
            if(common.count()==1)
            {   
                cout<<common._Find_first()<<el; 
            }
            else
            {
                cout<<-1<<el;
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
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