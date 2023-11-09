#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 1;
 
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
// tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 5e3+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
ll n,x,y;
string X,Y;
vector<int> tt;
ll f[N][N],h[N][N],a[N];
void doc()
{
	tt.clear();
	cin>>n>>x>>y;
	cin>>X;
	X = "#" + X;
	cin>>Y;
	Y = "#" + Y;
	for(int i=1;i<=n;i++)
	{
		if(X[i] != Y[i]) tt.pb(i);
		int u = X[i] - '0';
		int v = Y[i] - '0';
		a[i] = u^v;
	}
	if(tt.size()%2 == 1)
	{
		cout<<-1<<'\n';
		return;
	}
	else if(tt.size() == 2)
	{
		if(tt[1] - tt[0] == 1)
		{
			cout<<min(y*2,x)<<'\n';
		}
		else
		{
			cout<<min(x*(tt[1] - tt[0]) , y)<<'\n';
		}
	}
	else if(tt.size() == 0|| x >= y)
	{
		cout<<tt.size()/2*y<<'\n';
	}

	else
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=i+1;j++)
			{
				f[i][j] = h[i][j] = inf;
			}	
		}

		if(a[1] == 0)f[1][0] = 0;
		if(a[1] == 1)h[1][1] = 0;

		for(int i = 2; i <= n; i++)
		{
			for(int j = i + 1; j >= 0; j--)
			{
				if(a[i])
				{
					if(j <= i)f[i][j] = min(f[i - 1][j + 1] + y, h[i - 1][j + 1] + x);
					if(j)
					{
						f[i][j] = min({f[i][j], f[i - 1][j - 1] + x, h[i - 1][j - 1] + y});
						h[i][j] = min(f[i - 1][j - 1], h[i - 1][j - 1]);
					}
				}
				else
				{
					
					f[i][j] = min(f[i - 1][j], h[i - 1][j]);
					h[i][j] = min(f[i - 1][j] + y, h[i - 1][j] + x);
					if(j > 1)h[i][j] = min({h[i][j], f[i - 1][j - 2] + x, h[i - 1][j - 2] + y});
				}
			}
		}
		cout<<f[n][0]<<'\n';
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