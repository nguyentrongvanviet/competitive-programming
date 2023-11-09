/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "G_Banh_goi_Ly_Quoc_Su"
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
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+22071997; 
const int N = 125000+5, oo = 2e9, LO = 17, CH = 26 ; 

int n  ; 
int g[N] ; 
int c[N] ; 
int q; 
void doc()
{
	cin>>n>>q;
	FOR(i,1,n)cin>>g[i] ; 
	FOR(i,1,n)cin>>c[i] ; 
}
namespace sub2
{	
	int C[9][N] ; 
	int pw(int a, int n)
	{
		if(n==0) return 1;   
		int b = pw(a,n/2); 
		if(n&1)return 1ll*b*b%sm*a%sm;  	
		return 1ll*b*b%sm ;
	}
	struct Node
	{
		int num_way ; 
		int f[9] ; 
		Node()
		{
			num_way = -1; 
			FOR(i,0,8)f[i] = 0 ; 
		}
	} ; 
	Node st[4*N] ; 
	int lazyG[4*N]  , lazyC[4*N] ; 
	void dolazy(int id, int l ,int r)
	{
		if(lazyG[id]==0)return ; 
		st[id].num_way = pw(lazyG[id]+lazyC[id],r-l+1) ;
		FOR(i,0,8)
		{
			if(i>r-l+1)st[id].f[i] = 0 ; 
			else st[id].f[i] = 1ll*C[i][r-l+1]*pw(lazyG[id],i)%sm*pw(lazyC[id],r-l+1-i)%sm; 
		}
		if(l<r)
		{
			lazyG[id*2] = lazyG[id] ;
			lazyC[id*2] = lazyC[id] ;
			lazyG[id*2+1] = lazyG[id] ;
			lazyC[id*2+1] = lazyC[id] ;
		} 
		lazyG[id] = lazyC[id] = 0 ;
	}
	Node merge(Node L , Node R)
    {
    	if(L.num_way==-1)return R ; 
    	if(R.num_way==-1)return L ;
        Node ans; 
        ans.num_way = 1ll*L.num_way*R.num_way%sm; 
        FOR(x,0,8)
        {
            FOR(y,0,8-x)
            {
                (ans.f[x+y]+=1ll*L.f[x]*R.f[y]%sm)%=sm;
            }
        }   
        return ans ; 
    }
	void build(int id ,int l,int r)
	{
		if(l==r)
		{
			st[id].num_way = 1ll*(g[l]+c[l])%sm;
			st[id].f[0] = c[l] ; 
			st[id].f[1] = g[l] ;
			return ; 
		}
		int mid = (l+r)/2;
		build(id*2,l,mid) ;
		build(id*2+1,mid+1,r) ; 
		st[id] =merge(st[id*2],st[id*2+1]) ;
	}
	void up(int id ,int l, int r, int t, int p,int G , int C)
	{
		dolazy(id,l,r) ; 
		if(t<=l&&r<=p)
		{
			lazyG[id] = G ; 
			lazyC[id] = C ;
			dolazy(id,l,r) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid= (l+r)/2; 
		up(id*2,l,mid,t,p,G,C) ;
		up(id*2+1,mid+1,r,t,p,G,C) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ; 
	}
	Node get(int id, int l ,int r ,int t, int p)
	{
		dolazy(id,l,r) ;
		if(t<=l&&r<=p)return st[id] ;
		if(r<t||p<l)return Node();
		int mid = (l+r)/2; 
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
    void xuly()
    {
    	FOR(i,0,n)
    	{
    		C[0][i] = 1 ; 
    	}
    	FOR(i,1,n)
    	{
    		FOR(j,1,min(8,i))
    		{
    			C[j][i] = (C[j-1][i-1]+C[j][i-1])%sm;
    		}

    	}
    	build(1,1,n) ;
    	while(q--)
    	{
    		char TYPE ; cin>>TYPE ; 
    		if(TYPE=='S')
    		{
    			int l ,r , g , c; cin>>l>>r>>g>>c ;	
    			up(1,1,n,l,r,g,c) ; 
    		}
    		else
    		{
    			int l ,r , k; cin>>l>>r>>k; 
    			Node ans=  get(1,1,n,l,r) ;
    			int res = ans.num_way ; 
    			FOR(i,0,k-1)
    			{
    				(res-=ans.f[i]-sm)%=sm;
    			}
    			cout<<res<<" ";
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int theta ;cin>>theta; 
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(theta==1)sub1::xuly();
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}