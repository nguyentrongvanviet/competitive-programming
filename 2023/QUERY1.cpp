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

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 4e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n; 
struct pt
{
	int x, y; 
    int c; 
	bool operator<(const pt&a)const
	{
		return y<a.y;
	}
} ; 
pt a[N] ; 
vi V ;
ll VAL[N] ;  
void doc()
{	
	cin>> n; 
	FOR(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].c ;
        int u =min(a[i].x,a[i].y) ; 
        int v = max(a[i].x,a[i].y) ; 
        V.pb(u) ;
        V.pb(v) ; 
        a[i].x= u ; 
        a[i].y= v ;  
	}
}
namespace sub1
{
    ll st[8*N] ; 
    ll lazy[8*N] ; 
    void build(int id ,int l , int r )
    {
        if(l==r)
        {
            st[id] = VAL[l] ; 
            return ; 
        }
        int mid =(l+r)/2 ;
        build(id*2,l,mid) ; 
        build(id*2+1,mid+1,r) ; 
        st[id] =max(st[id*2],st[id*2+1]) ; 
    }
    void dolazy(int id)
    {
        if(lazy[id])
        {
            st[id]+=lazy[id] ; 
            lazy[id*2]+=lazy[id] ; 
            lazy[id*2+1]+=lazy[id] ; 
            lazy[id] = 0 ;
        }
    }
    void up(int id, int l, int r ,int t ,int p ,int val)
    {
        dolazy(id) ; 
        if(t<=l&&r<=p)
        {
            lazy[id]+=val ; 
            dolazy(id) ; 
            return ; 
        }
        if(r<t||p<l)return ; 
        int mid = (l+r)/2; 
        up(id*2,l,mid,t,p,val); 
        up(id*2+1,mid+1,r,t,p,val) ;
        st[id] =max(st[id*2],st[id*2+1]) ;
    }
    ll get(int id ,int l ,int r, int t, int p)
    {
        dolazy(id) ;
        if(t<=l&&r<=p)return st[id] ; 
        if(r<t||p<l)return -inf ; 
        int mid =(l+r)/2; 
        return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
    }
    void xuly()
    {
        sort(a+1,a+n+1);
        uni(V) ; 
        int m = V.size() ; 
    	FOR(i,1,m)
        {
            VAL[i] = V[i-1] ; 
        }
    	ll res =0 ; 
        build(1,1,m); 
        int it = 1; 
        FOR(i,1,m)
        {
            while(it<=n&&a[it].y<=VAL[i])
        	{      
                int u = LB(VAL+1,VAL+m+1,a[it].x)-VAL; 
                up(1,1,m,1,u,a[it].c) ; 
                ++it ; 
        	}
            maxi(res,-VAL[i]+get(1,1,m,1,i)); 
        } 
        cout<<res;
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
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