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
const int N = 5e4+100, oo = 1e9+3, LO = 17, CH = 26 ; 

int n; 
str a ; 
void doc()
{
	cin>>a;  
	n = a.size() ; 
	a="$"+a  ;  
}
// namespace sub1
// {
// 	struct ke 
// 	{
// 		int v, w; 
// 	} ; 
// 	ve<ke>g[N*2] ; 
// 	int f[N*2] ;
// 	int node  ; 
// 	vi q['z'+5]['z'+5] ; 
// 	void bfs(int s, int t )
// 	{
// 		deque<int>q;
// 		FOR(i,1,node)
// 		{
// 			f[i] = oo ;  
// 		}
// 		f[s] = 0 ; 
// 		q.pb(s) ;
// 		while(!q.empty())
// 		{
// 			int u= q.front() ;
// 			if(u==t)return void(cout<<f[u]<<el); 
// 			q.pop_front() ;
// 			for(auto x : g[u])
// 			{
// 				int v= x.v ; 
// 				int w= x.w; 
// 				if(mini(f[v],f[u]+w))
// 				{
// 					if(w==0)
// 					{
// 						q.push_front(v) ; 
// 					}
// 					else q.push_back(v) ;
// 				}
// 			}
// 		}
// 	}
//     void xuly()
//     {		
//     	node = n ; 
//     	FOR(i,1,n-1)
//     	{
//     		g[i].pb({i+1,1}) ;  
//     		g[i+1].pb({i,1}) ; 
//     		q[a[i]][a[i+1]].pb(i); 
//     	}
//     	FOR(i,'a','z')FOR(j,'a','z') 	
//     	{
//     		++node; 
//     		for(auto v:q[i][j])
//     		{
//     			g[v].pb({node,1}) ;
//     			g[node].pb({v,0}) ; 
//     		}
//     	}
//     	int m ; 
//     	cin>>m ; 
//     	while(m--)
//     	{
//     		int s ,t ; cin>>s>>t; 
//     		bfs(s,t) ; 
//     	}
//     }
// }
namespace sub2
{
	int node ; 
	vi g[N+CH*CH] ; 
	int f[CH*CH+5][N+CH*CH] ;
	void bfs(int id )
	{
		deque<int>q ; 
		for(int i=1;i<=n+CH*CH;i++)
		{
			f[id][i] = oo ; 
		}
		f[id][id+n] = 0 ; 
		q.push_back(id+n) ; 
		while(!q.empty())
		{
			int u =q.front() ; 
			q.pop_front() ; 
			for(auto v: g[u])
			{
				if((v>n||u>n)&&mini(f[id][v],f[id][u]+1))
				{
					q.push_front(v) ;
				}
				if(u<=n&&v<=n&&mini(f[id][v],f[id][u]+2))
				{
					q.push_back(v) ;
				}
			}
		}
	}
	int trans(int i)
	{
		return (a[i]-'a')*CH+a[i+1]-'a'+n+1;
	}
	void xuly()
	{
    	FOR(i,1,n-1)
    	{
    		g[i].pb(i+1) ; 
    		g[i+1].pb(i) ; 
    		g[trans(i)].pb(i);
    		g[i].pb(trans(i)); 
    	}
    	FOR(i,1,CH*CH)
    	{
    		bfs(i) ;
    	}
    	int m ; 
    	cin>> m; 
    	while(m--)
    	{
    		int l ,r ;
    		cin>> l >>r ; 
    		int dis = oo; 
    		FOR(i,1,CH*CH)
    		{
    			mini(dis,f[i][l]+f[i][r]);
    		}
    		cout<<min(abs(r-l),dis/2)<<el;
    	}
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
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}