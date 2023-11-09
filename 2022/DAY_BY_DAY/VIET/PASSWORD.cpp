#define TASK "text"
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
const int N =20+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

str s ; 
int n  ; 
int a[20] ;
int sl[10] ; 
int h[N] ;
ll f[N][1<<16][3];
int pos[1<<16][10];
void read()
{
	cin>>s ; 
	n= s.size(); 
	s="$"+s;
	FOR(i,1,n)a[i] = s[i]-'0';
	FOR(i,1,n)cin>>h[i];
	for(int bit=0;bit<(1<<n);bit++)
	{
		for(int j= 1; j<=9;j++)
		{
			for(int i=0;i<n;i++)
			{
				if((bit>>i&1)==0&&a[i+1]==j&&pos[bit][j]==0)
				{
					pos[bit][j] =i; 
				}
			}
		}
	}
}
int tinh(int idx,int bit,int ok)
{
	if(f[idx][bit][ok]!=-1)return f[idx][bit][ok];
	if(idx==n+1)
	{
		return f[idx][bit][ok] = 1; 
	}
	f[idx][bit][ok] = 0 ; 
	for(int i= 1;i<=9;i++)		
	{
		if(pos[bit][i]&&h[idx]!=i)
		{
			int nok = ok ; 
			if(ok==0)
			{
				if(a[idx]<i)nok =1 ; 
				else if(a[idx]>i)nok = 2 ;
			}
			f[idx][bit][ok]|=tinh(idx+1,bit|(1<<(pos[bit][i]-1)),nok);
		}
	}
	return f[idx][bit][ok] ; 
};
struct DL
{
	int idx ;
	int bit ; 
	int ok ; 
	ll w; 
}; 
struct cmp
{
	bool operator()(DL a , DL b)
	{
		return a.w>b.w; 
	}
};
ll trace()
{
	prirotity_queue<DL,ve<DL>,cmp>q; 
	FOR(i,1,n+1)
	{
		for(int j = 0;j<(1<<i);j++)
		{
			for(int ok = 0 ; ok<=2;ok++)
			{
				d[i][j][ok] = inf ; 
			}
		}
	}
	q.push({1,0,0});
	d[1][0][0] = 0 ;	
	ll ans = inf ;
	while(!q.empty())
	{
		int idx = q.top().idx; 
		int bit = q.top().bit;
		int ok = q.top().ok ;
		ll w= q.top().w; 
		q.pop() ;
		if(d[idx][bit][ok]!=w)continue ;
		if(idx==n+1)res=min(res,w) ;
		for(int i= 1;i<=9;i++)
		{
			if(pos[bit][i]&&h[idx]!=i)
			{
				if(pos[bit][i]&&h[idx]!=i)
				{
					int nok = ok ; 
					ll nw =w*10;
					if(ok==0)
					{
						if(a[idx]<i)
						{
							nw+=();
							nok =1 ; 
						}
						else if(a[idx]>i)
						{
							nok = 2 ;
						}
					}
					else if(ok==1)
					{
						nw += 
					}
					ll u = d[idx+1][bit|(1<<(pos[bit][i]-1))][nok] ;
				}
			}
		} 
	}
	return ans; 
}
void solve()
{
	memset(f,-1,sizeof(f)) ; 
	ll ok = tinh(1,0,0) ; 
	if(ok==0)return void(cout<<-1);
	ll res= trace();
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