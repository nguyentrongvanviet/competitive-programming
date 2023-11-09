/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define            tct  template<class T>
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
const ll inf = 1e18, cs = 331;
const int  sm = 1e4+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , k;  
int g[N] ,c[N] ; 
int q; 

void doc()
{
    cin>> n >> k ;
    FOR(i,1,n)cin>>g[i] ; 
    FOR(i,1,n)cin>>c[i] ;
}
namespace sub1
{
    ll f[N][21] ; 
    void xuly()
    {
        cin>>q ;  
        while(q--)
        {
            int pos , G ,C ; 
            cin>>pos>>G>>C ; 
            g[pos]=G ; 
            c[pos]=C ; 
            ll num_way = 1 ;
            f[0][0] = 1 ; 
            FOR(i,1,n)
            {
                (num_way*=(g[i]+c[i]))%=sm;
                f[i][0] =f[i-1][0]*c[i]%sm; 
                FOR(j,1,k-1)
                {
                    f[i][j] = (f[i-1][j]*c[i]%sm+f[i-1][j-1]*g[i]%sm)%sm;
                }
            }
            FOR(i,0,k-1)
            {
                (num_way-=f[n][i]-sm)%=sm;
            }
            cout<<num_way<<" ";
        }   
    }
}
namespace sub2
{
    struct Node
    {
        int num_way ; 
        int f[9] ; 
        Node()
        {
            num_way = 1;  
            FOR(i,0,k-1)f[i] = 0; 
        }
        Node(int G , int C)
        {
            num_way = (G+C)%sm; 
            f[0] = C%sm ;  
            f[1] = G%sm ;
        }
    }; 
    Node st[4*N] ; 
    Node merge(Node& L , Node& R)
    {
        Node ans; 
        ans.num_way = L.num_way*R.num_way%sm; 
        FOR(x,0,k-1)
        {
            FOR(y,0,k-1-x)
            {
                ans.f[x+y]+=L.f[x]*R.f[y]%sm;
            }
        }   
        FOR(x,0,k-1)ans.f[x]%=sm;
        return ans ; 
    }
    void build(int id, int l ,int r)
    {
        if(l==r)
        {
            st[id] = Node(g[l],c[l]) ;  
            return ; 
        }
        int mid=(l+r)/2; 
        build(id*2,l,mid) ; 
        build(id*2+1,mid+1,r) ; 
        st[id] = merge(st[id*2],st[id*2+1]) ; 
    }
    void up(int id ,int l ,int r ,int pos , int G , int C)
    {
        if(l==r&&l==pos)
        {   
            st[id] = Node(G,C) ; 
            return  ; 
        }
        if(r<pos||pos<l)return ; 
        int mid = (l+r)/2 ; 
        up(id*2,l,mid,pos,G,C) ; 
        up(id*2+1,mid+1,r,pos,G,C) ; 
        st[id] = merge(st[id*2],st[id*2+1]) ; 
    }
    void xuly()
    {
        build(1,1,n) ;
        cin>>q ;
        while(q--)
        {
            int pos , G , C ; cin>>pos>>G>>C; 
            up(1,1,n,pos,G,C) ; 
            int res= st[1].num_way ; 
            FOR(i,0,k-1)
            {
                (res-=st[1].f[i]-sm)%=sm;
            }
            cout<<res<<" ";
        }
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
        // if(n<=1e3&&q<=1e3)
            // sub1::xuly() ; 
        // else 
            sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}