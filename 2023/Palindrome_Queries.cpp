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

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17; 

int n , q ;
char a[N] , b[N] ; 
ll mu[N] ; 
ll stA[4*N] , stB[4*N] ; 
void doc()
{
	cin>> n >> q ; 
	FOR(i,1,n)cin>>a[i] ;
	FOR(i,1,n)b[i] =a[n-i+1] ;      
}
ll merge(ll L , ll R , int len)
{
	return (L*mu[len]%sm+R)%sm;
}
void build(int id ,int l ,int r ,char a[],ll st[]  )
{
	if(l==r)
	{
		st[id] =a[l] ;
		return ; 
	}
	int mid=(l+r)/2 ;
	build(id*2,l,mid,a,st) ;
	build(id*2+1,mid+1,r,a,st) ;
	st[id] = merge(st[id*2],st[id*2+1],r-mid) ; 
}
void up(int id, int l, int r, int pos ,int val ,ll  st[])
{
	if(l==r&&l==pos)
	{
		st[id] = val ; 
		return ;
	}
	if(r<pos||pos<l)return ;
	int mid=(l+r)/2; 
	up(id*2,l,mid,pos,val,st) ; 
	up(id*2+1,mid+1,r,pos,val,st) ; 
	st[id] = merge(st[id*2],st[id*2+1],r-mid) ; 	
}
int giao(int l ,int r , int t, int p )
{
	int x =max(l,t) ; 
	int y =min(r,p) ; 
	return max(0,y-x+1) ; 
}
ll get(int id ,int l ,int r ,int t , int p  , ll st[])
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return 0 ; 
	int mid= (l+r)/2; 
	ll L = get(id*2,l,mid,t,p,st) ; 
	ll R = get(id*2+1,mid+1,r,t,p,st) ; 
	int u = giao(mid+1,r,t,p);
	return merge(L,R,u); 
}
void xuly()
{
	mu[0] = 1 ; 
	FOR(i,1,n)mu[i]=mu[i-1]*cs%sm; 
    build(1,1,n,a,stA) ; 
    build(1,1,n,b,stB) ; 
    FOR(i,1,q)
    {
    	int ty  ; cin>>ty ; 
    	if(ty==1)
    	{
    		int pos ; cin>>pos ; 
    		char c ; cin>> c ;
    		up(1,1,n,pos,c,stA) ;
    		up(1,1,n,n-pos+1,c,stB) ; 
    	}
    	else
    	{
    		int l , r ; cin>>l>>r; 
    		ll A = get(1,1,n,l,r,stA) ; 
    		ll B = get(1,1,n,n-r+1,n-l+1,stB) ;
    		cout<< (A==B ? "YES": "NO" )<<el;
    	}
    }
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
        xuly() ; 
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}