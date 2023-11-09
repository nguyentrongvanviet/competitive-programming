#define TASK "QUEUE"
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
const int N =1e6+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n; 
vi value ;
int a[N] ,b[N] , c[N] ; 
unordered_map<int,int>pos; 
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i],value.pb(a[i]) ; 
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin());
	FOR(i,1,n)
	{
		pos[value[i-1]] =i ; 
	}
	FOR(i,1,n)a[i] = pos[a[i]]; 
}
int bit[N] ;
void up(int idx , int val)
{
	for(int i=idx;i<=n;i+=i&-i)
	{
		bit[i]+=val; 
	}
}
int get(int idx )
{
	int ans =0 ; 
	for(int i= idx;i;i-=i&-i)
	{
		ans+=bit[i] ; 
	}
	return ans; 
}
void up2(int idx,int val)
{
	for(int i= idx;i<=n;i+=i&-i)
	{
		bit[i]=max(bit[i],val) ; 
	}
}
int get2(int idx )
{
	int ans= 0 ; 
	for(int i=idx;i;i-=i&-i)
	{	
		ans=max(ans,bit[i]) ; 
	}
	return ans; 
}
pii ma[N] ; 
void solve()
{	
	for(int  i=n ;i>=1;i--)
	{
		b[i] = get(a[i]-1); 
		up(a[i],1) ; 
	}
	FOR(i,1,n)bit[i] =0 ;  
	for(int i= 1;i<=n;i++)
	{
		c[i] = get(n)-get(a[i]);
		up(a[i],1) ;
	}	
	// FOR(i,1,n)cout<<b[i]<<" "<<c[i]<<el;
	int ans= 0 ; 
	int u = 0 , v = 0 ;
	FOR(i,1,n)bit[i] = 0  ;
	FORD(i,n,1)
	{
		int g = b[i] +get2(a[i]-1);
		if(ans<g)
		{
			ans =g ; 
			u =  i; 
		}
		up2(a[i],c[i]);
	}
	if(ans==0)return void(cout<<-1<<" "<<-1);  
	cout<<u<< " " ; 
	for(int i= 1 ;i<=n;i++)
	{
		if(i==u)
		{
			for(int j = i+1;j<=n;j++)
			{
				if(c[j]==ans-b[u])
				{
					cout<<j ; return ;
				}	
			}
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