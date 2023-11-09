#define TASK "WPRIME"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define int long long 
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
#define mp make_pair
#define el '\n'
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
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =1e6+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1000000, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
const int M  = 35*N; 
int n ,q ; 
ll s; 
ll sum = 0 ;
int nt[(int)1e6+5] ;
int head[N];
int L[M],R[M];
int st[M]; 
void snt()
{
	nt[1]= -1 ; 
	nt[0]= -1 ; 
	for(ll i= 2;i<=(ll)1e3;i++)if(nt[i]==0)
	{
		nt[i] = i; 
		for(ll j =i*i;j<=(ll)1e6;j+=i)nt[j] = i ;
	}
	for(ll i = 2;i<=(ll)1e6;i++)
	{
		if(nt[i]==0)nt[i] = i; 
	}
} 
ve<pii> pt(int val)
{	
	ve<pii>q ;
	while(val!=1)
	{		
		int x= nt[val] ; 
		int cnt =0 ; 
		while(val%x==0)
		{
			++cnt; 
			val/=x;
		}
		q.pb(mp(x,cnt));
	}	
	return q ; 
}		
int a[N] ;
void read()
{
	cin>>n>>q>>s ;
	FOR(i,1,n)cin>>a[i];
}
int node= 0 ; 
int update(int id,  int l , int r , int pos ,int val )
{
	int cur = ++node;
	if(l==r)
	{	
		st[cur] = st[id]+val;  
		return cur ; 
	}
	int mid =(l+r)/2; 
	if(pos<=mid)
	{
		R[cur] =R[id] ;
		L[cur]= update(L[id],l,mid,pos,val); 
	}
	else
	{
		L[cur] =L[id] ; 
		R[cur] =update(R[id],mid+1,r,pos,val) ;
	}
	st[cur]=st[L[cur]]+st[R[cur]];
	return cur ; 
}
int get(int id ,int l, int r, int t , int p)
{
	if(t<=l&&r<=p)return st[id] ;
	if(r<t||p<l)return 0 ; 
	int mid =(l+r)/2; 
	return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
}
void solve()
{

	int m= (int)1e6;	
	FOR(i,1,n)
	{
		ve<pii>uoc = pt(a[i]) ; 
		head[i] = head[i-1];
		for(auto v: uoc)
		{
			head[i]  = update(head[i],1,m,v.fi,v.se);	
		}
	} 
	ll res= 0;
	FOR(i,1,q)
	{
		int x , y , z , t  ; 
		cin>>x>>y>>z>>t ; 
		int L = 1 + min((x + sum*s)%n,(y + sum * s)%n);
		int R = 1 + max((x + sum*s)%n,(y + sum * s)%n);
		int u = 1 + min((z + sum*s)%sm,(t + sum * s)%sm);
		int v = 1 + max((z + sum*s)%sm,(t + sum * s)%sm);

		res= get(head[R],1,m,u,v)-get(head[L-1],1,m,u,v);
		cout<<res<<el; 
		sum+=res; 
	}	
}	

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
    	snt() ;
        read(); 
        solve();
    }
}