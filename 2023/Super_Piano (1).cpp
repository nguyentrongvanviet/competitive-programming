/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool multitest = 0;

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
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll       
#define            tct  template<typename T>

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
// end of template
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
#define uni(a) sort(all(a)),a.resize(unique(all(a))-a.begin()) ; 
const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 5e5+5, oo = 2e9, LO = 17; 

int n  , K , L , R ;  
int a[N] ; 
int S[N] ; 
vi value ;
unordered_map<int,int>pos;
int node= 0 ; 
int  m ;
struct DL
{
	vi a ; 
	vi T = {0} ; 
	int L , R ; 
}st[4*N] ; 
void doc()
{
    cin>> n >> K>>L>>R ; 
    FOR(i,1,n)cin>>a[i],S[i]=S[i-1]+a[i]; 
}
void build(int id, int l, int r )
{
	// cout<<"id:"<<id<<" l:"<<l<<" r:"<<r<<el;
	// for(auto v: st[id].a)cout<<v<<" ";cout<<el;
	if(l==r||st[id].a.empty())return ; 
	vi L , R ;
	int mid =(l+r)/2 ; 
	for(auto v : st[id].a)
	{
		if(v<=mid)L.pb(v),st[id].T.pb(st[id].T.back()+1) ; 
		else R.pb(v) ,st[id].T.pb(st[id].T.back()) ; 
	} 
	st[id].L=++node; 
	st[node].a=L ; 
	build(node,l,mid) ; 

	st[id].R = ++node ;
	st[node].a = R ; 
	build(node,mid+1,r) ; 
} 
int get(int id ,int l ,int r ,int t ,int p ,int k)
{
	if(l==r)return st[id].a[0];
	int mid =(l+r)/2; 
	int U = st[id].T[t-1] ; 
	int V = st[id].T[p] ; 
	int sl = V-U ;
	if(sl>=k)
	{
		return get(st[id].L,l,mid,U+1,V,k);
	}	
	return get(st[id].R,mid+1,r,t-U,p-V,k-sl) ; 
}
void init()
{
	FOR(i,0,n)value.pb(S[i]); 
	uni(value) ; 

	m =value.size() ;
	FORN(i,0,m)pos[value[i]] = i+1 ; 
	
	FOR(i,0,n)st[1].a.pb(S[i]=pos[S[i]]) ;
	
	build(++node,1,m) ;
}
struct BG
{
	int idx ;
	int k ;    
	ll val; 
}; 
struct cmp
{
	bool operator()(const BG &a  , const BG&b)const
	{
		return a.val<b.val;
	}
}; 
ll cal(int l ,int r)
{
	return value[r-1]-value[l-1] ;
}
BG add(int i ,int k)
{	
	int l = max(0,i-R); 
	int r = i-L ; 
	ll val = -inf ; 
	if(r-l+1>=k)
	{
		val= value[S[i]-1]-value[get(1,1,m,l+1,r+1,k)-1] ;
	}
	return {i,k,val} ; 
}
void xuly()
{
	priority_queue<BG,ve<BG>,cmp>q ; 
	ll res = 0 ;
	FOR(i,L,n)q.push(add(i,1)) ; 
	while(K--)
	{
		int idx= q.top().idx;
		int k = q.top().k ;  
		ll val =q.top().val; 
		res+=val ;
		q.pop();
		q.push(add(idx,k+1)); 
	}
	cout<<res; 
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        init() ; 
        xuly() ; 
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}