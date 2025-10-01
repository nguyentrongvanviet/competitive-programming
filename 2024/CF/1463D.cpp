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
int n ; 
int a[N] , b[N] ; 
int Left[N] , Right[N] ; 
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

    int test ;cin>>test ;
    while(test--)
    {
    	int n; 
    	cin>> n; 
    	vi dd(2*n+1,0) ;
    	FOR(i,1,n)cin>>a[i] , dd[a[i]]=1;

    	// build b 
    	int cnt = 0  ; 
    	FOR(i,1,2*n)if(dd[i]==0)
    	{
    		b[++cnt]  = i ;  
    	}
    	// build mi[i] - i and  	
    	FOR(i,1,n)
    	{
    		int l =1 ; 
    		int r = n ; 
    		int ans = n+1; 
    		while(l<=r)
    		{
    			int mid =(l+r)>>1 ; 
    			if(a[i]<b[mid])
    			{
    				ans=mid ; 
    				r=mid-1 ; 
    			}
    			else if(a[i]>b[mid])
    			{
    				l=mid+1 ;
    			}
    			else abort() ; 
    		}
    		Left[i] = ans-i ; 
    		l = 1 ; 
    		r = n ; 
    		ans = 0 ; 
    		while(l<=r)
    		{
    			int mid = (l+r)>>1; 
    			if(a[i]>b[mid])
    			{
    				ans=mid ; 
    				l=mid+1 ; 
    			}
    			else r=mid-1 ; 
    		}
    		Right[i] = ans-i; 
    	}
    	FOR(i,1,n)
    	{
    		maxi(Left[i],Left[i-1]) ; 
    	}
    	Right[n+1]=n;
    	FORD(i,n,1)
    	{
    		mini(Right[i],Right[i+1]) ; 
    	}
    	// cout<<Right[1]<<el;
    	int res = 0 ;
    	FOR(x,0,n)
    	{
    		// cout<<Left[x]<<" "<<Right[x+1]<<el;
    		// if(1<=x&&x<=3)
    		// {
    		// 	cout<<Left[x]<<" "<<Right[x+1]<<el;
    		// }
    		res+=Left[x]<=n-x&&Right[x+1]>=-x ; 
    	}
    	cout<<res<<el;
    }



    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



