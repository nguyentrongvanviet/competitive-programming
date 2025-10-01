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
const int N = 2e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

ll fac[N] , ifac[N] ;
ll C(int k ,int n)
{
	if(k<0||k>n)return 0 ; 
	return fac[n]*ifac[k]%sm*ifac[n-k]%sm ;
}
ll ways(int x ,int y ,int len)
{
	if((len+x-y)&1)return 0 ; 
	return C((len+x-y)/2,len)  ; 
}
ll cal(int pos ,int len)
{
	return (ways(pos,0,len)-ways(pos,-2,len)+sm)%sm;
}
ll pw(ll a, ll n)
{
	if(n==0) return 1;   
	ll b = pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm ;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
    int n; 
    cin>> n;  
    string s; 
    cin>>s;  
    int start = 0 ; 
    for(auto x:s)
    {
        if(x=='(')
        {
            start++ ; 
        }
        else
        {
            start-- ;
            if(start<0)
            {
                cout<<0<<el; 
                return 0 ;
            }
        }
    }
    fac[0] = 1 ; 
    FOR(i,1,2e6)fac[i] = fac[i-1]*i%sm ;
    ifac[int(2e6)] = pw(fac[int(2e6)],sm-2) ; 
    FORD(i,2e6-1,0)ifac[i] = ifac[i+1]*(i+1)%sm; 
    cout<<cal(start,n-s.size())<<el;

    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



