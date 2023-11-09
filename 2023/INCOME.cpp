/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "INCOME"
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

struct DL
{
	int val ; 
	int id ;  
}; 
struct Range
{
	int L , R ; 
}; 
struct ke 
{
	int v ; 
	int w ; 
} ; 
int n ;
DL a[N] ; 
Range Q[N] ;

int ID[N] ;  
int f[4*N],d[4*N] ;  

ve<ke>g[4*N] ;
void doc()
{
 	cin>>n ; 
 	FOR(i,1,n)cin>>a[i].val , a[i].id = i ;    
 	FOR(i,1,n)cin>>Q[i].L>>Q[i].R ; 
}
void build(int id, int l , int r)
{
	if(l==r)
	{
		ID[l] = id ; 
		f[id] = a[l].val;
		d[id] = 0 ; 
		return ; 
	}
	int mid =(l+r)/2; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	g[id*2].pb({id,0}) ; 
	g[id*2+1].pb({id,0}) ; 
}
void add(int id ,int l ,int r,int t ,int p ,int pos )
{
	if(t<=l&&r<=p)
	{
		g[id].pb({pos,1}) ;
		return ;  
	}
	if(r<t||p<l)return ; 
	int mid=(l+r)/2 ;
	add(id*2,l,mid,t,p,pos) ;
	add(id*2+1,mid+1,r,t,p,pos) ; 
}	
void bfs1_0(vi & start)
{
	deque<int>q ; 
	for(auto v : start)q.push_back(v) ; 
	while(!q.empty())
	{
		int u= q.front() ;
		q.pop_front() ; 
		for(auto c : g[u])
		{	
			int v= c.v ; 
			int w= c.w ; 
			if(f[v]>=f[u])continue ;
			f[v] = f[u] ; 
			d[v]=d[u]+w;
			if(w==0)q.push_front(v);
			else q.push_back(v);
		}	
	}
}
void xuly()
{
	build(1,1,n) ; 
	FOR(i,1,n)
	{
		int L = Q[i].L ;  
		int R = Q[i].R ; 
		add(1,1,n,L,R,ID[i]) ; 
	}
	sort(a+1,a+n+1,[](const DL &a , const DL&b )
		{
			return a.val>b.val;  
		});
	for(int i=1,j;i<=n;i=j)
	{
		j = i ;
		vi node ; 
		while(a[i].val==a[j].val&&j<=n)
		{
			int u = ID[a[j].id] ; 
			if(d[u]==0)
			{
				node.pb(u) ;
			}	
			++j ; 
		}
		bfs1_0(node) ;
	}
	int res = 0 ;
	FOR(i,1,n)
	{
		maxi(res,d[ID[i]]); 
	}
	cout<<res+1 ;
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