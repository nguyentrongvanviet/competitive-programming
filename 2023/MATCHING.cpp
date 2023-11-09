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
#define    FORN(i,a,b)  for(int i=(int)a;i<(int)b;i++)
#define       REP(i,a)  for(int i=0;i<(int)a;i++)
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
const int N = 1e6+5, oo = 2e9, LO = 17; 

int n , m; 
int a[N*2] ; 
int b[N] ; 
int pre[N] , ne[N] ;
int le[N] , ri[N] ;  
void doc()
{
    cin>> m >> n ; 
    REP(i,m)cin>>b[i],--b[i] ; 
    REP(i,n)cin>>a[i+m] ;     
}
int kmp[N*2];
bool check(int j ,int i )
{
    if(le[j]!=-1&&a[i]<=a[i-j+le[j]])return 0 ; 
    if(ri[j]!=-1&&a[i]>=a[i-j+ri[j]])return 0 ; 
    return 1 ; 
}
void xuly()
{
    REP(i,m)
    {   
        a[b[i]]=i;
        pre[i]=i-1,ne[i]=i+1;
    }
    FORD(i,m-1,0)
    {   
        int L = pre[a[i]] , R = ne[a[i]] ; 
        le[i] = L>=0 ? b[L]:-1 ;
        ri[i] = R<m  ? b[R]:-1 ;  
        if(L>=0)ne[L]=R ; 
        if(R<m) pre[R]=L ; 
    }
    vi ans ;
    FORN(i,1,n+m)
    {   
        int j=kmp[i-1] ; 
        while(j&&!check(j,i))
        {
            j=kmp[j-1] ;
        }
        if(check(j,i))++j;
        kmp[i]=j ;  
        if(kmp[i]==m)ans.pb(i-m-m+2);
    }   
    cout<<ans.size()<<el ;
    for(auto v: ans)cout<<v<<" ";
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