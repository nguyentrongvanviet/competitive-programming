/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "Polynomial_Queries"
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

int n ,q ; 
int a[N] ;

void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)cin>>a[i] ; 
}

ll st[8*N] , lazy[8*N] , chenhlech[8*N] ; 
void build(int id ,int l ,int r)
{
    if(l==r)
    {
        st[id] = a[l] ;
        return ; 
    }
    int mid=(l+r)/2;
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r) ; 
    st[id] = st[id*2]+st[id*2+1] ; 
}
void dolazy(int id ,int len )
{       
    if(lazy[id]==0)return ;
    st[id]+=lazy[id]*len+chenhlech[id]*len*(len-1)/2;
    
    lazy[id*2]+=lazy[id] ;
    chenhlech[id*2]+=chenhlech[id]; 
    
    lazy[id*2+1]+=lazy[id]+(len/2+(len&1))*chenhlech[id]; 
    chenhlech[id*2+1]+=chenhlech[id] ; 
    
    lazy[id]=chenhlech[id] = 0 ;
}       
int giao(int l  ,int r, int t ,int p )
{
    int L = max(l,t) ; 
    int R = min(r,p) ; 
    return max(0,R-L+1);
}
void up(int id, int l , int r, int t, int p ,ll val)
{       
    dolazy(id,r-l+1) ; 
    if(t<=l&&r<=p)
    {
        lazy[id]=val; 
        chenhlech[id]=1; 
        dolazy(id,r-l+1) ; 
        return ; 
    }
    if(r<t||p<l)return ; 
    int mid =(l+r)/2; 
    up(id*2,l,mid,t,p,val) ; 
    up(id*2+1,mid+1,r,t,p,val+giao(l,mid,t,p)) ; 
    st[id] = st[id*2]+st[id*2+1] ; 
}
ll get(int id ,int l ,int r ,int t ,int p )
{
    dolazy(id,r-l+1) ; 
    if(t<=l&&r<=p)return st[id] ;
    if(r<t||p<l)return 0 ;
    int mid=(l+r)/2; 
    return get(id*2,l,mid,t,p)+get(id*2+1,mid+1,r,t,p) ; 
}
void xuly()
{
    build(1,1,n) ; 
    while(q--)
    {
        int t ,l,r; cin>>t>>l>>r ;
        
        if(t==1)up(1,1,n,l,r,1) ; 

        if(t==2)cout<<get(1,1,n,l,r)<<el; 
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