#define TASK "ANT"
#include<bits/stdc++.h>
using namespace std;

const bool multitest = false;
#define int long long 
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
#define fora(v,a) for(auto v: a )

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
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct ANT
{
	int x , w, t;  
	bool operator<(const ANT& a)const
	{
		return x<a.x; 
	}
};
int n , L , q ;
ANT a[N] ; 
ll s[N] ; 
pll ans[N]; 
void doc()
{
	cin>> n >>L>>q; 
	FOR(i,1,n)cin>>a[i].x>>a[i].w>>a[i].t; 
}

void solve()
{
	vi  go0 ; 
	vi  goL ; 
	FORD(i,n,1)if(a[i].t==0)go0.pb(i) ; 
	FOR(i,1,n)
	{
		if(a[i].t==1)
		{
			goL.pb(i) ; 
			int x= goL.size() ; 
			int y =go0.size() ;
			if(y==0)ans[i] = {L-a[i].x,a[i].w} ;
			else 
			{
				if(x<=y)ans[i]={a[go0[y-x]].x,a[i].w};
				else ans[i]={L-a[goL[x-y-1]].x,a[i].w};
			}
		}
		if(a[i].t==0)
		{
			int x= goL.size() ; 
			int y =go0.size() ;
			if(x==0)ans[i]={a[i].x,a[i].w};
			else 
			{
				if(y<=x)ans[i] = {L-a[goL[x-y]].x,a[i].w}; 
				else ans[i] = {a[go0[y-x-1]].x,a[i].w} ;
			}
			go0.pk() ; 	
		}
	}
}
int tknp(ll val)
{
	int pos =0 ; 
	int l =1 ;
	int r =n ;
	while(l<=r)
	{
		int mid =(l+r)/2;
		if(ans[mid].fi<=val)pos=mid,l=mid+1; 
		else r=mid-1;
	}
	return pos ;
}
void xuly()	
{
	sort(a+1,a+n+1); 	
	solve();
	// FOR(i,1,n)cout<<ans[i].fi<<" ";cout<<endl;
	sort(ans+1,ans+n+1);
	
	FOR(i,1,n)s[i] =s[i-1]+ans[i].se;  
	while(q--)
	{
		ll t;  cin>>t ;
		int ans = tknp(t) ; 
		cout<<s[ans]<<' ';
	}
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