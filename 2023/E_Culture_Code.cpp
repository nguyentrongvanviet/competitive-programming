/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
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
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 1e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
struct DL
{
	int in , out ; 
	bool operator<(const DL&a)const
	{
		return out<a.out ; 
	}
} ;  
DL a[N] ; 
int ma_in = 0 ; 
void doc()
{
	cin>> n ; 
	FOR(i,1,n)
	{
		cin>>a[i].out>>a[i].in ;
		ma_in  = max(ma_in,a[i].in) ; 
	} 
} 
struct NODE
{
	int mi ; 
	ll sl ; 
}; 
NODE f[N] ;
NODE st[4*N] ; 
NODE merge(NODE a, NODE b)
{
	if(a.mi<b.mi)return a; 
	if(a.mi>b.mi)return b;
	return {a.mi,(a.sl+b.sl)%sm} ; 
}
void up(int id ,int l ,int r ,int pos , int val,ll sl)
{
	if(l==r&&l==pos)
	{
		st[id] = {val,sl} ; 
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid = (l+r)/2 ; 
	up(id*2,l,mid,pos,val,sl) ; 
	up(id*2+1,mid+1,r,pos,val,sl) ; 
	st[id] =merge(st[id*2],st[id*2+1]) ; 
}
NODE get(int id ,int l, int r ,int t ,int p )
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return {oo,0}; 
	int mid=(l+r)/2; 
	return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
}
void xuly()
{
	sort(a+1,a+n+1) ; 
	FOR(i,1,n)
	{
		int FAR = UB(a+1,a+i,a[i].in,[](const int&b, const DL& A)
		{
			return b<A.out;
		})-a-1 ; 
		f[i] = {a[i].in,1};
		NODE tmp = get(1,1,n,1,FAR) ;
		tmp.mi+=a[i].in;
		f[i] = merge(f[i],tmp); 
		up(1,1,n,i,f[i].mi-a[i].out,f[i].sl);  
	}
	NODE res = {oo,0};
	FOR(i,1,n)if(a[i].out>ma_in)
	{
		res=merge(res,f[i]) ; 
	}
	cout<<res.sl;
}

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}