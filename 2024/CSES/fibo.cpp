/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


struct MT
{
    int n , m; 
    ve<vll> mt ; 
    MT(int _n=0, int _m=0)  
    {
        n = _n ;
        m = _m ; 
        mt=ve<vll>(n+1,vll(m+1,0)); 
    }
};
MT mul(MT A , MT B )
{   
    int n = A.n ;
    int m = B.m ; 
    MT ans(n,m) ; 
    FOR(i,1,n)
        FOR(j,1,m)
            FOR(k,1,A.m)
                ans.mt[i][j]=(ans.mt[i][j]+A.mt[i][k]*B.mt[k][j]%sm)%sm;
    return ans ;
}
MT pw(MT A , ll n)
{
    if(n==1)return A ; 
    MT B = pw(A,n/2) ;
    if(n&1)return mul(mul(B,B),A) ; 
    return mul(B,B) ; 
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    ll n ; 
    cin>>n; 
   	if(n==0)
   	{
   		cout<<0<<el; 
   		return 0 ; 
   	}
    MT A(1,2) ; 
    A.mt[1][2] =  1 ; 
    MT B(2,2) ; 
    B.mt[1][1] = 0 ; 
    B.mt[1][2] = 1 ; 
    B.mt[2][1] = 1 ; 
    B.mt[2][2] = 1 ; 
    B = pw(B,n) ; 
    A = mul(A,B) ; 
    cout<<A.mt[1][1]<<el;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



