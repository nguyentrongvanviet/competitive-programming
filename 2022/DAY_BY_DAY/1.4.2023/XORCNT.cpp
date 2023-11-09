#define TASK "XORCNT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
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
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';

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

const int N =1e5+5, maxN=20, oo = 2e9, CH = 26 ;
const int B = sqrt(N);   
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , q; 
int a[N] ; 
struct DL
{
	unordered_map<int,int>sl ; 
	int s= 0; 
};
DL A[N] ; 
void read()
{
	cin>> n >>q ; 
	FORN(i,0,n)cin>>a[i] ; 
}
void up(int idx)
{
	A[idx].s= 0 ; 
	A[idx].sl.clear(); 
	int l  =  (idx-1)*B;  
	FOR(i,l,min(n,l+B-1))
	{
		A[idx].s^=a[i] ; 
		A[idx].sl[A[idx].s]++;
	}
}
int get(int r ,int val)
{
	int ans= 0  ; 
	int sum = 0 ;  
	FOR(i,1,r/B)
	{
		if(A[i].sl.count(val^sum))ans+=A[i].sl[val^sum] ; 
		sum^=A[i].s ;
	}
	int l  = r/B+1;
 	FOR(i,(l-1)*B,r)
	{
		sum^=a[i] ; 
		if(sum==val)ans++; 
	}	
	return ans; 
}
void solve()
{
	FORN(i,0,n)
	{
		A[i/B+1].s^=a[i];
		A[i/B+1].sl[A[i/B+1].s]++;
	}
	while(q--)
	{
	 	int t; cin>>t ; 
	 	if(t==1)
	 	{
	 		int pos , val; cin>>pos>>val ;
	 		--pos ; 
	 		a[pos] = val;   
	 		up(pos/B+1) ; 
	 	}
	 	else
	 	{
	 		int r, val; cin>>r>>val;
	 		--r; 
	 		int ans = get(r,val); 
	 		cout<<ans<<el;
	 	}
	}
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