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
#define int long long 
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

int n , k; 
int a[N] ; 
vi pos[N] ; 
void doc()
{
	FOR(i,1,n)pos[i].clear() ;
   	cin>> n >> k; 
   	FOR(i,1,n)cin>>a[i] ;
}

namespace sub1
{
	struct Node
	{
		int len ;
		ll sl; 
	} ; 
	Node st[4*N] ; 
	Node merge(Node L , Node R)
	{
		int len = max(L.len,R.len); 
		ll sl = 0 ; 
		if(len==L.len)sl+=L.sl; 
		if(len==R.len)sl+=R.sl ; 
		if(len==0)sl=1 ;
		sl%=sm;
		return {len,sl} ; 
	} 
	void up(int id ,int l ,int r, int pos ,Node a)
	{
		if(l==r&&l==pos)
		{
			st[id] = a; 
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid = (l+r)/2;
		up(id*2,l,mid,pos,a) ; 
		up(id*2+1,mid+1,r,pos,a) ; 
		st[id]  =merge(st[id*2],st[id*2+1]) ;
	}
	Node get(int id, int l, int r, int t, int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return {0,1} ; 
		int mid =(l+r)/2; 
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
	}
	Node f[N] ;
	ll fac[N] , inv_fac[N] ;
	ll C(int k ,int n)
	{
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm;
	}
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}	
    void xuly()
    {
    	if(k==1)
    	{
    		return void(cout<<1<<el) ;
    	}
    	fac[0] = inv_fac[0] = 1 ; 
    	FOR(i,1,n)fac[i] = fac[i-1]*i%sm , inv_fac[i]=inv_fac[i-1]*pw(i,sm-2)%sm; 
    	FOR(i,1,4*(n+1))
    	{
    		st[i] = {0,0} ; 
    	}	
    	up(1,0,n,0,{0,1}) ;
        FOR(i,1,n)
        {
        	f[i]={0,0} ;
        	pos[a[i]].pb(i) ; 
        	FORD(j,pos[a[i]].size()-k,0)
        	{
        		int id = pos[a[i]][j] ; 
        		Node tmp = get(1,0,n,0,id-1);
        		tmp.len+=k;
        		(tmp.sl*=C(k-2,pos[a[i]].size()-j-2))%=sm;
        		f[i] = merge(f[i],tmp) ;
        	}
      		up(1,0,n,i,f[i]) ; 
      	}
      	// FOR/(i,1,n)cout<<f[i].len<<" "<<f[i].sl<<el;
      	Node res={0,1} ; 
      	FOR(i,1,n)
      	{
      		if(f[i].len==0)continue ; 
      		if(f[i].len>res.len)
      		{
      			res=f[i] ; 
      		}
      		else if(f[i].len==res.len)
      		{
      			(res.sl+=f[i].sl)%=sm;
      		}
      	}
      	cout<<res.sl<<el;
    	
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}