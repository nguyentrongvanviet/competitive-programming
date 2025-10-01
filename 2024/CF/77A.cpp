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

ve<vi>like(7,vi(7,0)) ; 
int EXP[4]  ; 
int min_gap = oo ; 
int max_like = 0 ; 
int add(int msk , int j)
{
	int sum = 0 ; 
	FORN(i,0,7)if(msk>>i&1)
	{
		sum+=like[i][j]+like[j][i] ; 
	}
	return sum ; 
}
void solve(int boss ,int used, int msk,int mi ,int ma,int total_like)
{	
	if(used==(1<<7)-1)
	{
		if(boss==4)
		{
			if(mini(min_gap,ma-mi))
			{
				max_like = total_like;  
			} 
			else if(min_gap==ma-mi)
			{
				maxi(max_like,total_like) ; 
			}
		}
		return ; 
	} 
	if(msk)
	{
		solve(boss+1,used|msk,0,min(mi,EXP[boss]/btpc(msk)),max(ma,EXP[boss]/btpc(msk)),total_like) ; 
	}
	FORN(i,0,7)
	{
		if(!BIT(used,i)&&!BIT(msk,i))
		{
			solve(boss,used,msk|(1<<i),mi,ma,total_like+add(msk,i));
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
    int n; cin >> n; 
    ve<str> name = {"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal" };
    auto trans = [&](string s)->int
    {	
    	int t = 0 ; 
    	for(auto x : name)
    	{
    		if(x==s)return t ; 
    		++t ; 
    	}
    	assert(0) ; 
    	return 0 ; 
    } ; 
    FOR(i,1,n)
    {
    	string a , v , b ; cin>> a >> v >>b ; 
    	int x = trans(a) ; 
    	int y = trans(b) ; 
    	like[x][y] = 1;  
    }
    FOR(i,1,3)
    {
    	cin>>EXP[i] ; 
    }
    solve(1,0,0,oo,-oo,0) ;
    cout<<min_gap<<" "<<max_like<<el; 
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



