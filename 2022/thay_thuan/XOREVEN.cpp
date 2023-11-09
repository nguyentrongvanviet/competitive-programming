#define TASK "XOREVEN"
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
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct DL
{
	int sum , mil=oo , mal=-oo , mic=oo , mac=-oo ; 
};
int n , q; 
int a[N] ;
DL st[4*N] ;
DL merge(DL a, DL b)
{
	if(btpc(a.sum)&1)
	{
	 	swap(b.mil,b.mic); 
	 	swap(b.mal,b.mac);
	}
	DL ans ; 
	ans.sum = ( a.sum^b.sum );
	ans.mil = min(a.mil,b.mil);
	ans.mal = max(a.mal,b.mal) ; 
	ans.mic = min(a.mic,b.mic) ; 
	ans.mac = max(a.mac,b.mac) ; 
	return ans ; 
}
void update(int id ,int l ,int r , int pos , int val)
{
	if(l==r&&l==pos)
	{
		if(btpc(val)%2==0)st[id] ={val,oo,-oo,l,l};
		else st[id]={val,l,l,oo,-oo};
		return ; 
	}
	int mid =(l+r)/2; 
	if(pos<=mid)update(id*2,l,mid,pos,val) ; 
	else update(id*2+1,mid+1,r,pos,val) ; 
	st[id] = merge(st[id*2],st[id*2+1]) ; 
}
void read()
{	
	cin>> n >>q ; 
	update(1,0,n,0,0);
	FOR(i,1,n)cin>>a[i] , update(1,0,n,i,a[i]) ; 
	FOR(i,1,q)
	{
		int pos ,val ; cin>>pos>>val; ++pos ; 
		a[pos] = val ; 
		update(1,0,n,pos,val) ;
		int res= 0  ;
		int mil =st[1].mil;
		int mal= st[1].mal;
		int mic = st[1].mic; 
		int mac = st[1].mac;
		if(mil!=oo&&mal!=-oo)res=max(res,mal-mil) ;
		if(mic!=oo&&mac!=-oo) res=max(res,mac-mic); 
		cout<<res<<" ";
	}
	cout<<el;
}	

void solve()
{

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