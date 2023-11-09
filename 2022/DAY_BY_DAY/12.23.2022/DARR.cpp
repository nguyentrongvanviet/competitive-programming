#include<bits/stdc++.h>
using namespace std;
#define TASK "DARR"
const bool multitest = false;

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second

#define pb push_back
#define pk pop_back
#define all(a) a.begin(),a.end() 
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   

#define print(a) for(auto  v: a )cout<<v<<" ";
#define fora(a) for(auto v: a )

ll sq(ll a ){return a*a;}
ll gcd(ll a, ll b )  {return b==0 ? a:gcd(b,a%b);}
ll lcm(ll a , ll b ){ return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
}
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ,k ; 
ll a[N] , s[N] ; 
ll pre[N], cur[N] ; 
void tinh(int l ,int r, int optl , int optr,int j )
{
	if(l>r)return ; 
	int mid =(l+r)/2; 
	ll ans=  -inf ; 
	int pos =  0 ; 
	FOR(i,optl , min(mid,optr))	
	{
		ll value= pre[i-1]+(s[mid]-s[i-1])*j;
		if(ans<value)
		{
			ans= value ; 
			pos = i ; 
		}
	}
	cur[mid] = ans ; 
	tinh(l,mid-1,optl,pos,j); 
	tinh(mid+1,r,pos,optr,j);
}
ve<ll>q; 
void doc()
{
	cin>> n >> k;
	FOR(i,1,n)cin>>a[i] ; 
	FORD(i,n,1)
	{
		s[i] = s[i+1]+a[i] ; 
		q.pb(s[i]) ; 
	}
	ll res= s[1] ; 
	q.pk() ;
	sort(all(q),greater<ll>()); 
	FORN(i,0,k-1)
	{
		res+=q[i] ; 
	}
	cout<<res;
}
void xuly()
{
    
}
signed main()
{
    IOS();
    int test= 1;
    if(multitest)cin>>test; 
    while(test--)
    {
        doc() ;  
        xuly() ;  
    }
}