/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tamgiac"
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
#define          SZ(_)  (int)(_.size())
#define             ce  cerr 
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
const int N = 9000+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n  , q; 
int tmp[N] ; 
int a[N] ; 
int sz= 0 ; 
ll res =0 ; 
ll count(int pos)
{
	ll way = 0 ; 
	int it = sz ;
	// i<=pos<=j 
	FORD(j,pos,1)
	{
		while(it>=pos&&tmp[pos]+tmp[j]<=tmp[it])--it;
		way+=it-pos+1;
	}
	it = pos+1; 
	// pos<i<=j 
	FOR(j,pos+1,sz)
	{
		while(it<=j&&tmp[pos]+tmp[it]<=tmp[j])++it;
		way+=j-it+1;
	}
	// i<=j<=pos
	it = 1 ;
	FORD(j,pos-1,1)
	{
		while(it<=j&&tmp[it]+tmp[j]<=tmp[pos])++it; 
		if(j-it+1<=0)break;
		way+=max(0,j-it+1); 
	}
	return way;
}
void add(int val)
{
	tmp[++sz] = val ; 
	int pos = sz ; 
	FORD(i,sz,2)
	{
		if(tmp[i-1]>tmp[i])swap(tmp[i-1],tmp[i]),pos=i-1; 
	}	
	res+=count(pos); 
}
void erase(int val)
{	
	int pos = 0  ; 
	FOR(i,1,sz) 
	{
		if(tmp[i]==val)
		{
			pos=i ; 
			break;
		}
	}
	res-=count(pos) ; 
	FOR(i,pos,sz-1)swap(tmp[i],tmp[i+1]) ;
	--sz; 
}
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    	add(a[i]) ; 
    }
}

namespace sub1
{
    void xuly()
    {	
	    cout<<res<<el;
	    FOR(i,1,q)
	    {
	    	int pos ,val; cin>>pos>>val; 
	    	erase(a[pos]) ; 
	    	add(a[pos]=val) ; 
	    	cout<<res<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
}