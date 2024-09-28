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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
int iscave[N] ;
int rat[N][N],cat[N][N] ;

void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>iscave[i]; 
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            cin>>rat[i][j] ; 
        }
    }
}
namespace sub1
{
    struct DL
    {
        int u , v , is_rat , dis ; 
    } ; 
    struct cmp
    {
        bool operator()(const DL&a , const DL&b)const
        {
            return a.dis>b.dis ; 
        }
    }; 
    int f[N][N][2]; 
    int sl[N][N] ; 
    int ke[N] ;
    void xuly()
    {
        FOR(i,1,n)
        {
            int ok = 0 ; 
            FOR(j,1,n)if(rat[i][j])
            {
                FOR(k,1,n)
                {
                    cat[i][k]|=rat[j][k] ;
                    ok+=cat[i][k];
                }
            }
            if(ok==0)cat[i][i] = 1; 
        }
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(rat[i][j])
                {
                    ke[i]++ ;
                }
            }
            if(ke[i]==0)
            {
                ke[i] = 1; 
                rat[i][i] = 1 ;
            }
        }
        FOR(i,1,n)FOR(j,1,n)
        {
            sl[i][j] = ke[i] ; 
        }
        priority_queue<DL,vector<DL>,cmp> q;
        FOR(i,1,n)FOR(j,1,n)
        {
            f[i][j][0] = f[i][j][1] = -1 ; 
        } 
        FOR(i,1,n)
        {
            if(iscave[i])
            {
                FOR(j,1,n)
                {
                    f[i][j][0] = oo ; 
                    q.push({i,j,0,f[i][i][0]}) ; 
                }
            }   
            else
            {
                f[i][i][0] = 0 ;
                q.push({i,i,0,f[i][i][0]}) ;
            }
        }   
        while(!q.empty())
        {
            auto [u,v,ok,val] = q.top() ;
            // cout<<u<<" "<<v<<" "<<ok<<" "<<val<<el; 
            q.pop() ; 
            if(f[u][v][ok]!=val)continue ;
            if(ok==0)
            {
                FOR(t,1,n)if(cat[t][v]&&f[u][t][1]==-1)
                {
                    q.push({u,t,1,f[u][t][1]=min(oo,val+1)}) ; 
                }
            }
            else
            {
                FOR(t,1,n)if(rat[t][u]&&f[t][v][0]==-1)
                {
                    sl[t][v]--;
                    if(sl[t][v]==0||val==oo)
                    {
                        q.push({t,v,0,f[t][v][0]=min(val+1,oo)});
                    }
                }
            }
        }
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                // cout<<f[i][j][0]<<" ";
                if(f[i][j][0]==oo||f[i][j][0]==-1)
                {
                    cout<<-1<<" ";
                }
                else
                {
                    cout<<f[i][j][0]/2<<" ";
                }
            }
            cout<<el;
        }
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}