/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "garden"
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
int xx[] = {0,0,-1,1,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 2207+5, oo = 2e9, LO = 17; 

int n , m ,  K ;
int a[N][N] ;
ll  f[N][N][2] ; 
ll res = -inf ; 
ll H_Trai[N][N] ,  C_Tren[N][N] , H_Phai[N][N] ,C_Duoi[N][N] ;
void doc()
{
    cin>> n>> m  >>K ; 
    FOR(i,1,n)FOR(j,1,m)
        cin>>a[i][j] ;  

}

void xuly()
{
    FOR(i,0,n+1)FOR(j,0,m+1)FOR(k,0,1)f[i][j][k]=-inf; 
    
    FOR(i,1,n)f[i][1][0]=a[i][1];
    FOR(j,2,m)FOR(i,1,n)
    {
        f[i][j][0]  = -inf ;
        FOR(t,1,3)
        {
            int ii = i +xx[t] ; 
            maxi(f[i][j][0],f[ii][j-1][0]);
        } 
        f[i][j][0]+=a[i][j] ; 
    }   
    FOR(i,1,n)maxi(res,f[i][m][0]) ; 
    
    FOR(i,1,n)
        H_Trai[i][0]=H_Phai[i][m+1]=-inf ; 
    
    FOR(i,1,m)
        C_Tren[0][i]=C_Duoi[n+1][i]=-inf ; 

    FOR(k,1,K)
    {
        int pre = (k-1)&1 ;
        FOR(i,1,n)FOR(j,1,m)
        {
            H_Trai[i][j]=max(f[i][j][pre],H_Trai[i][j-1]);
            C_Tren[i][j]=max(f[i][j][pre],C_Tren[i-1][j]);
        }
        FORD(i,n,1)FORD(j,m,1)
        {
            H_Phai[i][j]=max(f[i][j][pre],H_Phai[i][j+1]);
            C_Duoi[i][j]=max(f[i][j][pre],C_Duoi[i+1][j]); 
        }
        int cur = k&1 ; 
        FOR(j,1,m)FOR(i,1,n)
        {
            f[i][j][cur] = max({H_Trai[i][j-1],C_Tren[i-1][j],H_Phai[i][j+1],C_Duoi[i+1][j]});
            FOR(t,1,3)
            {
                int ii = i+xx[t] ; 
                maxi(f[i][j][cur],f[ii][j-1][cur]);
            }
            f[i][j][cur]+=a[i][j] ; 
        }
        FOR(i,1,n)
            maxi(res,f[i][m][cur]);
    }
    cout<<res; 
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