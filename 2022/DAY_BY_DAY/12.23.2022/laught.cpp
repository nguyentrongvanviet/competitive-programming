#define TASK "text"
#include<bits/stdc++.h>
using namespace std;

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
#define el '\n' 
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define printv(a) for(auto v: a )cout<<v.fi<<" "<<v.se<<'\n';
#define print(a) for(auto  v: a )cout<<v<<" ";

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
const ll sm1 = 1e9+7,cs=38 ,inf = 1e17;
const ll sm2 = 1203871832;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , m; 
str s;
map<pll,ll>q[N];
vi value ;
pll ha[N] , mu[N] ; 
pll get_hash(ll l , ll r )
{
	return {(ha[r].fi - ha[l-1].fi*mu[r-l+1].fi%sm1+sm1*sm1)%sm1,(ha[r].se-ha[l-1].se*mu[r-l+1].se%sm2+sm2*sm2)%sm2};
}
int f[N] ; 
pll tohash(str s)
{
	ll val1 = 0 ;
	ll val2 = 0;
	FORN(i,0,s.size())
	{
		val1=val1*cs%sm1+s[i];
		val2=val2*cs%sm2+s[i];
		val1%=sm1;
		val2%=sm2; 
	} 
	return {val1,val2};
} 
void doc()
{
	cin>>  n; 
	cin>> s  ;
	FOR(i,1,n)
	{
		str x ; 
		cin>>x ;
		if(x.size()>s.size())continue ;
		q[x.size()][tohash(x)]=1 ; 
		value.pb(x.size());  
	}
	sort(all(value))  ; 
	value.resize(unique(all(value))-value.begin());
	n = s.size() ;
	s="#"+s;
	mu[0].fi=mu[0].se =1 ;
	FOR(i,1,n)mu[i].fi = mu[i-1].fi*cs%sm1, mu[i].se=mu[i-1].se*cs%sm2; 
	FOR(i,1,n)
	{
		ha[i].fi = ha[i-1].fi*cs%sm1+s[i];
		ha[i].se = ha[i-1].se*cs%sm2+s[i];
		ha[i].fi%=sm1;
		ha[i].se%=sm2;
	}
	int res=0  ;
	FOR(i,1,n)
	{	
		for(int j= 0 ; j<value.size();j++)
		{	
			if(value[j]>i)break;  
			if(q[value[j]].find(get_hash(i-value[j]+1,i))!=q[value[j]].end())
			{
				f[i] = max(f[i],f[i-value[j]]+value[j]);
			}
		}
		res=max(res,f[i]);
	}
	cout<<res;
}
void xuly()
{
 	FOR(i,1,n)
	{

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