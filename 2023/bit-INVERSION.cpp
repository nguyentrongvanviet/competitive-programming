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
 
const int N = 2e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;
int n,q;
string S; 
int a[N];
struct DL
{
	int pre,suf,maxsum,len;
};
DL st_1[4*N],st_0[4*N];
DL merge(DL x,DL y)
{
	DL ans;
	if(x.pre == x.len) ans.pre = x.len + y.pre;
	else ans.pre = x.pre;
	if(y.suf == y.len) ans.suf = y.len + x.suf;
	else ans.suf = y.suf;

	ans.maxsum = max({x.pre,y.suf,x.suf + y.pre,x.maxsum,y.maxsum});
	ans.len = x.len + y.len;
	return ans;
}
void build(int id,int l,int r,DL w[],bool bit)
{
	if(l==r)
	{
		if(a[l] == bit) w[id] = {1,1,1,1};
		else w[id] = {0,0,0,1};
		// cout<<l<<" "<<r<<" "<<w[id].maxsum<<" "<<w[id].pre<<" "<<w[id].suf<<endl;
		return;
	}
	int mid = (l+r)>>1;
	build(id*2,l,mid,w,bit);
	build(id*2+1,mid+1,r,w,bit);
	w[id] = merge(w[id*2],w[id*2+1]);
	// cout<<l<<" "<<r<<" "<<w[id].maxsum<<" "<<w[id].pre<<" "<<w[id].suf<<endl;
}
void update(int id,int l,int r,int pos,int val,DL w[])
{
	if(l>pos||r<pos) return;
	if(l==r&&l==pos)
	{
		if(val == -1) w[id] = {0,0,0,1};
		else w[id] = {1,1,1,1};
		// cout<<l<<" "<<r<<" "<<w[id].maxsum<<" "<<w[id].pre<<" "<<w[id].suf<<endl;
		return;
	}
	int mid = (l+r)>>1;
	update(id*2,l,mid,pos,val,w);
	update(id*2+1,mid+1,r,pos,val,w);
	w[id] = merge(w[id*2],w[id*2+1]);
	// cout<<l<<" "<<r<<" "<<w[id].maxsum<<" "<<w[id].pre<<" "<<w[id].suf<<endl;
}
void doc()
{
	cin>>S;
	int n = S.size();
	S = "#" + S;
	for(int i=1;i<=n;i++)
	{
		a[i] = S[i] - '0';
	}
	cin>>q;
	build(1,1,n,st_0,0);
	build(1,1,n,st_1,1);
	for(int i=1;i<=q;i++)
	{
		int x; cin>>x;
		int w = a[x];
		if(w == 1)
		{
			update(1,1,n,x,-1,st_1);
			// cout<<endl;
			update(1,1,n,x,1,st_0);
			a[x] = 0;
			cout<<max(st_1[1].maxsum,st_0[1].maxsum)<<" ";
		}
		else
		{
			update(1,1,n,x,-1,st_0);
			update(1,1,n,x,1,st_1);
			a[x] = 1;
			cout<<max(st_1[1].maxsum,st_0[1].maxsum)<<" ";
		}
		// cout<<endl;
		// for(int j=1;j<=n;j++) cout<<a[j];
		// cout<<endl;
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