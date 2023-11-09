/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "Schedule"
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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e17 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 
vi V ; 
struct DL
{
	ll val;  
	int l, r  ;  
}a[N] ;
ll R = 0 ;
void doc()
{
	cin>> n>> m; 
	FOR(i,1,n)
	{
		cin>>a[i].val>>a[i].l>>a[i].r,V.pb(a[i].l); 
		R+=a[i].val; 
		V.pb(a[i].r+1) ; 
	}
}

namespace sub1
{
	int x[N] ; 
	struct DL
	{
		int id ; 
		int r; 
		ll val; 
	} ; 
	ve<DL>g[N] ;
	struct cmp
	{
		bool operator()(const DL&a , const DL&b)const
		{
			return a.r>b.r||(a.r==b.r&&a.val>b.val);
		}
	}; 
	vi en[N] ; 
	int die[N] ; 
	bool check(ll val)
	{
		priority_queue<DL,ve<DL>,cmp>q ;
		FOR(i,1,n)die[i] = 0 ;  
		FOR(i,1,V.size())
		{
			ll dam = 0 ;
			if((x[i]-x[i-1])>=inf/val)dam= inf ; 
			else dam = 1ll*(x[i] - x[i-1])*val ;
			while(!q.empty())
			{
				int id = q.top().id ;
				int r= q.top().r; 
				ll val = q.top().val;
				q.pop() ;  
				if(val>dam)
				{
					val-=dam; 
					q.push({id,r,val}) ; 
					break;
				}
				else
				{
					dam-=val; 
					die[id]=1 ;
				}
			} 
			for(auto v : en[i])if(!die[v])return 0; 
			for(auto x : g[i])q.push(x);  
		}
		return 1 ; 
	}
    void xuly()
    {
    	V.pb(m+1) ; 
    	uni(V) ; 
    	FOR(i,1,V.size())x[i] = V[i-1]; 
    	x[0] = x[1] ; 
    	FOR(i,1,n)
    	{
    		int l=UB(all(V),a[i].l)-V.begin() ; 
    		int r=UB(all(V),a[i].r+1)-V.begin() ; 
    		g[l].pb({i,r,a[i].val});
    		en[r].pb(i) ; 
    	}
    	ll l = 1 ;
    	ll r = R ;
    	ll ans = -1 ; 
    	while(l<=r)
    	{
    		ll mid = (l+r)/2;  
    		if(check(mid))ans=mid,r=mid-1 ; 
    		else l=mid+1; 
    	}
    	cout<<ans;   
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
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}