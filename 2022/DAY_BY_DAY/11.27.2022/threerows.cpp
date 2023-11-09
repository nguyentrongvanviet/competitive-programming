#define TASK "threerows"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
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
#define vd cerr<<"---------------------------"<<el;
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v:a)cerr<<v<<" ";cerr<<" ]"<<el;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))freopen(INPUT ,"r",stdin),freopen(OUTPUT,"w",stdout) ;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;
ll rd(ll l , ll r)
{
    return uniform_int_distribution<ll>(l,r)(rng);
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


struct DL
{
	int l , r ; 
	ll  w; 
};
int n , m ; 
ll a[4][N] ;
DL q[N] ; 
int ok1= 1 ; 
void read()
{
	cin>> n >>m ; 
	FOR(i,1,3)FOR(j,1,n)cin>>a[i][j] ; 
	FOR(i,1,m)
	{
		int l , r; 
		ll  val;  
		cin>>l>>r>>val; 
		if(val)ok1=0 ; 
		q[i]= {l,r,val};
	}
}

void solve()
{

}
void sub1()
{	
	vi ok(n+1,0) ; 
	ve<vll>f(4,vll(n+1,0)) ;
	for(int i =1 ;i<=m;i++)
	{
		int l = q[i].l; 
		int r = q[i].r ;
		ok[l]++ ; 
		ok[r]-- ;
	}
	for(int i=1 ;i<=n;i++)ok[i] +=ok[i-1] ;
	FOR(i,1,3)FOR(j,1,n)
	{
		if(i==1)f[i][j] = f[i][j-1]+a[i][j] ; 
		else if(i==2&&ok[j])
		{
			f[i][j] = max(f[i-1][j],(ok[j-1]?f[i][j-1]:-inf))+a[i][j] ; 
		}
		else
		{
			f[i][j] = max((j?f[i][j-1]:-inf),(ok[j]?f[i-1][j]:-inf))+a[i][j];
		}
	}
	cout<<f[3][n];
}
void sub2()
{
	ve<vll>f(n+1,vll(m+1,-inf)); 
	vll s1(n+1,0) ;
	vll s2(n+1,0) ; 
	vll s3(n+1,0) ;
	FOR(i,1,n)	{
		s1[i] =s1[i-1]+a[1][i]; 
		s2[i] =s2[i-1]+a[2][i] ;
		s3[i] =s3[i-1]+a[3][i];
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(q[j].l<=i&&i<=q[j].r)
			{
				f[i][j] = max(f[i][j],s1[i]+a[2][i]-q[j].w);
			}
		}
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(i<q[j].l||q[j].r<i)continue;
			FOR(ii,i+1,q[j].r)
			{
				f[ii][j] = max(f[ii][j],f[i][j]+s2[ii]-s2[i]);
			}
			for(int jj = 1 ;jj<=m;jj++)
			{
				int l = q[j].l;  
				int r = q[j].r;
				int nl = q[jj].l;
				int nr =q[jj].r; 
				if(r+1>=nl&&r<nr)
				{
					FOR(ii,r+1,nr)
					{
						f[ii][jj]=max(f[ii][jj],f[i][j]-q[jj].w+s2[ii]-s2[i]);
					}
				}
			}
			// cout<<i<<" "<<j<<" "<<f[i][j]<<el;
		}
	}
	ll res= -inf  ; 
	for(int i=1 ;i<=n;i++)
	{	
		for(int j =1 ;j<=m;j++)
		{
			res=max(res,f[i][j]+s3[n]-s3[i-1]);
		}
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
        if(ok1)
        {
        	sub1() ; 
        	return 0 ; 	
        }
        else sub2();
    }
}