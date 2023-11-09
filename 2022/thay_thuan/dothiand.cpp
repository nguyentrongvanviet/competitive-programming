#define TASK "dothiand"
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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};


int n , m ; 

int dd[1<<23][2] ; 
int a[N] ; 
int ok[1<<23] ;
void read()
{
	cin>> n >> m;  
	FOR(i,1,m)cin>>a[i],ok[a[i]]= 1;
}
void dfs(int u,int t)
{
    dd[u][t]= 1 ; 
    if(t==1)
    {   
        if(dd[u][0]==0)dfs(u,0);
    }
    else
    {
        if(dd[(1<<n)-1-u][1]==0&&ok[(1<<n)-1-u])dfs((1<<n)-1-u,1);
        FORN(i,0,n)
        {
            if(!(u>>i&1))
            {
                if(dd[u|(1<<i)][0]==0)dfs(u|(1<<i),0);
            }   
        }
    }
}
void solve()
{   
    int res= 0 ;
    FOR(i,1,m)
    {
        if(dd[a[i]][1])continue;
        dfs(a[i],1); 
        res++ ; 
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
        solve();
    }
}