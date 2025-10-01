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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 5e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k ; 
int f[N][N];
int sumid[N][N] , summax[N][N]; 
// sum that fix the id index and sum that fix the max index 
void add(int& val ,int inc)
{
	val+=inc ; 
	if(val>=sm)val-=sm; 
}
int sumID(int id ,int l ,int r)
{
	if(l>r)return 0 ; 
	return (sumid[id][r]-(l-1<0?0:sumid[id][l-1])+sm)%sm;
}
int sumMAX(int max, int pos)
{
    if(pos<=0)return 0 ;
    int val = 0 ; 
    for(int i = pos;i;i-=i&-i)
    {
        add(val,summax[i][max]) ; 
    }
    return val;  
}
int sumMAX(int max, int l ,int r)
{
	if(l>r)return 0 ; 
    return (sumMAX(max,r)-sumMAX(max,l-1)+sm)%sm;
}
void buildid(int id)
{
    sumid[id][0] = f[id][0] ; 
    for(int i=1;i<=n;i++)
    {
        sumid[id][i] = (sumid[id][i-1]+f[id][i])%sm  ; 
    }
}
void buildmax(int id)
{
    for(int ma=1;ma<=n;ma++)
    {
        for(int pos = id;pos<=n;pos+=pos&-pos)
        {
            add(summax[pos][ma],f[id][ma]);
        }
    }
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

    cin>> n >> k; 
    f[0][0] = 1 ;
    sumid[0][0] = 1 ;
    buildid(0) ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j] = (sumID(i-j,0,j)+sumMAX(j,i-j+1,i-1))%sm; 
        }
        buildid(i) ; 
        buildmax(i) ; 
    }  
    int res = 0 ;  
    for(int i=1;i<=n;i++)
    {
        int t= min(n,k/i-(k%i==0)) ;
        add(res,f[n][i]*sumID(n,1,t)%sm);
    }
    cout<<(res*2)%sm<<endl;


    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



