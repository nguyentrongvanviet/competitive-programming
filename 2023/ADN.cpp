/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "ADN"
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
const int N = 1e6+5, oo = 2e9, LO = 17; 

int n; 
char a[N] ;  
char L[N] , R[N] ;
char A[N] ;  
ll sl[N] ; 
void doc()
{
    str S; 
    cin>>S ; 
    n = S.size() ; 
    FOR(i,1,n)
    {
        a[i] =S[i-1 ];  
    }
}
ll f[N] ;
void xuly()
{
    bool ok =1 ;
    FOR(i,1,n) 
    {
        if(a[i]!='?')ok= 0 ;
    }
    if(ok)
    {
        return void(cout<<0) ; 
    }
    L[0]=R[n+1]='#'; 
    FOR(i,1,n)  
    {
        L[i] = (a[i]=='?' ? L[i-1]:a[i]);
    }
    FORD(i,n,1)
    {
        R[i] =(a[i]=='?' ? R[i+1]:a[i]) ; 
    }

    FOR(i,1,n)
    {
        if(L[i]==R[i])
        {
            a[i] =L[i] ; 
        }
        else
        {
            if(L[i]=='#')a[i]=R[i] ; 
            else if(R[i]=='#')a[i]=L[i] ; 
        }
    }
    // prt(a,n) ;
    int cnt = 0; 
    for(int i=1,j;i<=n;i=j)
    {
        j = i; 
        while(a[i]==a[j])
        {
            ++j ; 
        }
        sl[++cnt]=j-i ; 
        A[cnt] = a[i] ; 
    }
    int tmp = n;
    n=cnt; 
    // prt(A,n) ;
    // prt(sl,n) ; 
    FOR(i,1,n)sl[i]+=sl[i-1] ; 
    FOR(i,1,n)
    {
        bool ok = 0; 
        for(int j=1;j<=3;j++)
        {
            if(i-j+1==0)break;
            if(A[i-j+1]!='?')
            {
                if(ok)break ;
                else ok = 1; 
            } 
            ll cnt = sl[i] - sl[i-j] ; 
            maxi(f[i],f[i-j]+cnt*(cnt+1)/2);
        }
    }
    cout<<1LL*tmp*(tmp+1)/2-f[n] ;
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