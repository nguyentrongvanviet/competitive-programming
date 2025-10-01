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

int res[9][9],cnt[9][9]  ;
bool check()
{
    FOR(i,1,8)FOR(j,1,8)if(res[i][j]==0)return 0 ; 
    return 1 ; 
}

void build(int x , int y)
{
    auto in = [](int x ,int y)->bool
    {
        return 1<=x&&x<=8&&1<=y&&y<=8;
    };
    FOR(i,1,8)FOR(j,1,8)res[i][j] = 0 ;   
    FOR(i,1,8)FOR(j,1,8)
    {
        FOR(u,-2,2)FOR(v,-2,2)if(sq(u)+sq(v)==5)
        {
            int nx = i+u ; 
            int ny = j+v ; 
            if(in(nx,ny))cnt[i][j]++ ; 
        }
    }
    int tt = 0 ; 
    while(1)
    {  
        res[x][y] = ++tt; 
        vector<pii>possible ;  
        FOR(u,-2,2)FOR(v,-2,2)if(sq(u)+sq(v)==5)
        {
            int nx = x+u ; 
            int ny = y+v ; 
            if(res[nx][ny]==0&&in(nx,ny))
            {
                cnt[nx][ny]--;
                if(!possible.empty()&&cnt[possible.back().fi][possible.back().se]>cnt[nx][ny])
                {
                    possible.clear() ; 
                } 
                if(possible.empty()||cnt[possible.back().fi][possible.back().se]==cnt[nx][ny])
                {
                    possible.pb(mp(nx,ny)) ; 
                }
            }
        }
        if(possible.empty())break; 
        int id = rd(0,possible.size()-1) ; 
        x = possible[id].fi ; 
        y = possible[id].se ;
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
    int x , y ; cin>>x>>y ; 
    swap(x,y) ; 
    while(check()==0)
    {
        build(x,y) ; 
    }
    FOR(i,1,8)
    {
        FOR(j,1,8)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<el;  
    }


    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



