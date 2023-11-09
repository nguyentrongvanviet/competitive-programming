#define TASK "TENNIS"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
// tct bool mini(Tx& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e6+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n;
int a[N];
struct cmp
{
	bool operator() (pii x,pii y)
	{
		return x<y;
	}
};
vector<int> g[N];
queue<int> q;
priority_queue<pii,vector<pii>,cmp> H;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		H.push({a[i],i});
	}
	while(!H.empty())
	{
		int u = H.top().fi;
		int id = H.top().se;
		int cnt = u;
		// cout<<u<<" "<<id<<endl;
		H.pop();
		while(!H.empty()&&cnt>0)
		{
			g[id].pb(H.top().se);
			q.push(H.top().se);
			a[H.top().se]--;
			H.pop();
			cnt--;
		}

		while(!q.empty())
		{
			// cout<<a[q.front()]<<" ";
			if(a[q.front()] != 0)H.push({a[q.front()],q.front()});
			q.pop();
		}
		// cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto v : g[i]) cout<<v<<" "<<i<<'\n';
	}
}

void xuly()
{

}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}