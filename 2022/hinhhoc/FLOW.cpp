#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n,k;
ll a[N],s[N],f[N],t[N*4];
void read()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
}
void update(int id,int l,int r,int d,int c,ll val){
	if(l>r) return ;
	if(l>c || r<d) return;
	if(d<=l&&r<=c){
		t[id] = val;
		return;
	}
	int mid = (l+r)/2;
	update(id*2,l,mid,d,c,val);
	update(id*2+1,mid+1,r,d,c,val);
	t[id] = max(t[id*2],t[id*2+1]);
}
ll get(int id,int l,int r,int d,int c){
	if(l>r) return  -1e17;
	if(l>c || r<d) return -1e17;
	if(d<=l&&r<=c){
		return t[id];
	}
	int mid = (l+r)/2;
	return max(
		get(id*2,l,mid,d,c),
		get(id*2+1,mid+1,r,d,c)
	);
}
void solve()
{
	ll res =0 ;
	for(int i=1;i<=k;i++){
		f[i] = f[i-1] + a[i];
		update(1,0,n,i,i,f[i] - s[i+1]);
	}
	update(1,0,n,0,0,-s[1]);
	for(int i=k+1;i<=n;i++){
		f[i] = s[i] +  get(1,0,n,i-k-1,i-1);
		// for(int j=max(1,i-k);j<=i;j++) f[i] = max(f[i] , f[j-1] + s[i] - s[j]);
		update(1,0,n,i,i,f[i] - s[i+1]);
		res = max(res,f[i]);
	}
	cout<<res;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}