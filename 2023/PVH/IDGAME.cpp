/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "IDGAME"
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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ,T ;
int a[N] ;

void doc()
{
    cin>> n >> T; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	struct DL
	{
		int val , sl;  
	} ; 
	deque<DL>q ;
	struct Query
	{
		int val , id; 
		bool operator<(const Query&a)const
		{
			return val>a.val; 
		}
	}Q[N] ;
	ll res[N] ; 
    void xuly()
    {
        sort(a+1,a+n+1);
        FOR(i,1,n)
        {
        	if(!q.empty()&&q.back().val==a[i])
        	{
        		q.back().sl++ ; 
        	}
        	else
        	{
        		q.pb({a[i],1}) ; 
        	}
        }
        FOR(i,1,T)
        {
        	cin>>Q[i].val; 
        	Q[i].id=i ;
        }
        sort(Q+1,Q+T+1) ; 
        
        int it = 1 ;
        ll used = 0 ; 
        while(it<=T&&q.back().val-q.front().val<=Q[it].val)res[Q[it].id]=0,++it;  
        while(it<=T)
        {
        	int t = q.front().val; 	
        	int u = q.front().sl; 
        	int s = q.back().val; 
        	int v = q.back().sl ; 
        	if(u<v)
        	{
        		used+=u ; 
        		q.back().sl-=u ; 
        		DL tmp = q.back() ; 
        		q.pk() ; 
        		if(q.back().val==s-1)q.back().sl+=u ; 
        		else q.pb({s-1,u}) ; 
        		q.pb(tmp) ; 
        		q.pop_front() ;
        		if(t+1==q.front().val)q.front().sl+=u ; 
        		else q.push_front({t+1,u}) ; 
        	}
        	else if(u>v)
        	{
        		used+=v ; 
        		q.front().sl-=v; 
        		DL tmp = q.front() ;
        		q.pop_front() ; 
        		if(q.front().val==t+1)q.front().sl+=v; 
        		else q.push_front({t+1,v}) ; 
        		q.push_front(tmp) ; 
        		q.pop_back() ;
        		if(s-1==q.back().val)q.back().sl+=v ;
        		else q.pb({s-1,v}) ; 
        	}
        	else 
        	{
        		used+=u ;  
        		q.pop_front() ; 
        		q.pop_back() ; 
        		if(q.front().val==t+1)q.front().sl+=u ; 
        		else q.push_front({t+1,u}) ;

        		if(q.back().val==s-1)q.back().sl+=v; 
        		else q.push_back({s-1,v}) ;
        	}
	        while(it<=T && q.back().val-q.front().val<=Q[it].val)
	        {
	        	res[Q[it].id] = used; 
	        	++it; 
	        }
        }
        FOR(i,1,T)cout<<res[i]<<el;
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