/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "YENOM"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool multitest = 0;

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
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll       
#define            tct  template<typename T>

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
// end of template
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17; 

int n; 
ll T ; 
int a[2005];
void doc()
{
  	cin>> n >>T  ; 
  	FOR(i,1,n)cin>>a[i] ;
}
void sub1_2()
{
	vi f(T+1,0) ; 
	f[0]=1 ;
	FOR(i,1,n)
	{
		FOR(j,a[i],T)
		{
			f[j]|=(f[j-a[i]]) ; 
		}
	}
	int res =0 ; 
	FOR(i,0,T)if(f[i])res++ ; 
	cout<<res;
}

void sub4()
{
	struct ke
	{
		int u ; 
		int w ; 
	} ;
	struct DL
	{
		int u ; 
		ll dis ; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a,const DL &b )const
		{
			return a.dis>b.dis ; 
		}
	};
	ve<ve<ke>>g(a[1]) ; 
	vll f(a[1],0) ;  
	
	FOR(u,0,a[1]-1)
	{
		FOR(i,1,n)
		{
			g[u].pb({ (u+a[i])%a[1],a[i] } ) ; 
		}
	}
	
	priority_queue<DL,ve<DL>,cmp> q;
	
	FOR(i,0,a[1]-1 )f[i] =inf ; 
	q.push({0,f[0] = 0 }) ; 
	while(!q.empty())
	{
		auto [u,dis] = q.top() ; 
		q.pop() ;
		if(f[u]<dis)continue ;
		for(auto [v,w] : g[u])
		{
			if(mini(f[v],f[u]+w)){
				q.push({v,f[v]});
			}
		}
	}
	ll res=0 ; 
	FOR(i,0,a[1]-1)
	{
		if(f[i]<=T)
		{
			res+=(T-f[i])/a[1]+1; 
		}
	}
	cout<<res;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        // if(T<=2e4)sub1_2() ; 
        if(T<=1e18)sub4() ;
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}