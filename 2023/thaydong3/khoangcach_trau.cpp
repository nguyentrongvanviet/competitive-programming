/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "khoangcach"
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


int n , k ;
struct pt
{
	int x, y;
	bool operator<(const pt&a)const
	{
		return x<a.x||(x==a.x&&y<a.y) ;
	} 
} ;
pt a[N] ; 
void doc()
{
   	cin>> n >> k ; 
   	FOR(i,1,n)
   	{
   		cin>>a[i].x>>a[i].y ;
   	} 
}

namespace sub1
{
	int dis(pt x , pt y)
	{
		return min(abs(x.x-y.x),abs(x.y-y.y));
	}
    void xuly()
    {
    	vi q; 
    	FOR(i,1,n)FOR(j,i+1,n)
    	{
    		q.pb(dis(a[i],a[j])); 
    	}
    	sort(all(q)) ;
    	cout<<q[k-1]<<el;
    }
}
namespace sub2
{
	int len;
	int H[N] , L[N] , R[N] ;
	int st[4*N];
	int node = 0 ; 
	int up(int old ,int l ,int r,int pos )
	{
		int cur = ++node ;
		if(l==r)
		{
			st[cur] = st[old]+1 ;
			return cur ; 
		}
		int mid=(l+r)>>1; 
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur] = up(L[old],l,mid,pos) ;
		}
		else
		{
			L[cur] = L[old] ;
			R[cur] = up(R[old],mid+1,r,pos) ;
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur; 
	}
	int get(int id ,int l, int r ,int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0 ;
		int mid = (l+r)>>1 ; 
		return get(L[id],l,mid,t,p) + get(R[id],mid+1,r,t,p) ;
	}
	const int MA = 2e5 ;
	int get(int x,int y ,int u ,int v)
	{
		return get(H[u],1,MA,1,v)-get(H[u],1,MA,1,y-1)-get(H[x-1],1,MA,1,v)+get(H[x-1],1,MA,1,y-1) ;
	}
	ll dem(int d)
	{
		ll res = 0; 
		FOR(i,1,n)
		{
			int x=a[i].x , y=a[i].y ;
			res+=get(max(0,x-d),0,min(MA,x+d),MA); 
			res+=get(0,max(0,y-d),MA,min(MA,y+d));
			res-=get(max(0,x-d),max(0,y-d),min(MA,x+d),min(MA,y+d)) ;
		}	
		return res-n ;
	}
	vi q[N] ;
	void xuly()
	{
		sort(a+1,a+n+1) ;
		FOR(i,1,n)
		{
			a[i].x+=1e5 ;
			a[i].y+=1e5 ;
		}
		FOR(i,1,n){
			q[a[i].x].pb(a[i].y) ;
		}
		FOR(i,1,MA)
		{
			H[i] = H[i-1] ; 
			for(auto v :q[i])
			{
				H[i] = up(H[i],1,MA,v) ; 
			}
		}
		int l = 0 ; 
		int r = MA ; 
		int ans = -1;
		while(l<=r)
		{
			int mid = (l+r)>>1 ; 
			if(dem(mid)>=k)ans=mid,r=mid-1 ;
			else l=mid+1 ; 
		} 
		assert(ans!=-1) ; 
		cout<<ans<<el;
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
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        // sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}