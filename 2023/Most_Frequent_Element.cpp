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
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , q; 
int a[N] ; 

void doc()
{
 	cin>> n >>q ;
 	FOR(i,1,n)cin>>a[i] ;    
}

namespace sub1
{
	struct Query
	{
		int id ;
		int l, r, k ; 
		bool operator<(const Query&a)const
		{
			return r<a.r ;
		}
	} Q[N] ; 
	struct DL
	{
		int res; 
		int val; 
	} ;  
	DL st[8*N] ; 
	int lazy[8*N] ;
	int L[N]; 
	DL merge(DL L , DL R)
	{
		if(L.val<R.val)return R ; 
		return L; 
	}
	void build(int id, int l ,int r )
	{
		if(l==r)
		{
			st[id] ={a[l],0} ; 
			return ;
		}
		int mid = (l+r)/2; 
		build(id*2,l,mid) ; 
		build(id*2+1,mid+1,r) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ;
	}
	void dolazy(int id )
	{
		st[id].val+=lazy[id] ; 
		lazy[id*2]+=lazy[id] ;
		lazy[id*2+1]+=lazy[id] ; 
		lazy[id] = 0 ; 
	}
	void up(int id ,int l,int r, int t, int p )
	{
		dolazy(id) ;
		if(r<t||p<l)return ; 
		if(t<=l&&r<=p)
		{
			lazy[id]++ ;
			dolazy(id) ; 
			return; 
		}
		int mid= (l+r)/2 ;  
		up(id*2,l,mid,t,p) ; 
		up(id*2+1,mid+1,r,t,p) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ; 
	}
	DL get(int id ,int l,int r, int t ,int p )
	{
		dolazy(id) ;
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return {0,0} ;
		int mid=(l+r)/2; 
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
	}
	int res[N] ;
    void xuly()
    {
    	a[0] = -1 ;
        FOR(i,1,n)
        {
        	if(a[i]==a[i-1])L[i] = L[i-1]; 
        	else L[i] =  i ; 
        }
        FOR(i,1,q)
        {
        	int l , r , k ;cin>>l>>r>>k; 
        	Q[i] = {i,l,r,k} ;
        }
        sort(Q+1,Q+q+1) ; 
        int it =1 ;
        build(1,1,n) ;
        FOR(i,1,n)
        {
    		up(1,1,n,L[i],i);
        	while(it<=q&&Q[it].r==i)
        	{
        		int id= Q[it].id ; 
        		DL tmp = get(1,1,n,Q[it].l,Q[it].r);
        		if(tmp.val<Q[it].k)
        			res[id]=-1 ; 
        		else
        			res[id] = tmp.res; 
        		++it ; 
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}