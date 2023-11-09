/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1;

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
#define            tct  template<typename T>
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
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

ll L , R; 
int res ;
ll  VALUE ;   
void doc()
{ 
    cin>> L >>R ; 
    res= oo ;
    VALUE = -1; 
}
int cL[20] ;
int cR[20] ; 

int build(ll val,int c[])
{
    int sl =0 ; 
    FOR(i,1,19)c[i] = 0 ;
    while(val)
    {
        c[++sl] = val%10 ; 
        val/=10 ; 
    }
    return sl; 
}
ll f[20][2][2][10][10] ;

void cal(int idx, int okL , int okR , int mi , int ma)
{      
    if(idx==0)
    {
        if(ma-mi<res)
        {
            VALUE = f[idx][okL][okR][mi][ma] ; 
            res=ma-mi ;
        }
        return ;
    }
    FOR(c,0,9)
    {
        int nmi = min(mi,c) ; 
        int nma = max(ma,c) ; 
        if(okL==0&&c<cL[idx])continue ;
        if(okR==0&&c>cR[idx])continue ;
        int nokL = max(okL,(int)(c>cL[idx])) ;
        int nokR = max(okR,(int)(c<cR[idx])) ; 
        if(f[idx-1][nokL][nokR][nmi][nma]==-1)
        {
            f[idx-1][nokL][nokR][nmi][nma]=f[idx][okL][okR][mi][ma]*10+c ;   
            cal(idx-1,nokL,nokR,nmi,nma) ; 
        }
    }
}
void xuly()
{ 
    int len1 = build(L,cL); 
    int len2 = build(R,cR); 
    FOR(idx,0,19)FOR(okL,0,1)FOR(okR,0,1)FOR(mi,0,9)FOR(ma,0,9)f[idx][okL][okR][mi][ma] = -1 ; 
    FOR(idx,len1+1,len2-1)
    {
        FOR(i,1,9)
        {
            if(f[idx-1][1][1][i][i]==-1)
            {
                f[idx-1][1][1][i][i] = i ;
                cal(idx-1,1,1,i,i) ; 
            } 
        }
    }
    if(len1==len2)
    {
        FOR(i,cL[len1],cR[len2])
        {
            int okL = (i>cL[len1]) ; 
            int okR = (i<cR[len2]) ;
            if(f[len1-1][okL][okR][i][i]==-1)
            {
                f[len1-1][okL][okR][i][i]=i ; 
                cal(len1-1,okL,okR,i,i) ;
            }
        }
    }
    else
    {
        FOR(i,cL[len1],9)
        {
            int okL= (i>cL[len1]) ; 
            int okR = 1; 
            if(f[len1-1][okL][okR][i][i]==-1)
            {
                f[len1-1][okL][okR][i][i]=i ; 
                cal(len1-1,okL,okR,i,i) ;
            }
        }
        FOR(i,1,cR[len2])
        {
            int okL = 1 ; 
            int okR = (i<cR[len2]); 
            if(f[len2-1][okL][okR][i][i]==-1)
            {
                f[len2-1][okL][okR][i][i]=i ; 
                cal(len2-1,okL,okR,i,i) ;
            }
        }
    }
    cout<<VALUE<<el;
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
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}