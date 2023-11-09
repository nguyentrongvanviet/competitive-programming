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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


struct pt
{
	int x,w ;
    int id ;
    bool operator<(const pt&a)const
    {
        return x<a.x; 
    }
} ; 
int n , q; 
pt a[N]  ;
int pos[N] ;
struct Query
{
    int l ,id ; 
}; 
ll res[N] ; 
ve<Query>Q[N] ; 
void doc()
{
    cin>> n>>q ; 
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].w ;
        a[i].id=  i;
    }
    sort(a+1,a+n+1) ;
    FOR(i,1,n)
    {
        pos[a[i].id] = i ;
    }
    FOR(i,1,q)
    {
        int l ,r ; cin>>l>>r ;
        l = pos[l];
        r = pos[r] ; 
        Q[r].pb({l,i}) ;
    }
}

namespace sub1
{
    ll st[4*N] ;
    void up(int id, int l ,int r ,int  pos , ll val)
    {
        if(l==r&&l==pos)
        {
            mini(st[id] , val); 
            return ; 
        }    
        if(r<pos||pos<l)return ; 
        int mid = (l+r)/2 ;
        up(id*2,l,mid,pos,val) ; 
        up(id*2+1,mid+1,r,pos,val);
        st[id] = min(st[id*2],st[id*2+1]) ;  
    }
    ll get(int id, int l, int r ,int t, int p)
    {
        if(t<=l&&r<=p)return st[id] ;
        if(r<t||p<l)return inf ; 
        int mid = (l+r)/2 ;
        return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
    } 
    vi g[N] ; 
    void xuly()
    {
        FOR(i,1,4*n)st[i] = inf ; 
        stack<int>st; 
        FOR(i,1,n)
        {
            while(!st.empty()&&a[st.top()].w>a[i].w)st.pop() ; 
            if(!st.empty())g[i].pb(st.top()); 
            st.push(i) ; 
        }
        st=stack<int>{} ;
        FORD(i,n,1)
        {
            while(!st.empty()&&a[st.top()].w>a[i].w) st.pop() ;
            if(!st.empty())g[st.top()].pb(i) ; 
            st.push(i) ; 
        }
        FOR(i,1,n)
        {
            for(auto x : g[i])up(1,1,n,x,1ll*(a[i].x-a[x].x)*(a[i].w+a[x].w)) ; 
            for(auto x : Q[i])
                res[x.id] = get(1,1,n,x.l,i); 
        }   
        FOR(i,1,q)cout<<res[i]<<el;
    }
}
namespace subtrau
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        subtrau::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}