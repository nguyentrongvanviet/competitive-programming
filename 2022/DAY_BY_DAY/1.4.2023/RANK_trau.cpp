#define TASK "RANKING"
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
const db PI = acos(-1) ,eps=1e-9; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct line
{
	db a , b;
	db val(db x)
	{
		return x*a+b ; 
	} 
}; 
int n ; 
line L[N] ;
pii res[N] ; 
ve<pair<double,int>>q;  
void read()
{
	cin>>  n ;
	FOR(i,1,n)cin>>L[i].a>>L[i].b,L[i].b=-L[i].b; 
}
void GD(int i , int idx)
{		
	db tu  = -(L[i].b-L[idx].b) ; 
	db mau = L[i].a-L[idx].a;  
	if(tu*mau<=0||abs(mau)<eps)return ;
	tu=abs(tu) ; 
	mau=abs(mau) ;  
	q.pb(make_pair(tu/mau,i));
}

int hi = 0 ;

void init(int idx)
{	
	db u = L[idx].val(1e-9);
	FOR(i,1,n)if(i!=idx)
	{
		db v = L[i].val(1e-9);
		if(abs(u-v)>eps)hi+= u<v;
	}
}	
void check(int idx)
{
	hi = 0  ; 
	q.clear() ; 
	FOR(i,1,n)if(i!=idx)GD(i,idx) ;
	sort(all(q)) ; 
	init(idx); 
	res[idx] = {hi,hi} ;
	int it=0 ; 
	while(it<q.size())
	{
		int j=  it; 
		int up  = 0 , down =0 ; 
		while(abs(q[j].fi-q[it].fi)<eps&&j<q.size())
		{
			int id =q[j].se; 
			if(L[idx].a>L[id].a)
			{
				down++;
			}
			else up++ ; 
			++j ; 
		}
		hi-=down ; 
		res[idx].fi=min(res[idx].fi,hi);
		hi+=up; 
		res[idx].se=max(res[idx].se,hi);
		it= j ;
	}
}
void solve()
{
	FOR(i,1,n)check(i);
	FOR(i,1,n)cout<<res[i].fi+1<<" "<<res[i].se+1<<el;
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