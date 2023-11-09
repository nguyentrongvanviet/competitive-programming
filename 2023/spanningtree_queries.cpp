#define TASK "text"
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
#define int ll
const int N = 1000, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n,m;
struct BG
{
	int u,v,w;
};
BG edg[N];
vector<int> new_edg,chest_sum,chest_cnt,chest_pre;
int par[N],sz[N];
int getpar(int u)
{
	if(u == par[u]) return u;
	return par[u] = getpar(par[u]);
}
void doc()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		edg[i]={u,v,w*2};
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			new_edg.pb((edg[i].w + edg[j].w)/2);
		}
	}
	new_edg.pb(0);
	sort(new_edg.begin(),new_edg.end());
	new_edg.resize(unique(all(new_edg)) - new_edg.begin());
	for(auto w : new_edg)
	{
		for(int i=1;i<=n;i++)
		{
			par[i] = i;
			sz[i] = 1;
		}
		sort(edg+1,edg+m+1,[&](BG x,BG y){
			int u = abs(w - x.w);
			int v = abs(w - y.w);
			if(u!=v) return u < v;
			return x.w > y.w;
		});
		int sum = 0,cnt =0 ;
		for(auto u : edg)
		{
			int r1 = getpar(u.u), r2 = getpar(u.v);
			if(r1 != r2)
			{
				if(r1 > r2) swap(r1,r2);
				par[r1] = r2;
				sz[r2] += sz[r1];
				sum += abs(u.w - w);
				cnt += w < u.w;
			}
		}
		chest_sum.pb(sum);
		chest_cnt.pb(cnt);
		chest_pre.pb(w);
	}
	int p,k,a,b,c,x = 0,res = 0;
	cin>>p>>k>>a>>b>>c;
	for(int i=1;i<=k;i++)
	{
		if(i<=p)
		{
			cin>>x;
		}
		else
		{
			x = (x*a + b)%c;
		}
		int j = upper_bound(new_edg.begin(),new_edg.end(),2*x) - new_edg.begin() - 1;
		int sum = chest_sum[j],cnt = chest_cnt[j],pre = chest_pre[j];
		res ^= (sum + (n - 1 - cnt)*(2*x - pre) - cnt*(2*x - pre))/2;
	}
	cout<<res;
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