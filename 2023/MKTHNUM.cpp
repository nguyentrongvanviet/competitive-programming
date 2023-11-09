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
#define uni(a) sort(all(a)),a.resize(unique(all(a))-a.begin()) ; 
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

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17; 

struct DL
{
	vi a ; 
	vi T ={0} ;    
	int L , R ; 
}; 
DL st[20*N] ; 
int n , q ; 
int a[N] ;
vi value ; 
unordered_map<int,int>P ; 

int node =0  ;
void doc()
{
	cin>> n >> q; 
	FOR(i,1,n)cin>>a[i],value.pb(a[i]); 
}
void build(int id ,int l ,int r)
{ 
	if(l==r||st[id].a.empty())return ; 
	int mid =(l+r)/2 ; 
	vi Left, Right ; 
	for(auto v: st[id].a)
	{
		if(v<=mid)
		{ 
			Left.pb(v) ; 
			st[id].T.pb(st[id].T.back()+1);  
		}
		else
		{
			Right.pb(v) ;  
			st[id].T.pb(st[id].T.back());
		}
	}
	st[id].L=++node ;
	st[node].a=Left;
	build(node,l,mid) ; 
	st[id].R=++node ;
	st[node].a = Right ;    
	build(node,mid+1,r) ;   
}
int get(int id ,int l ,int r ,int t ,int p ,int k)
{
	if(l==r)return st[id].a[0];
	int U =st[id].T[t-1]; 
	int V =st[id].T[p] ;
	int sl = V-U;   
	int mid= (l+r)/2;
	if(sl>=k)
	{
		int nl = U+1;
		int nr = V ;  		
		return get(st[id].L,l,mid,nl,nr,k); 
	}
	return get(st[id].R,mid+1,r,t-U,p-V,k-sl); 
}
void xuly()
{
	uni(value) ; 
	int m = value.size() ; 
	FORN(i,0,m)P[value[i]]=i+1 ; 
	FOR(i,1,n)a[i] = P[a[i]] , st[1].a.pb(a[i]) ; 
	build(++node,1,m) ; 
	while(q--)
	{
		int  l ,r , k ; 
		cin>>l>>r>> k; 
		cout<<value[get(1,1,m,l,r,k)-1]<<el ; 
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    // if(fopen(INPUT,"r"))
    // {
    //     freopen(INPUT ,"r",stdin);
    //     freopen(OUTPUT,"w",stdout);
    // }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    // cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}