#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
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
const int N = 8e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int k ; 
char a[2*N] ; 
int st[2*N] ; 
void doc()
{
	cin>> k; 
	FORD(i,(1<<k)-1,1)cin>>a[i];
}
void build(int l , int r ,int id )
{
	if(l==r)
	{
		st[id] =1 ;
		return ;  
	}
	int mid = (l+r)/2 ;
	build(l,mid,id*2+1) ; 
	build(mid+1,r,id*2);
	if(a[id]=='?')st[id] = st[id*2]+st[id*2+1];
	else if(a[id]=='0')st[id] = st[id*2+1]; 
	else st[id] = st[id*2] ; 
}
void update(int id )
{
	if(a[id]=='?')st[id] = st[id*2]+st[id*2+1];
	else if(a[id]=='0')st[id] = st[id*2+1]; 
	else st[id] = st[id*2] ; 
	if(id!=1)update(id/2);
}
void xuly()
{
	int q ; 
	cin>>q ;
	build(1,1<<k,1);
	while(q--)
	{
		int c ; char q ; cin>>c>>q;
		c= (1<<k)-c; 
		a[c] = q; 
		// cout<<c<<"\n";
		update(c) ; 
		cout<<st[1]<<el;
	}
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
}