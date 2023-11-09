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
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ; 
int a[(int)3e5+5] ; 
ll s[(int)3e5+5] ; 
void doc()
{
	cin>> n >> k ; 
	FOR(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i];
	if(*min_element(a+1,a+n+1)>=0)
	{
		cout<<s[n] ; 
		exit(0); 
	} 
	int pos = -1;  
	int cnt =0 ; 
	FOR(i,1,n)
	{
		if(a[i]<0)pos=i,cnt++;
	}
	if(cnt==1)
	{
		if(k==1)
		{
			cout<<max({s[n],s[pos-1],s[n]-s[pos]}) ;
			exit(0) ;  
		}
		cout<<s[n]-a[pos] ;
		exit(0) ; 
	}
}
	
namespace sub1
{
	ll f[N][N] ;
	ll st[4*N] ; 
	void build(int id ,int l, int r ,int k)
	{
		if(l==r)
		{
			st[id] = f[l][k]-s[l] ; 
			return ; 
		}
		int mid= (l+r)/2 ;
		build(id*2,l,mid,k) ; 
		build(id*2+1,mid+1,r,k) ; 
		st[id] = max(st[id*2],st[id*2+1]) ;
	}
	ll get(int id ,int l, int r, int t, int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return -inf ; 
		int mid= (l+r)/2; 
		return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
    void xuly()
    {		 	
    	ll mi = 0 ;
    	ll tmp = 0 ; 
    	FOR(i,1,n)
    	{
    		mini(mi,s[i]);
    		maxi(tmp,s[i]-mi);
    		if(i<=2e3)f[i][1] = max(f[i-1][1],s[i]-mi) ; 
    	}
    	if(k==1)
    	{
    		cout<<tmp;
    		exit(0) ;
    	}
    	// f[i][j] = max(f[i-1][j],f[ii][j-1]+(s[i]-s[ii]));
    	FOR(j,2,k)
    	{
    		build(1,1,n,j-1) ;
    		FOR(i,1,n)
    		{	
    			f[i][j] = max(f[i-1][j],s[i]+get(1,1,n,1,i));
    		}
    	}
    	cout<<f[n][k] ; 
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