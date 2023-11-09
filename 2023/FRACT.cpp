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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e7+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k ; 
int dd[N] ; 
str  tmp ; 
int node = 0 ; 
ll mu[N] ; 
ll ha[N] ; 
str S ; 
ll HS = 0 ; 
ll get(int l, int r)
{
	return (ha[r]-ha[l-1]*mu[r-l+1]%sm+sm)%sm;
}
str TO_STRING(int val)
{
	str x ; 
	while(val)
	{
		x=char(val%10+'0')+x;
		val/=10 ; 
	}
	return x ; 
}
void doc()
{	
    cin>> n >> m >> k ;
    cin>>S ;
    for(auto v :S)
    {
    	HS=(HS*cs+v)%sm;
    } 
    str tmp  ; 
    while(dd[n]==0)
    {
    	dd[n] = (int)tmp.size()+1;
    	while(n<m)n*=10,tmp+='0' ;
    	tmp+=TO_STRING(n/m) ; 
    	n%=m;
    	n*=10;
    	if(n==0)break;
    }
    mu[0] = 1; 
	int len=tmp.size();
	FOR(i,1,len)mu[i] = mu[i-1]*cs%sm;    
	tmp="#"+tmp;
    FOR(i,1,len)	
    {
    	ha[i] = (ha[i-1]*cs+tmp[i])%sm;
    }
	FOR(i,S.size(),len)
	{
		if(get(i-S.size()+1,i)==HS)
		{
			k--; 
			if(k==0)return void(cout<<i<<el);
		}
	}
	if(S=="0")return void(cout<<len+1<<el);
    if(n==0)
    {
    	return ; 
    }
    FOR(i,1,n)
    {
    	
    }
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

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}