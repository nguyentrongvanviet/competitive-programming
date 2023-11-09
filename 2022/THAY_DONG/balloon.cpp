#include<bits/stdc++.h>

#define TASK "balloon"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define db long double
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;

const int N =2e2+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e10  ;  
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};


struct pt 
{
	ll x, y ; 
	pt operator-(const pt &a)const
	{
		return pt{x-a.x,y-a.y}; 
	}
	ll operator *(const pt &a)const
	{
		return x*a.y-y*a.x; 
	}
};
ll sq(ll a){return a*a ; }
ll dis(pt a , pt b){return  sq(a.x-b.x)+sq(a.y-b.y) ;}
struct line
{
	ll a , b ,c ;
	db dis(const pt& p)
	{
		return (db)abs(a*p.x+b*p.y+c)/sqrt((sq(a)+sq(b)));
	} 
};
line create(pt a, pt b)
{
	ll A =a.y-b.y; 
	ll B =b.x-a.x; 
	ll C = -A*a.x-B*a.y; 
	return {A,B,C}; 
}
db distance(pt&A , pt&B , pt&C)
{
	ll c= dis(A,B) ;
	ll b = dis(A,C) ; 
	ll a=  dis(B,C) ; 

	if(a+b>=c||a+c>=b)
	{
		return (db)min(sqrt(b),sqrt(c)) ; 
	} 
	line tmp = create(B,C);  
	return min(tmp.dis(B),tmp.dis(C)); 
}
db minlen(pt&a , ve<pt>&p)
{
	db best =(db)inf ; 
	for(int i=1;i<p.size();i++)
	{	
		best = min(best, distance(a,p[i],p[i-1]));
	}	
	return best ; 
}  
db mindis(ve<pt>&u , ve<pt>&v)
{
	int n = u.size(); 
	int m=  v.size(); 
	db res= (db)inf ; 
	for(auto node : u)
	{
		db dis = minlen( node , v) ;
		res=min(res,dis);
	}
	return res; 
}
int n  ,S , T ; 
ve<pt> P[N] ; 

void read()
{
    cin>> n >>S >>T  ;
    FOR(i,1,n)
    {
    	int m ; cin>> m; 
    	FOR(j,1,m)
    	{	
    		ll x, y ; 
    		cin>>x>>y;
    		P[i].pb({x,y}) ; 
    	}
    	P[i].pb(P[i][0]);
    } 	
}
struct ke 
{
	int v ; 
	ll w ; 
}; 
struct BG 
{
	int u ; 
	ll val; 
};
struct cmp
{
	bool operator()(BG a ,BG b)
	{
		return a.val>b.val; 
	}
};
ll f[N] ;
bool dd[N] ;
ve<ke>g[N] ;
db dij(int s, int t )
{
	priority_queue<BG,ve<BG>,cmp>q; 
	FOR(i,1,n)f[i] = inf;  
	q.push({s,f[s]=0LL}); 
	while(!q.empty())
	{
		int u =q.top().u; 
		q.pop() ; 
		if(dd[u])continue;
		for(auto it: g[u])
		{
			int v= it.v; 
			ll w = it.w;
			if(dd[v])continue ;
			if(f[v]>f[u]+w)
			{
				q.push({v,f[v]=f[u]+w}); 
			}
		} 
	}
	return f[t] ; 
}
void build()
{
	FOR(i,1,n)
	{
		FOR(j,i+1,n)
		{
			db dis= mindis(P[i],P[j]) ; 
			g[i].pb({j,(ll)(dis*1e6)});
			g[j].pb({i,(ll)(dis*1e6)});
			// cout<<i<<" "<<j<<" "<<dis<<endl;
		}
	}
}
void process()
{
	// cout<<mindis(P[1],P[2])<<endl;
 	build();   
}
void print()
{	
    ll res= dij(S,T); 
    cout<<(ll)res;
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
    
}