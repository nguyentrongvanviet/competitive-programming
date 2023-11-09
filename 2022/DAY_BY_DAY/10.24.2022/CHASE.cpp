#define TASK "CHASE"
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

const int N =2e5+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct DL
{
	db x ,t; 
	bool operator<(const DL&a)const
	{
		return x<a.x; 
	}
};  
int n ,k ; 
DL a[N] ; 
db s; 	
db V1 ,V2 ; 
void read()
{
	cin>> n >> k; 
	cin>>V1>>V2 ; 
	cin>>s;
	FOR(i,1,n)cin>>a[i].x>>a[i].t ;
}

void solve()
{
	if(s==0)return void(cout<<0);
	if(V1>=V2)return void(cout<<"inf");
	sort(a+1,a+n+1) ; 

	int it= n+1; 
	FOR(i,1,n)if(a[i].x>=s){it=i;break;}
	priority_queue<ll>q;	
	db d = s; 
	while(it<=n)	
	{
		while(k&&!q.empty()&&d/(V2-V1)<=(a[it].x-s)/V1)
		{
			d+=q.top()*V2;
			q.pop();
			--k ;
		} 
		if(d/(V2-V1)<=(a[it].x-s)/V1)break;  
		q.push(a[it].t);
		++it; 
	}
	while(k&&!q.empty())
	{
		d+=q.top()*V2;
		q.pop() ; 
		--k;
	}
	cout<<setprecision(10)<<fixed;
	db res=  d/(V2-V1);
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