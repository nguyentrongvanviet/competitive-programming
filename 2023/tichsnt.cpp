/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tichsnt"
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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define          SZ(_)  (int)(_.size())
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
const int N = 1e7+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int nt[(int)1e7+5] ;
vi V;  
void snt()
{
	nt[1]= 0 ; 
	FOR(i,2,1e7)if(nt[i]==0)
	{
		nt[i] = i;
		V.pb(i) ; 
		FOR(j,i,(int)1e7/i)nt[i*j] = i ; 
	}
}
void doc()
{
	ll n ; int k; cin>>n>> k; 
	if(k==1)
	{
		if(n==1)return void(cout<<"No"<<el);
		for(auto v:V)
		{
			if(n==v)return void(cout<<"Yes"<<el) ;
			if(n%v==0)return void(cout<<"No"<<el) ; 
		}
		return void(cout<<"Yes"<<el);
	}
	if(k>12)return void(cout<<"No"<<el); 
	FORN(i,0,SZ(V)-k+1)
	{
		ll tmp = 1;
		bool ok = 1 ;  
		FOR(j,i,i+k-1) 
		{
			if(tmp>n/V[j])
			{
				ok = 0 ; 
				break;
			}
			tmp*=V[j] ; 
			if(n%tmp)
			{
				ok = 0 ; 
				break;
			}
		}
		if(ok&&n==tmp)return void(cout<<"Yes"<<el) ; 
	}
	cout<<"No"<<el;
}

namespace sub1
{
    void xuly()
    {
        
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
	snt() ; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}