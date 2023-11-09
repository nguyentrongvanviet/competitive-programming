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
#define SZ(a) (int)(a.size()) 
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
const int N = 5e4+5 , oo = 2e9 , LO = 15 , CH = 26 ; 
const int VAL = 1e5+5 ;
int n ,q ; 
int a[N] ; 

void doc()
{
    cin>>n ; 
    FOR(i,1,n)cin>>a[i] ; 
}
namespace sub1
{
	int nt[VAL] ;
	vi uoc[VAL] ;  
	void sieve()
	{
		nt[0] = nt[1] = -1 ; 
		FOR(i,2,1e5)if(!nt[i])
		{
			nt[i] = i ;
			FOR(j,i,1e5/i)nt[i*j] = i ; 
		}
		FOR(i,1,1e5)
		{
			int val = i; 
			while(val!=1)
			{
				int u = nt[val] ; 
				uoc[i].pb(u) ; 
				while(val%u==0)val/=u ; 
			}
		}
	}
	int node = 0 ;
	int st[N*LO*64] ; 
	int L[N*LO*64] , R[N*LO*64] ; 
	int H[N*LO*64] ;
	int up(int old ,int l, int r, int pos ,int val)
	{
		int cur = ++node ;
		if(l==r&&l==pos)
		{
			st[cur] = st[old]+val;
			return cur;  
		}
		int mid=(l+r)/2; 
		if(pos<=mid)
		{
			R[cur] =R[old] ;
			L[cur] = up(L[old],l,mid,pos,val) ;
		}
		else
		{
			L[cur] = L[old]; 
			R[cur] = up(R[old],mid+1,r,pos,val) ; 
		}
		st[cur] =st[L[cur]]+st[R[cur]] ; 
		return cur ;
	}
	int get(int id ,int l, int r, int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0; 
		int mid=(l+r)/2; 
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p); 
	}
	void change(int id ,int val)
	{	
		int u = a[id] ; 
		FORN(MASK,1,1<<SZ(uoc[u]))
		{
			int tmp = 1 ; 
			for(int msk = MASK ;msk;)
			{
				int id = __builtin_ctz(msk) ; 
				tmp*=uoc[u][id]; 
				msk^=(1<<id) ;
			}
			H[tmp] = up(H[tmp],1,n,id,val) ;
		}
	}
	int get(int l ,int r ,int u)
	{
		int res = 0 ; 
		FORN(MASK,1,1<<SZ(uoc[u]))
		{
			int tmp = 1; 
			for(int msk=MASK;msk;)
			{
				int id = __builtin_ctz(msk) ; 
				tmp*=uoc[u][id] ; 
				msk^=(1<<id) ;
			}
			if(btpc(MASK)&1)res+=get(H[tmp],1,n,l,r) ;
			else res-=get(H[tmp],1,n,l,r) ;
		}
		return res ;
	}
    void xuly()
    {
    	sieve() ;
    	FOR(i,1,n)change(i,1) ;
    	cin>>q ; 
    	while(q--)
    	{
    		int TYPE ; cin>>TYPE ;
    		if(TYPE==1)
    		{
    			int id ,val; cin>>id>>val; 
    			change(id,-1) ;
    			a[id] = val; 
    			change(id,1) ; 
    		}
    		else
    		{
    			int l, r , k; 
    			cin>>l>>r>>k ; 
    			cout<<r-l+1-get(l,r,k)<<el;
    		}
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
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}