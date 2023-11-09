#define TASK "NMIN"
#include<iostream>
// #include<conio.h>
using namespace std; 

bool multitest =  true ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =1e7+1 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
// const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int nt[N] ;
int f[N]; 
ll s[N] ;
void snt()
{
	for(ll i= 2;i<=(ll)1e7;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 
			for(ll j = i*i;j<=(ll)1e7;j+=i)
			{
				nt[j] =i ; 
			}
		}		
	}
}
int val;  
void read()
{	  
	cin>>val; 
	cout<<(f[val]==0?-1:f[val])<<el;
}
void solve()
{
	s[1] =1 ; 
	s[2] =3 ;  
	f[1] =1 ; 
	f[3] =2 ;
	FOR(i,1,(int)1e7)
	{
		int u  = nt[i] ; 
		int val = i ;
		ll res= u ;  
		while(val%u==0)
		{
			res*=u;
			val/=u;
		}
		res = (res-1)/(u-1)*s[val];
		s[i] = res;
		if(res>(ll)1e7)continue;
		if(f[res]==0||f[res]>i)
		{
			f[res]= i ;
		}
	}
	FORD(i,(int)1e7,1)cout<<s[i]<<el;
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    snt() ;
    solve() ;
    while(test--)
    {
        read() ; 
    }
}