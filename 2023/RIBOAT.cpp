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

bool mtt = 1 ;
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

int n ,W ; 
struct DL
{
	int l ,r ;  
} ; 
DL a[N] ;  
void doc()
{
	cin>> n>>W ;
	FOR(i,1,n)cin>>a[i].l>>a[i].r ; 
	a[++n] = {W,W};
}

namespace sub1
{
	ll f[N] ; 
	struct BG
	{
		int u ; 
		ll val;  
	} ;
	struct cmp
	{
		bool operator()(const BG&a , const BG&b)const
		{
			return a.val>b.val; 
		}
	} ; 
	pii trans(int u ,ll val)
	{
		int lu = a[u].l ; 
		int ru = a[u].r ; 
		int d= ru-lu ; 
		val%=2*d; 
		if(val<d)
		{
			return {lu+val,0} ; 
 		}
		val-=d; 
		return {ru-val,1} ; 
	}
	ll len(int u ,int v, ll val)
	{
		pii x= trans(u,val) ; 
		pii y = tran(v,val) ;
		ll res = inf ;
		if((x+y)%2)return inf ;  
		FOR(i,max(a[u].l,a[v].l),min(a[u].r,a[v].r))
		{

		} 
		return res ; 
	}
	void dij()
	{
		priority_queue<BG,ve<BG>,cmp>q ; 
		FOR(i,1,n)f[i] = oo ; 
		FOR(i,1,n)
		{
			if(a[i].l==0)
			{
				q.push({i,f[i]=0}) ; 
			}
		}
		while(!q.empty())
		{
			int u = q.top().u ; 
			ll val =q.top().val; 
			q.pop() ; 
			if(f[u]<val)continue ; 
			FOR(v,1,n)
			{
				ll w = len(u,v,val) ; 
				if(w!=inf&&mini(f[v],f[u]+w))
				{
					q.push({v,f[v]}) ; 
				}
			}
		}
		if(f[n]==inf)
		{
			cout<<"IMPOSSIBLE"<<el; 
		}
		else
		{
			cout<<f[n]<<el;
		}
	}	
    void xuly()
    {
    	FOR(i,1,n)f[i] = inf ; 
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