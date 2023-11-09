/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "d13cutstrct"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
#define pll pair<ll,ll> 
const int N =1e4+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm1 = 1e9+7, sm2 = 1e9+11,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ; 
pll mu[N]  ; 
pll ha[N]  , hb[N] ; 
void doc()
{
 	string s ; cin>>s; 
	n=s.size() ;  
 	s="#"+s;
 	FOR(i,1,n)
 	{
 		a[i] =s[i] ;
 		ha[i].fi = (ha[i-1].fi*cs+a[i])%sm1 ;
 		ha[i].se = (ha[i-1].se*cs+a[i])%sm2 ;
 	}  
 	for(int  i= 1  , j = n ; i<=n;i++,j--)
 	{ 
 		hb[i].fi = (hb[i-1].fi*cs+a[j])%sm1 ;
 		hb[i].se = (hb[i-1].se*cs+a[j])%sm2 ;
 	}
 	mu[0] = {1,1}; 
 	FOR(i,1,n)mu[i].fi = mu[i-1].fi*cs%sm1,mu[i].se=mu[i-1].se*cs%sm2;
}
pll get_hash(int l , int r ,pll ha[])
{
	return {(ha[r].fi - ha[l-1].fi*mu[r-l+1].fi%sm1 +sm1*sm1)%sm1,(ha[r].se-ha[l-1].se*mu[r-l+1].se%sm2+sm2*sm2)%sm2}; 
}
vi value ;  
vi query[N] ;
bool check(int l , int r)
{
	pll x= get_hash(l,r,ha) ;
	pll y= get_hash(n-l+1,hb) ; 
	return (x==y) ;
}
int g[N][2610];
int id[2610];
void build()
{
	FORD(i,n,1)
	{	
		FORN(j,0,value.size())
		{	
			g[i][j] = g[i+1][j];
		} 	
		FORN(j,0,value.size())
		{
			int len = value[j]; 
			if(i+len-1>n)break; 
			if(check(i,i+len-1))
			{
				g[i][j] =  i ;
			}
		}
	}
} 
struct BG 
{
	int u  ; 
	int mask ; 
}; 
bool f[N][1<<13];

bool bfs(vi& a)
{
	queue<BG>q;
	int m =a.size() ;
	FOR(i,1,n+1)
	{
		FORN(j,0,(1<<m))
		{
			f[i][j] = 0 ;
		}
	} 
	// memset(f,0,sizeof(f));
	f[1][0]=1;
	q.push({1,0}); 
	while(!q.empty())
	{
		int u= q.front().u ;
		int mask= q.front().mask ; 
		q.pop() ;
		if(u==n+1)continue ;
		for(int i =0  ;i<a.size();i++)
		{
			int pos= id[a[i]];
			
			if(mask>>i&1)continue ;
			if(!g[u][pos])continue;

			int v= g[u][pos] ; 
			int x= v+value[pos]; 
			if(f[x][mask|(1<<i)])continue ;
			f[x][mask|(1<<i)]=1; 
			if((mask|(1<<i))==(1<<m)-1)return 1 ;
			if(x==n+1)continue;
			q.push({x,mask|(1<<i)}) ;  
		}
	}
	return 0 ; 
}
void xuly()
{	
	int m;  
	cin>> m ;
	
	FOR(i,1,m)
	{
		int k ; 
		cin>> k; 
		FOR(j,1,k)
		{
			int len ; cin>>len ; 
			query[i].pb(len) ; 
			value.pb(len) ;
		}
	}
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin());
	FORN(i,0,value.size())
	{
		id[value[i]] =i ;
	}
	build() ; 
	FOR(i,1,m)
	{
		bool ok = bfs(query[i]);
		if(ok)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}	