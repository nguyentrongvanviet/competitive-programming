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

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 31 , sm = 1e9+7; 
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int len , n ; 
int pos[N] ; 
int a[N]; 
void doc()
{
    cin>> len>> n ; 
    FOR(i,1,len)
    {
        // int val ; cin>>val; 
        // pos[val] = i ; 
        cin>>pos[i] ; 
    }
    FOR(i,1,n)
    {
        cin>>a[i] ; 
    }
}           

namespace sub1
{
    void xuly()
    {
        auto check=[&](int l ,int r )->bool 
        {
            ve<pii>b ; 
            FOR(i,l,r)
            {
                b.push_back({a[i],i-l+1}); 
            }
            sort(all(b)) ; 
            FORN(i,0,b.size())
            {
                if(b[i].se!=pos[i+1])return 0 ; 
            }
            return 1; 
        }; 
        vi res ; 
        FOR(i,1,n-len+1)if(check(i,i+len-1))
        {
            res.push_back(i); 
        }
        cout<<res.size()<<el;
        for(auto x : res)cout<<x<<" "; 
    }
}
namespace sub
{
    vll mu; 
    struct SG
    {
        int n;
        struct Node;
        SG(int n):n(n)
        {
            st.resize(4*n+5) ; 
            mu[0] = 1 ; 
            
        } 
        struct Node
        {
            ll sum ; 
            int len ; 
            Node()
            {
                sum = len = 0 ;
            }
            friend Node operator+(Node a , Node b)
            {
                Node c ; 
                c.len = a.len + b.len ; 
                c.sum = (a.sum*mu[b.len]%sm+b.sum)%sm;
                return c; 
            }
        };  
        vector<Node>st ; 
        void up(int id ,int l , int r ,int pos ,int val)
        {
            if(pos<l||pos>r)return  ; 
            if(l==r)
            {
                st[id].sum = val ; 
                st[id].len = (val==0?0:1) ;  
                return ; 
            }
            int mid = (l+r)/2 ; 
            up(id*2,l,mid,pos,val); 
            up(id*2+1,mid+1,r,pos,val); 
            st[id] = st[id*2]+st[id*2+1]; 
        }
        void up(int pos ,int val)
        {
            up(1,1,n,pos,val); 
        }
        ll get()
        {
            return st[1].sum ; 
        }
    }; 
    void xuly()
    {
        ll hash = 0 ;
        FOR(i,1,len)
        {
            hash = (hash*cs+pos[i])%sm; 
        }
        mu.resize(n+1,0) ; 
        mu[0] = 1;
        FOR(i,1,n)
        {
            mu[i]=mu[i-1]*cs%sm; 
        }
        vi V ; 
        FOR(i,1,n)
        {
            V.push_back(a[i]) ; 
        }
        sort(all(V)) ; 
        V.resize(unique(all(V))-V.begin()) ;    
        FOR(i,1,n)
        {
            a[i] = UB(all(V),a[i])-V.begin() ; 
        }
        SG st(n) ; 
        ll cur = 1 ; 
        ll chenhlech = 0 ; 
        FOR(i,1,len)
        {
            (chenhlech+=cur)%=sm ; 
            (cur*=cs)%=sm; 
        }
        // cout<<hash<<endl;
        vector<int>pos_list ; 
        for(int i=1;i<=n;i++)
        {
            if(i-len>0)
            {
                st.up(a[i-len],0) ;
            }
            st.up(a[i],i) ; 
            if(i>=len)
            {
                if(st.get()==hash)
                {
                    pos_list.push_back(i-len+1); 
                }
                (hash+=chenhlech)%=sm ; 
            }
        }
        cout<<pos_list.size()<<el; 
        for(auto x : pos_list)cout<<x<<" " ; 
        cout<<endl; 
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        // if(n<=1000&&len<=100)sub1::xuly() ; 
        sub::xuly(); 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}