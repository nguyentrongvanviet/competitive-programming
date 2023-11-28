/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "probs3"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k;  
struct DL
{
	int a ,b ;  
	bool operator<(const DL& other)const
	{
		return a<other.a||(a==other.a&&b<other.b) ; 
	}
};
DL a[N] ; 

void doc()
{   
    cin>> n >> k; 
    FOR(i,1,n)cin>>a[i].a>>a[i].b; 
}

namespace sub1
{
    int f[N][2] ; 
    void xuly()
    {
        sort(a+1,a+n+1) ; 
        FOR(i,1,n)
        {
            f[i][0] = 1 ;
            f[i][1] = 2 ; 
            FOR(j,1,i-1)if(a[j].b<=a[i].b)
            {
                if(abs(a[i].b-a[j].b)<=k)
                {
                    maxi(f[i][0],f[j][0]+1) ;
                    maxi(f[i][1],f[j][1]+1) ; 
                }
                else
                {
                    if(abs(a[i].b-a[j].b)<=2*k)
                    {
                        maxi(f[i][1],f[j][0]+2) ; 
                    }
                }   
            }
        }
        int res = 0 ;

        FOR(i,1,n)
        {
            maxi(res,max(f[i][0]+1,f[i][1])) ; 
        }
        cout<<res;
    }
}
namespace sub2
{
    struct data
    {
        int f0 ,f1; 
        data(int _f0=0, int _f1=0)
        {
            f0 = _f0 ; 
            f1 = _f1 ;
        }
        data operator +(const data&x)
        {
            return data(max(f0,x.f0),max(f1,x.f1)) ; 
        }
    } ; 
    data st[4*N] ; 
    int f[N][2] ; 
    void up(int id ,int l ,int r, int pos , int f0,int f1)
    {
        if(l==r&&l==pos)
        {
            maxi(st[id].f0,f0) ; 
            maxi(st[id].f1,f1) ; 
            return ; 
        }
        if(r<pos||pos<l)return ;
        int mid=(l+r)>>1; 
        up(id<<1,l,mid,pos,f0,f1) ; 
        up(id<<1|1,mid+1,r,pos,f0,f1) ; 
        st[id] = st[id<<1]+st[id<<1|1] ; 
    }
    data get(int id ,int l, int r, int t ,int p)
    {
        if(t<=l&&r<=p)
        {
            return st[id] ; 
        }
        if(r<t||p<l)
        {
            return data(0,0) ; 
        }
        int mid = (l+r)>>1; 
        return get(id<<1,l,mid,t,p)+get(id<<1|1,mid+1,r,t,p) ; 
    }
    int VAL[N] ; 
    void xuly()
    {
        vi V ; 
        FOR(i,1,n)V.pb(a[i].b) ;
        uni(V) ;
        int m = SZ(V) ; 
        FOR(i,1,m)
        {
            VAL[i] = V[i-1] ; 
        }
        sort(a+1,a+n+1) ;  
        FOR(i,1,n)
        {
            int pos = LB(VAL+1,VAL+m+1,a[i].b)-VAL ; 
            int l = LB(VAL+1,VAL+m+1,a[i].b-k)-VAL ; 
            f[i][0] = get(1,1,m,l,pos).f0+1 ;
            f[i][1] = get(1,1,m,l,pos).f1+1 ;
            l = LB(VAL+1,VAL+m+1,a[i].b-2*k)-VAL ; 
            maxi(f[i][1] , get(1,1,m,l,pos).f0+2) ;  
            up(1,1,m,pos,f[i][0],f[i][1]) ; 
        }
        int res = 0 ; 
        FOR(i,1,n)
        {
            maxi(res,max(f[i][0]+1,f[i][1])) ; 
        }
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
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}