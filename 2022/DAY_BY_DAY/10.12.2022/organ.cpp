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

bool mtt = 1 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 
int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n , k , W , M ; 
ll smin , smax;  
int a[N] ; 
void doc()
{
    cin>> n >> k >> W >> M >> smin >> smax ; 
    FOR(i,1,n)
    {
        cin>>a[i] ; 
        a[i]=a[i]*M ; 
    }
}
str cong(str a , str b )
{
    if(a.empty())a="0" ; 
    if(b.empty())b="0";
    while(a.size()<b.size())a='0'+a; 
    while(b.size()<a.size())b='0'+b;
    string ans= "";  
    int nho  =0 ; 
    for(int i= b.size()-1;i>=0;i--)
    {
        int tmp = nho+ a[i]-'0'+b[i]-'0' ; 
        int c= tmp%10 ; 
        nho = tmp/10 ; 
        ans=(char)(c+'0')+ans; 
    }
    if(nho)ans='1'+ans;         
    return ans; 
}
str tru(str a , str b)
{
    while(b.size()<a.size())b='0'+b;
    str ans="" ; 
    int thieu =0 ;
    FORD(i,b.size()-1,0)
    {
        int tmp = a[i]-b[i]-thieu ; 
        if(tmp<0)thieu = 1 , tmp+=10; 
        else thieu = 0 ;
        int c= tmp%10;
        ans=(char)(c+'0')+ans; 
    }
    while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
    return ans ; 
}
str mul(str a , int b)
{
    str ans="";
    int nho = 0 ;
    FORD(i,a.size()-1,0)
    {
        int tmp = (a[i]-'0')*b+nho ; 
        nho=tmp/10;  
        int c= tmp%10;
        ans=(char)(c+'0')+ans;  
    }
    if(nho)ans=(char)(nho+'0')+ans;
    return ans;  
}
str nhan(str a, str b)
{
    if(a.empty())a="0" ; 
    if(b.empty())b="0";
    str ans=""; 
    str zero = "" ;
    FORD(i,b.size()-1,0)
    {
        str tmp = mul(a,b[i]-'0');
        tmp+=zero;  
        ans=cong(ans,tmp);
        zero+="0"; 
    }
    return ans; 
}
bool compare(str a , str b)
{
    if(a.size()>b.size())return 0; 
    if(a.size()<b.size())return 1 ; 
    return a<b ; 
}
str f[N][N] ; 
str sum[N][N] ;  
void init()
{
    int n = 30 ; 
    f[0][0]="1";
    FOR(i,1,n)
    {
        f[i][0]="1";
        FOR(j,1,i-1)
        {
            f[i][j] = cong(nhan(f[i-1][j],to_string(j+1)) , nhan(f[i-1][j-1],to_string(i-j) ));
        }
    }
    FOR(i,1,n)
    {
        sum[i][0] = "1"; 
        FOR(j,1,n)
        {
            sum[i][j] = cong(sum[i][j-1],f[i][j]);
        }
    }
}
namespace sub1
{
    ll s[N] ; 
    ll get(int l ,int r )
    {
        return s[r]-s[l-1] ;
    }
    str ma[N][N]; 
    void xuly()
    {
        FOR(i,1,n)
        {
            s[i] = s[i-1]+a[i] ; 
            if(smin<=s[i]&&s[i]<=smax)
            {
                ma[i][1] = sum[i][W];
            }
            else ma[i][1] = "0";
        }
        FOR(j,2,k)
        {
            FOR(i,j,n)
            {
                ma[i][j] = "0" ; 
                FOR(ii,j-1,i-1)if(smin<=s[i]-s[ii]&&s[i]-s[ii]<=smax)
                {
                    if(compare(ma[i][j],cong(ma[ii][j-1],sum[i-ii][W])))
                    {
                        ma[i][j] = cong(ma[ii][j-1],sum[i-ii][W]) ;
                    }
                }
            }
        }
        cout<< ma[n][k]<<el;
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
    init() ; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}