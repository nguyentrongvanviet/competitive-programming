#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
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
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , m ; 
int dd[N] ;
vi value ;
void doc()
{
	cin>> n >>m ; 
	FOR(i,1,n)
	{
		int val; cin>>val; 
		value.pb(val) ;
		dd[val] =1 ; 
	}
}	
vi g[N] ; 
int cnt[N] ;
void xuly()
{
	FOR(i,1,m)
	{
		for(int j= i ;j<=(int)1e5;j+=i)
		{
			if(dd[j])g[j].pb(i);
		}
	}
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin());
	int thieu = m ;
	int l =0 ,r = 0 ;  
	while(thieu&&r<(int)value.size())
	{
		for(auto v : g[value[r]])
		{
			cnt[v]++;
			if(cnt[v]==1)thieu-- ; 
		}
		++r;
	}	
	if(thieu)return void(cout<<-1<<el);
	int res= value[r-1]-value[l] ;
	while(l<value.size())
	{
		for(auto v :g[value[l]])
		{
			cnt[v]-- ; 
			if(cnt[v]==0)thieu++ ;
		}
		while(thieu&&r<(int)value.size())
		{	
			for(auto v: g[value[r]])
			{
				cnt[v]++ ; 
				if(cnt[v]==1)thieu--;
			}
			++r;
		}
		if(thieu)break;	
		++l;
		res=min(res,value[r-1]-value[l]); 
	}
	cout<<res<<el;
}
void clear() 
{
	FOR(i,1,m)cnt[i]=0 ; 
	for(auto v : value)dd[v]= 0,g[v].clear() ;
	value.clear();
}
signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
        clear() ;
    }
}