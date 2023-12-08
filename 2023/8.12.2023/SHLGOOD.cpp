/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "SHLGOOD"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N = 5e5+5 , oo = 2e9 , LO = 20 , CH = 26 ; 


int n ;
int a[N] ; 


void doc()
{
    cin>> n ; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
    int m; 
    int b[N] ;
    bool CK()
    {
        int ma = 0 , mi =oo ; 
        FOR(i,1,m/2)maxi(ma,b[i]) ;
        FOR(i,m/2+1,m)mini(mi,b[i]) ; 
        return ma<=mi ; 
    }
    void xuly()
    {        
        int res = 0; 
        FOR(i,1,n)for(int j = i+1;j<=n;j+=2)
        {
            m= 0 ; 
            FOR(k,i,j)
            {
                b[++m] = a[k] ; 
            }
            FOR(t,1,m)
            {
                FOR(pos,0,m-1)b[pos] =  b[pos+1] ;
                b[m] = b[0] ; 
                if(CK())
                {
                    res++ ;
                    break;
                }
            }
        }
        cout<<res<<el;
    }
}
namespace sub2
{
    int mi[N][LO+1] ;
    void build_rmq()
    {
        FOR(i,1,n)mi[i][0] = a[i] ; 
        FOR(j,1,LO)FOR(i,1,n-M(j)+1)
        {
            mi[i][j] =min(mi[i][j-1],mi[i+M(j-1)][j-1]) ;
        }
    }
    int get_mi(int l ,int r)
    {
        int k = __lg(r-l+1) ; 
        return min(mi[l][k],mi[r-M(k)+1][k]) ;
    }
    ll res =0 ; 
    int L[N] , R[N] ;
    int LEFT(int R ,int val)
    {
        int ans = R+1 ;
        int l =1 ;
        int r =R ;
        while(l<=r)
        {
            int mid = (l+r)>>1 ; 
            if(get_mi(mid,R)>val)ans=mid,r=mid-1; 
            else l=mid+1; 
        }
        return R-ans+1; 
    }
    int RIGHT(int L ,int val)
    {
        int ans = L-1 ;
        int l =L; 
        int r= n ;
        while(l<=r)
        {
            int mid=(l+r)>>1; 
            if(get_mi(L,mid)>val)ans=mid,l=mid+1; 
            else r=mid-1; 
        }
        return ans-L+1; 
    }
    int giao(int l ,int r, int u,int v)
    {
        return max(0,min(r,v)-max(l,u)+1);
    }
    void solve()
    {
        build_rmq() ;
        stack<int>st; 
        FOR(i,1,n)
        {
            while(!st.empty()&&a[st.top()]<=a[i])st.pop(); 
            if(st.empty())L[i] = 1;
            else L[i] = st.top()+1 ;
            st.push(i) ;
        }
        st=stack<int>{} ; 
        FORD(i,n,1)
        {
            while(!st.empty()&&a[st.top()]<a[i])st.pop() ;
            if(st.empty())R[i]=n ;
            else R[i] = st.top()-1 ;
            st.push(i) ;
        }
        // prt(L,n) ;
        // prt(R,n) ;
        FOR(i,1,n)
        {
            int l = L[i] ;
            int r = R[i] ; 
            int lenl = LEFT(l-1,a[i]) ;
            int lenr = RIGHT(r+1,a[i]) ;  
            mini(lenl,r-l+1) ; 
            mini(lenr,r-l+1) ;
            int len = r-l+1 ;
            int x = giao(1,lenl,len-lenr,len-1);
            res+=x ;
            res+=giao(1,lenl,i-L[i]+1,len) ; 
        }
    }
    void xuly()
    { 
        FOR(i,1,n)a[i]+=1e9+1;
        FOR(i,1,n)assert(a[i]>0) ; 
        solve() ; 
        FOR(i,1,n)a[i]=-a[i] ; 
        solve() ;
        cout<<res<<el;  
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        // sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}