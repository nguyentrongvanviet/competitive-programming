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

int n , q ;
struct DL
{
	int val , id ; 
	bool operator<(const DL&a)const
	{
		return val>a.val ; 
	}
} ;
DL a[N] ;
void doc()
{
    cin>> n >> q ; 
    FOR(i,1,n)
    {
    	cin>>a[i].val ;
    	a[i].id = i; 
    } 
}
namespace sub1
{
	int node = 0 ; 
	int st[(LO+1)*N] ; 
	int L[(LO+1)*N] ;
	int R[(LO+1)*N] ;
	int s[N] ;  
	int head[N] ; 
	int up(int old ,int l ,int r , int pos)
	{
		++node; 
		int cur = node; 
		if(l==r&&l==pos)
		{
			st[cur] = 1; 
			return cur ; 
		}
		int mid =(l+r)/2 ;
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
		return cur ; 
	}
	int get(int id ,int l, int r , int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0 ; 
		int mid =(l+r)/2; 
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
	}
	void build()
	{	
		sort(a+1,a+n+1) ;
		int it =1; 
		FORD(i,n,1)
		{
			s[i]=s[i+1] ; 
			while(it<=n&&a[it].val>=i)
			{
				s[i]++ ; 
				++it;  
			}
		}
		FOR(i,1,n)
		{
			head[i] = up(head[i-1],1,n,a[i].id) ; 
		}
	}	
    void xuly()
    {
    	build();

    	while(q--)
    	{
    		int L , R ; cin>> L >> R ; 
	    	int l = 1 ; 
	    	int r = R-L+1 ; 
	    	int ans = 0; 
	    	while(l<=r)
	    	{
    			int mid=(l+r)/2 ; 
    			if(get(head[s[mid]],1,n,l,r)>=mid)ans=mid,l=mid+1 ;
    			else r=mid-1;
	    	}
	    	cout<<ans<<el;
    	}
    }
}
namespace sub2
{
	int bit[N] ;
	void up(int idx, int val)
	{
	    for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
	}
	int get(int idx )
	{
	    int ans =0 ; 
	    for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
	    return ans ;
	}
	int get(int l ,int r)
	{
		return get(r)-get(l-1) ;
	}
	struct query
	{
		int l, r ; 
	} ; 
	query Q[N] ;
	int L[N] , R[N] ; 
	int res[N] ;
	vi qi[N] ; 
	void xuly()
	{
		sort(a+1,a+n+1) ; 
		FOR(i,1,q)
		{
			cin>>Q[i].l>>Q[i].r ; 
			L[i] = 1 ; 
			R[i] = n ; 
		} 
		while(1)
		{		
			int ok = 1 ; 
			FOR(i,1,n)bit[i]=0,qi[i].clear() ;
			FOR(i,1,q)
			{ 
				if(L[i]<=R[i])
				{
					qi[(L[i]+R[i])/2].pb(i);
					ok = 0 ;
				}
			}	
			if(ok)break ;
			int it = 1;  
			FORD(i,n,1)
			{
				while(it<=n&&a[it].val>=i)
				{
					up(a[it].id,1) ;
					++it; 
				}
				for(auto v:qi[i])
				{
					if(get(Q[v].l,Q[v].r)>=i)
					{
						res[v] = i ; 
						L[v] = i+1 ; 
					}
					else
					{
						R[v] = i-1 ; 
					}
				}
			}	
		}
		FOR(i,1,q)cout<<res[i]<<el;
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
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}