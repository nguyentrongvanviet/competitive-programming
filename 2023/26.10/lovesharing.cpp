/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "lovesharing"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
struct DL
{
	int x , len ;
	int TYPE  ; 
};
DL tmp[N] ; 
void doc()
{			
    cin>> n >> q; 
    FOR(i,1,n)
    {
    	int x , len ,TYPE ; cin>> x >> len >> TYPE ; 
    	tmp[i] = {x,len,TYPE} ;  
    }
}

namespace sub1
{
    void xuly()
    {
    	while(q--)
    	{
    		int l ,r ;cin>>l>>r ; 
    		int res = 0 ;
    		FOR(i,1,n)if(l<=tmp[i].TYPE&&tmp[i].TYPE<=r)
    		{
    			FOR(j,i+1,n)if(l<=tmp[j].TYPE&&tmp[j].TYPE<=r)
    			{
    				res+=min(tmp[i].len,tmp[j].len)>=abs(tmp[i].x-tmp[j].x) ;
    			}
    		}
    		cout<<res<<el;
    	}
    }
}
namespace sub2
{
	struct IT 
	{
		vi st , L ,R ; 
		vi val; 
		int n , node = 0;
		IT(){}
		void init (int _n)
		{
			n=_n ; 
			st = L = R = vi(n*(lg(n)+3),0) ;  
		}
		int up(int old ,int l, int r, int pos )
		{
			int cur = ++node; 
			if(l==r)
			{
				st[cur]=st[old]+1;  
				return cur ;
			}
			int mid=(l+r)/2; 
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
		int get(int id , int l ,int r ,int t , int p)
		{
			if(id==0)return 0 ;
			if(t<=l&&r<=p)return st[id] ; 
			if(r<t||p<l)return 0 ;
			int mid=(l+r)/2 ;
			return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
		}
		int get(int u ,int v,int x)
		{
			int d = LB(all(val),x)-val.begin()+1;
			return -get(u,1,n,d,n) + get(v,1,n,d,n);
		}
	}; 
	struct pt
	{
		int x ,len ; 
		bool operator<(const pt&a)const
		{		
			return x<a.x ;
		}
	} ; 
	int color ; 
	ve<pt> Q[N] ;
	 	
	map<pii,ll>f , g ; 
	IT tree[N] ; 
	vi H[N] ;
	void solve1()
	{
		FOR(i,1,color)
		{
			for(auto [x,len]:Q[i])tree[i].val.pb(x+len) ; 
			tree[i].init(SZ(Q[i]));
			H[i]=vi(SZ(Q[i])+1,0);
			uni(tree[i].val) ; 
			tree[i].n=SZ(tree[i].val); 
			FORD(j,i,max(1,i-50))f[{j,i}]=f[{j,i-1}]; 
			FOR(id,1,SZ(Q[i]))
			{
				int x = Q[i][id-1].x; 
				int len = Q[i][id-1].len ; 
				ll sum = 0 ; 
				FORD(j,i,max(1,i-50))
				{
					int d = LB(all(Q[j]),x-len,
					[&](pt a , int val)
					{
						return a.x<val;
					})-Q[j].begin()+1; 
					int c = UB(all(Q[j]),x,[&](int val ,pt a )
					{
						return val<a.x;
					})
					-Q[j].begin() ; 
					if(j==i)
					{
						mini(c,id-1);
					}
					sum+=tree[j].get(H[j][d-1],H[j][c],x);
					f[{j,i}]+=sum ; 
				}
				int d = UB(all(tree[i].val),x+len)-tree[i].val.begin() ;
				H[i][id] = tree[i].up(H[i][id-1],1,tree[i].n,d);
			}
		}
	}
	void solve2()
	{
		FOR(i,1,color)tree[i]=IT(); 
		FOR(i,1,color)
		{
			FORN(j,0,SZ(Q[i]))
			{
				Q[i][j].x=-Q[i][j].x;
			}
			sort(all(Q[i]));
		}
		FOR(i,1,color)
		{
			for(auto [x,len]:Q[i])tree[i].val.pb(x+len) ; 
			tree[i].init(SZ(Q[i]));
			H[i]=vi(SZ(Q[i])+1,0);
			uni(tree[i].val) ; 
			tree[i].n=SZ(tree[i].val) ; 
			FORD(j,i,max(1,i-50))g[{j,i}]=g[{j,i-1}]; 
			FOR(id,1,SZ(Q[i]))
			{
				int x = Q[i][id-1].x; 
				int len = Q[i][id-1].len ; 
				ll sum = 0 ;
				FORD(j,i-1,max(1,i-50))
				{
					int d = LB(all(Q[j]),x-len,
					[&](pt a , int val)
					{
						return a.x<val;
					})-Q[j].begin()+1; 
					int c = LB(all(Q[j]),x,[&](pt a, int val)
					{
						return a.x<val;
					})
					-Q[j].begin() ;
					sum+=tree[j].get(H[j][d-1],H[j][c],x);
					g[{j,i}]+=sum ; 
				}
				int d = UB(all(tree[i].val),x+len)-tree[i].val.begin() ;
				H[i][id] = tree[i].up(H[i][id-1],1,tree[i].n,d);
			}
		}
	}
	void xuly()
	{
		vi V ;
		FOR(i,1,n)V.pb(tmp[i].TYPE) ; 
		uni(V) ; 
		color = SZ(V) ;
		FOR(i,1,n)
		{	
			tmp[i].TYPE = UB(all(V),tmp[i].TYPE)-V.begin() ; 
			Q[tmp[i].TYPE].pb({tmp[i].x,tmp[i].len});
		}
		FOR(i,1,color)sort(all(Q[i]));
		solve1() ; 
		solve2() ;
		FOR(i,1,q)
		{
			int l ,r ;cin>>l>>r; 
			int u = LB(all(V),l)-V.begin()+1;
			int v = UB(all(V),r)-V.begin() ; 
			cout<<f[{u,v}]+g[{u,v}]<<" ";
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
    	int sub ; 
    	cin >> sub ; 
        doc() ; 
       	// if(sub==1)sub1::xuly() ; 
       	if(sub<=2)sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}