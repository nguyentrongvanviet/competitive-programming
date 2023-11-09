#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = false;
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
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
#define btpcll(a) __builtin_popcountll(a);
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 60, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

ll val ; 
ll res= 0 ; 
int cnt =0 ; 
ll C[N][N] ;
void doc()
{
	cin>>val;  
	FOR(i,0,49)
	{
		C[i][0] = 1; 
		FOR(j,1,i)
		{
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}
	FORD(i,50,0)
	{
		if(val>>i&1)
		{
			// cerr<<i<<el;
			FOR(j,0,i)
			{
				res+=(cnt+j)*C[i][j];
			} 			
			// cerr<<res<<el;
			++cnt;
		}
	}
	res+=btpcll(val);
	cout<<res;
	res=0  ; 
	// FOR(i,1,val)res+=btpcll(i);
	// cerr<<res<<el;
}
void xuly()
{

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
    }
    cerr<<"Time: "<<clock()<<"ms"<<el;
}
// 1, 10, 11, 100, 101, 110, 111