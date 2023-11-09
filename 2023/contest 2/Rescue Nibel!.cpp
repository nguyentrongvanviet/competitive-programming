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

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct DL
{
	int l ,r ; 
	bool operator<(const DL&a)const
	{
		return l <a.l ; 
	}
} ; 
vi V ; 
int n , k; 
DL a[N] ; 
void doc()
{
    cin>> n >> k;  
    FOR(i,1,n)
    {
    	cin>>a[i].l>>a[i].r ;
    	V.pb(a[i].l) ;
    	V.pb(a[i].r) ; 
    }
}

namespace sub1
{
	ll fac[N] , inv_fac[N] ;
	ll pw(ll a , ll n)
	{
		if(n==0)return 1 ; 
		ll b = pw(a,n/2)  ;
		if(n&1)return b*b%sm*a%sm; 
		return b*b%sm;
	}
	ll C(int k ,int n)
	{
		if(k>n)return 0; 
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
	}
    void xuly()
    {
        uni(V) ; 
        sort(a+1,a+n+1) ;
        FOR(i,1,n)
        {
        	a[i].l=UB(all(V),a[i].l)-V.begin() ;
        	a[i].r=UB(all(V),a[i].r)-V.begin() ; 
        	// cout<<a[i].l<<" "<<a[i].r<<el;
        }

        fac[0] = inv_fac[0] = 1;
        FOR(i,1,n)fac[i] = fac[i-1]*i%sm , inv_fac[i] = inv_fac[i-1]*pw(i,sm-2)%sm; 
       	priority_queue<int,vi,greater<int>>q ;
       	ll res  = 0 ;
       	int it = 1 ; 
       	FOR(v,1,V.size())
       	{
       		while(!q.empty()&&q.top()<v)
       		{
       			q.pop() ; 
       		}
       		while(it<=n&&a[it].l==v)
       		{
       			(res+=C(k-1,q.size()))%=sm; ; 
       			q.push(a[it].r);
       			++it; 
       		}
       	}	
       	cout<<res; 
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