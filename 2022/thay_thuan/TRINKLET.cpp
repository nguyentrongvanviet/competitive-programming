#define TASK "TRINKLET"
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
const int N = 1e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

vi pos[N] ; 
int id[N] ; 
int n , S ; 
int a[N] ; 
struct node
{
	int sum ;
	int ma ; 
};
node st[4*N] ;

void read()
{
	cin>> n >>S ; 
	FOR(i,1,n)cin>>a[i] , pos[a[i]].pb(i);
}

node merge(node a, node b)
{
	int sum = a.sum+b.sum ; 
	int ma = max(a.ma,a.sum+b.ma) ;
	return node{sum,ma};  
}
void update(int id , int l ,int r, int pos ,int val)
{
	if(l==r&&l==pos)
	{
		st[id] = {val,val}; 
		return ; 
	}
	int mid =(l+r)/2 ;
	if(pos<=mid)update(id*2,l,mid,pos,val) ; 
	else update(id*2+1,mid+1,r,pos,val) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
node get(int id, int l, int r , int t , int p )
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t)return node{st[id].sum,-oo} ;
	else if(p<l)return node{0,-oo}; 
	int mid=(l+r)/2; 
	return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)); 
}	
int cnt[N] ; 
void solve()
{
	int res=0 ; 
	for(int i =1 ;i<=n;i++)
	{
		cnt[a[i]]++ ; 
		if(cnt[a[i]]==S+1)
		{
			id[a[i]] =  S; 
			update(1,1,n,i,-S);
		}
		else if(cnt[a[i]]<=S)update(1,1,n,i,1);
		else update(1,1,n,i,0);
	}
	res=max(res,get(1,1,n,1,n).ma);
	FOR(i,2,n)
	{
		update(1,1,n,i-1,0);
		if(id[a[i-1]]!=0&&id[a[i-1]]<pos[a[i-1]].size())
		{
			update(1,1,n,pos[a[i-1]][id[a[i-1]]],1);
			// cout<<pos[a[i-1]][id[a[i-1]]]<<" "<<1<<el;
			// cout<<pos[a[i-1]][id[a[i-1]]]<<el;
			++id[a[i-1]];
			// cout<<pos[a[i-1]][id[a[i-1]]]<<el;
			// cout<<"___________"<<el;
			if(id[a[i-1]]<pos[a[i-1]].size()) update(1,1,n,pos[a[i-1]][id[a[i-1]]],-S);
		}
		res=max(res,get(1,1,n,i,n).ma); 
	}
	cout<<res<<el; 
}
void clear()
{
	FOR(i,1,(int)1e5)pos[i].clear(),id[i]=0,cnt[i]=0;
	FOR(i,1,4*n)st[i]=node{0,0}; 
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
        clear() ;
    }
}