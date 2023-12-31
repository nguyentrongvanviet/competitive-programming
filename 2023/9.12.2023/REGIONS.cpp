/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "REGIONS"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k , q ; 
int a[N] ; 
vi g[N] ; 
int type[N] ; 
void doc()
{
    cin>> n >> k >>q ;
    FOR(i,1,n)
    {
    	if(i!=1)
    	{
    		int p ;cin>>p; 
    		g[p].pb(i) ; 
    	}
    	cin>>type[i] ; 
    }
}

namespace sub1
{
    int in[N] , out[N] , tt = 0; 
	void dfs(int u ,int p)
	{
		in[u] = ++tt ;  
		for(auto v :g[u])if(v!=p)
		{
			dfs(v,u) ; 
		}
		out[u] = ++tt ; 
	}
	vi list_in[N] , list_out[N] ; 
	unordered_map<int,ll>ques[N] ; 
	vi list[N] ;
    int getin(int c , int l ,int r)
    {
        return UB(all(list_in[c]),r)-LB(all(list_in[c]),l) ; 
    } 
    int getout(int c , int l ,int r)
    {
        return UB(all(list_out[c]),r)-list_out[c].begin() ; 
    }
    void xuly()
    {
    	dfs(1,0) ;
    	FOR(i,1,n)
    	{
    		int c = type[i] ; 
    		list[c].pb(i) ;
    		list_in[c].pb(in[i]) ; 
    		list_out[c].pb(out[i]) ; 
    	} 
    	FOR(i,1,k)sort(all(list_in[i])) ,sort(all(list_out[i])) ; 
    	while(q--)
    	{
    		int u ,v ; cin>> u >> v ; 
    		if(ques[u].count(v))cout<<ques[u][v]<<el; 
    		else 
    		{
                ll res = 0 ; 
    			if(SZ(list[u])<SZ(list[v]))
    			{
                    res = 0 ;
    				for(auto c : list[u])
    				{
                        res+=getin(v,in[c],out[c]) ; 
    				}
                    cout<<res<<el;
    			}
    			else
    			{
                    res = 1ll*SZ(list[v])*SZ(list[u]) ; 
                    for(auto c : list[v])
                    {
                        res-=SZ(list[u])-(LB(all(list_in[u]),in[c])-list_in[u].begin()) ; 
                        res-=getout(u,1,in[c]) ;
                    }
                    cout<<res<<el ; 
    			}
                ques[u][v]= res;
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}