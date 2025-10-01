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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q ; 
ll st[4*N] ;
int a[3][N]  , val[3][N] ; 
void build(int id ,int l, int r)
{
	if(l==r)
	{
		st[id] = min(val[1][l],val[2][l]) ;
		return ; 
	}
	int mid = (l+r)>>1 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = st[id<<1]*st[id<<1|1]%sm ; 
}
void up(int id ,int l ,int r , int type ,int pos )
{
	if(l==r&&l==pos)
	{
		val[type][pos]++ ; 
		st[id] = min(val[1][l],val[2][l]) ; 
		return ; 
	}
	if(r<pos||pos<l)return ;
	int mid = (l+r)>>1 ; 
	up(id<<1,l,mid,type,pos);
	up(id<<1|1,mid+1,r,type,pos) ; 
	st[id] = st[id<<1]*st[id<<1|1]%sm ; 
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
    int test ; cin>>test  ;
    while(test--)
    {
   		cin>> n >> q; 
   		FOR(j,1,2)
   		{
	   		FOR(i,1,n)
	   		{
	   			cin>>a[j][i] ;  
	   			val[j][i] = a[j][i] ; 
	   		}
   		}
   		FOR(i,1,2)sort(val[i]+1,val[i]+n+1) ; 
   		build(1,1,n) ; 
   		cout<<st[1]<<" ";
   		FOR(_,1,q)
   		{
   			int type , pos ; cin>> type>>pos ;
   			int l = 1 ; 
   			int r = n ;
   			int ans = 0 ;
   			while(l<=r)
   			{
   				int mid =(l+r)>>1; 
   				if(val[type][mid]<=a[type][pos])
   				{
   					ans=mid ; 
   					l=mid+1 ; 
   				}
   				else r=mid-1 ; 
   			}
   			a[type][pos]++;
   			up(1,1,n,type,ans) ; 
   			cout<<st[1]<<" ";
   		}
   		cout<<el;
    }


    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



