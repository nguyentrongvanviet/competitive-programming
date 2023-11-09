/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#include<bits/stdc++.h>
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
int test = 1 ;  

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

int n ,k ;
int a[N] , cold[N] , hot[N] ;
void doc()
{	
    cin>> n >>  k ; 
    FOR(i,1,n)cin>>a[i] ;
    FOR(i,1,k)cin>>cold[i];
    FOR(i,1,k)cin>>hot[i] ; 
}

namespace sub1
{
	const int N = 5e3+5 ;
	ll f[N][N] ;
    void xuly()
    {
    	FOR(i,1,n)FOR(j,0,n)f[i][j] = inf ; 
    	f[1][0] = cold[a[1]] ; 
    	FOR(i,1,n-1)
    	{
    		FOR(j,0,i-1)
    		{
				mini(f[i+1][j],f[i][j]+(a[i]==a[i+1]?hot[a[i+1]]:cold[a[i+1]])) ;
				mini(f[i+1][i],f[i][j]+(a[j]==a[i+1]?hot[a[i+1]]:cold[a[i+1]])); 
    		}
    	}
    	ll res =inf;
    	FOR(i,0,n)
    	{
    		mini(res,f[n][i]) ; 
    	}
    	cout<<res<<el;
    }
}

namespace sub2
{
	ll lazy[8*N] ; 
	ll st[8*N] ; 
	void dolazy(int id)
	{
		if(lazy[id]==0)return ;
		st[id]+=lazy[id] ; 
		lazy[id*2]+=lazy[id] ; 
		lazy[id*2+1]+=lazy[id] ;
		lazy[id] = 0 ;  
	}
	void up(int id ,int l ,int r, int t,int p  ,int val )
	{
		if(t<=l&&r<=p)
		{
			lazy[id]+=val;
			dolazy(id) ; 
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid = (l+r)/2 ; 
		up(id*2,l,mid,t,p,val) ; 
		up(id*2+1,mid+1,r,t,p,val) ; 
		st[id] = min(st[id*2],st[id*2+1]) ;
	}
	void up_pos(int id, int l, int r ,int pos , ll val)
	{
		dolazy(id) ; 
		if(l==r&&l==pos)
		{
			mini(st[id],val) ; 
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid = (l+r)/2 ;
		up_pos(id*2,l,mid,pos,val) ; 
		up_pos(id*2+1,mid+1,r,pos,val) ; 
		st[id] = min(st[id*2],st[id*2+1]) ;
	}
	ll get(int id ,int l, int r ,int t ,int p)
	{
		dolazy(id) ;
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return inf ; 
		int mid = (l+r)/2; 
		return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}	
	void xuly()
	{
		FOR(i,1,8*k) st[i] =  inf , lazy[i] = 0; 
		up_pos(1,0,k,a[1],cold[a[1]]) ; 
		FOR(i,1,n-1)
		{		
			ll val =min(get(1,0,k,a[i+1],a[i+1])+hot[a[i+1]],min(get(1,0,k,0,a[i+1]-1),get(1,0,k,a[i+1]+1,k))+cold[a[i+1]]) ; 
			up(1,0,k,0,k, (a[i]==a[i+1]?hot[a[i+1]]:cold[a[i+1]]) );
			up_pos(1,0,k,a[i],val);
		}	
		cout<<st[1]<<el;
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
        // if(n<=5e3)sub1::xuly() ; ac
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}