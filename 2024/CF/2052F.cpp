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
    int test ; cin>>test ;
    while(test--)
    {
    	int n ; cin>> n; 
    	vi msk(n+1,0) ; 
    	FORN(i,0,2)
    	{
    		FOR(j,1,n)
    		{
    			char u ; cin>>u ; 
    			msk[j]|=((u=='#')<<i);
    		}
    	}
    	ve<vi> f(n+1,vi(1<<2,0)) ; 
    	f[0][3] = 1 ;
    	FOR(i,1,n)
    	{
    		int cur = msk[i]; 
    		if(cur==3)
    		{
    			f[i][3] = f[i-1][3] ;
    		}
    		else if(cur==0)
			{
				f[i][0] = f[i-1][3] ;
				f[i][1] = f[i-1][2] ;
				f[i][2] = f[i-1][1] ;  
				f[i][3] = f[i-1][3]+f[i-1][0] ; 
			}
			else if(cur==1)
			{
				f[i][1] = f[i-1][3] ; 
				f[i][3] = f[i-1][1] ; 
			}
			else if(cur==2)
			{
				f[i][2] = f[i-1][3] ; 
				f[i][3] = f[i-1][2] ; 
			}
			FORN(msk,0,3)
			{
				mini(f[i][msk],2) ; 
			}
    	}
    	if(f[n][3]==0)
    	{
    		cout<<"None"<<el;
    	}
    	else if(f[n][3]==1)
    	{
    		cout<<"Unique"<<el;
    	}
    	else cout<<"Multiple"<<el;
    }



    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



