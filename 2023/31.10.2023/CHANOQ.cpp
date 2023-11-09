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
const int N = 1e5+5 , oo = 2e9 , LO = 19 , CH = 26 ; 


int n , q ;
struct range
{
	int l, r; 
} ; 
range a[N] ; 
void doc()
{
    cin>> n ; 
    FOR(i,1,n)cin>>a[i].l>>a[i].r ;
}

namespace sub1
{
	int cnt[N] ; 
    void xuly()
    {
	    cin>>q ;
	    while(q--)
	    {
	    	int m; cin>> m; 
	    	while(m--)
	    	{
	    		int pos ;cin>>pos ;
	    		FOR(i,1,n)cnt[i]+=(a[i].l<=pos&&pos<=a[i].r) ;
	    	}
	    	int res =0 ; 
	    	FOR(i,1,n)if(cnt[i]&1)res++,cnt[i]=0 ;
	    	cout<<res<<el;
	    }
    }
}
namespace sub2
{
	vi Left[N] ;
	int node= 0 ; 
	int st[N*LO],L[N*LO],R[N*LO] ;
	int s[N] ; 
	int H[N] ;
	int pos[N];
	int up(int old ,int l ,int r, int pos)
	{
		int cur=++node ;
		if(l==r)
		{
			st[cur] = st[old]+1;
			return cur ; 
		}
		int mid=(l+r)/2;
		if(pos<=mid)
		{
			R[cur] = R[old] ;
			L[cur]=up(L[old],l,mid,pos) ;
		}
		else
		{
			L[cur] = L[old] ; 
			R[cur] = up(R[old],mid+1,r,pos) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur; 
	}
	int get(int id ,int l ,int r ,int t,int p)
	{
		if(id==0||r<t||p<l)return 0 ;
		if(t<=l&&r<=p)return st[id] ; 
		int mid=(l+r)/2;
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ;
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			Left[a[i].r].pb(a[i].l) ; 
		}
		FOR(i,1,n)
		{
			sort(all(Left[i])) ;
			H[i] = H[i-1] ; 
			for(auto l : Left[i])
			{
				H[i] = up(H[i],1,n,l) ; 
			}
		}
		cin>>q ;
		while(q--)
		{
			int k;  cin>>k ;
			FOR(i,1,k)
			{
				cin>>pos[i] ; 
			}
			sort(pos+1,pos+k+1) ;
			pos[k+1] = n+1;
			if(k<=(int)sqrt(n))
			{
				int res =0 ; 
				FOR(i,1,k)for(int j=i;j<=k;j+=2)
				{
					int u= pos[i-1] ; 
					int v = pos[j+1]-1;
					res+=get(H[v],1,n,u+1,pos[i])-get(H[pos[j]-1],1,n,u+1,pos[i]); 
				}	
				cout<<res<<el;
			}	
			else
			{
				FOR(i,1,n)s[i]=0;
				FOR(i,1,k)s[pos[i]]=1; 
				FOR(i,1,n)s[i]+=s[i-1] ;
				int res = 0 ; 
				FOR(i,1,n)
				{
					int l =a[i].l ;
					int r =a[i].r ;
					res+=((s[r]-s[l-1])&1);
				}
				cout<<res<<el;
			}
		}
		FOR(i,1,node)
		{
			st[i] = 0; 
			L[i] = 0 ; 
			R[i] = 0 ; 
			H[i] = 0;
		}
		node = 0; 
		FOR(i,1,n)Left[i].clear();
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
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}