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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
int cal(const string&s,char a, char b  )
{
    int mi = 0 , ma = 0 ; 
    int sum = 0 ;
    FORN(i,0,s.size())
    {
        if(s[i]==a)
        {
            sum-- ; 
            mini(mi,sum) ; 
        }
        else if(s[i]==b)
        {
            sum++ ; 
            maxi(ma,sum) ; 
        }
    }
    return ma-mi+1 ; 
}
ll solve(string s , char a , char b ,char u , char v )
{
    int res = oo ; 
    int mi = 0 ;
    int res_mi = 0 ;  
    int ma = 0 ; 
    int res_ma = 0;
    int sum = 0 ;
    int tmp = 0 , l = 0 , r = 0 ;  
    FORN(i,0,s.size())
    {
        if(s[i]==a)
        {
            sum--;  
            if(mini(mi,sum))
            {
                res_mi = i ;
            } 
            if(maxi(ma,sum))
            {
                res_ma = i ; 
            }
        }
        else if(s[i]==b)
        {
            sum++; 
            if(maxi(ma,sum))
            {
                res_ma = i ; 
            }
            if(mini(mi,sum))
            {
                res_mi = i ; 
            } 
        } 
        else if(s[i]==u)
        {
            tmp-- ;
            mini(l,tmp) ;
        }
        else 
        {
            tmp++ ;
            maxi(r,tmp) ;
        }
    }   
    if(res_mi==res_ma)
    {
        return (mi==ma?r-l+1:2*(r-l+1))  ;
    }
    // assert(res_ma!=-1&&res_mi!=-1) ; 
    if(res_mi<res_ma)
    {
        s.insert(s.begin() + res_ma, a) ;
        mini(res,cal(s,a,b)) ;
        s.erase(s.begin() + res_ma) ; 
        s.insert(s.begin() +  res_mi, b) ;
        mini(res,cal(s,a,b)) ;
    }
    else    
    {
        s.insert(s.begin() + res_mi,b) ; 
        mini(res,cal(s,a,b)) ;
        s.erase(s.begin() + res_mi) ;
        s.insert(s.begin() + res_ma,a) ; 
        mini(res,cal(s,a,b)) ; 
    }
    return 1ll*res*(r-l+1) ; 
}   
void doc()
{
    str s ; cin>>s ; 
    ll x = solve(s,'A','D','S','W') ; 
    ll y = solve(s,'S','W','A','D') ; 
    // cout<<x<<" "<<y<<el; 
    cout<<min(x,y)<<endl;
}

namespace sub1
{
    void xuly()
    {

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