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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ,q ; 
struct edge
{
	int u , v; 
} ; 
edge E[N] ,Q[N] ;
int pa[N] ;
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u ,int v)
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	pa[chau]=chav ; 
}

void doc()
{
    cin>> n >> m >>q ; 
    FOR(i,1,m)
    {
    	cin>>E[i].u>>E[i].v;
    }
    FOR(i,1,q)
    {
    	cin>>Q[i].u>>Q[i].v; 
    }
}

namespace sub1
{
	vi pos[N] ;
    int res[N] , L[N] ,R[N] ; 
    void xuly()
    {
     	FOR(i,1,q)
     	{
     		res[i] = -1 ; 
     		L[i] = 1 ;
     		R[i] = m ;
     	}   
     	while(1)
     	{
     		FOR(i,1,n)pa[i] = i ;
     		FOR(i,1,m)pos[i].clear() ;
     		bool ok = 1 ; 
            FOR(i,1,q)
     		{
     			if(L[i]<=R[i])
     			{		
     				pos[(L[i]+R[i])/2].pb(i) ;
     				ok = 0;
     			}
     		}
            if(ok)break ; 
            FOR(i,1,m)
            {
                hop(E[i].u,E[i].v) ;
                for(auto id : pos[i])
                {
                    if(goc(Q[id].u)==goc(Q[id].v))
                    {
                        res[id] = i ; 
                        R[id] = i-1; 
                    }
                    else
                    {
                        L[id] = i+1; 
                    }
                }
            }
     	}
        FOR(i,1,q)
        {
            if(Q[i].u==Q[i].v)cout<<0<<el;
            else cout<<res[i]<<el;	
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}