#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = true; 
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
#define int long long
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define viet first 
#define duyen second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
int n, m; 
ll a[N][11]; 
unordered_set<ll>exist[11];
int pos[N][20] ; 
void doc()
{
	cin>> n >> m; 
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			cin>>a[i][j] ;
			pos[i][a[i][j]]=j;  
		}
		ll val= 0 ; 
		FOR(j,1,m)
		{
			val=(val*cs+pos[i][j]); 
			exist[j].insert(val) ; 
		}
	}
	FOR(i,1,n)
	{
		int res= 0 ; 
		ll val = 0  ;
		FOR(j,1,m)
		{
			val=(val*cs+a[i][j]);
			if(exist[j].count(val))res=j ;
		}
		cout<<res<<" ";
	}
	cout<<el;
}	

void xuly()
{

}
void clear()
{
	FOR(i,1,m)exist[i].clear() ; 
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
        clear();
    }
    cerr<<"Time: "<<clock()<<"ms"<<el;
}