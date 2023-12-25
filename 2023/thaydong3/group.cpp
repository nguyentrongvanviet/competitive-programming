/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "group"
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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ,q ;
void doc()
{
    cin >> n >> m ;
}

namespace sub1
{
	int deg[N] ; 
	int tot = 0 ;
	int tmp[N] ;
	map<int,int>exist[N] ;
	bool check()
	{
		FOR(i,1,n)tmp[i] = deg[i] ; 
		sort(tmp+1,tmp+n+1,greater<int>()) ; 
		int sum = 0;  
		FOR(i,1,n)
		{
			sum+=tmp[i] ; 
			if(sum-(tot-sum)==1ll*i*(i-1))
			{
				return 1; 
			}
		}
		return 0 ;
	}
	int e = 0; 
	multiset<int,greater<int>>S ;
	bool check2()
	{
		int cur = 0 ;
		int sum = 0 ;
		for(auto val : S)
		{
			sum+=val ;
			++cur;
			if(sum-(tot-sum)==1ll*cur*(cur-1))return 1; 
			if(cur>sqrt(tot))return 0 ;
		}
		return 0 ;
	}
    void xuly()
    {
    	FOR(i,1,m)
	    {
	    	int u ,v ;cin>> u >>v ;
	    	deg[u]++ ; 
	    	deg[v]++ ;
	    	tot+=2; 
	    	if(u>v)swap(u,v) ; 
	    	exist[u][v] =1 ; 
	    }
    	cin>>q;
    	FOR(i,1,n)S.insert(deg[i]) ; 
    	if(check2())cout<<"YES"<<el;
    	else cout<<"NO"<<el;
    	while(q--)
    	{
    		int u ,v; cin>> u >>v; 
    		if(u>v)swap(u,v) ;
    		if(exist[u].count(v))
    		{
    			tot-=2;
    			S.erase(S.find(deg[u])) ;
    			S.erase(S.find(deg[v])) ; 
    			deg[u]-- ; 
    			deg[v]-- ;
    			S.insert(deg[u]) ;
    			S.insert(deg[v]) ; 
    			exist[u].erase(exist[u].find(v)) ; 
    		}
    		else
    		{
    			tot+=2;
    			S.erase(S.find(deg[u])) ;
    			S.erase(S.find(deg[v])) ; 
    			deg[u]++ ;
    			deg[v]++ ; 
    			S.insert(deg[u]) ;
    			S.insert(deg[v]) ; 
    			exist[u][v] =1 ;
    		}
    		
    		if(check2())cout<<"YES"<<el;
    		else cout<<"NO"<<el;
    	}
    }
}
namespace sub2
{
	struct DL
	{
		int mi , ma; 
		ll sum ; 
		friend DL operator+(DL a , DL b)
		{
			int mi = min(a.mi,b.mi) ;
			int ma = max(a.ma,b.ma) ; 
			ll sum = a.sum + b.sum ;
			return {mi,ma,sum} ;
		}; 
	}; 
	DL st[4*N] ; 
	void inc(int id ,int l ,int r, int val)
	{
		if(l==r)
		{
			st[id].sum++; 
			st[id].mi++ ;
			st[id].ma++ ;
			return ; 
		}
		int mid = (l+r)>>1; 
		if(st[id<<1].mi<=val)inc(id<<1,l,mid,val) ; 
		else inc(id<<1|1,mid+1,r,val) ;
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	void dec(int id, int l ,int r, int val)
	{
		if(l==r)
		{
			st[id].sum--;
			st[id].mi-- ;
			st[id].ma-- ; 
			return ; 
		}
		int mid=(l+r)>>1;
		if(val<=st[id<<1|1].ma)dec(id<<1|1,mid+1,r,val) ;
		else dec(id<<1,l,mid,val) ; 
		st[id] = st[id<<1]+st[id<<1|1] ;
	}
	int deg[N] ; 
	map<int,int>exist[N] ;
	void check()
	{
		kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
	}
	void xuly()
	{
		FOR(i,1,m)
		{
			int u ,v  ;cin>> u >>v; 
			inc(1,1,n,deg[u]); 
			inc(1,1,n,deg[v]);
			++deg[u] ; 
			++deg[v] ;
			if(u>v)swap(u,v) ; 
			exist[u][v] =1 ;
		}
		cin>>q ;
		check() ;
		FOR(i,1,q)
		{
			int u ,v ; cin>> u >>v ;
			if(u>v)swap(u,v) ; 
			if(exist[u].count(v))
			{
				dec(1,1,n,deg[u]) ; 
				dec(1,1,n,deg[v]) ;
				deg[u]-- ;
				deg[v]-- ;
			}
			else
			{
				inc(1,1,n,deg[u]) ;
				inc(1,1,n,deg[v]) ;
				deg[u]++ ;
				deg[v]++ ;
			}
			check() ;
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