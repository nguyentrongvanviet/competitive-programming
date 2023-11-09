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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
ll d ; 
ll h[N] ; 
vll V ; 
void doc()
{
	cin>> n >> d; 
	FOR(i,1,n)
	{
		cin>>h[i] ; 
		V.pb(h[i]) ; 
		V.pb(h[i]-d) ; 
		V.pb(h[i]+d) ;
	}
}

namespace sub1
{
	struct Node
	{
		int val , pos ; 
	} ; 
	Node st[4*N];
	Node merge(Node L , Node  R)
	{
		if(L.val>=R.val)return L ; 
		return R ;
	}
	void up(int id, int l ,int r ,int pos , int i , int val)
	{
		if(l==r&&l==pos)
		{
			st[id]= {val,i};
			return ;  
		}
		if(r<pos||pos<l)return ; 
		int mid = (l+r)/2; 
		up(id*2,l,mid,pos,i,val) ; 
		up(id*2+1,mid+1,r,pos,i,val) ; 
		st[id] = merge(st[id*2],st[id*2+1]) ; 
	}
	Node get(int id ,int l ,int r ,int t ,int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return {0,0} ; 
		int mid =(l+r)/2 ; 
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
	int f[N] , pre[N] ;
    void xuly()
    {
    	uni(V) ; 
    	int m = V.size() ;
    	int res = 0; 
    	FOR(i,1,n)
    	{
    		int u = UB(all(V),h[i])-V.begin() ; 
    		int t = UB(all(V),h[i]-d)-V.begin() ; 	 
    		int p = UB(all(V),h[i]+d)-V.begin() ;
    		Node tmp = merge(get(1,1,m,1,t),get(1,1,m,p,m)); 
    		f[i] = tmp.val+1; 
    		pre[i] = tmp.pos ; 
    		up(1,1,m,u,i,f[i]) ; 
    		if(f[i]>f[res])res= i ; 
  	  	}
  	  	cout<<f[res]<<el;
  	  	vi ans ;  
  	  	while(res)
  	  	{
  	  		ans.pb(res) ; 
  	  		res=pre[res] ; 
  	  	}
  	  	reverse(all(ans)) ;
  	  	prv(ans) ; 
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