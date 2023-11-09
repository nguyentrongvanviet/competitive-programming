#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = false;
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
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
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
#define int long long 
int n =3 , m =3 ; 
int a[5][5] ;
int mu[N] ;
unordered_map<int,int>dd; 
int start ; 
int en ; 
void doc()
{	
	mu[0] = 1 ;
	FOR(i,1,9)mu[i] = mu[i-1]*10 ;
	n=3  ; 
	FOR(i,1,n)FOR(j,1,n)
	{
		int val;  cin>>val; 
		start+=val*mu[(i-1)*m+j];
	} 
	FOR(i,1,n)FOR(j,1,m)
	{
		en += ((i-1)*m+j)*mu[(i-1)*m+j];
	}
	cerr<<en<<el;
}	
void xuly()
{	
	queue<int>q; 
	dd[start] = 0 ; 
	q.push(start);
	while(!q.empty())
	{
		int tt = q.front() ; 		
		q.pop() ; 
		FOR(x,1,3)FOR(y,1,3)
		{
			int u = tt/(mu[(x-1)*m+y])%10;
			FOR(i,1,2)
			{
				int nx = x+xx[i] ; 
				int ny = y+yy[i] ; 
				if(1<=nx&&nx<=n&&1<=ny&&ny<=m)
				{
					int v= tt/mu[(nx-1)*m+ny]%10 ;
					// cerr<<u<<" "<<v<<" "<<x<<" "<<y<<" "<<nx<<" "<<ny<<el;
					int ntt = tt-u*mu[(x-1)*m+y]-v*mu[(nx-1)*m+ny]+v*mu[(x-1)*m+y]+u*mu[(nx-1)*m+ny];
					if(dd.find(ntt)==dd.end())dd[ntt] = dd[tt]+1,q.push(ntt);
					if(ntt==en)return void(cout<<dd[ntt]);
				}
			}
		}
		// return ; 
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
    cerr<<"Time: "<<clock()<<"ms"<<el;
}